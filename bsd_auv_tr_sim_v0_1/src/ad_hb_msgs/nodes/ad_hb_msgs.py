#!/usr/bin/env python3

import rospy
from avl_bsd_translator.msg import HeartbeatMsg
from std_msgs.msg import Float64

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
    u_vel = msg.HEARTBEAT_VN
    v_vel = msg.HEARTBEAT_VE
    w_vel = msg.HEARTBEAT_VD

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
    u_vel_msg.data = u_vel
    u_vel_hb_pub.publish(u_vel_msg)

    v_vel_msg = Float64()
    v_vel_msg.data = v_vel
    v_vel_hb_pub.publish(v_vel_msg)

    w_vel_msg = Float64()
    w_vel_msg.data = w_vel
    w_vel_hb_pub.publish(w_vel_msg)

    p_avel_msg = Float64()
    p_avel_msg.data = p_avel
    p_avel_hb_pub.publish(p_avel_msg)

    q_avel_msg = Float64()
    q_avel_msg.data = q_avel
    q_avel_hb_pub.publish(q_avel_msg)

    r_avel_msg = Float64()
    r_avel_msg.data = r_avel
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
