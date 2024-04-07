num = 1;
den = [1 1];
sys = tf(num, den);
t = 0:0.01:100;
Ki_Values = [0.001,0.01, 0.1, 1, 10, 50, 100];

figure;
OpenLoopSys = step(sys, t);
plot(t, OpenLoopSys, 'k--', 'LineWidth', 1.5);
hold on

ClosedLoopResWithoutController = step(feedback(sys, 1), t);
plot(t, ClosedLoopResWithoutController, 'b:', 'LineWidth', 1.5);
hold on

for i = 1:length(Ki_Values)
    Ki = Ki_Values(i);
    I_Controller = tf(Ki, [1 0]);
    SystemWithIController = series(I_Controller, sys);
    ClosedLoopSysWithController = feedback(SystemWithIController, 1);
    [SystemResWithIController, ~] = step(ClosedLoopSysWithController, t);
    plot(t, SystemResWithIController, 'LineWidth', 1.5);
    hold on
end

xlim([0 100]);
title('Effect of Ki on system response (1st order system)');
xlabel('Time');
ylabel('System Response');  % Clearer label
legend(['Open Loop'; 'Closed Loop Without Controller'; cellstr(num2str(Ki_Values))]);
