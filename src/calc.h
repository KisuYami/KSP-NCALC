#ifndef __CALC_H_
#define __CALC_H_

struct calc_data {
  char *name;
  float wf; // Height with fuel
  float we; // height without fuel
  float twr;
  float isp;
  float force;
  float gravity;
  float delta_v;
  float asl_vac;
  float fuelCons;
} newRocket;

void deltavEvaluate();
void twrEvaluate();
void ispEvaluete();
#endif // __CALC_H_
