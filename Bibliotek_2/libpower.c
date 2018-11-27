#include <stdio.h>
#include <stdlib.h>

// Bib 2
float calc_power_r(float volt, float resistance);
float calc_power_i(float volt, float current);
int main(void) {

  // Functions

  printf("This is the Power of r: %f \n", calc_power_r(240, 400));
  printf("This is the Power of i: %f \n", calc_power_i(240, 4));

  return 0;
}
