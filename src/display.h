#include <stddef.h>
#ifndef __DISPLAY_H_
#define __DISPLAY_H_

void setupScr();
void displayScr(int entry, const char ***menu);
void inputSubmenu(int cursor);
#endif // __DISPLAY_H_
