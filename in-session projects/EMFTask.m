%preparing
clear
clc
close all

%parameters of material
% in this case it's iron
mu_r = 1000;
mu_node = 4*pi*(10^-7);
mu= mu_node * mu_r;
sigma = 1*(10^7);
frequency = linspace(60,10^9,1000);
w = 2*pi*frequency;
delta = sqrt(1 ./ (pi*mu*sigma*frequency));
alpha = sqrt(pi*mu*frequency*sigma);
beta = alpha;
gamma = complex(alpha,beta);

%plotting 
t = 0:0.05:2*pi; 
Ez = Emax * exp(-alpha*z) * cos((w*t)-(beta*z);
Hy = (gamma/(i*w*mu))*Ez;

figure;
xlabel('propagation direction');
ylabel('Electric field');
zlabel('Magnetic field');
view(45, 20);

hold on;

for i = 1:length(t)
    plot3(-t(i), 0, 0, 'g.', 'MarkerSize', 20); % -x-axis
    plot3(-t(i), 0, Ez(i), 'r.', 'MarkerSize', 20); % z-axis
    plot3(-t(i),Hy(i), 0,'b.', 'MarkerSize', 20); % y-axis
    drawnow
    pause(0.02)
end

hold off;
saveas(gcf,'negativexzyConductur.jpg');