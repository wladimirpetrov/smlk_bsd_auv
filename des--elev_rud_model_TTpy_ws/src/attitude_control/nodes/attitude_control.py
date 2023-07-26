#!/usr/bin/env python3

import rospy
from std_msgs.msg import Float64
from avl_bsd_translator.msg import HeartbeatMsg, CommandMsg, ActionMsg
import numpy as np

class AttitudeControl:

    def __init__(self):

        rospy.init_node('attitude_control')

        self.command_pub = rospy.Publisher('bsd/command', CommandMsg, queue_size=10)
        self.action_pub = rospy.Publisher('bsd/action', ActionMsg, queue_size=10)
        self.z_ref_sub = rospy.Subscriber('z_ref_msg', Float64, self.z_ref_callback)
        self.psi_ref_sub = rospy.Subscriber('psi_ref_msg', Float64, self.psi_ref_callback)
        self.x_des_sub = rospy.Subscriber('x_des_msg', Float64, self.x_des_callback)
        self.y_des_sub = rospy.Subscriber('y_des_msg', Float64, self.y_des_callback)
        self.heartbeat_sub = rospy.Subscriber('bsd/heartbeat', HeartbeatMsg, self.heartbeat_callback)

        self.Ts = 0.05
        
        self.z_ref = 0.0
        self.psi_ref = 0.0
        self.x_des = 0.0
        self.y_des = 0.0
        self.x = 0.0
        self.y = 0.0
        self.z = 0.0
        self.psi = 0.0
        self.u = 0.0
        self.v = 0.0
        self.w = 0.0

        self.zerr_prev = 0.0
        self.zerrint_prev = 0.0
        self.psierr_prev = 0.0
        self.psierrint_prev = 0.0
        self.verr_prev = 0.0
        self.verrint_prev = 0.0

        # Read PID gains and additional variables from the ROS parameter server
        self.kp_elevator = rospy.get_param('~kp_elevator', 2.0)
        self.ki_elevator = rospy.get_param('~ki_elevator', 0.5)
        self.kd_elevator = rospy.get_param('~kd_elevator', 0.1)

        self.kp_rudder = rospy.get_param('~kp_rudder', 1.5)
        self.ki_rudder = rospy.get_param('~ki_rudder', 0.2)
        self.kd_rudder = rospy.get_param('~kd_rudder', 0.05)

        self.kp_prop = rospy.get_param('~kp_prop', 1.2)
        self.ki_prop = rospy.get_param('~ki_prop', 0.3)
        self.kd_prop = rospy.get_param('~kd_prop', 0.05)

        self.kx = rospy.get_param('~kx', 1.0)
        self.ky = rospy.get_param('~ky', 1.0)
        print('kp_elevator',self.kp_elevator)

    def x_actual_callback(self, msg):
        self.x = msg.data

    def y_actual_callback(self, msg):
        self.y = msg.data

    def z_ref_callback(self, msg):
        self.z_ref = msg.data

    def psi_ref_callback(self, msg):
        self.psi_ref = msg.data

    def x_des_callback(self, msg):
        self.x_des = msg.data

    def y_des_callback(self, msg):
        self.y_des = msg.data

    def heartbeat_callback(self, msg):
        self.u = msg.HEARTBEAT_VN
        self.v = msg.HEARTBEAT_VE
        self.w = msg.HEARTBEAT_VD
        self.z = msg.HEARTBEAT_DEPTH
        self.psi = msg.HEARTBEAT_YAW

        kx = self.kx  # Use the kx value extracted from the parameter server
        ky = self.ky  # Use the ky value extracted from the parameter server

        #x_error = self.x - self.x_des
        #y_error = self.y - self.y_des
        #z_error = self.z - self.z_ref

        x_error = self.x_des - self.x
        y_error = self.y_des - self.y
        z_error = self.z_ref - self.z


        rwi = np.array([[np.cos(self.psi), -np.sin(self.psi)],
                        [np.sin(self.psi), np.cos(self.psi)]])
        xy_error_rot = np.dot(rwi, np.array([[x_error], [y_error]]))
        x_error_rot = xy_error_rot[0][0]
        y_error_rot = xy_error_rot[1][0]

        v_des = kx * x_error_rot
        psi_des = ky * y_error_rot

        elevator = self.PID(z_error, self.kp_elevator, self.ki_elevator, self.kd_elevator, self.zerr_prev, self.zerrint_prev)
        rudder = self.PID(psi_des - self.psi, self.kp_rudder, self.ki_rudder, self.kd_rudder, self.psierr_prev, self.psierrint_prev)
        prop = self.PID(v_des, self.kp_prop, self.ki_prop, self.kd_prop, self.verr_prev, self.verrint_prev)

        elevator = self.limit_elevator(elevator)
        rudder = self.limit_rudder(rudder)

        print("elevator:", elevator)
        print("rudder:", rudder)
        print("prop:", prop)
        print("___________________")

        self.send_action_msg(2.0, elevator, rudder, prop)
        self.send_command_msg()

        self.zerr_prev = z_error
        self.psierr_prev = psi_des - self.psi
        self.verr_prev = v_des

        self.update_position()

    def PID(self, error, kp, ki, kd, prev_err, prev_int_err):
        error_int = error * self.Ts + prev_int_err
        error_dot = (error - prev_err) / self.Ts

        output = kp * error + ki * error_int + kd * error_dot

        return output

    def limit_elevator(self, value):
        if value >= 20:
            return 20
        elif value <= -20:
            return -20
        else:
            return value

    def limit_rudder(self, value):
        if value >= 20:
            return 20
        elif value <= -20:
            return -20
        else:
            return value

    def send_command_msg(self):
        command_msg = CommandMsg()
        command_msg.COMMAND_NAME = "MISSION"
        command_msg.NAMES = ["COMMAND"]
        command_msg.TYPES = [0x01]
        command_msg.VALUES = [str(0)]
        self.command_pub.publish(command_msg)  # Publish the command message

    def send_action_msg(self, duration, elevator, rudder, rpm):
        action_msg = ActionMsg()
        action_msg.ACTION_TYPE = "PRIMITIVE"
        action_msg.MODE = 0
        action_msg.NAMES = ["DURATION", "ELEVATOR", "RUDDER", "RPM"]
        action_msg.TYPES = [0x02, 0x02, 0x02, 0x02]
        action_msg.VALUES = [str(duration), str(elevator), str(rudder), str(rpm)]
        self.action_pub.publish(action_msg)  # Publish the action message

    def update_position(self):
            # Convert body-fixed velocity components to Earth-fixed velocity components
            u_e = self.u * np.cos(self.psi) - self.v * np.sin(self.psi)
            v_e = self.u * np.sin(self.psi) + self.v * np.cos(self.psi)

            # Integrate Earth-fixed velocity components to get position
            self.x += u_e * self.Ts
            self.y += v_e * self.Ts

    def run(self):
        rospy.spin()

if __name__ == '__main__':
    attitude_control = AttitudeControl()
    attitude_control.run()
