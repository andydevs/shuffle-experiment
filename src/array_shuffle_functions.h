#ifndef _ARRAY_SHUFFLE_FUNCTIONS_H_
#define _ARRAY_SHUFFLE_FUNCTIONS_H_

/**
 * Swaps the two values at the given indeces with each other in the array
 *
 * Parameter: array - the array in which to swap values 
 * Parameter: a     - the first index to swap
 * Parameter: b     - the second index to swap
 */
void swap(int array[], int a, int b);

/**
 * Shuffles the values in the given array with the given length for the given number of times
 * Each shuffle time, we pick two random indeces in the array to swap.
 * 
 * Parameter: array  - the array to shuffle
 * Parameter: length - the length of the array to shuffle
 * Parameter: times  - the number of times to shuffle the array
 */
void shuffle(int array[], int length, int times);

/**
 * Returns the square of the linear correlation coefficient of the array of integer values
 * with respect to the indeces. The linear correlation coefficient describes how well the
 * array of integer values fits a linear trend.
 *
 * Parameter: array - the array to determine the correlation coefficient of
 * Parameter: length - the length of the array to determine the correlation coefficient of
 *
 * Returns: the square of the linear correlation coefficient of the array of integer values
 * 			with respect to the indeces.
 */
double square_correlation(int array[], int length);

/**
 * Sorts the values in the given array with the given length in ascending order
 *
 * Parameter: array  - the array to sort
 * Parameter: length - the length of the array to sort
 *
 * Returns: the number of swaps made to sort the array
 */
int insertion_sort(int array[], int length);

#endif