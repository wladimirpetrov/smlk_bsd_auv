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
        
        kx = 1.0  # Gain for X error
        ky = 1.0  # Gain for Y error

        x_error = self.x - self.x_des
        y_error = self.y - self.y_des
        z_error = self.z - self.z_ref

        rwi = np.array([[np.cos(self.psi), -np.sin(self.psi)],
                        [np.sin(self.psi), np.cos(self.psi)]])
        xy_error_rot = np.dot(rwi, np.array([[x_error], [y_error]]))
        x_error_rot = xy_error_rot[0][0]
        y_error_rot = xy_error_rot[1][0]

        v_des = kx * x_error_rot
        psi_des = ky * y_error_rot

        elevator = self.PID(z_error)
        rudder = self.PID(psi_des - self.psi) #self.PID(psi_des - self.psi)
        prop = self.PID(v_des)

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

        self.update_position()

    def PID(self, error):
        kp = 3.0
        ki = 0.0
        kd = 3.0

        error_int = error * self.Ts + self.zerrint_prev
        error_dot = (error - self.zerr_prev) / self.Ts

        output = kp * error + ki * error_int + kd * error_dot

        self.zerrint_prev = error_int
        self.zerr_prev = error

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
