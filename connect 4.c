#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // sleep function.
#include <time.h>

typedef struct {
    char symbol;
    char color;
    int score;
    int moves ;
    char name[255];
}players;

players player_1 , player_2 ;


int width =16, height =6;
int flag ,counter = 0;
int turn = 0;
int turn2 = 0;
int start , end ;
int time_passed = 0 , time_min , time_sec;
void check_colum(int a[][width+3],int i,int j);
void check_row(int a[][width+3],int i,int j);
void check_diagonalr(int a[][width+3],int i,int j);
void check_diagonall(int a[][width+3],int i,int j);
void check_total(int a[][width],int i,int j);
void input(int a[][width+3],int arri[],int arrj[]);
void print(int a[][width+3]);
void gravity(int a[][width+3],char qqq[], int num1,int arri[],int arrj[]);
void main_menu(int a[][width+3],int arri[],int arrj[]);
void undo(int a[][width+3],int i[], int j[]);
void redo(int a[][width+3],int i[], int j[]);
void p_players(int qq);
void new_game(int a[][width+3]);
void details ();
int casting(char user_input[]);
void start_game(int a[][width]);

int main()
{
    strcpy(player_1.name,"Player 1");

    player_1.symbol = 'X';
    player_2.symbol = 'O';
    player_1.score=0;
    player_2.score=0;
    int a[height+3][width+3];
    int arri[width * height] ,arrj[width * height];
    start_game(a);
    printf("\033[0;35m");
    printf("\n\n\n\tHello To Connect 4...\n\n\n\t\tPLease Press Enter to start");
    printf("\033[0m");
    while(1){
        if(getch() == '\r'){
            system("cls");
            main_menu(a,arri,arrj);
        }
    }


}
void main_menu(int a[][width+3],int arri[],int arrj[]){
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
                input(a,arri,arrj);
            }
            exit(1);
            break;
        case 'l':
            system("cls");
            printf("Loading File ...\n");
            break;
        case 'q':
            system("cls");
            printf("\nQuit Game.....!\n");
            printf("\n\tYes 'y'\tNO 'n'\n");
            char sure = getch();
            if(sure == 'y'){
                printf("BYE.............!");
                exit(1);
            }
            else if(sure == 'n'){
                system("cls");
                main_menu(a,arri,arri);
            }
            break;
        default:
            system("cls");
            main_menu(a,arri,arrj);
            break;
    }
}

void input(int a[][width+3],int arri[],int arrj[]){
    int start = time(NULL);
    int qqq;
    char input1[255];
    p_players(turn%2+1);
    if(!(strcmp(player_2.name,"computer")) && turn%2 == 1){
        qqq = rand() % width ;
        while(!(qqq<= width && qqq > 0)){
            qqq = rand() % width;
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
        gravity(a,input1,qqq,arri,arrj);
    }


    system("cls");
    int end = time(NULL);
    time_passed+= end - start;
    time_min = time_passed / 60;
    time_sec = time_passed % 60;
    print(a);
}

void gravity(int a[][width+3],char qqq[], int num1,int arri[],int arrj[]){
    int arrscore1[width*height],arrscore2[width*height];
    char symbol[2] = {player_1.symbol , player_2.symbol};
    if(num1 <= width && num1 >= 0){
        for(int i =height-1; i>=0; i--){
            if(i == height-1 && a[i][num1-1] ==' '){           // first row at the bottom game.

                a[i][num1-1] = symbol[turn%2] ;
                arri[counter]=i;
                arrj[counter]=num1-1;

                check_total(a,i,num1-1);
                if(turn%2 == 0){player_1.moves++;}
                if(turn%2 == 1){player_2.moves++;}
                turn++;
                counter++;
                break;
            }
            else if ( a[i][num1-1] ==' ' && a[i+1][num1-1] !=' '){
                a[i][num1-1] = symbol[turn%2] ;
                arri[counter]=i;
                arrj[counter]=num1-1;
                check_total(a,i,num1-1);
                if(turn%2 == 0){player_1.moves++;}
                if(turn%2 == 1){player_2.moves++;}
                turn++;
                counter++;
                break;
            }
            else{
                if(i == 0)
                {
                    input(a,arri,arri);
                    printf("\nThis column is full!\n Try Another Place\n");
                }
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
            input(a,arri,arri);
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
            main_menu(a,arri,arrj);            
        }
        if(back == 'n'){
            system("cls");
            input(a,arri,arri);
        }

    }
    else if(!(strcmp(qqq,"s"))){
        system("cls");
        printf("\033[0;36m");
        printf("\tSaving Game.....\n");
        sleep(1);
        printf("\n\n\tGame Saved\n");
        sleep(1);
        printf("\033[0m");
        system("cls");
        print(a);
        input(a,arri,arri);
    }
    else if(!(strcmp(qqq,"u")) && counter < 0){
        undo(a,arri,arrj);
    }
    else if(!(strcmp(qqq,"d")) && counter < 0){
        redo(a,arri,arrj);
    }
}


void p_players(int qq){
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
void check_colum(int a[][width+3],int i,int j){
    if(a[i][j]==a[i+1][j]&&a[i+1][j]==a[i+2][j]&&a[i+2][j]==a[i+3][j]){
        if(a[i][j]==player_1.symbol){
             player_1.score++;
        }
        else if(a[i][j]==player_2.symbol){
             player_2.score++;
        }
    }
}
void check_row(int a[][width+3],int i,int j){
if(a[i][j]==a[i][j+1]&&a[i][j+1]==a[i][j+2]&&a[i][j+2]==a[i][j+3]){
   if(a[i][j]==player_1.symbol){
             player_1.score++;
        }
        else if(a[i][j]==player_2.symbol){
             player_2.score++;
        }
}
if(a[i][j]==a[i][j-1]&&a[i][j-1]==a[i][j-2]&&a[i][j-2]==a[i][j-3]){
     if(a[i][j]==player_1.symbol){
             player_1.score++;
        }
        else if(a[i][j]==player_2.symbol){
             player_2.score++;
        }
}
if(a[i][j]==a[i][j+1]&&a[i][j+1]==a[i][j+2]&&a[i][j]==a[i][j-1]){
     if(a[i][j]==player_1.symbol){
             player_1.score++;
        }
        else if(a[i][j]==player_2.symbol){
             player_2.score++;
        }
}
if(a[i][j]==a[i][j-1]&&a[i][j-1]==a[i][j-2]&&a[i][j]==a[i][j+1])
if(a[i][j]==player_1.symbol){
             player_1.score++;
        }
        else if(a[i][j]==player_2.symbol){
             player_2.score++;
        }
}

void check_diagonalr(int a[][width+3],int i,int j){
if(a[i][j]==a[i+1][j+1]&&a[i+1][j+1]==a[i+2][j+2]&&a[i+2][j+2]==a[i+3][j+3]){
   if(a[i][j]==player_1.symbol){
             player_1.score++;
        }
        else if(a[i][j]==player_2.symbol){
             player_2.score++;
        }
}
if(a[i][j]==a[i-1][j-1]&&a[i-1][j-1]==a[i-2][j-2]&&a[i-2][j-2]==a[i-3][j-3]){
     if(a[i][j]==player_1.symbol){
             player_1.score++;
        }
        else if(a[i][j]==player_2.symbol){
             player_2.score++;
        }
}
if(a[i][j]==a[i+1][j+1]&&a[i+1][j+1]==a[i+2][j+2]&&a[i-1][j-1]==a[i][j]){
     if(a[i][j]==player_1.symbol){
            player_1.score++;
        }
        else if(a[i][j]==player_2.symbol){
             player_2.score++;
        }
}
if(a[i][j]==a[i-1][j-1]&&a[i-1][j-1]==a[i-2][j-2]&&a[i][j]==a[i+1][j+1])
if(a[i][j]==player_1.symbol){
             player_1.score++;
        }
        else if(a[i][j]==player_2.symbol){
             player_2.score++;
        }
}


void check_diagnall(int a[][width+3],int i,int j){
if(a[i][j]==a[i-1][j+1]&&a[i-1][j+1]==a[i-2][j+2]&&a[i-2][j+2]==a[i-3][j+3]){
   if(a[i][j]==player_1.symbol){
             player_1.score++;
        }
        else if(a[i][j]==player_2.symbol){
            player_2.score++;
        }
}
if(a[i][j]==a[i+1][j-1]&&a[i+1][j-1]==a[i+2][j-2]&&a[i+2][j-2]==a[i+3][j-3]){
     if(a[i][j]==player_1.symbol){
             player_1.score++;
        }
        else if(a[i][j]==player_2.symbol){
            player_2.score++;
        }
}
if(a[i][j]==a[i-1][j+1]&&a[i][j]==a[i+1][j-1]&&a[i+1][j-1]==a[i+2][j-2]){
     if(a[i][j]==player_1.symbol){
             player_1.score++;
        }
        else if(a[i][j]==player_2.symbol){
            player_2.score++;
        }
}
if(a[i][j]==a[i+1][j-1]&&a[i][j]==a[i-1][j+1]&&a[i-1][j+1]==a[i-2][j+2])
if(a[i][j]==player_1.symbol){
             player_1.score++;
        }
        else if(a[i][j]==player_2.symbol){
            player_2.score++;
        }
}


void check_total(int a[][width+3],int i,int j){

    check_colum(a,i,j);
    check_row(a,i,j);
    check_diagonalr(a,i,j);
    check_diagnall(a,i,j);

}
void undo(int a[][width+3],int i[], int j[]){
    int h,k,y,z;
    h=i[counter-1];
    k=i[counter-2];
    y=j[counter-1];
    z=j[counter-2];
    if(!(strcmp(player_2.name,"Player 2"))){
        a[h][y]=' ';
        print(a);
        counter--;
        turn--;
        if(turn%2 == 0){player_1.moves--;}
        else if(turn%2 == 1){player_2.moves--;}}
    else if(!(strcmp(player_2.name,"computer"))){
        a[h][y]=' ';
        a[k][z]=' ';
        print(a);
        counter=counter-2;

        turn=turn-2;
        player_2.moves--;
        player_1.moves--;
    }
}
void redo(int a[][width+3],int i[], int j[]){
    int k,h,y,z;
    h=i[counter];
    k=i[counter+1];
    y=j[counter];
    z=j[counter+1];
    char symbol[2] = {player_1.symbol , player_2.symbol};
    if(!(strcmp(player_2.name,"Player 2"))){
        a[h][y]=symbol[turn%2];
        print(a);
        counter++;
        turn++;
        if(turn%2 == 1){player_1.moves++;}
        if(turn%2 == 0){player_2.moves++;}
    }
    else if(!(strcmp(player_2.name,"computer"))){
        a[h][y]=player_1.symbol;
        turn++;
        a[k][z]=player_2.symbol;
        counter=counter+2;
        turn++;
        player_1.moves++;
        player_2.moves++;
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
        switch(user_input[i]){
            case '0':
            qqq += 0;
            break;
            case '1':
            qqq += 1;
            break;
            case '2':
            qqq += 2;
            break;
            case '3':
            qqq+=3;
            break;
            case '4':
            qqq+=4;
            break;
            case '5':
            qqq+=5;
            break;
            case '6':
            qqq+=6;
            break;
            case '7':
            qqq+=7;
            break;
            case '8':
            qqq+=8;
            break;
            case '9':
            qqq+=9;
            break;
            default:
            qqq = -1;
            break;
        }
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

void save(){}
void load(){}
