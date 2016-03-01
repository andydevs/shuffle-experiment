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

%% Section 1: Data reading

% Read options into vector
options = dlmread('options.csv', ',');

% Read data into matrix
Data = dlmread('data.csv', ',');

% Get shuffles vector, lengths vector, and trials from options
shuffles = options(1):options(2);
lengths = options(3):options(4);
trials = options(5);

%% Section 2: Entropy vs array length and shuffle Times

% Construct surface plot axes from options
[Shuffles, Lengths] = meshgrid(shuffles, lengths);

% Plot Data wrt Lengths and Shuffles
figure;
surf(Lengths, Shuffles, Data);
xlabel('Array Length');
ylabel('Shuffle Times');
zlabel('Entropy (number of swaps)');
title('Entropy of Shuffles vs Array Length and Shuffle Times');

%% Section 3: Entropy vs shuffle times for largest array size

% Get best fit line (logarithm plot)
shuffles_fit = polyfit(log(shuffles), Data(end,:), 1);

% Display curve coefficients
display(shuffles_fit);

% Plot entropy vs shuffle times for largest array size and best fit line
figure;
semilogx(shuffles,Data(end,:),'blue', shuffles, polyval(shuffles_fit, log(shuffles)), 'black');
title(['Entropy of Shuffles vs Shuffle Times for Largest Array Length (' num2str(shuffles(end)) ')']);
xlabel('Shuffle Times');
ylabel('Entropy (number of swaps)');
legend('Raw Data', 'Best Fit Curve');

%% Section 4: Entropy vs array length for most shuffle times

% Find best fit polynomial curve
arrays_fit = polyfit(lengths, Data(:,end)', 3);

% Display curve coefficients
display(arrays_fit);

% Plot entropy vs array size for most shuffle times
figure;
plot(lengths,Data(:,end),'red', lengths, polyval(arrays_fit,lengths),'black');
title(['Entropy of Shuffles vs Array Size for Most Shuffle Times (' num2str(lengths(end)) ')']);
xlabel('Array Size');
ylabel('Entropy (number of swaps)');
legend('Raw Data', 'Best Fit Curve');

%% Section 5: clean up
% Clean up clean up
% Everybody everywhere
% clean up clean up
% Everybody do your share!

clear