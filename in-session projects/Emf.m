% First figure - XYZ Coordinates
clear
clc
close all

t = 0:0.05:2*pi;
phi = pi;
Emax = 2;
Hmax = 3;
lambda = 4000;
w = 4;

Ey = Emax * cos(w*t - (2*pi/lambda) * phi);
Hz = Hmax * cos(w*t - (2*pi/lambda) * phi);

figure;
xlabel('propagation direction');
ylabel('Electric field');
zlabel('Magnetic field');
view(45, 20);

hold on;

for i = 1:length(t)
    plot3(t(i), 0, 0, 'g.', 'MarkerSize', 20); % x-axis
    plot3(t(i), Ey(i), 0, 'r.', 'MarkerSize', 20); % y-axis
    plot3(t(i), 0, Hz(i), 'b.', 'MarkerSize', 20); % z-axis
    drawnow
    pause(0.02)
end

hold off;

% second figure
clear
clc
close all

t = 0:0.05:2*pi;
phi = pi;
Emax = 2;
Hmax = 3;
lambda = 4000;
w = 4;

Ey = Emax * cos(w*t - (2*pi/lambda) * phi);
Hz = Hmax * cos(w*t - (2*pi/lambda) * phi);

figure;
xlabel('Electric field');
ylabel('Magnetic Field');
zlabel('propagation direction');
view(45, 20);

hold on;

for i = 1:length(t)
    plot3(0, 0,t(i), 'g.', 'MarkerSize', 20); % z-axis
    plot3( Ey(i),0, t(i), 'r.', 'MarkerSize', 20); % x-axis
    plot3(0, Hz(i),t(i), 'b.', 'MarkerSize', 20); % y-axis
    drawnow
    pause(0.02)
end
% third figure
clear
clc
close all

t = 0:0.05:2*pi;
phi = pi;
Emax = 2;
Hmax = 3;
lambda = 4000;
w = 4;

Ey = Emax * cos(w*t - (2*pi/lambda) * phi);
Hz = Hmax * cos(w*t - (2*pi/lambda) * phi);

figure;
xlabel('Electric field');
ylabel('Magnetic Field');
zlabel('propagation direction');
view(45, 20);

hold on;

for i = 1:length(t)
    plot3(0, 0,t(i), 'g.', 'MarkerSize', 20); % z-axis
    plot3(0 ,Ey(i), t(i), 'r.', 'MarkerSize', 20); % y-axis
    plot3(-Hz(i),0 ,t(i), 'b.', 'MarkerSize', 20); % -x-axis
    drawnow
    pause(0.02)
end

% fourth figure
clear
clc
close all

t = 0:0.05:2*pi;
phi = pi;
Emax = 2;
Hmax = 3;
lambda = 4000;
w = 4;

Ey = Emax * cos(w*t - (2*pi/lambda) * phi);
Hz = Hmax * cos(w*t - (2*pi/lambda) * phi);
figure;
xlabel('propagation direction');
ylabel('Magnetic Field');
zlabel('Electric field');
view(45, 20);

hold on;

for i = 1:length(t)
    plot3(t(i),0, 0, 'g.', 'MarkerSize', 20); % x-axis
    plot3(t(i) ,0,Ey(i), 'r.', 'MarkerSize', 20); % z-axis
    plot3(t(i),-Hz(i),0, 'b.', 'MarkerSize', 20); % -y-axis
    drawnow
    pause(0.02)
end
% fifth figure
clear
clc
close all

t = 0:0.05:2*pi;
phi = pi;
Emax = 2;
Hmax = 3;
lambda = 4000;
w = 4;

Ey = Emax * cos(w*t - (2*pi/lambda) * phi);
Hz = Hmax * cos(w*t - (2*pi/lambda) * phi);
figure; 

xlabel('Magnetic Field');
ylabel('propagation direction');
zlabel('Electric field');
view(45, 20);

hold on;

for i = 1:length(t)
    plot3(0,t(i), 0, 'g.', 'MarkerSize', 20); % y-axis
    plot3(0,t(i),Ey(i), 'r.', 'MarkerSize', 20); % z-axis
    plot3(-Hz(i),t(i),0, 'b.', 'MarkerSize', 20); % x-axis
    drawnow
    pause(0.02)
end
% sixth figure
clear
clc
close all

t = 0:0.05:2*pi;
phi = pi;
Emax = 2;
Hmax = 3;
lambda = 4000;
w = 4;

Ey = Emax * cos(w*t - (2*pi/lambda) * phi);
Hz = Hmax * cos(w*t - (2*pi/lambda) * phi);
figure;
xlabel('Electric field');
ylabel('propagation direction');
zlabel('Magnetic Field');
view(45, 20);

hold on;

for i = 1:length(t)
    plot3(0,t(i), 0, 'g.', 'MarkerSize', 20); % y-axis
    plot3(Ey(i),t(i),0, 'r.', 'MarkerSize', 20); % x-axis
    plot3(0,t(i),-Hz(i), 'b.', 'MarkerSize', 20); % -z-axis
    drawnow
    pause(0.02)
end
