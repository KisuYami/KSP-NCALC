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

void twrEvaluate() {
  /* We need two formulas here Thrust and TWR
   * thrust = force / mass
   * twr = thrust / G
   * where:
   *  - G is 9.8 m/s
   */
  if (newRocket.force == 0)
    newRocket.force = newRocket.asl_vac / newRocket.wf;

  newRocket.twr = newRocket.force / 9.8;
}
