% This script analyzes data generated from the shuffle experiment binary.
%
% It generates three plots of the data.
%    The first plot is a surface plot that displays entropy with respect to
%    array size and shuffle times
%
%    The second plot is a loglog plot that displays entropy with respect 
%    to shuffle times for the largest array size
%
%    The third plot is a loglog plot that displays entropy with 
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

%% Section 2: Entropy vs array length and shuffle times

% Construct surface plot axes from options
[Shuffles, Lengths] = meshgrid(shuffles, lengths);

% Plot Data wrt Lengths and Shuffles
figure(1);
surf(Lengths, Shuffles, Data);
xlabel('Array Lengths');
ylabel('Shuffle Times');
zlabel('Entropy (number of swaps)');
title('Entropy of Shuffles vs Array Length and Shuffle mes');

%% Section 3: Entropy vs shuffle times for largest array size

% Plot entropy vs shuffle times for largest array size
figure(2);
semilogx(shuffles,Data(end,:),'b');
xlabel('Shuffle Times');
ylabel('Entropy (number of swaps)');
title(['Entropy of Shuffles vs Shuffle Times for Largest Array Size (' num2str(options(2)) ')']);

%% Section 4: Entropy vs array length for most shuffle times

% Plot entropy vs array size for most shuffle 
figure(3);
loglog(lengths,Data(:,end),'r');
xlabel('Array Size');
ylabel('Entropy (number of swaps)');
title(['Entropy of Shuffles vs Array Size for Most Shuffle Times (' num2str(options(4)) ')']);