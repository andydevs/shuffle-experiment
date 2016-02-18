#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DEFAILT_FILEPATH "."

/**
 * The name of the file containing data
 */
#define DATA_FILENAME "\\data.csv"

/**
 * The name of the file containing options
 */
#define OPTIONS_FILENAME "\\options.csv"

/**
 * Initial values of the experiment
 *
 * ARRAY_LENGTH_MIN  - Minimum array length to test
 * ARRAY_LENGTH_MAX  - Maximum array length to test
 * SHUFFLE_TIMES_MIN - Minimum number of shuffle times to test
 * SHUFFLE_TIMES_MAX - Maximum number of shuffle times to test
 * SHUFFLE_TRIALS    - Number of shuffle trials to perform in each experiment
 */
const int ARRAY_LENGTH_MIN = 10,
		  ARRAY_LENGTH_MAX = 20,
		  SHUFFLE_TIMES_MIN = 10,
		  SHUFFLE_TIMES_MAX = 20,
		  SHUFFLE_TRIALS = 10;

/**
 * The data and option files to write
 */
FILE *data, *options;

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
 * Sorts the values in the given array with the given length in ascending order
 *
 * Parameter: array  - the array to sort
 * Parameter: length - the length of the array to sort
 *
 * Returns: the number of swaps made to sort the array
 */
int insertion_sort(int array[], int length);


/**
 * The main method of the program
 *
 * Parameter: argc - the number of arguments passed to the main method
 * Parameter: argv - the command line arguments passed to the main method
 *
 * Return: the exit status of the program
 */
int main(int argc, char *argv[])
{
	// Initialize buffers
	int swap_buffer;
	int array_buffer[ARRAY_LENGTH_MAX];
	char data_file_path[100], options_file_path[100];

	//---------------------------------INITIALIZE FILES---------------------------------

	// Store given filepath if filepath is given
	// Else store default filepath
	if (argc == 2)
	{
		sprintf(data_file_path, argv[1]);
		sprintf(options_file_path, argv[1]);	
	}
	else
	{
		sprintf(data_file_path, DEFAILT_FILEPATH);
		sprintf(options_file_path, DEFAILT_FILEPATH);
	}

	// Concatenate filenames to path
	strcat(data_file_path, DATA_FILENAME);
	strcat(options_file_path, OPTIONS_FILENAME);

	// Initialize files with filenames
	data = fopen(data_file_path, "w+");
	options = fopen(options_file_path, "w+");

	//---------------------------------BEGIN EXPERIMENT---------------------------------

	// Write options to file
	fprintf(options, "%i,%i,%i,%i,%i\n", ARRAY_LENGTH_MIN,
								      	 ARRAY_LENGTH_MAX,
								      	 SHUFFLE_TIMES_MIN,
								      	 SHUFFLE_TIMES_MAX,
								      	 SHUFFLE_TRIALS);

	// Seed random number generator
	srand(time(NULL));

	// For every array length from ARRAY_LENGTH_MIN through ARRAY_LENGTH_MAX
	for (int array_length = ARRAY_LENGTH_MIN; 
			 array_length <= ARRAY_LENGTH_MAX; 
			 array_length++)
	{
		// Initialize array for experiment
		for (int i = 0; i < array_length; ++i)
		{
			array_buffer[i] = i;
		}

		// ---------------------------------PERFORM SHUFFLE EXPERIMENT ON ARRAY---------------------------------

		// For each number of shuffle times from SHUFFLE_TIMES_MIN to SHUFFLE_TIMES_MAX
		for (int shuffle_times = SHUFFLE_TIMES_MIN; 
				 shuffle_times <= SHUFFLE_TIMES_MAX; 
				 shuffle_times++)
		{
			// Compute average swaps of all shuffle trials
			swap_buffer = 0;
			for (int i = 0; i < SHUFFLE_TRIALS; ++i)
			{
				shuffle(array_buffer, array_length, shuffle_times);
				swap_buffer += insertion_sort(array_buffer, array_length);
			}
			swap_buffer /= SHUFFLE_TRIALS;

			// Print average swap count for this experiment
			fprintf(data, shuffle_times == SHUFFLE_TIMES_MIN ? "%i" : ",%i", swap_buffer);
		}
		// Go to next line
		fprintf(data, "\n");
	}

	// Close data and options files
	fclose(data);
	fclose(options);

	return 0;
}

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
int insertion_sort(int array[], int length)
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