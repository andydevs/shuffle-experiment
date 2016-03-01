/**
 * Shuffle Experiment: An experiment to determine a pattern in the entropy of an array of given length when shuffled a given amount of times Copyright (C) 2016 Anshul
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.
 */

#include "array_shuffle_functions.h"
#include "program_constants.h"

#include <stdlib.h>
#include <math.h>

/**
 * Swaps the two values at the given indeces with each other in the array
 *
 * Parameter: array - the array in which to swap values 
 * Parameter: a     - the first index to swap
 * Parameter: b     - the second index to swap
 */
void swap(int array[], int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * Shuffles the values in the given array with the given length for the given number of times
 * Each shuffle time, we pick two random indeces in the array to swap.
 * 
 * Parameter: array  - the array to shuffle
 * Parameter: length - the length of the array to shuffle
 * Parameter: times  - the number of times to shuffle the array
 */
void shuffle(int array[], int length, int times)
{
	// Create random index buffers
	int rand_a, rand_b;

	// For given number of times
	for (int i = 0; i < times; ++i)
	{
		// Create two distinct random indeces from 0 to length - 1
		do
		{
			rand_a = rand() % length;
			rand_b = rand() % length;
		} 
		while (rand_a == rand_b);

		// Swap array at random indeces
		swap(array, rand_a, rand_b);
	}
}

/**
 * Sorts the values in the given array with the given length in ascending order
 *
 * Parameter: array  - the array to sort
 * Parameter: length - the length of the array to sort
 */
int sort(int array[], int length)
{
	// Initialize swap counter
	int swaps = 0;

	// For each position after the first
	for (int curnt = 1; curnt < length; curnt++)
	{
		// Move element at curnt to it's sorted position in the array
		// Indicating the number of swaps
		int i = curnt;
		while (array[i] < array[i - 1])
		{
			swap(array, i, i - 1);
			swaps++;
			i--;
		}
	}

	// Return the number of swaps
	return swaps;
}