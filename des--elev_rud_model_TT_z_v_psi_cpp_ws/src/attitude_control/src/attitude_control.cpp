#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <avl_bsd_translator/HeartbeatMsg.h>
#include <avl_bsd_translator/CommandMsg.h>
#include <avl_bsd_translator/ActionMsg.h>
#include <cmath>

class AttitudeControl {
public:
    AttitudeControl() {
        ros::NodeHandle nh;

        command_pub = nh.advertise<avl_bsd_translator::CommandMsg>("/bsd/command", 10);
        action_pub = nh.advertise<avl_bsd_translator::ActionMsg>("/bsd/action", 10);
        z_ref_sub = nh.subscribe("/z_ref_msg", 1, &AttitudeControl::z_ref_callback, this);
        psi_ref_sub = nh.subscribe("/psi_ref_msg", 1, &AttitudeControl::psi_ref_callback, this);
        x_des_sub = nh.subscribe("/x_des_msg", 1, &AttitudeControl::x_des_callback, this);
        y_des_sub = nh.subscribe("/y_des_msg", 1, &AttitudeControl::y_des_callback, this);
        heartbeat_sub = nh.subscribe("/bsd/heartbeat", 1, &AttitudeControl::heartbeat_callback, this);

        Ts = 0.05;

        z_ref = 0.0;
        psi_ref = 0.0;
        x_des = 0.0;
        y_des = 0.0;
        x = 0.0;
        y = 0.0;
        z = 0.0;
        psi = 0.0;
        roll = 0.0;
        pitch = 0.0;
        yaw = 0.0;
        v_north = 0.0;
        v_east = 0.0;
        v_depth = 0.0;

        zerr_prev = 0.0;
        zerrint_prev = 0.0;
        psierr_prev = 0.0;
        psierrint_prev = 0.0;
        verr_prev = 0.0;
        verrint_prev = 0.0;

        nh.param<double>("kp_elevator", kp_elevator, 9.0);
        nh.param<double>("ki_elevator", ki_elevator, 0.0);
        nh.param<double>("kd_elevator", kd_elevator, 5.0);

        nh.param<double>("kp_rudder", kp_rudder, 2.0);
        nh.param<double>("ki_rudder", ki_rudder, 0.0);
        nh.param<double>("kd_rudder", kd_rudder, 1.0);

        nh.param<double>("kp_prop", kp_prop, 1.2);
        nh.param<double>("ki_prop", ki_prop, 0.3);
        nh.param<double>("kd_prop", kd_prop, 3.0);

        nh.param<double>("kx", kx, 30.0);
        nh.param<double>("ky", ky, 1.0);
    }


    void z_ref_callback(const std_msgs::Float64& msg) {
        z_ref = msg.data;
    }

    void psi_ref_callback(const std_msgs::Float64& msg) {
        psi_ref = msg.data;
    }

    void x_des_callback(const std_msgs::Float64& msg) {
        x_des = msg.data;
    }

    void y_des_callback(const std_msgs::Float64& msg) {
        y_des = msg.data;
    }

    void heartbeat_callback(const avl_bsd_translator::HeartbeatMsg& msg) {
        v_north = msg.HEARTBEAT_VN;
        v_east = msg.HEARTBEAT_VE;
        v_depth = msg.HEARTBEAT_VD;
        z = msg.HEARTBEAT_DEPTH;
        psi = msg.HEARTBEAT_YAW;
        roll = msg.HEARTBEAT_ROLL;
        pitch = msg.HEARTBEAT_PITCH;
        yaw = msg.HEARTBEAT_YAW;
        actual_speed = msg.HEARTBEAT_RPM;
        x = msg.HEARTBEAT_GPS_LAT;
        y = msg.HEARTBEAT_GPS_LON;

        double u = v_north * cos(pitch) * cos(yaw) + v_east * (sin(roll) * sin(pitch) * cos(yaw) - cos(roll) * sin(yaw)) + v_depth * (cos(roll) * sin(pitch) * cos(yaw) + sin(roll) * sin(yaw));
        double v = v_north * cos(pitch) * sin(yaw) + v_east * (sin(roll) * sin(pitch) * sin(yaw) + cos(roll) * cos(yaw)) + v_depth * (cos(roll) * sin(pitch) * sin(yaw) - sin(roll) * cos(yaw));
        double w = -v_north * sin(pitch) + v_east * sin(roll) * cos(pitch) + v_depth * cos(roll) * cos(pitch);

        double kx = this->kx;  // Use the kx value extracted from the parameter server
        double ky = this->ky;  // Use the ky value extracted from the parameter server

        double x_error = x_des - x;
        double y_error = y_des - y;
        double z_error = z_ref - z;

        double rwi[2][2] = {{cos(psi), -sin(psi)},
                            {sin(psi), cos(psi)}};
        double xy_error_rot[2][1] = {{x_error * rwi[0][0] + y_error * rwi[0][1]},
                                     {x_error * rwi[1][0] + y_error * rwi[1][1]}};
        double x_error_rot = xy_error_rot[0][0];
        double y_error_rot = xy_error_rot[1][0];

        double v_des = kx * fabs(x_error_rot);
        double psi_des = ky * y_error_rot;

        double elevator = -PID(z_error, kp_elevator, ki_elevator, kd_elevator, zerr_prev, zerrint_prev); // used to be +PID
        double rudder = PID(psi_des - psi, kp_rudder, ki_rudder, kd_rudder, psierr_prev, psierrint_prev);
        double prop = fabs(PID(v_des, kp_prop, ki_prop, kd_prop, verr_prev, verrint_prev));

        elevator = limit_elevator(elevator);
        rudder = limit_rudder(rudder);
        prop = limit_prop(prop);  // Limit the prop value

        send_action_msg(2.0, elevator, rudder, prop);
        send_command_msg();

        zerr_prev = z_error;
        zerrint_prev = zerrint_prev + z_error * Ts;

        psierr_prev = psi_des - psi;
        psierrint_prev = psierrint_prev + (psi_des - psi) * Ts;

        verr_prev = v_des;
        verrint_prev = verrint_prev + v_des * Ts;

        update_position(u, v, w);
    }

    double PID(double error, double kp, double ki, double kd, double prev_err, double& integral) {
        integral = integral + error * Ts;
        // Limit the integral term to prevent windup
        integral = std::max(std::min(integral, 5.0), -5.0);
        double derivative = (error - prev_err) / Ts;
        double output = kp * error + ki * integral + kd * derivative;
        return output;
    }

    double limit_elevator(double value) {
        if (value >= 20.0)
            return 20.0;
        else if (value <= -20.0)
            return -20.0;
        else
            return value;
    }

    double limit_rudder(double value) {
        if (value >= 20.0)
            return 20.0;
        else if (value <= -20.0)
            return -20.0;
        else
            return value;
    }

    double limit_prop(double value) {
        return std::max(std::min(value, 1500.0), 400.0);
    }

    void send_command_msg() {
        avl_bsd_translator::CommandMsg command_msg;
        command_msg.COMMAND_NAME = "MISSION";
        command_msg.NAMES = {"COMMAND"};
        command_msg.TYPES = {0x01};
        command_msg.VALUES = {"0"};
        command_pub.publish(command_msg);  // Publish the command message
    }

    void send_action_msg(double duration, double elevator, double rudder, double prop) {
        avl_bsd_translator::ActionMsg action_msg;
        action_msg.ACTION_TYPE = "PRIMITIVE";
        action_msg.MODE = 0;
        action_msg.NAMES = {"DURATION", "ELEVATOR", "RUDDER", "RPM"};
        action_msg.TYPES = {0x02, 0x02, 0x02, 0x02};
        action_msg.VALUES = {std::to_string(duration), std::to_string(elevator), std::to_string(rudder), std::to_string(prop)};
        action_pub.publish(action_msg);
    }

    void update_position(double u, double v, double w) {
        // Convert body-fixed velocity components to Earth-fixed velocity components
        double u_e = u * cos(psi) - v * sin(psi);
        double v_e = u * sin(psi) + v * cos(psi);

        // Integrate Earth-fixed velocity components to get position
        x += u_e * Ts;
        y += v_e * Ts;
    }

    void run() {
        // Reset the integral terms before starting the control loop
        zerrint_prev = 0.0;
        psierrint_prev = 0.0;
        verrint_prev = 0.0;

        ros::Rate rate(1.0 / Ts);  // Run control loop at specified rate

        while (ros::ok()) {
            ros::spinOnce();
            // Rest of the control loop code remains unchanged

            rate.sleep(); // This will control the loop frequency
        }
    }

private:
    ros::Publisher command_pub;
    ros::Publisher action_pub;
    ros::Subscriber z_ref_sub;
    ros::Subscriber psi_ref_sub;
    ros::Subscriber x_des_sub;
    ros::Subscriber y_des_sub;
    ros::Subscriber heartbeat_sub;

    double Ts;
    double z_ref;
    double psi_ref;
    double x_des;
    double y_des;
    double x;
    double y;
    double z;
    double psi;
    double roll;
    double pitch;
    double yaw;
    double v_north;
    double v_east;
    double v_depth;
    double actual_speed;

    double zerr_prev;
    double zerrint_prev;
    double psierr_prev;
    double psierrint_prev;
    double verr_prev;
    double verrint_prev;

    double kp_elevator;
    double ki_elevator;
    double kd_elevator;
    double kp_rudder;
    double ki_rudder;
    double kd_rudder;
    double kp_prop;
    double ki_prop;
    double kd_prop;
    double kx;
    double ky;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "attitude_control");

    AttitudeControl attitude_control;
    attitude_control.run();

    return 0;
}
