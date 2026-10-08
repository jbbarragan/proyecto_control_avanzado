%% Ejecutar DESPUES de AERO2_LQR_OBSERVADOR.m (no cambia las ganancias).
Co=ctrb(A_modelo,B_modelo);
Ob=obsv(A_modelo,C);
fprintf('Controlabilidad: %d/4; observabilidad: %d/4\n',rank(Co),rank(Ob));
disp('Polos nominales A-BK:'); disp(eig(A_modelo-B_modelo*K_lqr));
fprintf('beta=%g, l=%g, m=%g\n',beta,l,m);
% Estado z=[theta_hat; velocidad_hat; alpha], por cada eje.
Ao=[0 1 0;-l 0 m;-1 0 -beta];
Bo=[0;l;1]; Co_obs=[1 0 0];
Ho=ss(Ao,Bo,Co_obs,0);
figure('Name','Respuesta del observador a una medicion escalon');
step(Ho); grid on;
% Matematicamente el polo es -p triple; eig/roots puede separarlo ligeramente
% por sensibilidad numerica. La transferencia no es la planta Aero 2.
disp('Coeficientes:'); disp([1 beta l l*beta+m]);
assert(norm([beta,l,l*beta+m]-[3*p,3*p^2,p^3])<1e-5);
% Prefiltro nominal opcional, calculado pero NO conectado al Simulink:
% u=-K*x+Nbar*r; r=[pitch_ref;yaw_ref].
Nbar_nominal = -inv(C*((A_modelo-B_modelo*K_lqr)\B_modelo));
disp('Nbar nominal (solo propuesta):'); disp(Nbar_nominal);
