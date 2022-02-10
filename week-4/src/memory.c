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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#include "../include/common/memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value)
{
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index)
{
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index)
{
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size)
{
  unsigned int i;
  for(i = 0; i < size; i++) 
  {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size)
{
  set_all(ptr, 0, size);
}

// my functions
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
  // important to know that we are pointing to the same type
  // to be compliant with the C standard
  uint8_t *s_pt = src;
  uint8_t *d_pt = dst;

  // compare the memory addresses - are we going to clobber
  // bits we are about to try and send? If not proceed forward
  if (d_pt < s_pt) 
  {
    while (length--)
    {
      *d_pt++ = *s_pt++;
    }
  }
  else
  // move backwards to avoid clobbering the bits to send
  {    
    for(uint8_t i = (length -1); i>0; i--)
    {
      *(d_pt+i)= *(s_pt+i);
    }
  }
  return dst;
}    

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  uint8_t *d_pt = dst;
  uint8_t *s_pt = src;
  while (length--)
  {
    *(d_pt++) = *(s_pt++);
  }
  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
  for(int8_t i=0; i<length;i++)
  {
    *(src+i) = value;
  }	
  return src;
}
  
uint8_t * my_memzero(uint8_t * src, size_t length)
{
  return my_memset(src, length, 0);
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
  uint8_t *temp_buffer;
  temp_buffer = (uint8_t*) malloc(length * sizeof(uint8_t));

  for (uint8_t i=0; i<length; i++)
  {
    *(temp_buffer+i) = *(src+i);
  }
  while (length--)
  {
    *(src+length) = *((temp_buffer+length)-(length-1));
  }
  free(temp_buffer);
  return src;
}

int32_t * reserve_words(size_t length)
{
  return malloc(length * sizeof(length));
}
void free_words(int32_t * src)
{
  return free(src);
}


