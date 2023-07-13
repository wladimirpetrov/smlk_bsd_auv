#!/usr/bin/env python3

import rospy
from std_msgs.msg import Float64
from avl_bsd_translator.msg import HeartbeatMsg

def heartbeat_callback(msg):
    # Assign values to psi_ref, z_ref, and n_rpm
    psi_ref = 2.1
    z_ref = 251
    n_rpm = 7.89

    # Publish psi_ref, z_ref, and n_rpm values to their respective topics
    psi_ref_msg = Float64()
    psi_ref_msg.data = psi_ref
    psi_ref_pub.publish(psi_ref_msg)

    z_ref_msg = Float64()
    z_ref_msg.data = z_ref
    z_ref_pub.publish(z_ref_msg)

    n_rpm_msg = Float64()
    n_rpm_msg.data = n_rpm
    n_rpm_pub.publish(n_rpm_msg)

if __name__ == '__main__':
    rospy.init_node('ad_hb_msgs')

    # Create publishers for psi_ref, z_ref, and n_rpm values
    psi_ref_pub = rospy.Publisher('psi_ref_msg', Float64, queue_size=10)
    z_ref_pub = rospy.Publisher('z_ref_msg', Float64, queue_size=10)
    n_rpm_pub = rospy.Publisher('n_rpm_msg', Float64, queue_size=10)

    # Subscribe to the heartbeat message
    rospy.Subscriber('/bsd/heartbeat', HeartbeatMsg, heartbeat_callback)

    rospy.spin()
