%% Setup 
%Duration of the experiment
Tmax = 10;

%Serial port name
port_name = "COM7";

%CONTROL_LOOP_PERIOD constant in the Arduino sketch
dt_arduino = 5e-3;

%Target folder
target_folder = './';

%% Retrieve data from robot
[log_time, data_values, line_idx] = ...
    get_data_from_robot(port_name, Tmax, target_folder);

%% Get filtered derivative (In progress ...)


%% Visualize data
%Display logged variable names
disp(data_values.keys)  

% Plot logged variables
figure; 
hold on;
legend_labels = data_values.keys;
for i = 1:numel(legend_labels)
    d = legend_labels{i};
    v = data_values(d);
    plot(log_time, v, 'DisplayName', d);
end
hold off;
legend('Location', 'best');
grid on;

GAINS = [1.5,   % MAHONY_TAU
         8.0,   % KP
         0.05,  % KD
         0.05,  % KP_PHI
         0.015];% KD_PHI


