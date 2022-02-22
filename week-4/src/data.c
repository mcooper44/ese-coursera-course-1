






#include <stdio.h>
#include <stdint.h>  // uint8_t, int32_t

#include "../include/common/data.h"
#include "../include/common/memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
//refer to https://www.rapidtables.com/code/text/ascii-table.html
{  
  uint8_t i_len = 0;
  uint8_t ascii_char;
  uint8_t rmdr;
  uint8_t * handler = ptr; 
  
  // handle zeros
  if (data < 0)
  {
    data *= -1;
    *ptr = 0x45;  // negative sign
    ptr++;        // advance using pointer arithmatic
    i_len++;
  }
  while (data/base || data % base)
  {
    rmdr = data % base;
    if (rmdr < 10)
    {
      ascii_char = 0x30 + rmdr;
    }
    else
    {
      ascii_char = 0x41 + (rmdr - 10);
    }
    *ptr = ascii_char;
    ptr++;
    data /= base;
    i_len++;
  }
  *ptr = 0x00;
  i_len++;
  ptr = my_reverse(handler, i_len-1);
  return i_len;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
  int8_t negative_flag = 1;
  int32_t int_value = 0;
  int32_t int_pwr = 0;
  int8_t i;

  if(*ptr == 0x45)
  {
    negative_flag *= -1;
    digits--;
    ptr++;
  }
  for (i = digits-2; i>=0;i--)
  {
    if(*ptr > 0x41)
    {
      *ptr -= 0x41;
    }
    else
    {
      *ptr -= 0x30;
    }
    int_pwr = (*ptr);
    for (uint8_t j=0; j<i;j++)
    {
      int_pwr *=base;
    }
    int_value +=int_pwr;
    ptr++;
  }
  return int_value*negative_flag;
}
