%preparing workspace
clear;
clc;

%parameters
k = 2*pi;
w = 10; 
Exm = 20*sqrt(2); 
Hym = 15*sqrt(2); 
x = 5:-0.01:0; 
Zeros = zeros(size(x));

% Loss coefficient is high because it's a good conductor
alpha = 0.99; 

% Fixed time to be able to see skin depth
t = 0.9;

%good conductors formula
Ez = Exm * cos(w * t * k * x) .* exp(-alpha * x);
Hy = Hym * cos(w * t * k * x - pi/4) .* exp(-alpha * x);

% Plotting
figure(1);
plot3(x, Zeros,Ez, 'k');
hold on;
plot3(x, Hy,Zeros, 'g');
grid on;
axis([0, 5, -20, 20, -20, 20]);
xlabel('propagation');
ylabel('Magnetic Field');
zlabel('Electric Field');
set(gcf, 'color', 'w');
hold off;
saveas(gcf,'negativexzyConductur.jpg');