#include <stdio.h>
#include <stdlib.h>
int main(){
    int m = 10;
    scanf("%d", &m);
    int n;
    int *array;
    int output[m];
    for(int i = 0; i < m; i ++){
        scanf("%d", &n);
        array = malloc(sizeof(int) * n);
        for(int j = 0; j < n; j ++){
            scanf("%d", &array[j]);
        }
        int len = 0;
        int max = 0;
        int temp = array[0];
        for(int j = 0; j < n; j ++){
            if(temp == array[j]){
                len ++; 
            }
            else{
                if(max < len){
                    max = len;
                }
                len = 1;
            }
            temp = array[j];
        }
        if(max < len){
            max = len;
        }
        output[i] = max;
        free(array);
    }
    for(int i = 0; i < m; i ++){
        printf("%d\n", output[i]);
    }
    return 0;
}