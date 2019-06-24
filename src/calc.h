#ifndef __CALC_H_
#define __CALC_H_

struct rocket {
  char *name;
  float delta_v;
  float twr;
  float isp;
  float force;
  float wf; // Height with fuel
  float we; // height without fuel
} newRocket;

#endif // __CALC_H_
