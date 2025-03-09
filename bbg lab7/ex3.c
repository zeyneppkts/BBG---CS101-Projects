#include <stdio.h>
#define MAX_ROW_LENGTH 1000

int main(){

    //matris boyutları
    int rows, cols, i, j, index;
    printf("Satır sayısı:");
    scanf("%d", &rows);

    printf("Sütun sayısı:");
    scanf("%d", &cols);

    //matris dizilerini tanımlayalım
    char matris[rows][cols];
    char rowStrings[rows][MAX_ROW_LENGTH];

    //matris elemanları (char)
    printf("Matris elemanlarını girin: \n");
    
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("Matris[%d][%d]:", i, j);
            scanf(" %c", &matris[i][j]); // %c ile çalışırken başına boşluk bırakmamız gerekir
        }
    }

    //birleştirme
    for(i = 0; i < rows; i++){
        index = 0;
        for(j = 0; j < cols; j++){
            rowStrings[i][index++] = matris[i][j];
        }
        rowStrings[i][index++] = '\0';
    }

    //ekrana string dizisini yazma
    printf("Satır stringleri: \n");

    for(i = 0, i < rows; i++){
        printf("%s\n", rowStrings[i]);
    }

    return 0;
}