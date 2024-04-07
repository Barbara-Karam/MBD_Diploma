wn = 2;
zeta = 0.5;

num = 1;
den = [1 2*zeta*wn wn^2];
sys = tf(num, den);

t = 0:0.01:100;
Ki_Values = [0.001 0.01 0.1 1 10 50 100];

figure;

for i = 1:length(Ki_Values)
    Ki = Ki_Values(i);
    I_Controller = tf(Ki, [1 0]);
    SysteWithIController = series(I_Controller, sys);
    ClosedLoopSysWithController = feedback(SysteWithIController, 1);
    [SysteResWithIController, ~] = step(ClosedLoopSysWithController, t);
    
    subplot(length(Ki_Values), 1, i);
    plot(t, OpenLoopRes, 'k--', 'LineWidth', 1.5);
    hold on
    plot(t, ClosedLoopResWithoutController, 'b:', 'LineWidth', 1.5);
    hold on
    plot(t, SysteResWithIController, 'LineWidth', 1.5);
    hold off
    
    xlim([0 100]);
    title(['Ki = ', num2str(Ki)]);
    ylabel('System Response');
end

sgtitle('Effect of Ki on system response (2nd order system)');
xlabel('Time');
