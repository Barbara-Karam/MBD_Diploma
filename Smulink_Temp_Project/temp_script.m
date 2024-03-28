% Define system parameters
tau = 5; % Time constant (seconds)
Ku = 1;  % System gain

% Create step input for desired temperature
T_setpoint = 100; % Desired temperature in degrees Celsius (can be changed)
time = 0:0.1:50; % Time vector for simulation (adjust as needed)
T_input = T_setpoint * ones(size(time)); % Step input signal

% Simulink model reference (replace with your model name if different)
sim('temperature_control_model');

% Plot the results (modify variable names if needed)
plot(time, T, time, T_input);
xlabel('Time (seconds)');
ylabel('Temperature (degrees Celsius)');
title('Temperature Control System Response');
legend('Actual Temperature', 'Desired Temperature');
