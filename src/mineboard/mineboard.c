#include "mineboard.h"

#include <stdlib.h>
#include <time.h>

void place_mines(gameboard_t *gb){
    srand(time(NULL));
    int nb_mines_placed = 0;
    while(nb_mines_placed < gb->nb_mines){
        int r = rand() % gb->nb_rows;
        int c = rand() % gb->nb_cols;
        if(gb->board[r][c].type == MINE)
            continue;
        gb->board[r][c].type = MINE;
        nb_mines_placed++;

        for(int i = r - 1; i <= r + 1; i++){
            for(int j = c - 1; j <= c + 1; j++){
                if(i >= 0 && i < gb->nb_rows && j >= 0 && j < gb->nb_cols && gb->board[i][j].type == NUMBER)
                    gb->board[i][j].number++;
            }
        }
    }
}

gameboard_t *create_gameboard(int nb_rows, int nb_cols, int nb_mines){
    if(nb_rows <= 0 || nb_cols <= 0 || nb_mines <= 0 || nb_mines >= nb_rows * nb_cols)
        return NULL;
    gameboard_t *gb = malloc(sizeof(gameboard_t));
    gb->nb_rows = nb_rows;
    gb->nb_cols = nb_cols;
    gb->nb_mines = nb_mines;
    gb->nb_flags_left = nb_mines;
    gb->nb_cases_revealed = 0;
    gb->board = malloc(nb_rows * sizeof(case_t*));
    for(int i = 0; i < nb_rows; i++){
        gb->board[i] = malloc(nb_cols * sizeof(case_t));
        for(int j = 0; j < nb_cols; j++){
            gb->board[i][j].type = NUMBER;
            gb->board[i][j].number = 0;
            gb->board[i][j].is_revealed = false;
            gb->board[i][j].is_flagged = false;
        }
    }
    place_mines(gb);
    return gb;
}

void destroy_gameboard(gameboard_t *gb){
    for(int i = 0; i < gb->nb_rows; i++){
        free(gb->board[i]);
    }
    free(gb->board);
    free(gb);
}

void get_gameboard_display(gameboard_t *gb, char** display){
    for(int i = 0; i < gb->nb_rows; i++){
        for(int j = 0; j < gb->nb_cols; j++){
            if(gb->board[i][j].is_revealed){
                if(gb->board[i][j].type == MINE)
                    display[i][j] = 'X';
                else
                    display[i][j] = gb->board[i][j].number > 0 ? '0' + gb->board[i][j].number : '.';
            }
            else if(gb->board[i][j].is_flagged)
                display[i][j] = 'F';
            else
                display[i][j] = 'o';
        }
    }
}

case_type_t reveal_case(gameboard_t *gb, int row, int col){
    if(gb->board[row][col].is_revealed)
        return gb->board[row][col].type;
    gb->board[row][col].is_revealed = true;
    gb->nb_cases_revealed++;
    if(gb->board[row][col].type == MINE)
        return MINE;
    if(gb->board[row][col].number != 0)
        return NUMBER;
    for(int i = row - 1; i <= row + 1; i++){
        for(int j = col - 1; j <= col + 1; j++){
            if(i >= 0 && i < gb->nb_rows && j >= 0 && j < gb->nb_cols){
                if(!gb->board[row][col].is_flagged)
                    reveal_case(gb, i, j);
            }
        }
    }
    return NUMBER;
}

void toogle_flag_case(gameboard_t *gb,  int row, int col){
    if(gb->board[row][col].is_revealed)
        return;
    if(gb->board[row][col].is_flagged)
        gb->nb_flags_left++;
    else
        gb->nb_flags_left--;
    gb->board[row][col].is_flagged = !gb->board[row][col].is_flagged;
    return;
}