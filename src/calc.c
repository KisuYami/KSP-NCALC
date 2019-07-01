#include "calc.h"
#include <math.h>
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
  /* We need two formulas, Thrust and TWR
   * thrust = force / mass
   * twr = thrust / G
   * where:
   *  - G is the surface gravity
   */
  if (newRocket.force == 0)
    newRocket.force = newRocket.asl_vac / newRocket.wf;

  newRocket.twr = newRocket.force / newRocket.gravity;
}

void ispEvaluete() {
  /* Isp formula
   * isp = Ft / m
   * Where:
   *  - Ft is thrust in newstons
   *  - m is a fuel consumption in kg/s
   * */
  newRocket.isp = newRocket.force / newRocket.fuelCons;
}
