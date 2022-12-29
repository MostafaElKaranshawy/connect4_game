typedef struct {
    char symbol;
    char color;
    int score;
    int moves ;
    char name[255];
}players;
players player_1 , player_2 ;

typedef struct{
    int a1[6][7];
    int counting;
    int seconds;
    int score[2];
    int moves[2];
    char name[20];
    int countep;
}save_game;
save_game savess;
