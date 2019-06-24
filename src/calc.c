#include "calc.h"
#include <math.h>
#include <ncurses.h>
#include <stdlib.h>

void deltavEvaluate() {
  /* Delta-v Formula
   * delta-v = Ve * ln(Mf / Me)
   * where:
   *  - Ve is 9.8 * Isp
   *  - Mf is Mass Fuelled
   *  - Me is Mass Empy
   */

  newRocket.delta_v = 9.8 * newRocket.isp * logf(newRocket.wf / newRocket.we);
}

void twrEvaluate() {}
