/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file  stats.h
 * @brief  function prototypes for basic stats assignment
 *
 * These are prototypes for the week 1 warm up assignment for
 * Introduction to Embedded Systems Software and Development Environments
 * 
 *
 * @author mcooper
 * @date December 2021 
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
/**
 * @brief  prints summary statistics of the provided array
 *
 * This function prints the various stats determined 
 * by the other functions 
 * min, max, mean and median
 *
 * @param minimum: the min of the array
 * @param max: the max of the array
 * @param mean: the mean of the array
 * @param median: the median of the array
 *
 * @return void
 */

void print_statistics(unsigned char minimum, unsigned char maximum, float mean, unsigned char median);

/**
 * @brief prints an arbitrary array of numbers
 *
 * this function loops through an array of numbers and prints them
 * to the terminal
 *
 * @param array: the starting point of the array to be printed
 * @param counter: 
 * @return  void
 */

void print_array(unsigned char *array, unsigned int counter);

/**
 * @brief find the median of an arbitrary array of numbers
 *
 * Finds the median of a sorted array of integers 
 *
 * @param array: an array of integers
 * @param counter: the number of integers in the array
 *
 * 
 */

unsigned char find_median(unsigned char *array, unsigned int counter);

/**
 * @brief find the mean of an arbitrary array of numbers
 *
 *  
 *
 * @param array: an array of integers
 * @param counter: the number of elements in the array
 *
 * @return float
 */

float find_mean (unsigned char *array, unsigned int counter);

/**
 * @brief  finds the max of an array of numbers
 *
 * 
 *
 * @param array: an array of integers
 * @param counter: the number of elements in the array
 *
 * @return float
 */

unsigned char find_maximum (unsigned char *array, unsigned int counter);

/**
 * @brief  finds the min of an array of numbers
 *
 * 
 *
 * @param array: an array of integers
 * @param counter: the number of elements in the array
 *
 * @return float
 */

unsigned char find_minimum (unsigned char *array, unsigned int counter);


/**
 * @brief sorts an arbitrary array of numbers from max to min 
 *
 * 
 *
 * @param array:  pointer to an array
 * @param counter: the number of elements in the array
 *
 * @return void
 */

void sort_array (unsigned char *array, unsigned int counter);

#endif /* __STATS_H__ */
