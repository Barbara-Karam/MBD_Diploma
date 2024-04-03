K = 1; 

R = 10e3; 
C = 1e-7; 

T = R * C; 

num = [0 K]; 
den = [T 1]; 

G = tf(num,den);
t = 0:0.1:10; 
u_parabolic = 0.5 * t.^2; 
[y_ramp,t_ramp] = lsim(G,u_parabolic,t);
plot(t_ramp,y_ramp);