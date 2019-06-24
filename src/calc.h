#ifndef __CALC_H_
#define __CALC_H_

struct rocket {
  char *name;
  float wf; // Height with fuel
  float we; // height without fuel
  float twr;
  float isp;
  float force;
  float delta_v;
  float asl_vac;
} newRocket;

void deltavEvaluate();
void twrEvaluate();
#endif // __CALC_H_
