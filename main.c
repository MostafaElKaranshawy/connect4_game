#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // sleep function.
#include <windows.h>

// void textcolor(int color){
//     static int __BACKGROUND;
//     HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE );
//     CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
//     GetConsoleScreenBufferInfo(h, &csbiInfo);
//     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), color + (__BACKGROUND << 4));
// }

typedef struct {
    char symbol;
    char color;
    int score;
    int moves;
}players;

players player_1 , player_2 , computer ;


int width =6, height =6;
int flag ,counter = 0;
int turn = 0;
int start = 1;
int turn2 = 0;


void input(int a[][width]);
void print(int a[][width]);
void gravity(int arr[][width],int f);
void main_menu(int a[][width]);
void p_players(int qq);


int main()
{   

    // players defining.
    player_1.symbol = 'X';
    player_1.color = 'Red';
    player_2.symbol = 'O';
    player_2.color = 'Blue';

    int a[height][width];
    for(int i=0; i<height;i++){
        for(int j=0;j<width;j++){
            a[i][j] = ' ' ;
        }
    }
    while(1){
        // if(kbhit())
        // while(getch() == '\n')
        main_menu(a);
    }
    // while(counter < width * height){
    //     // input(a);
    //     
    // }
    
}
void main_menu(int a[][width]){
    //while(!(kbhit() && getch() == '\r')){}//busy while
    //while((kbhit() && getch() == '\r')){}//busy while
    char ch = ' ';
    ch = getch();
    if(ch == '\r'){
        printf("Hello To Connect 4!\n");
        printf("\nMain Menu\n");
        printf("\nNew Game 'Press N' \n");
        printf("\nLoad Game 'Press L' \n");
        printf("\nQuit Game 'Press Q' \n");
    }
    fflush(stdin);
    // ch = ' ';
    // ch = getch();
    // if(kbhit()){
        switch(getch()){
            case 'n':
                system("cls");
                print(a);
                while(counter < width * height){
                    input(a);
                }
                exit(1);
                
                break;
            case 'l':
                printf("Loading File ...\n");
                break;
            case 'q':
                exit(1);
                break;
        }
    // }
}
void input(int a[][width]){

    if(kbhit()){
        system("cls");
        char q = getch();
        int l = q - '0';
        if(!(l<= width && l > 0)){
            
            input(a);
            printf("\n No Available Place Here!\n Try Another Place\n");
        }
        else{
            gravity(a,l);
        }
        print(a);
        p_players(turn%2+1);
        
    }
    
}

void gravity(int a[][width],int f){
    char symbol[2] = {player_1.symbol , player_2.symbol};
    for(int i =height-1; i>=0; i--){
        if(i == height-1 && a[i][f-1] ==' '){

            a[i][f-1] = symbol[turn%2] ;
            turn++;
            counter++;
            break;
        }
        else if ( a[i][f-1] ==' ' && a[i+1][f-1] !=' '){
            a[i][f-1] = symbol[turn%2] ;
            turn++;
            counter++;
            break;
        }
        else{
            if (i == 0)
            {
                input(a);
                printf("\nNo Available Place Here!\n Try Another Place\n");
            }           
        }
    }
}

void print(int a[][width]){
    printf("\n");
    for(int sss =1; sss<=width ; sss++){
        if(sss == 1){printf("| %d |",sss);}
        else
        printf(" %d |",sss);
    }
    printf("\n ");
    for(int s = 0 ;s<width ; s++){
        printf("----");   
    }
    

    printf("\n");
    for(int i=0; i<height;i++){
        for(int j=0;j<width;j++){
            if( a[i][j] == player_1.symbol){
                if(j == 0){
                    // printf("| %c | ",a[i][j]);
                    printf("| ");
                    printf("\033[0;31m%c\033[0m",a[i][j]);
                    printf(" | ");
                    
                }
                else{
                    // printf("%c | ",a[i][j]);
                    printf("\033[0;31m%c\033[0m",a[i][j]);
                    printf(" | ");
                }
            }
            else if( a[i][j] == player_2.symbol){
                if(j == 0){
                    // printf("| %c | ",a[i][j]);
                    printf("| ");
                    printf("\033[0;34m%c\033[0m",a[i][j]);
                    printf(" | ");
                    
                }
                else{
                    // printf("%c | ",a[i][j]);
                    printf("\033[0;34m%c\033[0m",a[i][j]);
                    printf(" | ");
                }
            }
            else{
                if(j == 0){
                    printf("| %c | ",a[i][j]);
                    
                }
                else{
                    printf("%c | ",a[i][j]);
                }
            }
            
        }
        printf("\n ");

        for(int s = 0 ;s<width ; s++){
            printf("----");
        }
        printf("\n");
    }

}

void p_players(int qq){
    printf("\nPlayer [%d] Turn!\n",qq);
}
