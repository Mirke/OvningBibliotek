#include <stdlib.h>
#include "calc_power_r.h"
float calc_power_r(float volt, float resistance) {
  float s_volt = volt * volt;
  return s_volt / resistance;
}

