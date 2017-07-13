%% 
% plot the space formed with different U_l, U_h and alpha
% x: Utilization
% y: Control Cost

close all

color_map = ...
   [ 0 0 1; % 1 BLUE
   0 0.5 0; % 2 GREEN (medium dark)
   1 0 0; % 3 RED
   0 0.75 0.75; % 4 TURQUOISE
   0.75 0 0.75; % 5 MAGENTA
   0.75 0.75 0; % 6 YELLOW (dark)
   0.25 0.25 0.25; % 7 GREY (very dark)
   1 0.50 0.25; % 8 ORANGE
   0.6 0.5 0.4; % 9 BROWN
   1 1 0 ]; % 10 YELLOW (pale)

array_u = [];
array_c = [];
array_a = [];

for i = 0:5:100
    data_filename = sprintf('./result/stat_sym_50_100_%d.mat', i);
    load(data_filename)
    subplot(1,1,1)
    scatter(z_u', z_c', 15, 'filled', ...
            'LineWidth', 0.5, ...
            'Marker', 'o', ...
            'MarkerFaceColor', color_map(mod(i / 5,10) + 1, :) );
    hold on;
    
    %subplot(2,1,2)
    %plot(normc(z_c')); hold on; plot(normc(z_u'))
    %hold on;
    array_u = [array_u, z_u'];
    array_c = [array_c, z_c'];
    array_a = [array_a, ones(numel(z_u),1) .* 0.1 .* i]
end

array_t_high = repmat(x', 1, 9);
array_t_low = repmat(y', 1, 9);

legend('a = 0.1','a = 0.2','a = 0.3','a = 0.4','a = 0.5','a = 0.6','a = 0.7','a = 0.8','a = 0.9')

cd ..

