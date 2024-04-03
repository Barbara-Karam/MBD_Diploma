Zeta_values = [0.1, 0.5, 0.9];
wn_values = [1, 2, 4];

figure;

for j = 1:length(wn_values)
    for k = 1:length(Zeta_values)
        subplot_index = (j - 1) * length(Zeta_values) + k;
        subplot(3, 3, subplot_index);  % Adjust grid size as needed
        SecondOrderEq(wn_values(j), Zeta_values(k));
    end
end