/*Bibliotek 1 gjort av Daniel Rincon */

#include<stdlib.h> // Behövs för att kunna använda NULL
#include "resistance.h"

/*
 * Räknar ut ersättningsresistansen givet ett antal komponenters resistans
 * kopplade antigen seriellt eller parallellt.
 * Indata: 
 *   count = heltal större än 0
 *   array = pekare till 'count' antal positiva float-värden
 *   conn = 'S' eller 'P' som betecknar seriell resp. parallell koppling
 * Utdata: Beräknad ersättningsresistans som floatvärde
 *   -1: vid fel indata (count < 1, array inte pekare till count positiva floats eller conn inte 'S' eller 'P')
 *    0: då conn = 'P' och någon av resistanserna är 0
 *    Ersättningsresistans: annars 
 */
float calc_resistance(int count, char conn, float *array)
{
  if (count < 1)
    return -1;
  
  if (conn == 'S')
  {
    float sersum = 0;
    for(int i = 0;i < count;i++)
    {
      if (array == NULL || *array < 0)
      {
	return -1;
      }
      else
      {
	sersum += *(array++);
      }
    }
    return sersum;
  }
  else if (conn == 'P')
  {
    float parsum = 0;
    for(int i = 0;i < count;i++)
    {
      if (array == NULL || *array < 0)
      {
	return -1;
      }
      else if (*array == 0)
      {
	return 0;
      }
      else
      {
	parsum += 1/(*(array++));
      }
    }
    return 1/parsum;
  }
  else
  {
    return -1;
  }
}
