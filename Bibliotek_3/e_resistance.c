#include "e_resistance.h"
#define E12SIZE 12


int e_resistance(float orig_resistance, float *res_array)
{
  float e12[] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};
  float e12value, previous;
  int i=0, count = 0, pwr;
  float resistance = orig_resistance;
  pwr = (int)log10(resistance);  // used to convert e12 table to appropriate size

  while(count<3 && i<E12SIZE && resistance>=1){
    e12value=e12[i];
    for(int j=0;j<pwr;j++){
      e12value = e12value*10;

    }


    if(e12value>resistance || i==(E12SIZE-1)){    // used to catch the largest possible value that's <= resistance
      if(e12value>resistance) e12value = previous;
      res_array[count] = e12value;
      resistance -= e12value;
      pwr = (int)log10(resistance);
      count++;
      i=0;

    }
    else{
      previous=e12value;
      i++;

    }

  }
  return count;

}
