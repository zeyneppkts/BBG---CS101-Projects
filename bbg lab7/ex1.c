#include <stdio.h>
#define SIZE 3

int main() {
    // matrisi ve değişkenleri tanımlama
    int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE];
    int i, j;

    //matrisin elemanlarını işleme
    printf("Birinci matrisin elemanlarını giriniz (3x3): \n");

    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("matrix1[%d][%d]" i,j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("İkinci matrisin elemanlarını giriniz (3x3): \n");

    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("matrix2[%d][%d]" i,j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    //eşit olup olmadığının kontrolü
    for(i = 0; i < SIZE; j++) {
        for(j = 0; j < SIZE; j++){
            if(matrix1[i][j] != matrix2[i][j]){
                printf("\nMatrisler eşit değil\n")
                return 0;
            } 
        }
    }

    //eşit olup olmadığını yazdırma
    printf("\n Matrisler eşittir\n");

    return 0;
}