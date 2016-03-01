/**
 * Shuffle Experiment: An experiment to determine a pattern in the entropy of an array of given length when shuffled a given amount of times Copyright (C) 2016 Anshul
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.
 */

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