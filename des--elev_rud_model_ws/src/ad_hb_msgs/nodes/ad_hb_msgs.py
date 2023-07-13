#!/usr/bin/env python3

import rospy
import math
from std_msgs.msg import Float64
from avl_bsd_translator.msg import HeartbeatMsg

def heartbeat_callback(msg):
    # Assign values to n_rpm
    n_rpm = 1500

    # Calculate the current time in seconds
    current_time = rospy.get_time()

    # Calculate the desired depth using a sine function
    period = 20
    amplitude = 2.0
    frequency = 1.0 / period
    z_ref = 250 + amplitude * math.sin(2 * math.pi * frequency * current_time)

    # Calculate the desired heading angle (psi_ref) based on the desired trajectory
    psi_ref = math.atan2(-amplitude * frequency * 2 * math.pi * math.cos(2 * math.pi * frequency * current_time), 1)

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

