#include <stdio.h>
#include <stdlib.h>
int dest[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
int inMatrix(int x, int y);
int main(){
    int matrix[8][8];
    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j ++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int x, y, x1, y1;
    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j ++){
            if(matrix[i][j] == 1){
                for(int k = 0; k < 8; k ++){
                    x = dest[k][0] + i;
                    y = dest[k][1] + j;
                    if(inMatrix(x, y)){
                        if(matrix[x][y] == 2){
                            while(matrix[x][y] != 0){
                                x += dest[k][0];
                                y += dest[k][1];
                                if(!(inMatrix(x, y))){
                                    break;
                                }
                                if(matrix[x][y] == 0){
                                    matrix[x][y] = 3;
                                    break;
                                }
                                if(matrix[x][y] == 1 || matrix[x][y] == 3){
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int num = 0;
    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j ++){
            if(matrix[i][j] == 3){
                num ++;
            }
        }
    }
    printf("%d\n", num);
}
int inMatrix(int x, int y){
    if(!(x >= 0 && x < 8)){
        return 0;
    }
    if(!(y >= 0 && y < 8)){
        return 0;
    }
    return 1;
}