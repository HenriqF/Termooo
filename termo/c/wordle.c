#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define AMA "\x1b[33m"
#define VER  "\x1b[32m"
#define RESET  "\x1b[0m"

char word[] = "carro";
char guess[] = "";
bool state = true;

void getguess(int a){
    printf("Guess: ");
    scanf("%s", guess);
    if (strlen(guess) != a){
        getguess(a);
    }
}

void main(){
    int len = strlen(word);
    int i;
    char start[1000];
    printf("\n");
    for (i=0;i<len;i++){
        strcat(start, "-");
    }
    printf("       ");
    printf(start);
    printf("\n");

    while (state == true){
        char truth[1000] = "";
        getguess(len);

        if (strcmp(guess, word) == 0){
            printf("VITORIA!");
            state = false;
            while (true){
                
            }
            break;
        }
        else{
            char backup[1000] = "";
            strcpy(backup, word);

            for (i=0;i<len;i++){
                if (backup[i] == guess[i]){
                    strcat(truth, "o");
                    backup[i] = '*';
                    guess[i] = '-';
                }
                else{
                    strcat(truth, "-");
                }
            }
            char *pos;
            int index;
            for (i=0;i<len;i++){
                if (strchr(backup, guess[i])){
                    pos = strchr(backup, guess[i]);
                    index = (int)(pos - backup);
                    backup[index] = '*';
                    truth[i] = '*';
                }
            }
            printf("       ");
            for (i = 0;i<len;i++){
                if (truth[i] == '*'){
                    printf(AMA "*");
                }
                else if (truth[i] == 'o'){
                    printf(VER "o");
                }
                else{
                    printf(RESET);
                    printf("-");
                }
            }
            printf(RESET "\n");
        }
    }
}