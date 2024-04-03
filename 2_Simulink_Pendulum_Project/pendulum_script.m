L = 5;
g = 9.81;
syms t;
theta = (g/L)*sin(t);
theta_dd = diff(diff(theta));

t_values = 0:0.1:100; 


theta_dd_values = double(subs(theta_dd, t, t_values));


plot(t_values, theta_dd_values)
