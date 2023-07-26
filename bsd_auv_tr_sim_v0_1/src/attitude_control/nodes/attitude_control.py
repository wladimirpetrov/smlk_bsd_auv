#!/usr/bin/env python3

import rospy
from std_msgs.msg import Float64
from avl_bsd_translator.msg import HeartbeatMsg, CommandMsg, ActionMsg

class AttitudeControl:

    def __init__(self):

        rospy.init_node('attitude_control')

        self.command_pub = rospy.Publisher('bsd/command', CommandMsg, queue_size=10)
        self.action_pub = rospy.Publisher('bsd/action', ActionMsg, queue_size=10)
        self.z_ref_sub = rospy.Subscriber('z_ref_msg', Float64, self.z_ref_callback)
        self.psi_ref_sub = rospy.Subscriber('psi_ref_msg', Float64, self.psi_ref_callback)
        self.rpm_sub = rospy.Subscriber('n_rpm_msg', Float64, self.rpm_callback)
        self.heartbeat_sub = rospy.Subscriber('bsd/heartbeat', HeartbeatMsg, self.heartbeat_callback)

        self.z_ref = 0.0
        self.psi_ref = 0.0
        self.rpm = 0.0
        self.Ts = 0.05

        # Variables for saving previous error and integral terms

        self.zerr_prev = 0.0
        self.zerrint_prev = 0.0
        self.thetaerr_prev = 0.0
        self.thetaerrint_prev = 0.0
        self.psierr_prev = 0.0
        self.psierrint_prev = 0.0

    def send_command_msg(self):

        command_msg = CommandMsg()
        command_msg.COMMAND_NAME = "MISSION"
        command_msg.NAMES = ["COMMAND"]
        command_msg.TYPES = [0x01]
        command_msg.VALUES = [str(0)]
        self.command_pub.publish(command_msg)

    def send_action_msg(self, duration, elevator, rudder, rpm):

        action_msg = ActionMsg()
        action_msg.ACTION_TYPE = "PRIMITIVE"
        action_msg.MODE = 0
        action_msg.NAMES = ["DURATION", "ELEVATOR", "RUDDER", "RPM"]
        action_msg.TYPES = [0x02, 0x02, 0x02, 0x02]
        action_msg.VALUES = [str(duration), str(elevator), str(rudder), str(rpm)]
        self.action_pub.publish(action_msg)
    
    # Getting calculated z_ref, psi_ref, rpm from PF and AD ctrl

    def z_ref_callback(self, msg):
        self.z_ref = msg.data

    def psi_ref_callback(self, msg):
        self.psi_ref = msg.data
 
    def rpm_callback(self, msg):
        self.rpm = msg.data

    def heartbeat_callback(self, msg):

        HEARTBEAT_STATUS = msg.HEARTBEAT_STATUS
        print("HEARTBEAT_STATUS", HEARTBEAT_STATUS)
        print("BSD pitch:", msg.HEARTBEAT_PITCH)
        print("BSD yaw:", msg.HEARTBEAT_YAW)
        print("BSD depth:", msg.HEARTBEAT_DEPTH)
 
        # Perform Action

        KP_APz = 3.0
        KI_APz = 0.0 * 0.1044
        KD_APz = 3.0
        KP_APtheta = 3.0
        KI_APtheta = 0.0 * 0.1466
        KD_APtheta = 3.0
        KP_APpsi = 3.0
        KI_APpsi = 0.0
        KD_APpsi = 12.199

        psi = msg.HEARTBEAT_YAW

        theta = msg.HEARTBEAT_PITCH

        z = msg.HEARTBEAT_DEPTH

        # calculating elevator

        zerr = self.z_ref - z
        zerrint = zerr * self.Ts + self.zerrint_prev
        zerrdot = (zerr - self.zerr_prev) / self.Ts
        dvz = KP_APz * zerr + KI_APz * zerrint + KD_APz * zerrdot

        thetaerr = 0.0 - theta
        thetaerrint = thetaerr * self.Ts + self.thetaerrint_prev
        thetaerrdot = (thetaerr - self.thetaerr_prev) / self.Ts
        dvtheta = KP_APtheta * thetaerr + KI_APtheta * thetaerrint + KD_APtheta * thetaerrdot

        elevator = dvz + dvtheta

        # calculating rudder

        psierr = self.psi_ref - psi
        psierrint = psierr * self.Ts + self.psierrint_prev
        psierrdot = (psierr - self.psierr_prev) / self.Ts
        rudder = KP_APpsi * psierr + KI_APpsi * psierrint + KD_APpsi * psierrdot

        self.send_action_msg(2.0, elevator, rudder, self.rpm)
        self.send_command_msg()

        self.zerr_prev = zerr
        self.zerrint_prev = zerrint
        self.thetaerr_prev = thetaerr
        self.thetaerrint_prev = thetaerrint
        self.psierr_prev = psierr
        self.psierrint_prev = psierrint

    def run(self):

        rospy.spin()

if __name__ == '__main__':

    attitude_control = AttitudeControl()

    attitude_control.run()