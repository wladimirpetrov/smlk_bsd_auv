#!/usr/bin/env python3

import rospy
from std_msgs.msg import Float64
from avl_bsd_translator.msg import HeartbeatMsg, CommandMsg, ActionMsg
import numpy as np
import math

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
        self.roll = 0.0
        self.pitch = 0.0
        self.yaw = 0.0
        self.v_north = 0.0
        self.v_east = 0.0
        self.v_depth = 0.0

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
        self.v_north = msg.HEARTBEAT_VN
        self.v_east = msg.HEARTBEAT_VE
        self.v_depth = msg.HEARTBEAT_VD
        self.z = msg.HEARTBEAT_DEPTH
        self.psi = msg.HEARTBEAT_YAW
        self.roll = msg.HEARTBEAT_ROLL
        self.pitch = msg.HEARTBEAT_PITCH
        self.yaw = msg.HEARTBEAT_YAW
        self.actual_speed = msg.HEARTBEAT_RPM

        u = self.v_north * math.cos(self.pitch) * math.cos(self.yaw) + self.v_east * (
                math.sin(self.roll) * math.sin(self.pitch) * math.cos(self.yaw) - math.cos(self.roll) * math.sin(self.yaw)) + self.v_depth * (
                    math.cos(self.roll) * math.sin(self.pitch) * math.cos(self.yaw) + math.sin(self.roll) * math.sin(self.yaw))
        v = self.v_north * math.cos(self.pitch) * math.sin(self.yaw) + self.v_east * (
                math.sin(self.roll) * math.sin(self.pitch) * math.sin(self.yaw) + math.cos(self.roll) * math.cos(self.yaw)) + self.v_depth * (
                    math.cos(self.roll) * math.sin(self.pitch) * math.sin(self.yaw) - math.sin(self.roll) * math.cos(self.yaw))
        w = -self.v_north * math.sin(self.pitch) + self.v_east * math.sin(self.roll) * math.cos(self.pitch) + self.v_depth * math.cos(
            self.roll) * math.cos(self.pitch)

        kx = self.kx  # Use the kx value extracted from the parameter server
        ky = self.ky  # Use the ky value extracted from the parameter server

        x_error = self.x_des - self.x
        y_error = self.y_des - self.y
        z_error = self.z_ref - self.z

        rwi = np.array([[np.cos(self.psi), -np.sin(self.psi)],
                        [np.sin(self.psi), np.cos(self.psi)]])
        xy_error_rot = np.dot(rwi, np.array([[x_error], [y_error]]))
        x_error_rot = xy_error_rot[0][0]
        y_error_rot = xy_error_rot[1][0]

        v_des = kx * abs(x_error_rot)
        psi_des = ky * y_error_rot

        elevator = self.PID(z_error, self.kp_elevator, self.ki_elevator, self.kd_elevator, self.zerr_prev, self.zerrint_prev)
        rudder = self.PID(psi_des - self.psi, self.kp_rudder, self.ki_rudder, self.kd_rudder, self.psierr_prev, self.psierrint_prev)
        prop = abs(self.PID(v_des, self.kp_prop, self.ki_prop, self.kd_prop, self.verr_prev, self.verrint_prev))

        elevator = self.limit_elevator(elevator)
        rudder = self.limit_rudder(rudder)
        prop = self.limit_prop(prop)  # Limit the prop value

        self.send_action_msg(2.0, elevator, rudder, prop)
        self.send_command_msg()

        self.zerr_prev = z_error
        self.zerrint_prev = self.zerrint_prev + z_error * self.Ts

        self.psierr_prev = psi_des - self.psi
        self.psierrint_prev = self.psierrint_prev + (psi_des - self.psi) * self.Ts

        self.verr_prev = v_des
        self.verrint_prev = self.verrint_prev + (v_des) * self.Ts

        self.update_position(u, v, w)

    def PID(self, error, kp, ki, kd, prev_err, integral):
        integral = integral + error * self.Ts
        # Limit the integral term to prevent windup
        integral = max(min(integral, 5), -5)
        derivative = (error - prev_err) / self.Ts
        output = kp * error + ki * integral + kd * derivative
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

    def limit_prop(self, value):
        return max(min(value, 1500), 400)

    def send_command_msg(self):
        command_msg = CommandMsg()
        command_msg.COMMAND_NAME = "MISSION"
        command_msg.NAMES = ["COMMAND"]
        command_msg.TYPES = [0x01]
        command_msg.VALUES = [str(0)]
        self.command_pub.publish(command_msg)  # Publish the command message

    def send_action_msg(self, duration, elevator, rudder, prop):
        action_msg = ActionMsg()
        action_msg.ACTION_TYPE = "PRIMITIVE"
        action_msg.MODE = 0
        action_msg.NAMES = ["DURATION", "ELEVATOR", "RUDDER", "RPM"]
        action_msg.TYPES = [0x02, 0x02, 0x02, 0x02]
        action_msg.VALUES = [str(duration), str(elevator), str(rudder), str(prop)]
        self.action_pub.publish(action_msg)

    def update_position(self, u, v, w):
        # Convert body-fixed velocity components to Earth-fixed velocity components
        u_e = u * np.cos(self.psi) - v * np.sin(self.psi)
        v_e = u * np.sin(self.psi) + v * np.cos(self.psi)

        # Integrate Earth-fixed velocity components to get position
        self.x += u_e * self.Ts
        self.y += v_e * self.Ts

    def run(self):
        # Reset the integral terms before starting the control loop
        self.zerrint_prev = 0.0
        self.psierrint_prev = 0.0
        self.verrint_prev = 0.0

        rate = rospy.Rate(1.0 / self.Ts)  # Run control loop at specified rate

        while not rospy.is_shutdown():
            # Rest of the control loop code remains unchanged

            rate.sleep()

if __name__ == "__main__":
    try:
        attitude_control = AttitudeControl()
        attitude_control.run()
    except rospy.ROSInterruptException:
        pass