clc,clear

% weight = [6000, 1120, 335, 138, 72, 45, 32, 25];    % Input weights coefficients
weight = [128, 64, 32, 16, 8, 4, 2, 1];    % Input weights coefficients

weight = fliplr(weight);    % Mirror vector

T = length(weight); % Number of sensors
N = 2^T-1; % All possible sensors outputs



error = zeros(1,N);

for k = 1:N % for all possible sensors outputs
    numerator = 0;      % Initialize variables
    denominator = 0;    % Initialize variables
    value = de2bi(k,T);
    for  i = 1:8
        numerator = numerator + value(i) * i * weight(i);
        denominator = denominator + value(i) * weight(i);
    end
    error(k) = numerator / denominator;
end

x = 1:1:N; % x for plot

error(1:100)

figure(4)
plot(x,error);
title('error plot')
