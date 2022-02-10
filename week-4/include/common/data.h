/******************************************************************************
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief  Abstraction of integer to ascii and reverse
 *
 * This header file provides an abstraction of functions 
 * Integer-to-ASCII needs to convert data from a standard integer type into 
 * an ASCII string
 * 
 * ASCII-to-Integer needs to convert data back from an ASCII represented string 
 * into an integer type.
 *
 * @author mcooper
 * @date Feb 2022
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief converts integer to ascii
 *
 * Function should return the length of the converted data (including a negative 
 * sign). Example my_itoa(ptr, 1234, 10) should return an ASCII string length 
 * of 5 (including the null terminator).
 * 
 *
 * @param 
 * @param 
 * @param 
 *
 * @return 
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief converts ascii to integer
 *
 * 
 *
 * @param 
 * @param 
 * @param 
 *
 * @return 
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
#endif
