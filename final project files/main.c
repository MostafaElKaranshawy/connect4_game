#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // sleep function.
#include <time.h>

#include "check.h"

int base=0;
int max=0;
int time_passed = 0 , time_min , time_sec;


void input(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]);
void gravity(int a[][width+3],char qqq[], int num1,int arri[],int arrj[],int scoret[],int score2[]);
void main_menu(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]);
void player_turn(int qq);
void new_game(int a[][width+3]);
void details ();
int casting(char user_input[]);
void start_game(int a[][width]);
void winner(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]);
int max_counter(int c);
int load_game();

int main()
{
    strcpy(player_1.name,"Player 1");
    player_1.symbol = 'X';
    player_2.symbol = 'O';
    player_1.score=0;
    player_2.score=0;
    int a[height+3][width+3];
    int arri[width * height] ,arrj[width * height],Scoret[width*height],score2[width*height];
    start_game(a);
    printf("\033[0;35m");
    printf("\n\n\n\tHello To Connect 4...\n\n\n\t\tPLease Press Enter to start");
    printf("\033[0m");
    while(1){
        if(getch() == '\r'){
            system("cls");
            main_menu(a,arri,arrj,Scoret,score2);
        }
    }
}
void main_menu(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]){
    printf("\033[0;36m");
    printf("\nMain Menu\n");
    printf("\n\tNew Game 'Press N' \n");
    printf("\n\tTop Players 'Press T'\n");
    printf("\n\tLoad Game 'Press L' \n");
    printf("\n\tQuit Game 'Press Q' \n");
    printf("\033[0m");
    fflush(stdin);
    switch(getch()){
        case 'n':
            system("cls");
            new_game(a);
            system("cls");
            print(a);
            while(counter < width * height){
                input(a,arri,arrj,scoret,score2);
            }
            winner(a,arri,arrj,scoret,score2);
            sleep(10);

            exit(1);
            break;
        case 'l':
            system("cls");
            printf("Loading File ...\n");
            sleep(1);
            system("cls");
            // load(a,arri,arrj,scoret,score2);
            counter=turn;
            base=turn;
            printf("%d",counter);
            bolean=0;
            while(counter < width * height){
                input(a,arri,arrj,scoret,score2);
            }
             winner(a,arri,arrj,scoret,score2);
             exit(5);
            break;
        case 'q':
            system("cls");
            printf("\033[0;36m");
            printf("\nQuit Game.....!\n");
            printf("\n\tYes 'y'\tNO 'n'\n");
            printf("\033[0m");
            char sure = getch();
            if(sure == 'y'){
                printf("BYE.............!");
                exit(1);
            }
            else if(sure == 'n'){
                system("cls");
                main_menu(a,arri,arri,scoret,score2);
            }
            break;
        default:
             system("cls");
            printf("EROR MESSAGE !");
            main_menu(a,arri,arrj,scoret,score2);

            break;
    }
}

void input(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]){
    int start = time(NULL);
    int qqq;
    char input1[255];
    player_turn(turn%2+1);
    if(!(strcmp(player_2.name,"computer")) && turn%2 == 1){
            //srand fn please
            srand(time(NULL));
        qqq = rand() % (width+1) ;
        while(!(qqq<= width && qqq > 0)){
            qqq = rand() % (width+1);
        }
        sleep(1);
    }
    else if(!(strcmp(player_2.name,"computer")) && turn%2 == 0){
        printf("\nEnter your move: ");
        scanf("%s", &input1);
        printf("\n");
        qqq= casting(input1);
    }
    else if(!(strcmp(player_2.name,"Player 2"))){
        printf("\nEnter your move: ");
        scanf("%s", &input1);
        printf("\n");
        qqq= casting(input1);
    }

    if(!(strcmp(input1,"q")) ||!(strcmp(input1,"m")) || !(strcmp(input1,"s")) || !(strcmp(input1,"u"))||!(strcmp(input1,"d")) || (qqq <= width && qqq >= 0)){
        gravity(a,input1,qqq,arri,arrj,scoret,score2);
    }


    system("cls");
    int end = time(NULL);
    time_passed+= end - start;
    time_min = time_passed / 60;
    time_sec = time_passed % 60;
    print(a);
}

void gravity(int a[][width+3],char qqq[], int num1,int arri[],int arrj[],int scoret[],int score2[]){
    int arrscore1[width*height],arrscore2[width*height];
    char symbol[2] = {player_1.symbol , player_2.symbol};
    if(num1 <= width && num1 > 0){

        for(int i =height-1; i>=0; i--){
            if(i == height-1 && a[i][num1-1] ==' '){           // first row at the bottom game.

                a[i][num1-1] = symbol[turn%2] ;
                arri[counter]=i;
                arrj[counter]=num1-1;
                bolean=0;
                check_total(a,i,num1-1);
            scoret[counter]=player_1.score;
                score2[counter]=player_2.score;
                if(turn%2 == 0){player_1.moves++;}
                else if(turn%2 == 1){player_2.moves++;}
                turn++;
                counter++;
                max=max_counter(counter);
                break;
            }
            else if ( a[i][num1-1] ==' ' && a[i+1][num1-1] !=' '){
                a[i][num1-1] = symbol[turn%2] ;
                arri[counter]=i;
                arrj[counter]=num1-1;
                check_total(a,i,num1-1);
                scoret[counter]=player_1.score;
                 bolean=0;
               score2[counter]=player_2.score;
                if(turn%2 == 0){player_1.moves++;}
                if(turn%2 == 1){player_2.moves++;}
                turn++;
                counter++;
                max=max_counter(counter);
                break;
            }
            else if(i == 0){
                system("cls");
                print(a);
                printf("\nNot available move!\n Try Another Place\n");
                input(a,arri,arrj,scoret,score2);
                break;
            }
        }
    }
    else if(!(strcmp(qqq,"q"))){
        system("cls");
        printf("\033[0;36m");
        printf("\n\n\nQuit Game.....!\n\n\n");
        printf("\t\tYes 'y'\t\tNO 'n'\n");
        printf("\033[0m");
        char sure = getch();
        if(sure == 'y'){
            system("cls");
            printf("\n\n\n\n\033[0;35mBYE.............!\033[0m");
            exit(1);
        }
        else if(sure == 'n'){
            system("cls");
            print(a);
            input(a,arri,arrj,scoret,score2);
        }
    }
    else if(!(strcmp(qqq,"m"))){
        system("cls");
        printf("\033[0;36m");
        printf("\n\n\nReurn to main menu ?\n\n\n\tYes 'y'\t\tNO 'n'\n");
        printf("\033[0m");
        char back = getch();
        if(back == 'y'){
            printf("\033[0;36m");
            printf("\n\n\nreturning to main menu.....\n\n\n");
            sleep(1);
            printf("\033[0m");
            system("cls");
            main_menu(a,arri,arrj,scoret,score2);
        }
        if(back == 'n'){
            system("cls");
            print(a);
            input(a,arri,arrj,scoret,score2);
        }

    }
    else if(!(strcmp(qqq,"s"))){
        system("cls");
        printf("\033[0;36m");
        printf("\tSaving Game.....\n");
        // save(a);
        sleep(1);
        printf("\n\n\tGame Saved\n");
        sleep(1);
        printf("\033[0m");
        system("cls");
        print(a);
        input(a,arri,arrj,scoret,score2);
    }
    else if(!(strcmp(qqq,"u")) && counter > base){
        undo(a,arri,arrj,scoret,score2);
    }
    else if(!(strcmp(qqq,"d")) &&counter <max&&bolean){
        redo(a,arri,arrj,scoret,score2);
    }
}


void player_turn(int qq){
    if(!(strcmp(player_2.name , "computer"))){
        if(qq == 2){
            printf("\n\n\t\t\t\033[034mComputer Turn!\033[0m\n\n");
            // player_1.moves++;
        }
        else if( qq == 1){
            printf("\n\n\033[0;31mPlayer [1] Turn!\033[0m\n\n");
            // player_2.moves++;
        }
    }
    else{
        if(qq %2 == 1){
            printf("\n\n\033[0;31mPlayer [1] Turn!\033[0m\n\n");
        }
        else if(qq %2 == 0){
            printf("\n\n\t\t\t\033[0;34mPlayer [2] Turn!\033[0m\n\n");
        }
    }
}

void start_game(int a[][width+3]){
    player_1.moves = 0 ;
    player_2.moves = 0 ;
    player_1.score=0;
    player_2.score=0;
    counter = 0;
    time_passed = 0;
    time_min = 0;
    time_sec = 0;
    bolean=0;
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
    printf("\n\t Human VS Human 'Press H'\n");
    printf("\n\t Human VS Computer 'Press C'\n");
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


void details (){
    printf("\033[0;36m");
    printf("Press 'u' for Undo\nPress 'd' for Redo\n");
    printf("Press 'm' to back to Main Menu\n");
    printf("Press 's' to save the game\n");
    printf("Press 'q' to Quit the game\n");
    printf("\033[0m");
    printf("\n");
    printf("\033[0;31mPlayer 1 Moves: %d\033[0m\t\033[0;34m%s Moves: %d\033[0m\n",player_1.moves,player_2.name, player_2.moves);
    printf("\n\033[0;31mplayer 1 score: %d\033[0m\t\033[0;34m%s score: %d\033[0m\n ",player_1.score,player_2.name,player_2.score);
}
int casting(char user_input[]){
    int qqq =0;
    int len = strlen(user_input);
    for(int i=0; i<len; i++){
        qqq*=10;
        qqq+=user_input[i] - '0';
    }
    return qqq;
}
void print(int a[][width+3]){
    printf("\n\033[0;32mTime Passed is 00:%.2d:%.2d\033[0m\n",time_min , time_sec);

    printf("\n ");
    for(int s = 0 ;s<width ; s++){
        printf("\033[0;33m----\033[0m");
    }


    printf("\n");
    for(int i=0; i<height;i++){
        for(int j=0;j<width;j++){
            if( a[i][j] == player_1.symbol){
                if(j == 0){
                    // printf("| %c | ",a[i][j]);
                    printf("\033[0;33m| \033[0m");
                    printf("\033[0;31m%c\033[0m",a[i][j]);
                    printf("\033[0;33m\033[0;33m | \033[0m");

                }
                else{
                    // printf("%c | ",a[i][j]);
                    printf("\033[0;31m%c\033[0m",a[i][j]);
                    printf("\033[0;33m | \033[0m");
                }
            }
            else if( a[i][j] == player_2.symbol){
                if(j == 0){
                    // printf("| %c | ",a[i][j]);
                    printf("\033[0;33m| \033[0;33m\033[0m");
                    printf("\033[0;34m%c\033[0m",a[i][j]);
                    printf("\033[0;33m | \033[0m");

                }
                else{
                    // printf("%c | ",a[i][j]);
                    printf("\033[0;34m%c\033[0m",a[i][j]);
                    printf("\033[0;33m | \033[0m");
                }
            }
            else{
                if(j == 0){
                    printf("\033[0;33m|\033[0m %c \033[0;33m| \033[0m",a[i][j]);

                }
                else{
                    printf("%c \033[0;33m| \033[0m",a[i][j]);
                }
            }

        }
        printf("\n ");

        for(int s = 0 ;s<width ; s++){
            printf("\033[0;33m----\033[0m");
        }
        printf("\n");
    }
    details ();
}
void winner(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]){
    char winner_player[255];
    if (player_1.score > player_2.score)
    {
        printf("\n\033[0;31mPlayer 1 \033[0m,\033[0;36m\tYou are the WINNER \n\tPLease enter your name :  ");
        scanf("%s",winner_player);
        printf("\t\t\n\n%s is the winner !!\n\n", winner_player);
        printf("\n\n\t\tCongratulations %s...!!!%c" ,winner_player ,7);
        printf("\033[0m");
    }
    else if(player_2.score > player_1.score)
    {
        if((strcmp(player_2.name,"computer"))){
            printf("\n\033[0;34mPlayer 2 \033[0m,\033[0;36m\tYou are the WINNER \n\tPLease enter your name :  ");
            scanf("%s",winner_player);
            printf("\t\t\n\n%s is the winner !!\n\n", winner_player);
            printf("\n\n\t\tCongratulations %s...!!!%c" ,winner_player ,7);
            printf("\033[0m");
        }
        else{
            printf("Computer is the winner ..!!!");
            printf("\nGame Over !");
        }

    }
    else if (player_2.score == player_1.score){
        printf("\nIT'S DRAW !!!");
        printf("\n\nCongratulations to both players.......!");
    }
    printf("\n\nReturn to main menu 'm' or exit 'q'");
    switch(getch()){
        case 'm':
            system("cls");
            printf("\nReturning to main menu....");
            sleep(1);
            system("cls");
            main_menu(a,arri,arrj,scoret,score2);
            break;
        case 'q':
            system("cls");
            printf("Exiting the game .....");
            sleep(1);
            exit(4);
    }
}
int max_counter(int c){

    if(c>max){
        max=c;
    }
    return(max);
}
