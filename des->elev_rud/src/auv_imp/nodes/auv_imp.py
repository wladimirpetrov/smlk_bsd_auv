#!/usr/bin/env python3

import rospy

from avl_bsd_translator.msg import CommandMsg, ActionMsg, HeartbeatMsg

class HeartbeatPublisher:

    def __init__(self):
        rospy.init_node('auv_imp')

        self.heartbeat_pub = rospy.Publisher('bsd/heartbeat', HeartbeatMsg, queue_size=10)
        self.command_sub = rospy.Subscriber('bsd/command', CommandMsg, self.command_callback)
        self.action_sub = rospy.Subscriber('bsd/action', ActionMsg, self.action_callback)

        self.heartbeat_msg = HeartbeatMsg()
        self.heartbeat_msg.HEARTBEAT_STATUS = 1
        self.heartbeat_msg.HEARTBEAT_ROLL = 0.5
        self.heartbeat_msg.HEARTBEAT_PITCH = 0.5
        self.heartbeat_msg.HEARTBEAT_YAW = 0.4
        self.heartbeat_msg.HEARTBEAT_VN = 0.1 # VX origin
        self.heartbeat_msg.HEARTBEAT_VE = 0.2 # VY origin
        self.heartbeat_msg.HEARTBEAT_VD = 0.3 # VZ origin
        self.heartbeat_msg.HEARTBEAT_DEPTH = 250.0
        self.heartbeat_msg.HEARTBEAT_HEIGHT = 0.0
        self.heartbeat_msg.HEARTBEAT_RPM = 1500.0
        self.heartbeat_msg.HEARTBEAT_WX = 0.3
        self.heartbeat_msg.HEARTBEAT_WY = 0.2
        self.heartbeat_msg.HEARTBEAT_WZ = 0.1
        self.heartbeat_msg.HEARTBEAT_AX = 0.1
        self.heartbeat_msg.HEARTBEAT_AY = 0.1
        self.heartbeat_msg.HEARTBEAT_AZ = 0.1
        self.heartbeat_msg.HEARTBEAT_VOLTAGE = 0.1
        self.heartbeat_msg.HEARTBEAT_UMODEM_SYNC = 1
        #self.heartbeat_msg.HEARTBEAT_IRIDIUM_STRENGTH = 4
        self.heartbeat_msg.HEARTBEAT_MISSION_MODE = 3
        self.heartbeat_msg.HEARTBEAT_FSD_MISSION_STATE = 0
        self.heartbeat_msg.HEARTBEAT_FSD_CURRENT_ACTION = 1
        self.heartbeat_msg.HEARTBEAT_FSD_TOTAL_ACTIONS = 5
        self.heartbeat_msg.HEARTBEAT_FSD_ACTION_PERCENT = 20.0
        self.heartbeat_msg.HEARTBEAT_BSD_MISSION_STATE = 0
        self.heartbeat_msg.HEARTBEAT_BSD_CURRENT_ACTION = 2
        self.heartbeat_msg.HEARTBEAT_BSD_TOTAL_ACTIONS = 3
        self.heartbeat_msg.HEARTBEAT_BSD_ACTION_PERCENT = 50.0
        self.heartbeat_msg.HEARTBEAT_GPS_SATS = 8
        self.heartbeat_msg.HEARTBEAT_GPS_LAT = 37.7749
        self.heartbeat_msg.HEARTBEAT_GPS_LON = -122.4194
        self.heartbeat_msg.HEARTBEAT_GPS_ALT = 0.0
        self.heartbeat_msg.HEARTBEAT_NAV_LAT = 37.7749
        self.heartbeat_msg.HEARTBEAT_NAV_LON = -122.4194
        self.heartbeat_msg.HEARTBEAT_NAV_ALT = 0.0
        self.heartbeat_msg.HEARTBEAT_NAV_YAW_STD = 0
        self.heartbeat_msg.HEARTBEAT_NAV_AVG_POS_ERR = 0
        self.heartbeat_msg.HEARTBEAT_NAV_INITIALIZED = 1

    def send_heartbeat_msg(self, event):
        self.heartbeat_pub.publish(self.heartbeat_msg)

    def command_callback(self, msg):
        if msg.COMMAND_NAME == "MISSION":
            self.heartbeat_msg.HEARTBEAT_ROLL += 1

    def action_callback(self, msg):
        self.heartbeat_msg.HEARTBEAT_DEPTH += 1

    def run(self):
        rospy.Timer(rospy.Duration(0.1), self.send_heartbeat_msg)
        rospy.spin()

if __name__ == '__main__':
    heartbeat_publisher = HeartbeatPublisher()
    heartbeat_publisher.run()
