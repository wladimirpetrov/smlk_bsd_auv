#!/usr/bin/env python3

import rospy
from avl_bsd_translator.msg import HeartbeatMsg
from std_msgs.msg import Float64


def heartbeat_callback(msg):

    # Extract pitch and yaw values from the HeartbeatMsg

    x = msg.HEARTBEAT_GPS_LAT #????????????????? define origin and then based on the origin we calculate the position
    y = msg.HEARTBEAT_GPS_LON # ???????????????? define origin and then based on the origin we calculate the position
    depth = msg.HEARTBEAT_DEPTH

    roll = msg.HEARTBEAT_ROLL
    pitch = msg.HEARTBEAT_PITCH
    yaw = msg.HEARTBEAT_YAW

    u_vel = msg.HEARTBEAT_VN # initially VX we need to convert VN to VX
    v_vel = msg.HEARTBEAT_VE # initially VY we need to convert VE to VY
    w_vel = msg.HEARTBEAT_VD # initially VZ we need to convert VD to VZ

    p_avel = msg.HEARTBEAT_WX
    q_avel = msg.HEARTBEAT_WY
    r_avel = msg.HEARTBEAT_WZ   

    # Publish pitch and yaw values to separate topics

    x_msg = Float64()
    x_msg.data = x
    x_hb_pub.publish(x_msg)

    y_msg = Float64()
    y_msg.data = y
    y_hb_pub.publish(y_msg)

    depth_msg = Float64()
    depth_msg.data = depth
    depth_hb_pub.publish(depth_msg)

    # roll, pitch and yaw

    roll_msg = Float64()
    roll_msg.data = roll
    roll_hb_pub.publish(roll_msg)

    pitch_msg = Float64()
    pitch_msg.data = pitch
    pitch_hb_pub.publish(pitch_msg)

    yaw_msg = Float64()
    yaw_msg.data = yaw
    yaw_hb_pub.publish(yaw_msg)

    # u, v, w speed
 
    u_vel_msg = Float64()
    u_vel_msg.data = u_vel
    u_vel_hb_pub.publish(u_vel_msg)

    v_vel_msg = Float64()
    v_vel_msg.data = v_vel
    v_vel_hb_pub.publish(v_vel_msg)

    w_vel_msg = Float64()
    w_vel_msg.data = w_vel
    w_vel_hb_pub.publish(w_vel_msg)   

    # p, q, r ang speed
 
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

    # Create publishers for pitch and yaw heartbeat values

    x_hb_pub = rospy.Publisher('/x_hb_msg', Float64, queue_size=10)
    y_hb_pub = rospy.Publisher('/y_hb_msg', Float64, queue_size=10)
    depth_hb_pub = rospy.Publisher('/z_hb_msg', Float64, queue_size=10)

    roll_hb_pub = rospy.Publisher('/roll_hb_msg', Float64, queue_size=10)
    pitch_hb_pub = rospy.Publisher('/pitch_hb_msg', Float64, queue_size=10)
    yaw_hb_pub = rospy.Publisher('/yaw_hb_msg', Float64, queue_size=10)

    u_vel_hb_pub = rospy.Publisher('/u_vel_x_hb_msg', Float64, queue_size=10)
    v_vel_hb_pub = rospy.Publisher('/v_vel_y_hb_msg', Float64, queue_size=10)
    w_vel_hb_pub = rospy.Publisher('/w_vel_z_hb_msg', Float64, queue_size=10)    
    
    p_avel_hb_pub = rospy.Publisher('/p_avel_x_hb_msg', Float64, queue_size=10)
    q_avel_hb_pub = rospy.Publisher('/q_avel_y_hb_msg', Float64, queue_size=10)
    r_avel_hb_pub = rospy.Publisher('/r_avel_z_hb_msg', Float64, queue_size=10)
 
    # Subscribe to the HeartbeatMsg topic

    rospy.Subscriber('/bsd/heartbeat', HeartbeatMsg, heartbeat_callback)

    rospy.spin()