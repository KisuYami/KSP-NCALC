#include "calc.h"
#include "display.h"
#include "main.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

// MenuEntry entries
const char *mainMenuEntry[] = {"Delta-v", "TWR", "ISP", "Print", "Clean", "\0"};
const char *deltavMenuEntry[] = {"ISP", "Mass(Empty)", "Mass(Full)", "\0"};
const char *twrMenuEntry[] = {"Force", "Mass(Full)", "\0"};
const char *ispMenuEntry[] = {"SAMPLE", "SAMPLE", "\0"};
const char *printMenuEntry[] = {"Name", "File Name", "Print", "\0"};
const char *cleanMenuEntry[] = {"SAMPLE", "SAMPLE", "\0"};
const char **menu[] = {mainMenuEntry, deltavMenuEntry, twrMenuEntry,
                       ispMenuEntry,  printMenuEntry,  cleanMenuEntry};
// Some lengths
const size_t menuLenght[] = {5, 3, 2, 2, 3, 2};

int main(int argc, char *argv[]) {

  int cursor;
  char key;

  // Default Values
  newRocket.name = "Default";
  newRocket.delta_v = 0;
  newRocket.isp = 0;
  newRocket.twr = 0;
  newRocket.wf = 0;
  newRocket.we = 0;
  cursor = 0;

  // Screen Initialization
  setupScr();
  displayScr(cursor + 1, menu);
  mvprintw(cursor, 2, "*");

  while ((key = getch()) != 'q') {
    switch (key) {

      // Movement
    case 'j':
      if (cursor + 1 < menuLenght[0])
        cursor++;
      break;

    case 'k':
      if (cursor - 1 >= 0)
        cursor--;
      break;

    case 'l':
      subMenu(cursor);
      break;
      // End Movement

    default:
      break;
    }
    clear();
    displayScr(cursor + 1, menu);
    mvprintw(cursor, 2, "*");
  }
  endwin();
  return 0;
}

void subMenu(int sub) {

  int cursor, x;
  char key;

  cursor = 0;

  x = getmaxx(stdscr);

  mvprintw(cursor, 3 + (x / 3), "*");
  while ((key = getch()) != 'h' && key != 'q') {
    switch (key) {

      // Movement
    case 'j':
      if (cursor + 1 < menuLenght[sub + 1])
        cursor++;
      break;

    case 'k':
      if (cursor - 1 >= 0)
        cursor--;
      break;

    default:
      break;
    }
    clear();
    displayScr(sub + 1, menu);
    mvprintw(cursor, 3 + (x / 3), "*");
    mvprintw(sub, 2, "*");
  }
}
