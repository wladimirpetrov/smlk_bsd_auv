clear all
close all

load("PF_scripps_ad.mat")
timesize_pf_ad = size(out.Bx1.signals.values);
timestep_pf_ad = timesize_pf_ad(1)-1;
t_pf_ad = 0:Tf/timestep_pf_ad:Tf;
pdee_pf_ad = BernsteinPoly(Cp,t_pf_ad);
x_pf_ad = -out.Bx1.signals.values - pdee_pf_ad(1,:)';
y_pf_ad = -out.Bx2.signals.values - pdee_pf_ad(2,:)';
z_pf_ad = out.Bx3.signals.values - pdee_pf_ad(3,:)';

load("TT_scripps_ad.mat")
timesize_tt_ad = size(out.Bx1.signals.values);
timestep_tt_ad = timesize_tt_ad(1)-1;
t_tt_ad = 0:Tf/timestep_tt_ad:Tf;
pdee_tt_ad = BernsteinPoly(Cp,t_tt_ad);
x_tt_ad = -out.Bx1.signals.values - pdee_tt_ad(1,:)';
y_tt_ad = -out.Bx2.signals.values - pdee_tt_ad(2,:)';
z_tt_ad = out.Bx3.signals.values - pdee_tt_ad(3,:)';

% Position
figure()
load("PF_scripps_ad.mat")
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values)
hold on
load("TT_scripps_ad.mat")
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values)


% Position error
figure()
subplot(2,1,1)
load("PF_scripps_ad.mat")
size_v = size(out.pos_err.signals.values);
norm_pos_err = reshape(out.pos_err.signals.values,[size_v(3) 1]);
plot(out.Bx1.time,norm_pos_err)
grid on
ylim([0,70])
xlim([0,500])
legend("PF")
xlabel("t (s)")
ylabel("Normalized position error (m)")
subplot(2,1,2)
load("TT_scripps_ad.mat")
size_v = size(out.pos_err.signals.values);
norm_pos_err = reshape(out.pos_err.signals.values,[size_v(3) 1]);
plot(out.Bx1.time,norm_pos_err)
ylim([0,70])
grid on
legend("TT")
xlabel("t (s)")
ylabel("Normalized position error (m)")

% vert. cmd.
figure()
subplot(2,1,1)
load("PF_scripps_ad.mat")
deg = -out.d5.signals.values;
plot(out.d5.time,deg)
ylim([-16,7])
xlim([0,500])
grid on
legend("PF")
xlabel("t (s)")
ylabel("\delta_V command (deg)")
subplot(2,1,2)
load("TT_scripps_ad.mat")
deg = -out.d5.signals.values;
plot(out.d5.time,deg)
ylim([-16,7])
grid on
legend("TT")
xlabel("t (s)")
ylabel("\delta_V command (deg)")

% (horiz. cmd.)
figure()
subplot(2,1,1)
load("PF_scripps_ad.mat")
deg = (out.d2.signals.values+out.d3.signals.values)/2;
plot(out.d2.time,deg)
legend("PF")
xlabel("t (s)")
ylabel("\delta_H command (deg)")
ylim([-21,13])
xlim([0,500])
grid on
subplot(2,1,2)
load("TT_scripps_ad.mat")
deg = (out.d2.signals.values+out.d3.signals.values)/2;
plot(out.d2.time,deg)
grid on
ylim([-21,13])
legend("TT")
xlabel("t (s)")
ylabel("\delta_H command (deg)")

%near surface comparison of AD vs no AD
figure()
load("pf_nearsurface_ad_ref.mat")
plot(out.Bx3.time,out.Bx3.signals.values)
hold on
load("pf_nearsurface.mat")
plot(out.Bx3.time,out.Bx3.signals.values)
hold on
load("pf_nearsurface_ad_ref.mat")
plot(out.Bx3.time,out.z_ad.signals.values,'-.')
hold on
zz_ref = out.z_ref.signals.values;
zzz_ref = zz_ref(:);
plot(out.Bx3.time,zzz_ref,'-.')
grid on
legend("w/ adaptation","w/o adaptation","augmented reference","reference","Location","southwest")
xlabel("t (s)")
ylabel("z (m)")

%pf gamma and psiref
figure()
load("PF_scripps_ad_ref.mat")
plot(out.gamma_dot.time,out.gamma_dot.signals.values)
xlabel("t (s)")
ylabel("gamma rate (\gamma/s)")
grid on

figure()
subplot(2,1,1)
load("PF_scripps_ad_ref.mat")
deg = 180/pi*out.psi_ref.signals.values;
plot(out.psi_ref.time,deg)
hold on
deg = 180/pi*out.Bx6.signals.values;
plot(out.Bx6.time,deg)
grid on
xlabel("t (s)")
ylabel("yaw (deg)")
legend("yaw reference","yaw")
title("PF")
subplot(2,1,2)
load("TT_scripps_ad_ref.mat")
deg = 180/pi*out.psi_ref.signals.values;
plot(out.psi_ref.time,deg)
hold on
deg = 180/pi*out.Bx6.signals.values;
plot(out.Bx6.time,deg)
grid on
xlabel("t (s)")
ylabel("yaw (deg)")
legend("yaw reference","yaw")
title("TT")

figure()
load("TT_scripps_ad_ref.mat")
plot(out.v_cmd.time,out.v_cmd.signals.values)
%hold on
%plot(out.v_norm.time,-out.Bv1.signals.values)
grid on
xlabel("t (s)")
ylabel("v (m/s)")
legend("commanded velocity")

figure()
load("PF_scripps_ad.mat")
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values,"Color","k","LineWidth",1)
hold on
load("TT_scripps_ad.mat")
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values,"Color","k","LineStyle","--","LineWidth",1)
hold on
plot3(pdee_pf_ad(1,:),pdee_pf_ad(2,:),pdee_pf_ad(3,:),"Color","k","LineStyle","-.","LineWidth",1)
hold on
fv = stlread('90k.stl');
%trisurf(fv.ConnectivityList,-.5*1.627906977*1.15*0.83625*15.7975*fv.Points(:,1)+450,-.5*1.396097561*17.895*fv.Points(:,2)+430,1.518181818*fv.Points(:,3)-280,"EdgeColor","none")
x = (-1.3*.975*1.1*8.729268293*(fv.Points(:,1)-41.75)-70)*.975;
y = (-1.3*.975*1.1*8.729268293*(fv.Points(:,2)-82.9)-558);
z = (1.3*.975*1.1*8.729268293*(fv.Points(:,3)-8.22)-520)*.975;
trisurf(fv.ConnectivityList,x,y,z,"EdgeColor",[.5 .5 .5],"FaceColor","w")
grid on
axis equal
xlabel("x (m)")
ylabel("y (m)")
zlabel("z (m)")
legend("PF","TT","Bernstein Polynomial")

figure()
load("PF_scripps_ad.mat")
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values,"Color","r")
hold on
load("TT_scripps_ad.mat")
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values,"Color","r","LineStyle","--")
hold on
plot3(pdee_pf_ad(1,:),pdee_pf_ad(2,:),pdee_pf_ad(3,:),"Color","r","LineStyle","-.")
hold on
fv = stlread('90k.stl');
%trisurf(fv.ConnectivityList,-.5*1.627906977*1.15*0.83625*15.7975*fv.Points(:,1)+450,-.5*1.396097561*17.895*fv.Points(:,2)+430,1.518181818*fv.Points(:,3)-280,"EdgeColor","none")
x = (-1.3*.975*1.1*8.729268293*(fv.Points(:,1)-41.75)-70)*.975;
y = (-1.3*.975*1.1*8.729268293*(fv.Points(:,2)-82.9)-558);
z = (1.3*.975*1.1*8.729268293*(fv.Points(:,3)-8.22)-520)*.975;
trimesh(fv.ConnectivityList,x,y,z,"FaceColor","w","EdgeColor","k")
hold on
view(3)
grid on
axis equal
xlabel("x (m)")
ylabel("y (m)")
zlabel("z (m)")
legend("PF","TT","Bernstein Polynomial")
