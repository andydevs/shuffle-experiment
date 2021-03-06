% Shuffle Experiment: An experiment to determine a pattern in the entropy of an array of given length when shuffled a given amount of times Copyright (C) 2016 Anshul
% 
% This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
% 
% This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
% 
% You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.

% This script analyzes data generated from the shuffle experiment binary.
%
% It generates three plots of the data.
%    The first plot is a surface plot that displays entropy with respect to
%    array size and shuffle times
%
%    The second plot is a semilogx plot that displays entropy with respect 
%    to shuffle times for the largest array size
%
%    The third plot is a linear plot that displays entropy with 
%    repsect to array size for the most amount of shuffle times

%% Section 1: Data initialization

% Read options into vector
options = dlmread('options.csv', ',');

% Read data into matrix
Data = dlmread('data.csv', ',');

% Get shuffles vector, lengths vector, and trials from options
shuffles = options(1):options(2);
lengths = options(3):options(4);
trials = options(5);

% Construct surface plot axes from options
[Shuffles, Lengths] = meshgrid(shuffles, lengths);

%% Section 2: Entropy vs array length and shuffle Times

% Plot Data wrt Lengths and Shuffles
figure(1);
surf(Lengths, Shuffles, Data);
xlabel('Array Length');
ylabel('Shuffle Times');
zlabel('Randomness (number of swaps)');
title('Randomness of Shuffles vs Array Length and Shuffle Times');

%% Section 3: Entropy vs shuffle times for largest array size

% Get best fit line (logarithm plot)
shuffles_fit = polynomial_fit(log(shuffles), Data(end,:), 1);

% Plot entropy vs shuffle times for largest array size and best fit line
figure(2);
semilogx(shuffles,Data(end,:),'blue', shuffles, polynomial_value(shuffles_fit, log(shuffles)), 'black');
title(['Randomness vs Shuffle Times for Largest Array Length (' num2str(shuffles(end)) ')']);
xlabel('Shuffle Times');
ylabel('Randomness (number of swaps)');
legend('Raw Data', 'Best Fit Curve');

%% Section 4: Entropy vs array length for most shuffle times

% Find best fit polynomial curve
arrays_fit = polynomial_fit(lengths, Data(:,end)', 3);

% Plot entropy vs array size for most shuffle times
figure(3);
plot(lengths,Data(:,end),'red', lengths, polynomial_value(arrays_fit,lengths),'black');
title(['Randomness vs Array Size for Most Shuffle Times (' num2str(lengths(end)) ')']);
xlabel('Array Size');
ylabel('Randomness (number of swaps)');
legend('Raw Data', 'Best Fit Curve');

%% Section 5: clean up
% Clean up clean up
% Everybody everywhere
% clean up clean up
% Everybody do your share!

clear