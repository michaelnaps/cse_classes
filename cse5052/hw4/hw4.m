%% CSE 5052 - Homework 4
%  Created by: Michael Napoli
%  Due date: 12/3/2021

clc;clear;
close all;

%% Part 1: Linear Least Squares
% Given data
x = [0.5; 1.5; 2.5; 3.5; 4.5];
y = [0.450; 1.292; 2.449; 3.847; 5.446];

% linear fit
[p0, p1, e] = least_squares(x, y);
f1 = @(x) p1*x + p0;

x1 = 0:0.01:5;
y1 = f1(x1);

figure(1)
hold on
plot(x, y, '.', 'markersize', 20)
plot(x1, y1)
title('Linear Fit Comparison')
ylabel('y')
xlabel('x')
legend('Given Data', 'Calculated Regression')
hold off

% quadratic fit
a2 = polynomial_fit(x, y, 2);
f2 = @(x) a2(3).*x.^2 + a2(2).*x + a2(1);

x2 = x1;
y2 = f2(x2);

figure(2)
hold on
plot(x, y, '.', 'markersize', 20)
plot(x2, y2)
title('Quadratic Fit Comparison')
ylabel('y')
xlabel('x')
legend('Given Data', 'Calculated Fit')
hold off

% cubic fit
a3 = polynomial_fit(x, y, 3);
f3 = @(x) a3(4).*x.^3 + a3(3).*x.^2 + a3(2).*x + a3(1);

x3 = x1;
y3 = f3(x3);

figure(3)
hold on
plot(x, y, '.', 'markersize', 20)
plot(x3, y3)
title('Cubic Fit Comparison')
ylabel('y')
xlabel('x')
legend('Given Data', 'Calculated Fit')
hold off

% 4th-order polynomial fit
a4 = polynomial_fit(x, y, 4);
f4 = @(x) a4(5).*x.^4 + a4(4).*x.^3 + a4(3).*x.^2 + a4(2).*x + a4(1);

x4 = x1;
y4 = f4(x4);

figure(4)
hold on
plot(x, y, '.', 'markersize', 20)
plot(x4, y4)
title('4th-Order Polynomial Fit Comparison')
ylabel('y')
xlabel('x')
legend('Given Data', 'Calculated Fit')
hold off
