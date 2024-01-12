#include <stdio.h>
#include <stdlib.h>
int getDot(int vector1[2], int vector2[2]);
int getDistSq(int vector[2]);
int main(){
    int n;
    scanf("%d", &n);
    int input[2][4][2];
    int area[2] = {0, 0};

    //input
    for(int i = 0; i < 2; i ++){
        for(int j = 0; j < 4; j ++){
            for(int k = 0; k < 2; k ++){
                scanf("%d", &input[i][j][k]);
            }
        }
    }

    for(int i = 0; i < 2; i ++){
        int vector[4][4][2];
        //vector [i][j] := i -> j
        for(int j = 0; j < 4; j ++){
            for(int k = 0; k < 4; k ++){
                vector[j][k][0] = input[i][k][0] - input[i][j][0];
                vector[j][k][1] = input[i][k][1] - input[i][j][1];
            }
        }
        int dot = 1;
        int distSq1 = 0, distSq2 = 0;
        int sideSq;
        dot = getDot(vector[0][1], vector[2][3]);
        if(dot == 0){
            distSq1 = getDistSq(vector[0][1]);
            distSq2 = getDistSq(vector[2][3]);
            if(distSq1 == distSq2){
                //對角線垂直且等長
                area[i] = distSq1;
            }
        }
        else if((sideSq = getDistSq(vector[0][1])) != getDistSq(vector[2][3])){
            continue;
        }

        dot = getDot(vector[0][2], vector[1][3]);
        if(dot == 0){
            distSq1 = getDistSq(vector[0][2]);
            distSq2 = getDistSq(vector[1][3]);
            if(distSq1 == distSq2){
                //對角線垂直且等長
                area[i] = distSq1;
                continue;
            }
        }
        else if((sideSq = getDistSq(vector[0][2])) != getDistSq(vector[1][3])){
            continue;
        }

        dot = getDot(vector[0][3], vector[1][2]);
        if(dot == 0){
            distSq1 = getDistSq(vector[0][3]);
            distSq2 = getDistSq(vector[1][2]);
            if(distSq1 == distSq2){
                //對角線垂直且等長
                area[i] = distSq1;
                continue;
            }
        }
        else if((sideSq = getDistSq(vector[0][3])) != getDistSq(vector[1][2])){
            continue;
        }
    }

    n = n * n;
    for(int i = 0; i < 2; i ++){
        area[i] = area[i] * n / 2;
        if(area[i] == 0){
            printf("No\n");
        }
        else{
            printf("Yes %d\n", area[i]);
        }
    }
    if(area[0] == area[1]){
        printf("Peace\n");
    }
    else if(area[0] > area[1]){
        printf("A\n");
    }
    else{
        printf("B\n");
    }

}
int getDot(int vector1[2], int vector2[2]){
    int dot = 0;
    for(int i = 0; i < 2; i ++){
        dot += vector1[i] * vector2[i];
    }
    return dot;
}
int getDistSq(int vector[2]){
    int distSq = 0;
    distSq += vector[0] * vector[0];
    distSq += vector[1] * vector[1];
    return distSq;
}