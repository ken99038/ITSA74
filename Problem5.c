#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char *move(char *a, int b);
int main(){
    int m = 0;
    scanf("%d", &m);
    getchar();
    char input[m][101];
    memset(input, 0, sizeof(input));

    for(int i = 0; i < m; i ++){
        int x = -1;
        while((input[i][++x] = getchar()) != '\n');
        input[i][x] = '\0';
    }

    char output[m][101];
    memset(output, 0, sizeof(output));
    const char AtoZ[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digit[] = "0123456789";

    for(int i = 0; i < m; i ++){
        char *posn, *posc;
        posn = strpbrk(input[i], digit);
        posc = strpbrk(input[i], AtoZ);
        char *temp;
        int num;
        do{
            if(posn == NULL){
                strcat(output[i], posc);
                break;
            }
            if(posn > posc){
                num = atoi(posn);
                move(posc, num);
                temp = posn + 1;
                strcat(output[i], posc);
                posc = strpbrk(temp, AtoZ);
            }
            posn = strpbrk(++posn, digit);
        }while(posc != NULL);
    }

    for(int i = 0; i < m; i ++){
        int x = 0;
        while(x < 101){
            if(output[i][x] != ' '){
                putchar(output[i][x]);
            }
            else if(output[i][x] == '\0'){
                break;
            }
            x ++;
        }
        printf("\n");
    }
}

char *move(char *a, int b){
    int x = 0;
    do{
        if(a[x] == ' '){
            continue;
        }
        a[x] += b;
        if(a[x] > 90){
            a[x] -= 26;
        }
    }while(isalpha(a[++x]) || a[x] == ' ');
    a[x] = '\0';
    return a;
}