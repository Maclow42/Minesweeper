#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <ncurses.h>
#include <locale.h>


#include "./src/mineboard/mineboard.h"
#include "./src/UI/menu/menu.h"

int main(){
    setlocale(LC_ALL, ""); //Config environment for UTF-8

    //Init ncurses with some options
    initscr(); // Init ncurses
    curs_set(0); //Disable cursor
    start_color(); // Ability to use colors
    noecho(); // Disable caractere echo
    mousemask(BUTTON1_CLICKED, NULL); // Enable mouse click detection

    //Init ncurses windows
    WINDOW *boite = newwin(0, 0, 0, 0);
    keypad(boite, TRUE); // Enable keypad special keys detection

    // Vérifie la prise en charge des couleurs
    if (!has_colors()) {
        endwin();
        printf("Your terminal does not support colors display.\n");
        return 1;
    }

    while(1){
        int nb_player = display_menu(boite);
        if(nb_player == -1)
            break;
    }

    endwin(); // Quit ncurses



    return 0;
}

int main2(){
    
    gameboard_t *gb = create_gameboard(10, 10, 1);

    if(!gb){
        printf("Error creating gameboard\n");
        return 1;
    }

    char **display = malloc(gb->nb_rows * sizeof(char*));
    for(int i = 0; i < gb->nb_rows; i++)
        display[i] = malloc(gb->nb_cols * sizeof(char));

    // get input from user and reveal case
    char mode;
    int row, col;
    bool game_over = false;
    while(!game_over){
        get_gameboard_display(gb, display);
        // printf display
        printf("\n");
        for(int i = 0; i < gb->nb_rows; i++){
            for(int j = 0; j < gb->nb_cols; j++)
                printf("%c ", display[i][j]);
            printf("\n");
        }
        printf("Cases revealed: %d\n", gb->nb_cases_revealed);
        printf("test: %d\n", gb->nb_cols * gb->nb_rows - gb->nb_mines);
        printf("Flags left: %d\n", gb->nb_flags_left);


        printf("Enter row and col: ");
        scanf("%c %d %d", &mode, &row, &col);
        if(mode != 'r' && mode != 'f'){
            printf("Invalid mode\n");
            continue;
        }
        if(row < 0 || row >= gb->nb_rows || col < 0 || col >= gb->nb_cols){
            printf("Invalid row or col\n");
            continue;
        }

        if(mode == 'r'){
            switch(reveal_case(gb, col, row)){
                case MINE:
                    printf("You lost\n");
                    game_over = true;
                    break;
                case NUMBER:
                    printf("You revealed a number\n");
                    break;
                default:
                    printf("You revealed an empty case\n");
                    break;
            }
        }else{
            toogle_flag_case(gb, col, row);
            printf("You toggled a flag\n");
        }


        if(gb->nb_cases_revealed == gb->nb_rows * gb->nb_cols - gb->nb_mines && gb->nb_flags_left == 0){
            printf("You won\n");
            game_over = true;
            break;
        }
    }


    get_gameboard_display(gb, display);
    // printf display
    for(int i = 0; i < gb->nb_rows; i++){
        for(int j = 0; j < gb->nb_cols; j++)
            printf("%c ", display[i][j]);
        printf("\n");
    }

    return 0;
}