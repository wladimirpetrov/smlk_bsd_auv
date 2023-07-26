#!/usr/bin/env python3

import rospy
from avl_bsd_translator.msg import CommandMsg, ActionMsg, HeartbeatMsg
from std_msgs.msg import Float64

import math

class AUVNode:
    def __init__(self):
        rospy.init_node('auv_imp')

        self.heartbeat_pub = rospy.Publisher('bsd/heartbeat', HeartbeatMsg, queue_size=10)
        self.z_pub = rospy.Publisher('bsd/z', Float64, queue_size=10)  # New topic for z
        self.command_sub = rospy.Subscriber('bsd/command', CommandMsg, self.command_callback)
        self.action_sub = rospy.Subscriber('bsd/action', ActionMsg, self.action_callback)

        self.elevator = 0.0
        self.rudder = 0.0
        self.rpm = 0.0
        self.z = 250.0  # Initial depth value

        self.rate = rospy.Rate(1)  # Set the publishing frequency to 1 Hz

        self.update_heartbeat()  # Start publishing heartbeat messages

    def command_callback(self, command_msg):
        #self.elevator = command_msg.ELEVATOR
        #self.rudder = command_msg.RUDDER
        #self.rpm = command_msg.RPM
        print("command_msg received")

    def action_callback(self, action_msg):
        self.elevator = float(action_msg.VALUES[1])
        self.rudder = float(action_msg.VALUES[2])
        self.rpm = float(action_msg.VALUES[3])

    def update_heartbeat(self):
        roll = 0.0
        pitch = 0.0
        yaw = 0.0
        x = 0.0
        y = 0.0
        z = self.z  # Set the initial depth value
        u = self.elevator
        v = self.rudder
        w = 0.0
        p = 0.0
        q = 0.0
        r = 0.0

        dt = 1.0  # Time step in seconds

        # Convert elevator and rudder from degrees to radians
        elevator_rad = math.radians(self.elevator)
        rudder_rad = math.radians(self.rudder)

        # Calculate depth based on elevator control
        depth = z + (w * dt) + (0.5 * elevator_rad * (dt ** 2)) # (w*dt -change in depth with time due to vert vel. )
        # (0.5 * elevator_rad * (dt ** 2)) represents the change in depth over time 
        # due to the elevator control input. It is calculated using the kinematic 
        # equation for uniformly accelerated motion, considering the elevator control 
        # input as the acceleration. The factor of 0.5 is included because the equation 
        # assumes constant acceleration over the time step. 
        # The term (dt ** 2) represents the square of the time step.

        # Update position based on velocity components
        x += u * dt
        y += v * dt
        z = depth

        self.z = z  # Store the updated depth value

        # Publish depth value to additional topic
        self.z_pub.publish(self.z)

        heartbeat_msg = HeartbeatMsg()
        heartbeat_msg.HEARTBEAT_STATUS = 1
        heartbeat_msg.HEARTBEAT_ROLL = roll
        heartbeat_msg.HEARTBEAT_PITCH = pitch
        heartbeat_msg.HEARTBEAT_YAW = yaw
        heartbeat_msg.HEARTBEAT_VN = u
        heartbeat_msg.HEARTBEAT_VE = v
        heartbeat_msg.HEARTBEAT_VD = w
        heartbeat_msg.HEARTBEAT_DEPTH = z
        heartbeat_msg.HEARTBEAT_HEIGHT = y
        heartbeat_msg.HEARTBEAT_RPM = self.rpm
        heartbeat_msg.HEARTBEAT_WX = p
        heartbeat_msg.HEARTBEAT_WY = q
        heartbeat_msg.HEARTBEAT_WZ = r
        heartbeat_msg.HEARTBEAT_AX = 0.0
        heartbeat_msg.HEARTBEAT_AY = 0.0
        heartbeat_msg.HEARTBEAT_AZ = 0.0
        heartbeat_msg.HEARTBEAT_VOLTAGE = 0.0
        heartbeat_msg.HEARTBEAT_UMODEM_SYNC = 0
        heartbeat_msg.HEARTBEAT_MISSION_MODE = 0
        heartbeat_msg.HEARTBEAT_FSD_MISSION_STATE = 0
        heartbeat_msg.HEARTBEAT_FSD_CURRENT_ACTION = 0
        heartbeat_msg.HEARTBEAT_FSD_TOTAL_ACTIONS = 0
        heartbeat_msg.HEARTBEAT_FSD_ACTION_PERCENT = 0.0
        heartbeat_msg.HEARTBEAT_BSD_MISSION_STATE = 0
        heartbeat_msg.HEARTBEAT_BSD_CURRENT_ACTION = 0
        heartbeat_msg.HEARTBEAT_BSD_TOTAL_ACTIONS = 0
        heartbeat_msg.HEARTBEAT_BSD_ACTION_PERCENT = 0
        heartbeat_msg.HEARTBEAT_GPS_SATS = 0
        heartbeat_msg.HEARTBEAT_GPS_LAT = 0
        heartbeat_msg.HEARTBEAT_GPS_LON = 0
        heartbeat_msg.HEARTBEAT_GPS_ALT = 0.0
        heartbeat_msg.HEARTBEAT_NAV_LAT = 0
        heartbeat_msg.HEARTBEAT_NAV_LON = 0
        heartbeat_msg.HEARTBEAT_NAV_ALT = 0.0
        heartbeat_msg.HEARTBEAT_NAV_YAW_STD = 0
        heartbeat_msg.HEARTBEAT_NAV_AVG_POS_ERR = 0
        heartbeat_msg.HEARTBEAT_NAV_INITIALIZED = 0

        self.heartbeat_pub.publish(heartbeat_msg)

        self.rate.sleep()  # Sleep to achieve the desired publishing frequency
        self.update_heartbeat()  # Call the function recursively for continuous publishing

if __name__ == '__main__':
    auv_node = AUVNode()
    rospy.spin()

