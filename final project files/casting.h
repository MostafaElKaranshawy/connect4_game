// casting the input into number.
int casting(char user_input[]){
    int boool = 1;
    int qqq =0;
    int len = strlen(user_input);
    for(int i=0; i<len; i++){
        qqq*=10;
        switch(user_input[i]){
            case ' ':
            qqq/=10;
            break;
            case '0':
            qqq+=0;
            break;  
            case '1':
            qqq+=1;
            break;
            case '2':
            qqq+=2;
            break;
            case '3':
            qqq+=3;
            break;
            case '4':
            qqq+=4;
            break;
            case '5':
            qqq+=5;
            break;
            case '6':
            qqq+=6;
            break;
            case '7':
            qqq+=7;
            break;
            case '8':
            qqq+=8;
            break;
            case '9':
            qqq+=9;
            break;
            default:
            qqq = -1;
            break;
        }
        if(qqq == -1){break;}
    }
    return qqq;
}