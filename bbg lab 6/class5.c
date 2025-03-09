/*Kelimeyi ters yazdıran kod*/
#include <stdio.h>

int main(){
    char arr[3][15] = {"yildiz", "teknik", "universitesi"};
    int i, j, k, kk;
    char temp;

    printf("Once:\n");

    for(i = 0; i < 3; i++){
        printf("%s\n", arr[i]);
    }

    for(i = 0; i < 3; i++){
        for(k = 0; arr[i][k; k++]){
            kk= k - 1;
        }
        for(j = 0; j < k/2; j++){
            temp = arr[i][j];
            arr[i][j] = arr[i][kk];
            arr[i][kk] = temp;
            kk--;
        }
    }

    printf("\nSonra:\n");

    for(i = 0; i < 3; i++){
        printf("%s\n", arr[i]);
    }

    return 0;
}