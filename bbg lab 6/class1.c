#include <stdio.h>
#define R 5 
#define C 2

int main(){
    int a[R][C] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int b[R][C] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int c[R][C];
    int i, j;

    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            c[i][j] = a[i][j] + b[i][j];
            printf("[%d][%d] = %d\n",i, j, c[i][j] );
        }
    }

    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            printf("%4d", c[i][c]);
        }
        printf("\n");
    }

    return 0;
}