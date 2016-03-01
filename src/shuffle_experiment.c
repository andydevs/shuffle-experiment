#include "array_shuffle_functions.h"
#include "program_constants.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
	sprintf(data_file_path,    argc == 2 ? argv[1] : DEFAILT_FILEPATH);
	sprintf(options_file_path, argc == 2 ? argv[1] : DEFAILT_FILEPATH);	

	// Concatenate filenames to path
	strcat(data_file_path, DATA_FILENAME);
	strcat(options_file_path, OPTIONS_FILENAME);

	//---------------------------------READ AND TEST OPTIONS---------------------------------		

	// Open options file, error if options fails to open
	if ((options = fopen(options_file_path, "r")) == NULL)
	{
		printf("ERROR: when reading options file --> %s\n", strerror(errno));
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

	// Error if minimum array length is less than 3
	if (ARRAY_LENGTH_MIN < 3)
	{
		printf("ERROR: Min array length must be at least 3! Min: %i\n", ARRAY_LENGTH_MIN);
		return 1;
	}

	// Error if minimum array length is greater than maximum array length
	if (ARRAY_LENGTH_MIN > ARRAY_LENGTH_MAX)
	{
		printf("ERROR: Min array length must be less than max array length! Min: %i, Max: %i\n", ARRAY_LENGTH_MIN, ARRAY_LENGTH_MAX);
		return 1;
	}

	// Error if minimum shuffle times is less than 1
	if (SHUFFLE_TIMES_MIN < 1)
	{
		printf("ERROR: Min shuffle_times must be greater than or equal to 1! Min: %i\n", SHUFFLE_TIMES_MIN);
		return 1;
	}

	// Error if minumum shuffle times is greater than maximum shuffle times
	if (SHUFFLE_TIMES_MIN > SHUFFLE_TIMES_MAX)
	{
		printf("ERROR: Min shuffle times must be less than max shuffle times! Min: %i, Max: %i\n", SHUFFLE_TIMES_MIN, SHUFFLE_TIMES_MAX);
		return 1;
	}

	// Error if shuffle trials is less than 1
	if (SHUFFLE_TRIALS < 1)
	{
		printf("ERROR: Shuffle trials must be at least 1! Trials: %i\n", SHUFFLE_TRIALS);
		return 1;
	}

	// Print options
	printf("Options:\n");
	printf("\tMin shuffle times: %i\n", SHUFFLE_TIMES_MIN);
	printf("\tMax shuffle times: %i\n", SHUFFLE_TIMES_MAX);
	printf("\tMin array length:  %i\n", ARRAY_LENGTH_MIN);
	printf("\tMax array length:  %i\n", ARRAY_LENGTH_MAX);
	printf("\tShuffle trials:    %i\n", SHUFFLE_TRIALS);

	//---------------------------------BEGIN EXPERIMENT---------------------------------

	// Initialize buffers
	int swap_buffer;
	int array_buffer[ARRAY_LENGTH_MAX];	

	// Open data file, error if data file is null
	if ((data = fopen(data_file_path, "w")) == NULL)
	{
		printf("ERROR: when reading data file --> %s\n", strerror(errno));
		return 1;
	}

	// Print start of experiment
	printf("Arrays:\n");

	// Seed random number generator
	srand(time(NULL));

	// For every array length from ARRAY_LENGTH_MIN through ARRAY_LENGTH_MAX
	for (int array_length =  ARRAY_LENGTH_MIN; 
			 array_length <= ARRAY_LENGTH_MAX; 
			 array_length++)
	{
		// Print array length
		printf("\tArray length: %i\n", array_length);

		// Initialize array for experiment
		for (int i = 0; i < array_length; ++i) array_buffer[i] = i;

		// ---------------------------------PERFORM SHUFFLE EXPERIMENT ON ARRAY---------------------------------

		// For each number of shuffle times from SHUFFLE_TIMES_MIN to SHUFFLE_TIMES_MAX
		for (int shuffle_times =  SHUFFLE_TIMES_MIN; 
				 shuffle_times <= SHUFFLE_TIMES_MAX; 
				 shuffle_times++)
		{
			printf("\t\tShuffle times: %i\n", shuffle_times);

			// Compute average swaps of all shuffle trials
			swap_buffer = 0;
			for (int i = 0; i < SHUFFLE_TRIALS; ++i)
			{
				// Perform shuffle
				shuffle(array_buffer, array_length, shuffle_times);

				// Print array
				printf("\t\t\t[%i", array_buffer[0]);
				if (array_length > 1)
				{
					for (int i = 1; i < array_length; ++i)
					{
						printf(", %i", array_buffer[i]);
					}
				}
				printf("]\n");

				// Add entropy to swap buffer
				swap_buffer += sort(array_buffer, array_length);
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
	printf("Done!\n");
	return 0;
}