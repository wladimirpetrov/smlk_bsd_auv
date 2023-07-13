#include <ros/ros.h>
#include <avl_bsd_translator/HeartbeatMsg.h>
#include <avl_bsd_translator/CommandMsg.h>
#include <avl_bsd_translator/ActionMsg.h>

class HeartbeatPublisher {
public:
    HeartbeatPublisher() {
        ros::NodeHandle nh;

        heartbeat_pub = nh.advertise<avl_bsd_translator::HeartbeatMsg>("bsd/heartbeat", 10);
        command_sub = nh.subscribe("bsd/command", 10, &HeartbeatPublisher::command_callback, this);
        action_sub = nh.subscribe("bsd/action", 10, &HeartbeatPublisher::action_callback, this);

        heartbeat_msg.HEARTBEAT_STATUS = 1;
        heartbeat_msg.HEARTBEAT_ROLL = 0.0;
        heartbeat_msg.HEARTBEAT_PITCH = 0.0;
        heartbeat_msg.HEARTBEAT_YAW = 0.0;
        heartbeat_msg.HEARTBEAT_VN = 0.0; // VX origin
        heartbeat_msg.HEARTBEAT_VE = 0.0; // VY origin
        heartbeat_msg.HEARTBEAT_VD = 0.0; // VZ origin
        heartbeat_msg.HEARTBEAT_DEPTH = 250.0;
        heartbeat_msg.HEARTBEAT_HEIGHT = 0.0;
        heartbeat_msg.HEARTBEAT_RPM = 1500.0;
        heartbeat_msg.HEARTBEAT_WX = 0.0;
        heartbeat_msg.HEARTBEAT_WY = 0.0;
        heartbeat_msg.HEARTBEAT_WZ = 0.0;
        heartbeat_msg.HEARTBEAT_AX = 0.0;
        heartbeat_msg.HEARTBEAT_AY = 0.0;
        heartbeat_msg.HEARTBEAT_AZ = 0.0;
        heartbeat_msg.HEARTBEAT_VOLTAGE = 0.0;
        heartbeat_msg.HEARTBEAT_UMODEM_SYNC = 1;
        //heartbeat_msg.HEARTBEAT_IRIDIUM_STRENGTH = 4;
        heartbeat_msg.HEARTBEAT_MISSION_MODE = 3;
        heartbeat_msg.HEARTBEAT_FSD_MISSION_STATE = 0;
        heartbeat_msg.HEARTBEAT_FSD_CURRENT_ACTION = 1;
        heartbeat_msg.HEARTBEAT_FSD_TOTAL_ACTIONS = 5;
        heartbeat_msg.HEARTBEAT_FSD_ACTION_PERCENT = 20.0;
        heartbeat_msg.HEARTBEAT_BSD_MISSION_STATE = 0;
        heartbeat_msg.HEARTBEAT_BSD_CURRENT_ACTION = 2;
        heartbeat_msg.HEARTBEAT_BSD_TOTAL_ACTIONS = 3;
        heartbeat_msg.HEARTBEAT_BSD_ACTION_PERCENT = 50.0;
        heartbeat_msg.HEARTBEAT_GPS_SATS = 8;
        heartbeat_msg.HEARTBEAT_GPS_LAT = 37.7749;
        heartbeat_msg.HEARTBEAT_GPS_LON = -122.4194;
        heartbeat_msg.HEARTBEAT_GPS_ALT = 0.0;
        heartbeat_msg.HEARTBEAT_NAV_LAT = 37.7749;
        heartbeat_msg.HEARTBEAT_NAV_LON = -122.4194;
        heartbeat_msg.HEARTBEAT_NAV_ALT = 0.0;
        heartbeat_msg.HEARTBEAT_NAV_YAW_STD = 0;
        heartbeat_msg.HEARTBEAT_NAV_AVG_POS_ERR = 0;
        heartbeat_msg.HEARTBEAT_NAV_INITIALIZED = 1;
    }

    void send_heartbeat_msg(const ros::TimerEvent& event) {
        heartbeat_pub.publish(heartbeat_msg);
    }

    void command_callback(const avl_bsd_translator::CommandMsg::ConstPtr& msg) {
        if (msg->COMMAND_NAME == "MISSION") {
            heartbeat_msg.HEARTBEAT_ROLL += 1;
        }
    }

    void action_callback(const avl_bsd_translator::ActionMsg::ConstPtr& msg) {
        heartbeat_msg.HEARTBEAT_DEPTH += 1;
    }

    void run() {
        ros::Timer timer = nh.createTimer(ros::Duration(0.1), &HeartbeatPublisher::send_heartbeat_msg, this);
        ros::spin();
    }

private:
    ros::Publisher heartbeat_pub;
    ros::Subscriber command_sub;
    ros::Subscriber action_sub;
    avl_bsd_translator::HeartbeatMsg heartbeat_msg;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "auv_imp");
    HeartbeatPublisher heartbeat_publisher;
    heartbeat_publisher.run();
    return 0;
}
