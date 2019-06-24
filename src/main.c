#include "calc.h"
#include "display.h"
#include "main.h"
#include <ctype.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

// MenuEntry entries
const char *mainMenuEntry[] = {"Delta-v", "TWR", "ISP", "Print", "Clean", "\0"};
const char *deltavMenuEntry[] = {"ISP", "Weight(Empty)", "Weight(Full)", "\0"};
const char *twrMenuEntry[] = {"Force", "Weight(Full)", "\0"};
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

  while ((key = getch()) != 'q' && key != 27) {
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
  float tmpNumber;
  char key;

  cursor = 0;

  x = getmaxx(stdscr);

  mvprintw(cursor, 3 + (x / 3), "*");
  while ((key = getch()) != 'h' && key != 'q' && key != 27) {
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
    case 'l':
      tmpNumber = inputNumbers();
      // I fucking know
      if (sub == 0) {
        if (cursor == 0)
          newRocket.isp = tmpNumber;
        if (cursor == 1)
          newRocket.wf = tmpNumber;
        if (cursor == 2)
          newRocket.we = tmpNumber;
      } else if (sub == 1) {
        if (cursor == 0)
          newRocket.force = tmpNumber;
        if (cursor == 1)
          newRocket.wf = tmpNumber;
      }
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

// Return inputed number
float inputNumbers() {
  int i = 0;
  int y = getmaxy(stdscr);
  char charNumber[255] = {0}, key;
  float number = 0;

  attron(A_STANDOUT | COLOR_PAIR(1));
  mvprintw(y - 1, 0, "Input Number: ");
  while ((key = getch()) != 27 && key != 10 && i < 255) {
    if (isdigit(key) || key == '.') {
      if (key == 127) {
        i--;
      } else {
        mvprintw(y - 1, i + 14, &key);
        mvprintw(y - 1, i + 15, " ");
        mvprintw(y - 1, i + 16, " ");
        charNumber[i] = key;
        i++;
      }
    }
  }
  attroff(A_STANDOUT | COLOR_PAIR(1));
  number = strtof(charNumber, NULL);
  return number;
}
