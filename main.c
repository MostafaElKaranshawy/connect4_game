#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // sleep function.
// #include "gravity.h"

int width , height ;
int flag ,counter = 0;
int turn = 0;
void input(int a[][width]);
void print(int a[][width]);
void gravity(int arr[][width],int f);

int main()
{   
    scanf("%d",&width);
    scanf("%d",&height);
    int a[height][width];
    for(int i=0; i<height;i++){
        for(int j=0;j<width;j++){
            a[i][j] = '0' ;
        }
    }

    while(counter < width * height){
        // sleep(1);
        input(a);
    }
    
}

void input(int a[][width]){

    if(kbhit()){
        system("cls");
        char q = getch();
        int l=q-'0';
        if(!(l<= width && l > 0)){
            printf("no place here\n");
            input(a);
        }
        else{
            gravity(a,l);
        }
        print(a);
    }
    
}

void gravity(int a[][width],int f){
    char symbol[2] = {'X' , 'Y'};
    for(int i =height-1; i>=0; i--){
        if(i == height-1 && a[i][f-1] =='0'){

            a[i][f-1] = symbol[turn%2] ;
            turn++;
            counter++;
            break;
        }
        else if ( a[i][f-1] =='0' && a[i+1][f-1] !='0'){
            a[i][f-1] = symbol[turn%2] ;
            turn++;
            counter++;
            break;
        }
        else{
            if (i == 0)
            {
                printf("No place here\n");
                input(a);
            }           
        }

    }
}

void print(int a[][width]){
    for(int i=0; i<height;i++){
        for(int j=0;j<width;j++){
            printf("%c ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}