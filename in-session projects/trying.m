% Set material and simulation parameters
mu_r = 1000;               % Relative permeability of iron
mu_0 = 4*pi*(10^-7);        % Permeability of free space
mu = mu_r * mu_0;             % Material permeability
sigma = 1*(10^7);          % Conductivity of iron (S/m)
frequency_range = linspace(60, 10^9, 1000);  % Frequency range (Hz)
w = 2*pi*frequency_range;    % Angular frequency (rad/s)

% Calculate propagation constant components
delta = sqrt(1 ./ (pi*mu*sigma*frequency_range));
alpha = sqrt(pi*mu*frequency_range*sigma);
beta = alpha;
gamma = complex(alpha, beta);

% Set time range and step
t_range = 0:0.05:2*pi;

% Initialize matrices for Ez and Hy
Ez = zeros(length(t_range), length(frequency_range));
Hy = zeros(size(Ez));

% Calculate Ez and Hy for each frequency and time step
for i = 1:length(frequency_range)
    f = frequency_range(i);
    w_i = 2*pi*f;
    alpha_i = sqrt(pi*mu*w_i*sigma);
    beta_i = alpha_i;
    gamma_i = complex(alpha_i, beta_i);

    for j = 1:length(t_range)
        t = t_range(j);
        Ez(j, i) = exp(-alpha_i*t) * cos((w_i*t) - (beta_i*t));
        Hy(j, i) = (gamma_i / (1i*w_i*mu)) * Ez(j, i);
    end
end

% Create 3D plot
figure;
xlabel('Propagation Direction (x)');
ylabel('Electric Field (Ez)');
zlabel('Magnetic Field (Hy)');
view(45, 20);
hold on;

% Plot markers along x-axis at different time steps
for i = 1:length(t_range)
    plot3(t_range(i)*ones(size(frequency_range)), 0, Ez(i, :), 'r-', 'LineWidth', 2);
    drawnow
    pause(0.01);
end

hold off;
saveas(gcf, 'negativexzyConductor_improved.jpg');
