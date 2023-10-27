#include "menu.h"

#include <string.h>
#include <stdlib.h>

int display_menu(WINDOW *window) {
    clear();
    wclear(window);
    wrefresh(window);
    refresh();

    int height = 11;
    int width = 30;
    
    char *title = " MINESWEEPER MENU " ;
    int length = strlen(title);

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);

    int highlight = 1;
    int choice = 0;
    int ch;
    do{
        // Clear old display
        clear();

        // Update window size and position to always be centered
        int start_y = (LINES - height) / 2;
        int start_x = (COLS - width) / 2;
        wresize(window, height, width);
        mvwin(window, start_y, start_x);
        box(window, 0, 0);

        // Display title and 'q' to qui tinstruction
        mvwprintw(window, 0, width/2 - length/2, "%s", title);
        mvprintw(LINES - 2, 1, "Press 'q' to quit");

        //display choices
        char *choices[] = {"8x8 board, 10 mines", "12x12 board, 25 mines", "16x16 board, 40 mines"};
        int x = 3;
        int y = height/3;
        for (int i = 0; i < 3; ++i) {
            if (highlight == i + 1) {
                wattron(window, COLOR_PAIR(2));
                mvwprintw(window, y, x, "> %s", choices[i]);
                wattroff(window, COLOR_PAIR(2));
            } else
                mvwprintw(window, y, x, "  %s", choices[i]);
            y += 2;
        }

        refresh();

        // Choice selection with arrow keys
        ch = wgetch(window);

        switch (ch) {
            case KEY_UP:
                if (highlight == 1)
                    highlight = 3;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight == 3)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 10: // Key Enter
                choice = highlight;
                break;
            default:
                break;
        }

        if (choice != 0) // Sort de la boucle si une option est sélectionnée
            break;
    }while(ch != 'q'); // Use 'q' to quit


    return ch == 'q' ? -1 : choice;
}