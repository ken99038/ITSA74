#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n = 0;
    scanf("%d", &n);
    int m[n];
    for(int i = 0; i < n; i ++){
        scanf("%d", &m[i]);
    }
    char input[n][100][11];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m[i]; j ++){
            scanf("%s", input[i][j]);
        }
    }

    //
    int output[n];
    for(int i = 0; i < n; i ++){
        int nonPair[m[i]];
        int len = 0;
        for(int j = 0; j < m[i]; j ++){
            int bool = 0;
            for(int k = 0; k < len; k ++){
                if(strcmp(input[i][nonPair[k]], input[i][j]) == 0){
                    len -= 1;
                    nonPair[k] = nonPair[len];
                    bool = 1;
                    break;
                }
            }
            if(bool == 0){
                nonPair[len] = j;
                len ++;
            }
        }
        output[i] = len;
    }

    for(int i = 0; i < n; i ++){
        printf("%d\n", output[i]);
    }
}