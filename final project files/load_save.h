#include "undo.h"
void main_menu(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]);
void save(int a[][width+3]);
void load(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]);
int load_game();

void save(int a[][width+3]){
    FILE *fb;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
        savess.a1[i][j]=a[i][j];}
    }
    savess.moves[0]=player_1.moves;
    savess.moves[1]=player_2.moves;
    savess.score[0]=player_1.score;
    savess.score[1]=player_2.score;
    strcpy(savess.name,player_2.name);
    savess.counting=counter;
    fb=fopen("savinggame","ab");
    fwrite(&savess,sizeof(savess),1,fb);
    fclose(fb);
}
void load(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]){
    system("cls");
    int qq = load_game();
    FILE *fb;
    int e;
    e=sizeof(savess);
    e=-(qq*e-e);
    if((fb=fopen("savinggame","rb"))==NULL){
        printf("can't open this file\n");
        sleep(1);
        system("cls");
        main_menu(a,arri,arrj,scoret,score2);
    }
    fseek(fb, e, SEEK_END);
    fread(&savess,sizeof(savess),1,fb);
    fclose(fb);
    for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
    a[i][j]=savess.a1[i][j];}}
    player_1.moves=savess.moves[0];
    player_2.moves=savess.moves[1];
    player_1.score=savess.score[0];
    player_2.score=savess.score[1];
    strcpy(player_2.name,savess.name);
    strcpy(player_1.name,"player 1");
    counter=savess.counting;
    turn=savess.counting;
    system("cls");
    print(a);
}
int load_game(){
    printf("LOADED NUMBER.....(1) \n");
    printf("LOADED NUMBER.....(2) \n");
    printf("LOADED NUMBER.....(3) \n");
    int qq ;
    switch(getch()){
        case '1':
            qq = 2;
            break;
        case '2':
            qq = 3;
            break;
        case '3':
            qq = 4;
            break;
        default:
            system("cls");
            printf("NO File There\n\nChoose else ..!\n\n");
            qq =load_game();
            
    }
    return (qq);
}