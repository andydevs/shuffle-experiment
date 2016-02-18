% Read data
O = dlmread('options.csv', ',');
D = dlmread('data.csv', ',');

% Construct axes from options
[S,L] = meshgrid(O(1):O(2), O(3):O(4));

% Plot entropy wrt array length (L) and shuffle times (S)
figure(1);
surf(L, S, D);
xlabel('Array Lengths');
ylabel('Shuffle Times');
zlabel('Entropy (number of swaps)');
title('Entropy of Shuffles vs Array Length and Shuffle Times');

% Plot entropy vs shuffle times for largest array size
figure(2);
plot(S(end,:),D(end,:),'b');
xlabel('Shuffle Times');
ylabel('Entropy (number of swaps)');
title(['Entropy of Shuffles vs Shuffle Times for Largest Array Size (' num2str(O(2)) ')']);

% Plot entropy vs array size for most shuffle times
figure(3);
plot(L(:,end),D(:,end),'r');
xlabel('Array Size');
ylabel('Entropy (number of swaps)');
title(['Entropy of Shuffles vs Array Size for Most Shuffle Times (' num2str(O(4)) ')']);