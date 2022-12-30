#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "casting.h"

// global variables.
int bolean=0;
int counter = 0;
int turn = 0;
int time_passed = 0 , time_min , time_sec;

char no_spaces[1024];
// congiduration struct
typedef struct {
    int width;
    int height;
    int highscores;
}configuration;
configuration configuration_elements;

int height;
int width ;
int highscores ;

// functions declaration
void remove_spaces(char s[]);
void read_file(char s[]);
int tag_input(char s[] ,char tag_open[], char tag_close[]);

// functions implementations
void configuration_func(){
    FILE* fp;
    char s[1024];
    int count_path_access = 0;
    char path[1024];
    strcpy(path ,"configuration.xml");
    
    // Open XML file to read
    fp = fopen(path, "r");
    
    if ( fp == NULL ){
        while(count_path_access < 3){
            printf("Can't open the XML file\n\nPlease Enter File Path : ");
            gets(path);
            fp = fopen(path, "r");
            if(!( fp == NULL )){
                fread(s , sizeof(s), 1, fp);
                fclose(fp);
                remove_spaces(s);
                read_file(no_spaces);
                break;
            }
            else if( fp == NULL && count_path_access == 2){
                width = 7;
                configuration_elements.width = width;
                height = 9;
                configuration_elements.height = height;
                highscores = 10;
                configuration_elements.highscores = highscores;
            }
            count_path_access++;
            system("cls");
        }
    }
    else
    {
        // read each lines of XML file
        fread(s , sizeof(s), 1, fp);
        fclose(fp);
        remove_spaces(s);
        read_file(no_spaces);
    }
}

// check if there any missed parameter.
void read_file(char s[] ){
    width = tag_input(s ,"<Width>" , "</Width>");
    if(width <=0){width = 7;}
    configuration_elements.width = width;
    height = tag_input(s ,"<Height>" , "</Height>");
    if(height <=0){height = 9;}
    configuration_elements.height = height;
    highscores = tag_input(s ,"<Highscores>" , "</Highscores>");
    if(highscores <=0){highscores = 10;}
    configuration_elements.highscores = highscores;
}

// tag the parameters from tags.
int tag_input(char s[] ,char tag_open[], char tag_close[]){
    char *open_tag = tag_open;
    char *close_tag = tag_close;

    char *Parameter = NULL;
    char *start, *end;

    if ( start = strstr( s, open_tag ) )
    {
        start += strlen( open_tag );
        if ( end = strstr( start, close_tag ) )
        {
            Parameter = ( char * )malloc( end - start + 1 );
            memcpy( Parameter, start, end - start );
            Parameter[end - start] = '\0';
            int number = casting(Parameter);
            return number;
        }
        else {
            return -1;
        }
    }
}

// ignore spaces in the xml file 
void remove_spaces(char s[]){
    int m = 0 ;
    for(int i = 0 ;i < strlen(s) ; i++){
        if(s[i] == ' '){continue;}
        else{
            no_spaces[m] = s[i];
            m++;
        }
    }
}