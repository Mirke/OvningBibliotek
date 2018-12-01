#include <stdio.h>
#include <stdlib.h>
#include "calc_power_r.h"
#include "calc_power_i.h"


// Bib 2
int main(void) {

  // Functions

  printf("This is the Power of r: %f \n", calc_power_r(240, 400));
  printf("This is the Power of i: %f \n", calc_power_i(240, 4));

  return 0;
}
