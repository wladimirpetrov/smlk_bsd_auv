#!/usr/bin/env python3

import rospy
from avl_bsd_translator.msg import HeartbeatMsg
from std_msgs.msg import Float64
import math

# Initialize origin coordinates and depth
x_origin = None
y_origin = None
depth_origin = None

def heartbeat_callback(msg):
    global x_origin, y_origin, depth_origin

    # Check if origin has been assigned
    if x_origin is None and y_origin is None and depth_origin is None:
        # Assign origin based on the first heartbeat message
        x_origin = msg.HEARTBEAT_GPS_LAT
        y_origin = msg.HEARTBEAT_GPS_LON
        depth_origin = msg.HEARTBEAT_DEPTH

    # Extract pitch and yaw values from the HeartbeatMsg
    
    roll = msg.HEARTBEAT_ROLL
    pitch = msg.HEARTBEAT_PITCH
    yaw = msg.HEARTBEAT_YAW

    # Extract u, v, and w velocities from the HeartbeatMsg
    
    v_north = msg.HEARTBEAT_VN
    v_east = msg.HEARTBEAT_VE
    v_depth = msg.HEARTBEAT_VD

    # Extract p, q, and r angular velocities from the HeartbeatMsg

    p_avel = msg.HEARTBEAT_WX
    q_avel = msg.HEARTBEAT_WY
    r_avel = msg.HEARTBEAT_WZ

    # Extract GPS latitude, longitude, and depth values from the HeartbeatMsg

    gps_lat = msg.HEARTBEAT_GPS_LAT
    gps_lon = msg.HEARTBEAT_GPS_LON
    depth = msg.HEARTBEAT_DEPTH

    # Calculate relative x, y, and depth coordinates

    x = gps_lat - x_origin
    y = gps_lon - y_origin
    relative_depth = depth - depth_origin

    # Calculate u, v, and w velocities in AUV coordinate system

    u = v_north * math.cos(pitch) * math.cos(yaw) + v_east * (math.sin(roll) * math.sin(pitch) * math.cos(yaw) - math.cos(roll) * math.sin(yaw)) + v_depth * (math.cos(roll) * math.sin(pitch) * math.cos(yaw) + math.sin(roll) * math.sin(yaw))
    v = v_north * math.cos(pitch) * math.sin(yaw) + v_east * (math.sin(roll) * math.sin(pitch) * math.sin(yaw) + math.cos(roll) * math.cos(yaw)) + v_depth * (math.cos(roll) * math.sin(pitch) * math.sin(yaw) - math.sin(roll) * math.cos(yaw))
    w = -v_north * math.sin(pitch) + v_east * math.sin(roll) * math.cos(pitch) + v_depth * math.cos(roll) * math.cos(pitch)

    # Calculate p, q, and r angular velocities in AUV coordinate system

    p = p_avel - q_avel * math.sin(roll) * math.tan(pitch) + r_avel * math.cos(roll) * math.tan(pitch)
    q = q_avel * math.cos(roll) - r_avel * math.sin(roll)
    r = q_avel * math.sin(roll) / math.cos(pitch) + r_avel * math.cos(roll) / math.cos(pitch)

    # Publish x, y, and depth values to separate topics

    x_msg = Float64()
    x_msg.data = x
    x_hb_pub.publish(x_msg)

    y_msg = Float64()
    y_msg.data = y
    y_hb_pub.publish(y_msg)

    depth_msg = Float64()
    depth_msg.data = relative_depth
    depth_hb_pub.publish(depth_msg)

    # Publish pitch, yaw, u, v, w, p, q, and r values to their respective topics

    roll_msg = Float64()
    roll_msg.data = roll
    roll_hb_pub.publish(roll_msg)

    pitch_msg = Float64()
    pitch_msg.data = pitch
    pitch_hb_pub.publish(pitch_msg)

    yaw_msg = Float64()
    yaw_msg.data = yaw
    yaw_hb_pub.publish(yaw_msg)

    u_vel_msg = Float64()
    u_vel_msg.data = u
    u_vel_hb_pub.publish(u_vel_msg)

    v_vel_msg = Float64()
    v_vel_msg.data = v
    v_vel_hb_pub.publish(v_vel_msg)

    w_vel_msg = Float64()
    w_vel_msg.data = w
    w_vel_hb_pub.publish(w_vel_msg)

    p_avel_msg = Float64()
    p_avel_msg.data = p
    p_avel_hb_pub.publish(p_avel_msg)

    q_avel_msg = Float64()
    q_avel_msg.data = q
    q_avel_hb_pub.publish(q_avel_msg)

    r_avel_msg = Float64()
    r_avel_msg.data = r
    r_avel_hb_pub.publish(r_avel_msg)

if __name__ == '__main__':
    rospy.init_node('ad_hb_msgs')

    # Create publishers for x, y, and depth heartbeat values

    x_hb_pub = rospy.Publisher('/x_hb_msg', Float64, queue_size=10)
    y_hb_pub = rospy.Publisher('/y_hb_msg', Float64, queue_size=10)
    depth_hb_pub = rospy.Publisher('/depth_hb_msg', Float64, queue_size=10)

    # Create publishers for roll, pitch, yaw heartbeat values
    
    roll_hb_pub = rospy.Publisher('/roll_hb_msg', Float64, queue_size=10)
    pitch_hb_pub = rospy.Publisher('/pitch_hb_msg', Float64, queue_size=10)
    yaw_hb_pub = rospy.Publisher('/yaw_hb_msg', Float64, queue_size=10)

    # Create publishers for u, v, w velocity heartbeat values

    u_vel_hb_pub = rospy.Publisher('/u_vel_hb_msg', Float64, queue_size=10)
    v_vel_hb_pub = rospy.Publisher('/v_vel_hb_msg', Float64, queue_size=10)
    w_vel_hb_pub = rospy.Publisher('/w_vel_hb_msg', Float64, queue_size=10)

    # Create publishers for p, q, r angular velocity heartbeat values

    p_avel_hb_pub = rospy.Publisher('/p_avel_hb_msg', Float64, queue_size=10)
    q_avel_hb_pub = rospy.Publisher('/q_avel_hb_msg', Float64, queue_size=10)
    r_avel_hb_pub = rospy.Publisher('/r_avel_hb_msg', Float64, queue_size=10)

    # Subscribe to the HeartbeatMsg topic

    rospy.Subscriber('/bsd/heartbeat', HeartbeatMsg, heartbeat_callback)

    rospy.spin()
