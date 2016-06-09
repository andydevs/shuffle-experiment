# Shuffle Experiment

## Overview

This was a project that I did for my ENGR 122 class, in which me and a couple other groupmates were to design a project in MATLAB. 

One of the components of computer science is figuring out how to sort an array of numbers in the quickest, most efficient way possible. My group and I did the opposite, figuring out how to shuffle an array of numbers such that the numbers are the most randomly distributed as possible. I've created an algorithm that takes two random inceces in the array and swaps them, what I call a shuffle.

This is an experiment to determine how many times a sorted array of arbitrary length must be shuffled to produce the maximum "randomness" in the array.

## Usage
If you'd like to run this code for yourself here is how:

### Note
This program has only been compiled for a 64-bit Unix system (either Mac or Linux, or Windows with a Unix shell). Also, this program uses make to build and run. Make sure you have that installed.

### Download
Simply download a .zip or a .tar.gz of the code and unpack it. In it you'll find the code needed to run the program. Keep the folder structure as is.

### Experiment Configuration
Within the analysis folder, you will find a file named "options.csv". You will use this file to configure the experiment.

| Cell |         Description          |
|------|------------------------------|
|   1  | The minimum shuffle times    |
|   2  | The maximum shuffle times    |
|   3  | The minimum array length     |
|   4  | The maximum array length     |
|   5  | The number of shuffle trials |

### Running the program
If the program is not built yet (there is no bin directory), you can build the program by using make.

Typing `make run` will run the program.

The program will iterate through each array length and shuffle times combination, and perform the given amount of shuffle trials on such an array, and get the average value.

This value will be recorded in the data.csv file located in the analysis folder. The row of the value corresponds to the number of shuffletimes, and the column corresponds to the array length.

### Using MATLAB code
Run "shuffle_experiment_analysis.m" in the analysis folder. This will read the data and options and plot three graphs of the data.
