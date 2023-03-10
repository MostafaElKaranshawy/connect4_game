#include "players_struct.h"
#include "top_scores.h"

typedef struct{
    int a1[2000][2000];
    int counting;
    int seconds;
    int score[2];
    int moves[2];
    char name[20];
    int countep;

}save_game;
save_game savess;

int base=0;
void print(int a[][width+3]);
void undo(int a[][width+3],int i[], int j[],int scoret[],int score2[]){
    int h,k,y,z;
    h=i[counter-1];
    k=i[counter-2];
    y=j[counter-1];
    z=j[counter-2];
    if(!(strcmp(player_2.name,"Player 2"))){
        a[h][y]=' ';
        if(turn%2 == 1){player_1.score=scoret[counter-2];
            if(counter==base||counter==base+1){
                player_1.score=savess.score[0];
            }
        }
        if(turn%2==0){
            player_2.score=score2[counter-2];
            if(counter==base||counter==base+1){
                player_2.score=savess.score[1];
            }
        }
            print(a);
            counter--;
            turn--;
            if(turn%2 == 0){player_1.moves--;}
            else if(turn%2 == 1){player_2.moves--;}

        }
    else if(!(strcmp(player_2.name,"computer"))){
        a[h][y]=' ';
        a[k][z]=' ';
        print(a);
        player_1.score=scoret[counter-3];
        player_2.score=score2[counter-2];
        if(counter<=3+base){
            player_1.score=0;
            player_2.score=0;
        }
        counter=counter-2;
        turn=turn-2;
        player_2.moves--;
        player_1.moves--;
    }
    bolean=1;
}

void redo(int a[][width+3],int i[], int j[],int scoret[],int score2[]){
    int k,h,y,z;
    h=i[counter];
    k=i[counter+1];
    y=j[counter];
    z=j[counter+1];
    char symbol[2] = {player_1.symbol , player_2.symbol};
    if(!(strcmp(player_2.name,"Player 2"))){
        a[h][y]=symbol[turn%2];
        print(a);
        player_1.score=scoret[counter];
        player_2.score=score2[counter];
        counter++;
        turn++;
        if(turn%2 == 1){player_1.moves++;}
        if(turn%2 == 0){player_2.moves++;}
    }
    else if(!(strcmp(player_2.name,"computer"))){
        a[h][y]=player_1.symbol;
        turn++;
        a[k][z]=player_2.symbol;
        player_1.score=scoret[counter+1];
        player_2.score=score2[counter+1];
        counter=counter+2;
        turn++;
        player_1.moves++;
        player_2.moves++;
    }
}