#ifndef _PROGRAM_CONSTANTS_H_
#define _PROGRAM_CONSTANTS_H_

/**
 * The default filepath of the files
 */
#define DEFAILT_FILEPATH ".\\analysis"

/**
 * The name of the file containing data
 */
#define DATA_FILENAME "\\data.csv"

/**
 * The name of the file containing options
 */
#define OPTIONS_FILENAME "\\options.csv"

/**
 * Minimum number of shuffle times to test
 */
const int SHUFFLE_TIMES_MIN;

/**
 * Maximum number of shuffle times to test
 */
const int SHUFFLE_TIMES_MAX;

/**
 * Minimum array length to test
 */
const int ARRAY_LENGTH_MIN;

/**
 * Maximum array length to test
 */
const int ARRAY_LENGTH_MAX;

/**
 * Number of shuffle trials to perform in each experiment
 */
const int SHUFFLE_TRIALS;

#endif