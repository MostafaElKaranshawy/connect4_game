#include "New_game.h"

typedef struct{
    char check_name[1000][20];
    char winner_name[1000][20];
    int winner_score[1000];
    int names_counter;
}top_rank ;
top_rank rank;
int index_score;

void write_toprank();
void toprankk(char nume[],int player_score );
void print_scores(int n_players);
void swap_arr(int i,int j);
int partition(int array[],int low,int high);
void quick_sort(int array[],int low,int high);
int check_check_name(char num[],int s);
void read_top();

void toprankk(char nume[],int player_score ){
    int paramter= configuration_elements.highscores;
    int l;
    rank.names_counter=0;
    read_top();
    if(paramter>rank.names_counter){
        paramter=rank.names_counter+1;
    }

    l=check_check_name(nume,player_score);
    if(l){ rank.names_counter++;
    }
    else{
        paramter=paramter-1;
        strcpy(rank.winner_name[index_score],nume);
        if(rank.winner_score[index_score]<player_score){
            rank.winner_score[index_score]=player_score;
        }
    }
    quick_sort(rank.winner_score,0,rank.names_counter);
    write_toprank();

}
void read_top(){
    FILE *fp;
    fp=fopen("topranking","rb");
    fread(&rank,sizeof(rank),1,fp);
    fclose(fp);
}
void write_toprank(){
    FILE *fp;
    fp=fopen("topranking","wb");
    fwrite(&rank,sizeof(rank),1,fp);
    fclose(fp);
}
int check_check_name(char num[],int s){
    int notfound=1;
    char sa[20];
    strcpy(sa,num);
    strupr(sa);
    for(int i=0;i<rank.names_counter+1;i++){
        if((!strcmp(strupr(rank.check_name[i]),sa))){
            notfound=0;
            index_score=i;
        }
    }
    if(notfound){
        strcpy(rank.winner_name[rank.names_counter],num);
        strcpy(rank.check_name[rank.names_counter],num) ;
        rank.winner_score[rank.names_counter]=s;
    }
    return(notfound);
}
void quick_sort(int array[],int low,int high){
    if(low<high){
        int pivot=partition(array,low,high);
        quick_sort(array,low,pivot-1);
        quick_sort(array,pivot+1,high);
    }
}
int partition(int array[],int low,int high){
    int pivot=array[high];
    int leftpointer=low-1;
    for(int j=low;j<high;j++){
        if(array[j]>pivot){
            swap_arr(++leftpointer,j);
        }
    }
    swap_arr(++leftpointer,high);
    return(leftpointer);
}

void swap_arr(int i,int j){
    int tempc;
    char tempn[20],tempnv[20];
    tempc=rank.winner_score[j];
    rank.winner_score[j]=rank.winner_score[i];
    rank.winner_score[i]=tempc;
    strcpy(tempn,rank.check_name[j]);
    strcpy(rank.check_name[j],rank.check_name[i]);
    strcpy(rank.check_name[i],tempn);
    strcpy(tempnv,rank.winner_name[j]);
    strcpy(rank.winner_name[j],rank.winner_name[i]);
    strcpy(rank.winner_name[i],tempnv);
}
void print_scores(int n_players){
    int print_players=n_players;
    read_top();
    if(n_players>rank.names_counter){
        print_players=rank.names_counter+1;
    }
    printf("\033[0;36m");
    printf("\nTOP PLAYERS\n");
    printf("\n\nPlayer name\tPlayer score\n");
    for(int i=0;i<print_players-1;i++){
        printf("\n%s\t\t%d\n",rank.winner_name[i],rank.winner_score[i]);
    }
    printf("\033[0m");
}
