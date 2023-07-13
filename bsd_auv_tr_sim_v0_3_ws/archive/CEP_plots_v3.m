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


% Position error
figure()
load("PF_scripps_ad.mat")
size_v = size(out.pos_err.signals.values);
norm_pos_err = reshape(out.pos_err.signals.values,[size_v(3) 1]);
plot(out.Bx1.time,norm_pos_err)
hold on
load("TT_scripps_ad.mat")
size_v = size(out.pos_err.signals.values);
norm_pos_err = reshape(out.pos_err.signals.values,[size_v(3) 1]);
plot(out.Bx1.time,norm_pos_err)
grid on
legend("PF","TT")
xlabel("t (s)")
ylabel("Normalized Position Error (m)")

