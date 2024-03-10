R = 5;
C = 100 * 10^(-6);
Vct = @(t) (20*sin(2*pi*t));

t = linspace(0, 10, 1000);

V = zeros(1, 1000);

for i = 1:1000
    Vd = 10*pi*cos(2*pi*t(i));

    V(i) = Vct(t(i))/R + Vd*C;
end

plot(t, V, 'r-', 'LineWidth', 2);
xlabel('Time');
ylabel('Voltage');
title('RC Circuit Response');
grid on;
