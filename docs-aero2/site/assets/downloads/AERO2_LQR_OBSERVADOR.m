%% Quanser Aero 2: LQR y observador de tercer orden
% Universidad Iberoamericana Ciudad de Mexico
% Autores: Joshua Barragan, Rodrigo Bartolo, Harold David Perez Garcia,
% Luis Roberto Cruz Caos.
% Transcripcion del codigo proporcionado el 8 de octubre de 2026.
% Se conserva el modelo, Q, R, p y el procedimiento simbolico.
% Requiere Control System Toolbox y Symbolic Math Toolbox.
clear; clc;
syms s beta l m p
Ksp=0.0130;
Jp=0.0231885;
Dp=0.00266;
Dy=0.00175;
Jy=0.0238104;
Dt=0.16743;
Kpp=0.00323;
Kpy=0.00149;
Kyy=0.00571;
Kyp=-0.00235;
A_modelo=[0 0 1 0
0 0 0 1
-(Ksp)/(Jp) 0 -(Dp)/(Jp) 0
0 0 0 -(Dy)/(Jy)];
B_modelo = [0 0
0 0
(Dt*Kpp)/(Jp) (Dt*Kpy)/(Jp)
(Dt*Kyp)/(Jy) (Dt*Kyy)/(Jy)];
C=[1 0 0 0
0 1 0 0];
D=[0 0
0 0];
Q = [270 0 0 0
      0 80 0 0
      0 0 1 0
      0 0 0 1]
R = [0.1 0
      0   0.05];
K_lqr = lqr(A_modelo, B_modelo, Q, R)
A_cl = A_modelo - B_modelo*K_lqr;
eig(A_cl)
p=200;
pol_obs = s^3 + beta*s^2 + l*s + (l*beta + m)
pol_des = expand((s + p)^3);
coef_obs = coeffs(pol_obs, s, 'All');
coef_des = coeffs(pol_des, s, 'All');
eq1 = coef_obs(2) == coef_des(2);
eq2 = coef_obs(3) == coef_des(3);
eq3 = coef_obs(4) == coef_des(4);
solucion = solve([eq1, eq2, eq3], [beta, l, m])
beta = double(solucion.beta);
l = double(solucion.l);
m = double(solucion.m);
