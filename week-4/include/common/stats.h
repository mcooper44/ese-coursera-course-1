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
#ifdef COURSE1
void print_array(unsigned char *array, unsigned char counter);

#else

/* Add Your Declarations and Function Comments here */ 
/**
 * @brief  prints summary statistics of the provided array
 * 	   to std out
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

void print_statistics(unsigned char minimum, unsigned char maximum, unsigned char mean, unsigned char median);

/**
 * @brief find the median of an arbitrary array of numbers
 *
 * Finds the median of a sorted array of integers.  The median
 * is the number in a sorted array that is the middle value.
 * In an even array you can find the middle value by dividing
 * length of the array by two.  Otherwise, you will need to
 * average the middle two values
 *
 * @param array: an array of integers
 * @param counter: the number of integers in the array
 *
 * @return float
 */

unsigned char find_median(unsigned char *array, unsigned int counter);

/**
 * @brief find the mean of an arbitrary array of numbers
 *
 * The mean is calculated by adding the values in the array
 * and dividing that sum by the number of elements in the array
 *
 * @param array: an array of integers
 * @param counter: the number of elements in the array
 *
 * @return unsigned char
 */

float find_mean (unsigned char *array, unsigned int counter);

/**
 * @brief  finds the max of an array of numbers
 *
 * Iterates through the array and finds the minimum 
 * value through an element wise comparison of each
 * element 
 *
 * @param array: an array of integers
 * @param counter: the number of elements in the array
 *
 * @return unsigned char
 */

unsigned char find_maximum (unsigned char *array, unsigned int counter);

/**
 * @brief  finds the min of an array of numbers
 *
 * Iterates through the array and finds the maximum 
 * value through an element wise comparison of each
 * element 
 *
 * @param array: an array of integers
 * @param counter: the number of elements in the array
 *
 * @return unsigned char
 */

unsigned char find_minimum (unsigned char *array, unsigned int counter);


/**
 * @brief sorts an arbitrary array of numbers from max to min 
 *
 * this implementation uses bubble sort to sort the array
 * in descending order 
 *
 * @param array:  pointer to an array
 * @param counter: the number of elements in the array
 *
 * @return void
 */

void sort_array (unsigned char *array, unsigned int counter);
#endif
#endif /* __STATS_H__ */
