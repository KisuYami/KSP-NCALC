#include <stddef.h>
#ifndef __DISPLAY_H_
#define __DISPLAY_H_

struct menu {
  const char *options[15];
  const int lenght;
  float *value[15];
  struct menu *next; // First time using this shit!
};

void setupScr();
void displayScr(int entry, const struct menu menu);
void inputSubmenu(int cursor);
#endif // __DISPLAY_H_
