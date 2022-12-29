#include "configuration.h"

void start_game(int a[][width+3]){
    player_1.moves = 0 ,player_1.score=0  , player_2.moves = 0 ,player_2.score=0;
    counter = 0 , bolean=0;
    time_passed = 0 , time_min = 0 , time_sec = 0;
    for(int i=0; i<height+3;i++){
        for(int j=0;j<width+3;j++){
            a[i][j] = ' ' ;
        }
    }
}
void new_game(int a[][width+3]){
    start_game(a);
    printf("\033[0;36m");
    printf("\nGame Mode:\n");
    printf("\n\t %cHuman VS Human 'Press H'\n",248);
    printf("\n\t %cHuman VS Computer 'Press C'\n",248);
    printf("\033[0m");
    switch(getch()){
        case 'h':
            strcpy(player_2.name , "Player 2");
            break;
        case 'c':
            strcpy(player_2.name , "computer");
            break;
        default:
            system("cls");
            new_game(a);
            break;
    }
}
