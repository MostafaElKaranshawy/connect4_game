#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // sleep function.
//handle score in the undo, redo

typedef struct {
    char symbol;
    char color;
    int score;
    int moves ;
    char name[255];
}players;

players player_1 , player_2 ;


int width =6, height =6;
int flag ,counter = 0;
int turn = 0;
int start = 1;
int turn2 = 0;

void check_colum(int a[][width+3],int i,int j);
void check_row(int a[][width+3],int i,int j);
void check_diagonalr(int a[][width+3],int i,int j);
void check_diagonall(int a[][width+3],int i,int j);
void check_total(int a[][width],int i,int j);
void input(int a[][width+3],int arri[],int arrj[]);
void print(int a[][width+3]);
void gravity(int a[][width+3],char qqq,int arri[],int arrj[],int human);
void main_menu(int a[][width+3],int arri[],int arrj[]);
void undo(int a[][width+3],int i[], int j[]);
void redo(int a[][width+3],int i[], int j[]);
void p_players(int qq);
void new_game();

int main()
{

    strcpy(player_1.name,"Player 1");
    player_1.moves = 0 ;
    player_2.moves = 0 ;
    player_1.symbol = 'X';
    // player_1.color = 'Red';
    player_2.symbol = 'O';
    // player_2.color = 'Blue';
    player_1.score=0;
    player_2.score=0;

    int a[height+3][width+3];
    int arri[width*height],arrj[width*height];
    for(int i=0; i<height+3;i++){
        for(int j=0;j<width+3;j++){
            a[i][j] = ' ' ;
        }
    }
    while(1){
        main_menu(a,arri,arrj);
    }


}
void main_menu(int a[][width+3],int arri[],int arrj[]){

    if(getch() == '\r'){
        printf("Hello To Connect 4!\n");
        printf("\nMain Menu\n");
        printf("\nNew Game 'Press N' \n");
        printf("\nLoad Game 'Press L' \n");
        printf("\nQuit Game 'Press Q' \n");
    }
    fflush(stdin);
    switch(getch()){
        case 'n':
            system("cls");
            new_game();
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
            printf("Closing the Game....\nBye...!\n");
            exit(1);
            break;
            //default here plz
    }
}

void input(int a[][width+3],int arri[],int arrj[]){
    // print(a);
    int human=1;
    printf("Player 1 Moves: %d\t%s Moves: %d\n",player_1.moves,player_2.name, player_2.moves);
    printf("================================================================\n");
    printf("\nplayer 1 score: %d\tplayer 2 score: %d\n ",player_1.score,player_2.score);
    char l;
    int qqq;
    p_players(turn%2+1);
    if(!(strcmp(player_2.name,"computer")) && turn%2 == 1){
        qqq = rand() % width ;
        human=0;
        while(!(qqq<= width && qqq > 0)){
            qqq = rand() % width;
        }
        l=qqq+'0';
        sleep(1);
    }
    else if(!(strcmp(player_2.name,"computer")) && turn%2 == 0){
        printf("\nEnter your move: ");
        scanf("%c", &l);
        printf("\n");
        qqq=l-'0';
    }
    else if(!(strcmp(player_2.name,"Player 2"))){
        printf("\nEnter your move: ");
        scanf("%c", &l);
        printf("\n");
        qqq=l-'0';
    }
    if(l=='u'||l=='d'){
        gravity(a,l,arri,arrj,human);
    }

   else if(!(qqq<= width && qqq > 0)){
        system("cls");
        printf("\n No Available Place Here!\n Try Another Place\n");
        print(a);
        input(a,arri,arrj);
    }
    else{
        gravity(a,l,arri,arrj,human);
    }
    system("cls");
    print(a);
    // p_players(turn%2+1);

}

void gravity(int a[][width+3],char qqq,int arri[],int arrj[],int human){
    int f=qqq-'0';
    int arrscore1[width*height],arrscore2[width*height];
    char symbol[2] = {player_1.symbol , player_2.symbol};
    if(qqq!='u'&&qqq!='d'){
    for(int i =height-1; i>=0; i--){
        if(i == height-1 && a[i][f-1] ==' '){           // first row at the bottom game.

            a[i][f-1] = symbol[turn%2] ;
            arri[counter]=i;
            arrj[counter]=f-1;


             //arrscore1[counter]=0;
           // arrscore2[counter]=0;
             check_total(a,i,f-1);
            if(turn%2 == 0){player_1.moves++;}
            if(turn%2 == 1){player_2.moves++;}
            turn++;
            counter++;
            break;
        }
        else if ( a[i][f-1] ==' ' && a[i+1][f-1] !=' '){
            a[i][f-1] = symbol[turn%2] ;
            arri[counter]=i;
            arrj[counter]=f-1;
    //         arrscore1[counter]=0;
      //      arrscore2[counter]=0;
        //    arrscore1[counter]=player_1.score;
          //  arrscore2[counter]=player_2.score;
            check_total(a,i,f-1);
            if(turn%2 == 0){player_1.moves++;}
            if(turn%2 == 1){player_2.moves++;}
            turn++;
            counter++;
            break;
        }
        else {
            if (i == 0)
            {
                input(a,arri,arri);
                printf("\nNo Available Place Here!\n Try Another Place\n");
            }
        }
    }}
    else if(qqq=='u'){

    undo(a,arri,arrj);
    }
else if(qqq=='d'){
     /*   int x;
    x=arri[counter];
            int d;
            d=arrj[counter];*/
        redo(a,arri,arrj);
}
}

void print(int a[][width+3]){
    printf("\n");
    // for(int sss =1; sss<=width ; sss++){
        // if(sss == 1){printf("%d ",sss);}
        // else
        // printf(" %d ",sss);
    // }
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
    printf("PRESS 'U' FOR <-  || PRESS 'D' FOR ->\n");

}

void p_players(int qq){
    if(!(strcmp(player_2.name , "computer"))){
        if(qq == 2){
            printf("\n\nComputer Turn!\n\n");
            // player_1.moves++;
        }
        else if( qq == 1){
            printf("\n\nPlayer [1] Turn!\n\n");
            // player_2.moves++;
        }
    }
    else{
        printf("\n\nPlayer [%d] Turn!\n\n",qq);
        // if(qq == 1){player_2.moves++;}
        // else if(qq == 2){player_1.moves++;}
    }

}

void new_game(){
    printf("\nGame Mode:\n");
    printf("\n\t Human VS Human 'Press H'\n");
    printf("\n\t Human VS Computer 'Press C'\n");
    switch(getch()){
        case 'h':
            strcpy(player_2.name , "Player 2");
            break;
        case 'c':
            strcpy(player_2.name , "computer");
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
void save(){}
void load(){}
