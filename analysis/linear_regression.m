function [m, b] = linear_regression(y, x)
%% linear_regression: Returns the slope and y-intercept of a linear best-fit line for the given data

C = [sum(y); sum(y.*x)];

B = [length(x), sum(x); sum(x), sum(x.^2)];

A = (B^-1)*C;

b = A(1);
m = A(2);
end