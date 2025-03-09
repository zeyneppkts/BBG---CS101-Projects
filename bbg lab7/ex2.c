#include <stdio.h>
#define SIZE 100

int main(){

    //matrisi tanımlama
    int n, i, j;
    int matrix[SIZE][SIZE];

    //Boyutunu isteme
    do{
        printf("Kare matrisin boyutunu girin (max%d)", SIZE);
        scanf("%d", &n);
    }while (n > SIZE);

    //Elemanlarını isteme
    printf("Matris elemanlarınız girin: \n");
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("Matris[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    //Matrisi yazdırma
    printf("Girilen matris: \n");

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    //Satırların simetrisi
    for(i = 0; i < n; i++){
        j = 0;
        while( j < n/2){
            if(matrix[i][j] != matrix[i][n - j -1]){
                printf("Bu matris panlindromik değildir");
                return 0;
            }
            j++;
        }
    }

    //Sütunların simetrisi
    for( j = 0; j < n; j++){
        i = 0;
        while(i < n/2){
            if(matrix[i][j] != matrix[n - i - 1][j]){
                printf("Bu matris palindromik değildir");
                return 0;
            }
            i++;
        }
    }

    //Polindrom olup olmadığını yazdırma
    printf("Bu matris palindromiktir");

    return 0;
}