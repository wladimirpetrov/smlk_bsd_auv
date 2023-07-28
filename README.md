# smlk_bsd_auv
Communication with AUV of VT

python_
1. bsd_auv_tr_sim - checks the subs and pubs. adaptation doesn't have translation from N and E speeds to actual speeds. Attitide control doesn't have limitations in tems of angles. AUV_imp doesn't estimate the position of the AUV properly.
2. des--elev_rud_model_ws - python without simulink part. Basically for sending to the Virginia tech. Everything is working. Even in rqt &
3. bsd_auv_tr_sim_v0_3_ws - python with simulink part. Not for sending to the Virginia tech. Everything is working. Even in rqt &
4. des--elev_rud_model_TT_z_v_psi_py_ws - python without simulink part, but with TT+PID part. For sending to the Virginia tech. Everything is working. Even in rqt &

cpp_
1. bsd_auv_tr_sim_v0_2 - cpp all pubs and subs are working. however the only values that are calculated are psi_ref,z_ref,n_rpm other values are not shown in the rqt &. Need to understand why. THis iis not for sending to  Virginia tech it has a simulink part. 
2. des--elev_rud_model_cpp_ws - cpp without simulink part. For sending to virginia tech. cpp all pubs and subs are working. however the only values that are calculated are psi_ref,z_ref,n_rpm other values are not shown in the rqt &. Need to understand why. hb act adn command messages are not working
3. des--elev_rud_model_TT_z_v_psi_cpp_ws - c++ without simulink part, but with TT+PID part. For sending to the Virginia tech. 
