#include <stddef.h>
#ifndef __DISPLAY_H_
#define __DISPLAY_H_

struct menu {
  const char *options[15]; // The menu entrys in text
  float *value[15]; // A pointer to the newRocket, so you can change the values
  const int lenght; // The total number of menu entrys
  const void (*evaluate)(); // A pointer to a function that should evaluete.
  struct menu *next;        // First time using this shit!
};

struct display_table {
  const char *entry;
  float data;
};

void setupScr();
void displayScr(int entry, const struct menu menu);
void inputSubmenu(int cursor);
#endif // __DISPLAY_H_
