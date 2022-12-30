#include "undo.h"

// functions declaration
void main_menu(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]);
void save(int a[][width+3]);
void load(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]);
int load_game();
int save_counts;

// save func
void save(int a[][width+3]){
    FILE *fb2;

    // array of the game to be saved
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            savess.a1[i][j]=a[i][j];}
    }
    // the file that save the number of save times.
    fb2 = fopen("save_counts","r");
    fread(&save_counts,sizeof(save_counts),1,fb2);
    fclose(fb2);
    save_counts++;
    fb2 = fopen("save_counts","w");
    fwrite(&save_counts,sizeof(save_counts),1,fb2);
    fclose(fb2);

    // the file of saving the current game
    FILE *fb;
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

// load func
void load(int a[][width+3],int arri[],int arrj[],int scoret[],int score2[]){
    system("cls");
    // take the desired game of 3 to be loaded
    int qq = load_game();
    // take the number of saving files .
    FILE *fb2;
    fb2 = fopen("save_counts","r");
    fread(&save_counts,sizeof(save_counts),1,fb2);
    fclose(fb2);
    FILE *fb;

    // size in bites
    int e;
    e=sizeof(savess);
    // seek a specific place in the file.
    e=-(qq*e-e);

    // take inputs from the saved file
    if((fb=fopen("savinggame","rb"))==NULL ){
        printf("can't open this file\n");
        save_counts = 0;
        fb2 = fopen("save_counts","w");
        fwrite(&save_counts,sizeof(save_counts),1,fb2);
        fclose(fb2);
        sleep(1);
        system("cls");
        main_menu(a,arri,arrj,scoret,score2);
    }
    fseek(fb, e, SEEK_END);
    fread(&savess,sizeof(savess),1,fb);
    fclose(fb);
    if(save_counts>=3 || (save_counts == 2 && qq<4) || (save_counts ==  1&&qq== 2)){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                a[i][j]=savess.a1[i][j];
            }
        }
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
    // if the file is not exist
    else{
        printf("\n\ncan't open this file\n");
        sleep(1);
        system("cls");
        main_menu(a,arri,arrj,scoret,score2);
    }

}

// choose the game of 3 to load
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