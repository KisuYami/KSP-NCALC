#include "calc.h"
#include "display.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

void setupScr() {

  initscr();
  cbreak();
  noecho();
  curs_set(0);
  start_color();
  // Colors
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
}

void displayScr(int entry, const struct menu menu) {

  int x, y;
  int i, v;
  // rocket table
  const struct menu *menuActive = &menu;
  struct display_table calc_table[] = {
      {"ISP: \t%3.2f", newRocket.isp}, // 9 entrys
      {"TWR: \t%3.2f", newRocket.twr},
      {"Force: \t%3.2f", newRocket.force},
      {"Fuel.C: \t%3.2f", newRocket.fuelCons},
      {"Delta-v: \t%3.2f", newRocket.delta_v},
      {"W(Full): \t%3.2f", newRocket.wf},
      {"W(Empt): \t%3.2f", newRocket.we},
      {"ASL/VAC: \t%3.2f", newRocket.asl_vac},
      {"Gravity: \t%3.2f", newRocket.gravity}};

  for (x = 0; x < entry; x++) {
    if (menuActive->next == NULL) // Be sure to not fuck up
      break;
    menuActive = menuActive->next;
  }

  getmaxyx(stdscr, y, x);

  v = x / 3;
  // Some cozy lines
  for (i = 0; i < y - 1; i++) {
    mvprintw(i, v, "|");
    mvprintw(i, 2 * v, "|");
  }

  // menus
  i = 0;
  while (i <= menu.lenght && i <= menuActive->lenght) {

    if (i < menu.lenght) {
      mvprintw(i, 1, "[ ]");
      mvprintw(i, 1 + 4, menu.options[i]);
    }

    if (i < menuActive->lenght) {
      mvprintw(i, 2 + v, "[ ]");
      mvprintw(i, 2 + 4 + v, menuActive->options[i]);
    }
    i++;
  }

  for (i = 0; i < sizeof(calc_table) / sizeof(calc_table[0]); i++) {
    mvprintw(i, 2 * v + 2, calc_table[i].entry, calc_table[i].data);
  }
}
