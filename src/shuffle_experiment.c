#include "program_constants.h"
#include "array_shuffle_functions.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/**
 * The default filepath of the files
 */
#define DEFAILT_FILEPATH "..\\analysis"

/**
 * The name of the file containing data
 */
#define DATA_FILENAME "\\data.csv"

/**
 * The name of the file containing options
 */
#define OPTIONS_FILENAME "\\options.csv"

/**
 * The data and option files to write
 */
FILE *data, *options;

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
	//---------------------------------GET FILENAMES---------------------------------

	// Initialize file buffers
	char data_file_path[100], options_file_path[100];

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

	//---------------------------------READ OPTIONS---------------------------------	

	// Open options file
	options = fopen(options_file_path, "r");

	// Error if options fails to open
	if (options == NULL)
	{
		printf("ERROR: ");
		if (errno == 2)
		{
			printf("file not found! : %s\n", options_file_path);
		}
		else
		{
			printf("when reading options file --> %s\n", strerror(errno));
		}
		return 1;
	}

	// Read options
	fscanf(options, "%i,%i,%i,%i,%i\n", &SHUFFLE_TIMES_MIN,
								      	&SHUFFLE_TIMES_MAX,
										&ARRAY_LENGTH_MIN,
								        &ARRAY_LENGTH_MAX,
								      	&SHUFFLE_TRIALS);
	// Close options file
	fclose(options);

	//---------------------------------BEGIN EXPERIMENT---------------------------------

	// Initialize buffers
	int swap_buffer;
	int array_buffer[ARRAY_LENGTH_MAX];

	// Initialize data file
	data = fopen(data_file_path, "w");

	// Error if data file is null
	if (data == NULL)
	{
		printf("ERROR: when reading data file --> %s\n", strerror(errno));
		return 1;
	}

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

	// Close data file
	fclose(data);

	// End program
	return 0;
}