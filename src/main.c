#include "calc.h"
#include "display.h"
#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  struct rocket newRocket;
  int maxY;
  int cursor, cursorY, entry;
  char *mainMenu[] = {"Delta-v", "ISP", "TWR", "Print", "Clean", "\0"};
  char *deltavMenu[] = {"ISP", "Mass(Empty)", "Mass(Full)", "\0"};
  char *twrMenu[] = {"Force", "Mass(Full)", "\0"};
  char *printMenu[] = {"Name", "File Name", "Print", "\0"};
  char *cleanMenu[] = {"Some smoth", "Must be 2, they say", "\0"};
  char **menu[] = {mainMenu, deltavMenu, twrMenu, printMenu, cleanMenu};
  char key;

  newRocket.name = "Default";
  newRocket.delta_v = 0;
  newRocket.isp = 0;
  newRocket.twr = 0;
  newRocket.wf = 0;
  newRocket.we = 0;

  cursor = 0;
  cursorY = 2;
  entry = -1;
  maxY = getmaxx(stdscr) / 3;

  setupScr();
  displayScr(entry, menu, &newRocket);
  mvprintw(cursor, cursorY, "*");

  while ((key = getch()) != 'q') {
    switch (key) {

      // Movement
    case 'j':
      if (cursor <= sizeof(&menu) - 5)
        cursor++;
      break;

    case 'k':
      if (cursor - 1 >= 0)
        cursor--;
      break;

    case 'h':
      entry = -1;
      cursorY = 2;
      break;

    case 'l':
      entry = cursor;
      cursorY = 2 + (2 * maxY);
      break;
      // End Movement

    default:
      break;
    }
    clear();
    displayScr(entry, menu, &newRocket);
    mvprintw(cursor, cursorY, "*");
  }
  endwin();
  return 0;
}
