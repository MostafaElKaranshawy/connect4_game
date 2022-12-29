// libraries
#include <conio.h>
#include <unistd.h>
#include <time.h>

// header Files
#include "check.h"

// Globbal Variables
int max=0;

// declaration of Functions
void input(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]);
void gravity(int a[][width+3],char qqq[], int num1,int arri[],int arrj[],int scoret[],int score2[]);
void player_turn(int qq);
void new_game(int a[][width+3]);
void details ();
void start_game(int a[][width]);
void winner(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]);
int max_counter(int c);

// Main Function
int main()
{
    configuration_func();
    system("cls");
    strcpy(player_1.name,"Player 1");
    player_1.symbol = 'X';
    player_2.symbol = 'O';
    player_1.score=0;
    player_2.score=0;
    int a[height+3][width+3];
    int arri[width * height] ,arrj[width * height],Scoret[width*height],score2[width*height];
    start_game(a);
    printf("\033[0;35m");
    printf("\n\n\n\tHello To Connect 4...\n\n\n\t\t%cPLease Press Enter to start",251);
    printf("\033[0m");
    while(1){
        if(getch() == '\r'){
            system("cls");
            main_menu(a,arri,arrj,Scoret,score2);
        }
    }
}
// main menu function for choosing mode of playing.
void main_menu(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]){
    printf("\033[0;36m");
    printf("\nMain Menu\n");
    printf("\n\t%cNew Game 'Press N' \n",248);
    printf("\n\t%cTop Players 'Press T'\n",248);
    printf("\n\t%cLoad Game 'Press L' \n",248);
    printf("\n\t%cQuit Game 'Press Q' \n",248);
    printf("\033[0m");
    fflush(stdin);
    switch(getch()){
        case 'n':
        case 'N':
            system("cls");
            new_game(a);
            system("cls");
            print(a);
            while(counter < width * height){
                input(a,arri,arrj,scoret,score2);
            }
            winner(a,arri,arrj,scoret,score2);

            exit(1);
            break;
        case 'l':
        case 'L':
            system("cls");
            printf("Loading File ...\n");
            sleep(1);
            system("cls");
            load(a,arri,arrj,scoret,score2);
            counter=turn;
            base=turn;
            bolean=0;
            while(counter < width * height){
                input(a,arri,arrj,scoret,score2);
            }
            winner(a,arri,arrj,scoret,score2);
            exit(5);
            break;
        case 'q':
        case 'Q':
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
        case 't':
        case 'T':
            system("cls");
            print_scores(configuration_elements.highscores);
            printf("\nPress any key to return to main menu...\n");
            if( getch()){
                system("cls");
                main_menu(a,arri,arri,scoret,score2);
            }
            break;
        default:
            system("cls");
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
        srand(time(NULL));
        qqq = rand() % (width+1) ;
        while(!(qqq<= width && qqq > 0)){
            qqq = rand() % (width+1);
        }
        sleep(1);
    }
    else if(!(strcmp(player_2.name,"Player 2")) || (!(strcmp(player_2.name,"computer")) && turn%2 == 0)){
        printf("\nEnter your move: ");
        gets(input1);
        printf("\n");
        qqq= casting(input1);
    }

    if(!(strcmp(input1,"q")) ||!(strcmp(input1,"m")) || !(strcmp(input1,"s")) || !(strcmp(input1,"u"))||!(strcmp(input1,"d")) || (qqq <= width && qqq >= 0)){
        gravity(a,input1,qqq,arri,arrj,scoret,score2);
    }
    else{
        system("cls");
        print(a);
        printf("\nTry another input ..!\n");
        input(a,arri,arrj,scoret,score2);
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
            if (( a[i][num1-1] ==' ' && a[i+1][num1-1] !=' ') || (i == height-1 && a[i][num1-1] ==' ')){
                a[i][num1-1] = symbol[turn%2] ;
                arri[counter]=i;
                arrj[counter]=num1-1;
                check_total(a,i,num1-1);
                scoret[counter]=player_1.score;
                bolean=0;
                score2[counter]=player_2.score;
                if(turn%2 == 0){player_1.moves++;}
                else if(turn%2 == 1){player_2.moves++;}
                turn++;
                counter++;
                max=max_counter(counter);
                break;
            }
            else if(i == 0){
                system("cls");
                print(a);
                if(strcmp(player_2.name,"computer")){printf("\nNot available move!\n Try Another Place\n");}
                if(!strcmp(player_2.name,"computer") && turn%2 == 0){printf("\nNot available move!\n Try Another Place\n");}
                input(a,arri,arrj,scoret,score2);
                break;
            }
        }
    }
    else if(!(strcmp(qqq,"q"))){
        system("cls");
        printf("\033[0;36m\n\n\nQuit Game.....!\n\n\n\t%cYes 'y'\t\t%cNO 'n'\n\033[0m",248,248);
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
        printf("\033[0;36m\n\n\nReurn to main menu ?\n\n\n\t%cYes 'y'\t\t%cNO 'n'\n\033[0m",248,248);
        char back = getch();
        if(back == 'y'){
            printf("\033[0;36m\n\n\nreturning to main menu.....\n\n\n\033[0m");
            sleep(1);
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
        printf("\033[0;36m\tSaving Game.....\n");
        save(a);
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
        }
        else if( qq == 1){
            printf("\n\n\033[0;31mPlayer [1] Turn!\033[0m\n\n");
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

void details (){
    printf("\033[0;36m");
    printf("%cPress 'u' for Undo\n%cPress 'd' for Redo\n",248,248);
    printf("%cPress 'm' to back to Main Menu\n",248);
    printf("%cPress 'q' to Quit the game\n",248);
    printf("\033[0m");
    printf("\n");
    printf("\033[0;31mPlayer 1 Moves: %d\033[0m\t\033[0;34m%s Moves: %d\033[0m\n",player_1.moves,player_2.name, player_2.moves);
    printf("\n\033[0;31mplayer 1 score: %d\033[0m\t\033[0;34m%s score: %d\033[0m\n ",player_1.score,player_2.name,player_2.score);
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
    int winner_points ;
    if ((player_1.score > player_2.score) || (player_2.score > player_1.score) && (strcmp(player_2.name,"computer")))
    {
        if (player_1.score > player_2.score){
        winner_points = player_1.score;
        printf("\n\033[0;31mPlayer 1 \033[0m,\033[0;36mYou are the WINNER \n\tPLease enter your name :  ");
        }
        else if(player_2.score > player_1.score ){
            winner_points = player_2.score;
            printf("\n\033[0;34mPlayer 2 \033[0m,\033[0;36mYou are the WINNER \n\tPLease enter your name :  ");
        }
        scanf("%s",winner_player);
        printf("\n\n %s is the winner !!\n\n", winner_player);
        printf("\n\n Congratulations %s...!!!%c" ,winner_player ,7);
        printf("\033[0m");
        toprankk(winner_player, winner_points);
    }
    else if(player_2.score > player_1.score && !(strcmp(player_2.name,"computer"))){
        printf("\nComputer is the winner ..!!!");
        printf("\nGame Over !");
    }
    else if (player_2.score == player_1.score){
        printf("\nIT'S DRAW !!!");
        printf("\n\nCongratulations to both players.......!");
    }
    print_scores(configuration_elements.highscores);
    printf("\n\nReturn to main menu 'm' or exit 'q'\n");
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
