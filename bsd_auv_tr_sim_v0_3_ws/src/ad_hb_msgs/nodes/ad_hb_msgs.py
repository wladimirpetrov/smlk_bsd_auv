#!/usr/bin/env python3

import rospy
from avl_bsd_translator.msg import HeartbeatMsg
from std_msgs.msg import Float64
import math


class HeartbeatTranslator:
    def __init__(self):
        self.x_origin = None
        self.y_origin = None
        self.depth_origin = None

        rospy.init_node('ad_hb_msgs')

        self.x_hb_pub = rospy.Publisher('/x_hb_msg', Float64, queue_size=10)
        self.y_hb_pub = rospy.Publisher('/y_hb_msg', Float64, queue_size=10)
        self.depth_hb_pub = rospy.Publisher('/z_hb_msg', Float64, queue_size=10)

        self.roll_hb_pub = rospy.Publisher('/roll_hb_msg', Float64, queue_size=10)
        self.pitch_hb_pub = rospy.Publisher('/pitch_hb_msg', Float64, queue_size=10)
        self.yaw_hb_pub = rospy.Publisher('/yaw_hb_msg', Float64, queue_size=10)

        self.u_vel_hb_pub = rospy.Publisher('/u_vel_x_hb_msg', Float64, queue_size=10)
        self.v_vel_hb_pub = rospy.Publisher('/v_vel_y_hb_msg', Float64, queue_size=10)
        self.w_vel_hb_pub = rospy.Publisher('/w_vel_z_hb_msg', Float64, queue_size=10)

        self.p_avel_hb_pub = rospy.Publisher('/p_avel_x_hb_msg', Float64, queue_size=10)
        self.q_avel_hb_pub = rospy.Publisher('/q_avel_y_hb_msg', Float64, queue_size=10)
        self.r_avel_hb_pub = rospy.Publisher('/r_avel_z_hb_msg', Float64, queue_size=10)

        rospy.Subscriber('/bsd/heartbeat', HeartbeatMsg, self.heartbeat_callback)

    def heartbeat_callback(self, msg):
        if self.x_origin is None and self.y_origin is None and self.depth_origin is None:
            self.x_origin = msg.HEARTBEAT_GPS_LAT
            self.y_origin = msg.HEARTBEAT_GPS_LON
            self.depth_origin = msg.HEARTBEAT_DEPTH

        roll = msg.HEARTBEAT_ROLL
        pitch = msg.HEARTBEAT_PITCH
        yaw = msg.HEARTBEAT_YAW

        v_north = msg.HEARTBEAT_VN
        v_east = msg.HEARTBEAT_VE
        v_depth = msg.HEARTBEAT_VD

        p_avel = msg.HEARTBEAT_WX
        q_avel = msg.HEARTBEAT_WY
        r_avel = msg.HEARTBEAT_WZ

        gps_lat = msg.HEARTBEAT_GPS_LAT
        gps_lon = msg.HEARTBEAT_GPS_LON
        depth = msg.HEARTBEAT_DEPTH

        x = gps_lat - self.x_origin
        y = gps_lon - self.y_origin
        relative_depth = depth - self.depth_origin

        roll_rad = roll * math.pi / 180.0
        pitch_rad = pitch * math.pi / 180.0
        yaw_rad = yaw * math.pi / 180.0

        p_avel_rad_sec = p_avel * math.pi / 180.0
        q_avel_rad_sec = q_avel * math.pi / 180.0
        r_avel_rad_sec = r_avel * math.pi / 180.0

        u = v_north * math.cos(pitch) * math.cos(yaw) + v_east * (
                math.sin(roll) * math.sin(pitch) * math.cos(yaw) - math.cos(roll) * math.sin(yaw)) + v_depth * (
                    math.cos(roll) * math.sin(pitch) * math.cos(yaw) + math.sin(roll) * math.sin(yaw))
        v = v_north * math.cos(pitch) * math.sin(yaw) + v_east * (
                math.sin(roll) * math.sin(pitch) * math.sin(yaw) + math.cos(roll) * math.cos(yaw)) + v_depth * (
                    math.cos(roll) * math.sin(pitch) * math.sin(yaw) - math.sin(roll) * math.cos(yaw))
        w = -v_north * math.sin(pitch) + v_east * math.sin(roll) * math.cos(pitch) + v_depth * math.cos(
            roll) * math.cos(pitch)

        p = p_avel_rad_sec - q_avel * math.sin(roll) * math.tan(pitch) + r_avel * math.cos(roll) * math.tan(pitch)
        q = q_avel_rad_sec * math.cos(roll) - r_avel * math.sin(roll)
        r = q_avel_rad_sec * math.sin(roll) / math.cos(pitch) + r_avel * math.cos(roll) / math.cos(pitch)

        x_msg = Float64()
        x_msg.data = x
        self.x_hb_pub.publish(x_msg)

        y_msg = Float64()
        y_msg.data = y
        self.y_hb_pub.publish(y_msg)

        depth_msg = Float64()
        depth_msg.data = relative_depth
        self.depth_hb_pub.publish(depth_msg)

        roll_msg = Float64()
        roll_msg.data = roll_rad
        self.roll_hb_pub.publish(roll_msg)

        pitch_msg = Float64()
        pitch_msg.data = pitch_rad
        self.pitch_hb_pub.publish(pitch_msg)

        yaw_msg = Float64()
        yaw_msg.data = yaw_rad
        self.yaw_hb_pub.publish(yaw_msg)

        u_vel_msg = Float64()
        u_vel_msg.data = u
        self.u_vel_hb_pub.publish(u_vel_msg)

        v_vel_msg = Float64()
        v_vel_msg.data = v
        self.v_vel_hb_pub.publish(v_vel_msg)

        w_vel_msg = Float64()
        w_vel_msg.data = w
        self.w_vel_hb_pub.publish(w_vel_msg)

        p_avel_msg = Float64()
        p_avel_msg.data = p
        self.p_avel_hb_pub.publish(p_avel_msg)

        q_avel_msg = Float64()
        q_avel_msg.data = q
        self.q_avel_hb_pub.publish(q_avel_msg)

        r_avel_msg = Float64()
        r_avel_msg.data = r
        self.r_avel_hb_pub.publish(r_avel_msg)

    def run(self):
        rospy.spin()


if __name__ == '__main__':
    hb_translator = HeartbeatTranslator()
    hb_translator.run()
