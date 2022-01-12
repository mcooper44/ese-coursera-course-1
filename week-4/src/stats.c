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
 * @file Stats.c 
 * @brief a bare bones command line stats program
 *
 * This is a basic C lang exercise to test and re-enforce basic skills
 * for completion of Introduction to Embedded Systems Course on Coursera
 * 
 * It takes an array, sorts it and prints basic stats such as mean, median, minimum
 * and maximum. 
 *
 * @author mcooper
 * @date December 11 2021
 *
 */

#include <stdio.h>
#include "../include/common/stats.h" // prototypes of stats functions to sort, determine min, max
		   // median of an array of numbers

/* Size of the Data Set */
#define SIZE (40)
/* Pretty print dimensions */
#define BLOCKWIDE (SIZE / 5)
#define BLOCKDEPTH (SIZE / 8)

void main(){
  // array of numbers to operate on
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* These variables will hold the values returned by the functions  */
  unsigned char mean = 0;
  unsigned char median = 0;
  unsigned char min = 0;
  unsigned char max = 0;

  /* calling functions defined in stats.h */
  printf("Initial array state: \n");
  print_array(test, SIZE);

  sort_array(test, SIZE);
  median = find_median(test, SIZE);
  mean = find_mean(test, SIZE);
  min = find_minimum(test, SIZE);
  max = find_maximum(test, SIZE);
  print_statistics(min, max, mean, median);
  printf("Final state of array after sorting: \n");
  print_array(test, SIZE);
}

/* implementation of the protyped functions in stats.h */

void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median){
  printf("The minimum of the array is %d \n", min);
  printf("The maximum of the array is %d \n", max);
  printf("The median of the array is %d\n", median);
  printf("The mean of the array is %d\n\n", mean);
}

void print_array(unsigned char *array, unsigned int counter){
  #ifdef VERBOSE
  for (int i=0;i<counter/BLOCKWIDE; i++){
    for(int j=0;j<counter/BLOCKDEPTH; j++){
      printf("%3d   ",array[BLOCKWIDE*i+j]);
    }
    printf("\n");
  }
  printf("\n");
  #endif
  return;
}

void sort_array (unsigned char *array, unsigned int counter){
  int i=0, j=0, temp = 0;
  for(i=0; i<counter; i++)

  {
    for(j=0; j<counter-i; j++)
    {
      if(array[j]<array[j+1])
      {
        temp=array[j];
        array[j]=array[j+1];
        array[j+1]=temp;
      }
    }
  }
}

unsigned char find_median(unsigned char *array, unsigned int counter){
  float median=0;
    if(counter%2==0)
      median=(array[(counter-1)/2] + array[counter/2])/2.0;
    else
      median = array[counter/2];
    return (unsigned char)(median);
}

float find_mean(unsigned char *array, unsigned int counter){
  unsigned int adder = 0;
  for(int i = 0; i < counter; i++){
    adder += array[i];
  }
  return (unsigned char)(adder / counter); 
}

unsigned char find_minimum(unsigned char *array, unsigned int counter){
  unsigned char min = *array;
  for (int i=1; i<counter;i++){
  if (*(array +i) < min){
    min = *(array +i);
    }
  }
  return min;
}

unsigned char find_maximum(unsigned char *array, unsigned int counter){
  unsigned char max = *array;
  for (int i=1; i<counter;i++){
  if (*(array +i) > max){
    max = *(array +i);
    }
  }
  return max;
}
