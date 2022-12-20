#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // sleep function.


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

void check(int a[][width],int height){
    char k1,k2;
    int count=0;
    k1 = 'X';
    k2 = 'Y';
    int p1=1,p2=0;

    //for loop for all rows with fixing i 
    for(int j =height-1; j>=0; j--){
        int i=0;
        while(i<width){
            for(int h = 0; h <2;h++){
                printf("score[%d] is %d ",h+1,score[h]);
            }
            if(p1){
                
                if(a[j][i]==k1){
                    count++;
                    if(count==4){
                        score[0]++;
                        count=0;
                    }
                    i++;
                }   
                else{
                    count=0;
                    p1=0;
                    p2=1;
                }
            }
            if(p2){
            
                if(a[j][i]==k2){
                    count++;
                    if(count==4){
                        score[1]++;
                        count=0;
                    }
                    i++;
                }   
                else{
                    count=0;
                    p1=1;
                    p2=0;
                } 
            }
        }
    }
}