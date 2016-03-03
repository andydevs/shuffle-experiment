function p = polynomial_fit(x, y, degree)
% polynomial_fit Coefficients of the best fit polynomial for the given data points
%
%   Finds the coefficients of the best fit polynomial (using the least squares method)
%   of the given degree for the given y and x values and returns them as a column vector,
%   sorted by the power of each term
%
%                                    [ a1 ]
%   Ex. f(x) = a1 + a2*x + a3*x^2 -> [ a2 ]
%                                    [ a3 ]
%   
%   Parameters:
%		x - the x values of the data points
%		y - the y values of the data points
%       degree - the degree of the best-fit polynomial
%
%   Returns:
%       p - the coefficients of the best fit polynomial
%
%   Preconditions:
%       - number of x values must equal number of y values
%       - number of x (and y) values must be greater than 0
%       - degree must be a whole number
%       - degree must be greater than or equal to 0

% Check first precondition
if size(x) ~= size(y)
    error(['Number of x values must equal number of y values! Got: ' num2Str(size(x)) ' and ' num2str(size(y))]);
end

% Check second precondition
if isempty(x)
    error('Number of x and y values must be greater than 0');
end

% Check third precondition
if round(degree) ~= degree
   error(['Degree must be a whole number! Got: ' num2str(degree)]); 
end

% Check fourth preconditon
if degree < 0
   error(['Degree must be greater than or equal to 0! Got:' num2Str(degree)]); 
end

% Array dimension n
n = length(x);

% Construct vector c
Ic = meshgrid(0:degree, 1:n)';
Xc = meshgrid(x, 0:degree);
Yc = meshgrid(y, 0:degree);
c = sum(Yc.*Xc.^Ic, 2);

% Construct matrix B
[Jb, Ib, Xb] = meshgrid(0:degree, 0:degree, x);
B = sum(Xb.^(Ib + Jb), 3);

% Vector p equals inverse of B times C
p = B^-1*c;
end