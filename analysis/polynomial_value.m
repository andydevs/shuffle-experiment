function y = polynomial_value(p, x)
% polynomial_value The y values of the polynomial vector at the given x values
%
%   Returns the y values of given polynomial vector at the given x
%   values
%	
%	Parameters:
%		p - the polynomial vector (a column vector)
%		x - the x values (a row vector)
%
%	Returns:
%		y - the y values of the polynomial vector at the x values

% Generate the series matrix "X"
%
% A polynomial series matrix is a matrix thay can by multiplied by a 
% polynomial vector to produce a series of y values for that 
% polynomial function
%
% Ex. series matrix X for a 2nd degree polynomial 
%     with x values x1, x2, x3, x4, x5
%
%       [ 1     x1    x1^2 ]
%       [ 1     x2    x2^2 ]
%   X = [ 1     x3    x3^2 ]
%       [ 1     x4    x4^2 ]
%       [ 1     x5    x5^2 ]
%
%   produce a series of y values for the given polynomial vector
%
%       [ a1 ]
%   a = [ a2 ]
%       [ a3 ]
%
%             [ 1     x1    x1^2 ]
%             [ 1     x2    x2^2 ]   [ a1 ]
%   y = S*a = [ 1     x3    x3^2 ] * [ a2 ]
%             [ 1     x4    x4^2 ]   [ a3 ]
%             [ 1     x5    x5^2 ]
%
%       [ a1 + a2*x1 + a3*x1^2 ]
%       [ a1 + a2*x2 + a3*x2^2 ]
%   y = [ a1 + a2*x3 + a3*x3^2 ]
%       [ a1 + a2*x4 + a3*x4^2 ]
%       [ a1 + a2*x5 + a3*x5^2 ]
%
%       [ y1 ]
%       [ y2 ]
%     = [ y3 ]
%       [ y4 ]
%       [ y5 ]
[I, N] = meshgrid(0:(length(p) - 1), x);
X = N.^I;

% Multiply X by p and set y to the transpose
y = (X*p)';
end