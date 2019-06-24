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

void displayScr(int entry, const char ***menu) {

  int y, x;
  int i, v;
  // rocket table
  char *rocketTable[] = {"name: %s",         "ISP: %d",
                         "TWR: %d",          "Delta-v: %d",
                         "Weight(Full): %d", "Weight(Empty): %d"};

  const char **mainMenu = menu[0];
  const char **menuActive = menu[entry];

  getmaxyx(stdscr, y, x);

  v = x / 3;
  // Some beuty lines
  for (i = 0; i < y; i++) {
    mvprintw(i, v, "|");
  }

  for (i = 0; i < y; i++) {
    mvprintw(i, 2 * v, "|");
  }

  // Main menu
  i = 0;
  while (strncmp(mainMenu[i], "\0", 2)) {

    mvprintw(i, 1, "[ ]");
    mvprintw(i, 1 + 4, mainMenu[i]);
    i++;
  }

  if (entry >= 0) {
    i = 0;
    while (strncmp(menuActive[i], "\0", 2)) {

      mvprintw(i, 2 + v, "[ ]");
      mvprintw(i, 2 + 4 + v, menuActive[i]);
      i++;
    }
  }

  mvprintw(0, 2 * v + 2, rocketTable[0], newRocket.name);
  mvprintw(1, 2 * v + 2, rocketTable[1], newRocket.isp);
  mvprintw(2, 2 * v + 2, rocketTable[2], newRocket.twr);
  mvprintw(3, 2 * v + 2, rocketTable[3], newRocket.delta_v);
  mvprintw(4, 2 * v + 2, rocketTable[4], newRocket.wf);
  mvprintw(5, 2 * v + 2, rocketTable[5], newRocket.we);
}