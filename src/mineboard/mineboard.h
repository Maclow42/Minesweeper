#pragma once

#include <stdbool.h>

typedef enum{
    MINE,
    NUMBER
} case_type_t;

typedef struct{
    case_type_t type;
    int number;
    bool is_revealed;
    bool is_flagged;
} case_t;


typedef struct{
    int nb_rows;
    int nb_cols;
    int nb_mines;
    int nb_flags_left;
    int nb_cases_revealed;
    case_t **board;
}gameboard_t;

gameboard_t *create_gameboard(int nb_rows, int nb_cols, int nb_mines);
void destroy_gameboard(gameboard_t *gb);

void get_gameboard_display(gameboard_t *gb, char** display);

case_type_t reveal_case(gameboard_t *gb, int row, int col);
void toogle_flag_case(gameboard_t *gb,  int row, int col);
