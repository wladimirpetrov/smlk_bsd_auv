clear all
close all
Tf = 500;
Cpx = flip(xlsread('canyon_v2_gm.xlsx','A2:A62')); 
Cpy = flip(xlsread('canyon_v2_gm.xlsx','B2:B62'));
Cpz = flip(xlsread('canyon_v2_gm.xlsx','C2:C62'));
Cpx = -1*Cpx;
Cpy = -1*Cpy;
Cp = [Cpx'; Cpy'; Cpz'];
t = 0:.01:Tf;
pdee = BernsteinPoly(Cp,t);
plot3(pdee(1,:),pdee(2,:),pdee(3,:))
hold on
Cpx = flip(xlsread('canyon_v2.xlsx','A2:A62')); 
Cpy = flip(xlsread('canyon_v2.xlsx','B2:B62'));
Cpz = flip(xlsread('canyon_v2.xlsx','C2:C62'));
Cpx = -1*Cpx;
Cpy = -1*Cpy;
Cp = [Cpx'; Cpy'; Cpz'];
t = 0:.01:Tf;
pdee2 = BernsteinPoly(Cp,t);
plot3(pdee2(1,:),pdee2(2,:),pdee2(3,:))
hold on
Cpx = flip(xlsread('Copy of canyon_gm.xlsx','A2:A62')); 
Cpy = flip(xlsread('Copy of canyon_gm.xlsx','B2:B62'));
Cpz = flip(xlsread('Copy of canyon_gm.xlsx','C2:C62'));
Cpx = -1*Cpx;
Cpy = -1*Cpy;
Cp = [Cpx'; Cpy'; Cpz'];
t = 0:.01:Tf;
pdeec = BernsteinPoly(Cp,t);
plot3(pdeec(1,:),pdeec(2,:),pdeec(3,:))
legend("New Polynomial","Original Polynomial","Test Polynomial")
xlabel("x (m)")
ylabel("y (m)")
zlabel("z (m)")
title("Comparison of Bernstein Polynomials")

load("PF_gm.mat")
figure()
subplot(3,1,1)
plot3(pdee(1,:),pdee(2,:),pdee(3,:))
hold on
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values)
grid on
xlabel("x (m)")
ylabel("y (m)")
zlabel("z (m)")
legend("Bernstein Polynomial","Actual Trajectory")
title("PF - Actual vs Desired Trajectory - New Trajectory")

load("PF_2.mat")
subplot(3,1,2)
plot3(pdee2(1,:),pdee2(2,:),pdee2(3,:))
hold on
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values)
grid on
xlabel("x (m)")
ylabel("y (m)")
zlabel("z (m)")
legend("Bernstein Polynomial","Actual Trajectory")
title("PF - Actual vs Desired Trajectory - Old Trajectory")

load("PF_copy.mat")
subplot(3,1,3)
plot3(pdeec(1,:),pdeec(2,:),pdeec(3,:))
hold on
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values)
grid on
xlabel("x (m)")
ylabel("y (m)")
zlabel("z (m)")
legend("Bernstein Polynomial","Actual Trajectory")
title("PF - Actual vs Desired Trajectory - Old Trajectory")

load("TT_gm.mat")
figure()
subplot(2,1,1)
plot3(pdee(1,:),pdee(2,:),pdee(3,:))
hold on
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values)
grid on
xlabel("x (m)")
ylabel("y (m)")
zlabel("z (m)")
legend("Bernstein Polynomial","Actual Trajectory")
title("TT - Actual vs Desired Trajectory - New Trajectory")

load("TT_2.mat")
subplot(2,1,2)
plot3(pdee2(1,:),pdee2(2,:),pdee2(3,:))
hold on
plot3(-out.Bx1.signals.values,-out.Bx2.signals.values,out.Bx3.signals.values)
grid on
xlabel("x (m)")
ylabel("y (m)")
zlabel("z (m)")
legend("Bernstein Polynomial","Actual Trajectory")
title("TT - Actual vs Desired Trajectory - Old Trajectory")