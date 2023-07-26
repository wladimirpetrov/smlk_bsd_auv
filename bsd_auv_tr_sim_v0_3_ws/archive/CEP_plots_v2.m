close all

load("PF_scripps_ad.mat")
timesize_pf_ad = size(out.Bx1.signals.values);
timestep_pf_ad = timesize_pf_ad(1)-1;
t_pf_ad = 0:Tf/timestep_pf_ad:Tf;
pdee_pf_ad = BernsteinPoly(Cp,t_pf_ad);
x_pf_ad = -out.Bx1.signals.values - pdee_pf_ad(1,:)';
y_pf_ad = -out.Bx2.signals.values - pdee_pf_ad(2,:)';
%h_pf_ad = sqrt(transpose(x_pf_ad)*x_pf_ad+transpose(y_pf_ad)*y_pf_ad);
z_pf_ad = out.Bx3.signals.values - pdee_pf_ad(3,:)';
%plot(out.Bx1.time,h_pf_ad)

load("PF_scripps.mat")
timesize_pf = size(out.Bx1.signals.values);
timestep_pf = timesize_pf(1)-1;
t_pf = 0:Tf/timestep_pf:Tf;
pdee_pf = BernsteinPoly(Cp,t_pf);
x_pf = -out.Bx1.signals.values - pdee_pf(1,:)';
y_pf = -out.Bx2.signals.values - pdee_pf(2,:)';
%h_pf = sqrt(x_pf^2+y_pf^2);
z_pf = out.Bx3.signals.values - pdee_pf(3,:)';

load("TT_scripps_ad.mat")
timesize_tt_ad = size(out.Bx1.signals.values);
timestep_tt_ad = timesize_tt_ad(1)-1;
t_tt_ad = 0:Tf/timestep_tt_ad:Tf;
pdee_tt_ad = BernsteinPoly(Cp,t_tt_ad);
x_tt_ad = -out.Bx1.signals.values - pdee_tt_ad(1,:)';
y_tt_ad = -out.Bx2.signals.values - pdee_tt_ad(2,:)';
%h_tt_ad = sqrt(x_tt_ad^2+y_tt_ad^2);
z_tt_ad = out.Bx3.signals.values - pdee_tt_ad(3,:)';

load("TT_scripps.mat")
timesize_tt = size(out.Bx1.signals.values);
timestep_tt = timesize_tt(1)-1;
t_tt = 0:Tf/timestep_tt:Tf;
pdee_tt = BernsteinPoly(Cp,t_tt);
x_tt = -out.Bx1.signals.values - pdee_tt(1,:)';
y_tt = -out.Bx2.signals.values - pdee_tt(2,:)';
%h_tt = sqrt(x_tt^2+y_tt^2);
z_tt = out.Bx3.signals.values - pdee_tt(3,:)';

% trajectory

figure()
plot3(pdee_pf(1,:),pdee_pf(2,:),pdee_pf(3,:))
hold on
load("PF_scripps_ad.mat")
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values)
hold on
load("PF_scripps.mat")
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values)
hold on
load("TT_scripps_ad.mat")
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values)
hold on
load("TT_scripps.mat")
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values)
hold on
legend("Bernstein Polynomial","PF, with adaptation","PF, no adaptation","TT, with adaptation","TT, no adaptation")
grid on
xlabel("x (m)")
ylabel("y (m)")
zlabel("z (m)")
title("Trajectory")

% horizontal error
figure()
load("PF_scripps_ad.mat")
plot(out.Bx1.time,y_pf_ad)
hold on
load("PF_scripps.mat")
plot(out.Bx1.time,y_pf)
hold on
load("TT_scripps_ad.mat")
plot(out.Bx1.time,y_tt_ad)
hold on
load("TT_scripps.mat")
plot(out.Bx1.time,y_tt)
grid on
legend("PF, with adaptation","PF, no adaptation","TT, with adaptation", "TT, no adaptation","Location","northwest")
xlabel("t (s)")
ylabel("Horizontal Error (m)")

% vertical error
figure()
load("PF_scripps_ad.mat")
plot(out.Bx3.time,z_pf_ad)
hold on
load("PF_scripps.mat")
plot(out.Bx3.time,z_pf)
load("TT_scripps_ad.mat")
plot(out.Bx3.time,z_tt_ad)
hold on
load("TT_scripps.mat")
plot(out.Bx3.time,z_tt)
grid on
legend("PF, with adaptation","PF, no adaptation","TT, with adaptation", "TT, no adaptation","Location","southeast")
xlabel("t (s)")
ylabel("Vertical Error (m)")

% (horiz. cmd.)
figure()
load("PF_scripps_ad.mat")
deg = (out.d2.signals.values+out.d3.signals.values)/2;
plot(out.d2.time,deg)
hold on
load("PF_scripps.mat")
deg = (out.d2.signals.values+out.d3.signals.values)/2;
plot(out.d2.time,deg)
load("TT_scripps_ad.mat")
deg = (out.d2.signals.values+out.d3.signals.values)/2;
plot(out.d2.time,deg)
hold on
load("TT_scripps.mat")
deg = (out.d2.signals.values+out.d3.signals.values)/2;
plot(out.d2.time,deg)
grid on
legend("PF, with adaptation","PF, no adaptation","TT, with adaptation", "TT, no adaptation","Location","southeast")
xlabel("t (s)")
ylabel("Horizontal Command (deg)")

% (vert. cmd.)
figure()
load("PF_scripps_ad.mat")
deg = -out.d5.signals.values;
plot(out.d5.time,deg)
hold on
load("PF_scripps.mat")
deg = -out.d5.signals.values;
plot(out.d5.time,deg)
load("TT_scripps_ad.mat")
deg = -out.d5.signals.values;
plot(out.d5.time,deg)
hold on
load("TT_scripps.mat")
deg = -out.d5.signals.values;
plot(out.d5.time,deg)
grid on
legend("PF, with adaptation","PF, no adaptation","TT, with adaptation", "TT, no adaptation")
xlabel("t (s)")
ylabel("Vertical Command (deg)")
