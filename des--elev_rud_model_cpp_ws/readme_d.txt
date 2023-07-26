This package comprises 3 nodes. (find the scheme.png in the folder)


ad_hb_msgs.cpp node - provides psi_ref, z_ref, n_rpm for the PID controller

auv_imp.cpp node - "impersonates" behaviour of the AUV in a simple manner. It sends hearbeat messages to AUV based on the elevator, rudder and rpm data provided by PID.

attitude_control.cpp node - PID controller that gains psi_ref, z_ref, n_rpm from ad_hb_msgs.cpp node and receives data(heartbeat messages) from the auv_imp.cpp


In order to test the PID we need to use ad_hb_msgs.cpp and attitude_control.cpp nodes. The SIL simulator has to substitute auv_imp.cpp node
