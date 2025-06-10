#include "utils.h"

void uint64_to_string(uint64_t value, char* buffer, int buffer_size)
{
  if(buffer_size <= 1)
    {
      if(buffer_size>0) buffer[0] = '\0';\
      return;
    }

  char temp[21];
  int i=0;

  if(value==0)
    {
      temp[i++]='0';
    }
  else
    {
      while(value > 0 && i < 20)
	{
	  temp[i++]='0'+(value%10);
	  value /= 10;
	}
    }

  int j = 0;
  while(i > 0 && j < buffer_size - 1)
    buffer[j++]=temp[--i];
  buffer[j]='\0';
}
