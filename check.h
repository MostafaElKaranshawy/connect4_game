#include "load_save.h"

void check_colum(int a[][width+3],int i,int j);
void check_row(int a[][width+3],int i,int j);
void check_diagonalr(int a[][width+3],int i,int j);
void check_diagonall(int a[][width+3],int i,int j);
void check_total(int a[][width],int i,int j);

// check if the new move connects any new 4 disks ao the score increase or not.

// the new move column
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
// the new move row
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

// the new move right diagonal
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

// the new move left diagonal
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

// check all possibilities
void check_total(int a[][width+3],int i,int j){
    check_colum(a,i,j);
    check_row(a,i,j);
    check_diagonalr(a,i,j);
    check_diagnall(a,i,j);
}
