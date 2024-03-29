#include "calc.h"
#include "display.h"
#include "main.h"
#include <ctype.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

// MenuEntry entries, see header display.h
struct menu ispMenu = {{"Force", "Fuel Cons(kg/s)"},
                       {&newRocket.force, &newRocket.fuelCons},
                       2,
                       ispEvaluete,
                       NULL};
struct menu twrMenu = {
    {"Force", "ASL/VAC", "Weight(Full)", "Gravity"},
    {&newRocket.force, &newRocket.asl_vac, &newRocket.wf, &newRocket.gravity},
    4,
    twrEvaluate,
    &ispMenu};
struct menu deltavMenu = {{"ISP", "Weight(Full)", "Weight(Empt)"},
                          {&newRocket.isp, &newRocket.wf, &newRocket.we},
                          3,
                          deltavEvaluate,
                          &twrMenu};
struct menu mainMenu = {{"Delta-v", "TWR", "ISP"},
                        {&newRocket.delta_v, &newRocket.twr, &newRocket.isp},
                        3,
                        NULL,
                        &deltavMenu};

int main() {

  int cursor;
  char key;

  // Default Values

  struct calc_data clean = {
      "Default", 0, 0, 0, 0, 0, 0, 0, 0,
  };

  newRocket = clean;
  cursor = 0;

  // Screen Initialization
  setupScr();
  displayScr(cursor + 1, mainMenu);
  mvprintw(cursor, 2, "*");

  while ((key = getch()) != 'q' && key != 27) {
    switch (key) {

      // Movement
    case 'j':
      if (cursor + 1 < mainMenu.lenght)
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

    // Clean the values
    case 'x':
      newRocket = clean;
      break;

    default:
      break;
    }
    clear();
    displayScr(cursor + 1, mainMenu);
    mvprintw(cursor, 2, "*");
  }
  endwin();
  return 0;
}

void subMenu(int sub) {

  int cursor, x;
  char key;

  struct menu *menuActive = &mainMenu;
  for (x = 0; x <= sub; x++) {
    menuActive = menuActive->next;
  }

  cursor = 0;
  x = getmaxx(stdscr);

  mvprintw(cursor, 3 + (x / 3), "*");
  while ((key = getch()) != 'h' && key != 'q' && key != 27) {
    switch (key) {

      // Movement
    case 'j':
      if (cursor + 1 < menuActive->lenght)
        cursor++;
      break;

    case 'k':
      if (cursor - 1 >= 0)
        cursor--;
      break;
    case 'l':
      *menuActive->value[cursor] = inputNumbers();
      break;

    // Use this to see the calc results
    case 'e':
      menuActive->evaluate(); // That is where the pointer to the calc comes to
      break;

    default:
      break;
    }
    clear();
    displayScr(sub + 1, mainMenu);
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

      mvprintw(y - 1, i + 14, &key);
      mvprintw(y - 1, i + 15, " ");
      mvprintw(y - 1, i + 16, " ");
      charNumber[i] = key;
      i++;
    }
  }

  attroff(A_STANDOUT | COLOR_PAIR(1));
  number = strtof(charNumber, NULL);
  return number;
}
