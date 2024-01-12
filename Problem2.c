#include <stdio.h>
#include <stdlib.h>
int main(){
    int m = 10;
    scanf("%d", &m);
    double input[m][2];
    double dSq = 0;
    int output[m];
    double score[11];
    for(int i = 0; i < 11; i ++){
        score[i] = i * i;
    }
    for(int i = 0; i < m; i ++){
        scanf("%lf %lf", &input[i][0], &input[i][1]);
        input[i][0] -= 10.0;
        input[i][1] -= 10.0;
        dSq = input[i][0] * input[i][0] + input[i][1] * input[i][1];
        for(int j = 1; j < 11; j ++){
            if(dSq > score[j]){
                continue;
            }
            else{
                output[i] = 10 - j + 1;
                break;
            }
        }
    }
    for(int i = 0; i < m; i ++){
        printf("%d\n", output[i]);
    }
    return 0;
}