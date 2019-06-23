#ifndef __CALC_H_
#define __CALC_H_

struct rocket {
  char *name;
  int delta_v;
  int twr;
  int isp;
  int wf; // Height with fuel
  int we; // height without fuel
};

#endif // __CALC_H_
