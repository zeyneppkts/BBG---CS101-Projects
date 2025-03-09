#include <stdio.h>
#define ARRAY_SIZE 100

int main(void) {
    int n, i, j, k, counter=0;
    printf("Dizinin boyutunu giriniz: ");
    scanf("%d", &n);

    int dizi[ARRAY_SIZE], unique[ARRAY_SIZE];

    for(i=0; i<n; i++){
        scanf("%d", &dizi[i]);
    }
    
    for (i = 0; i < n; i++){
        int tekrar = 0;

        for(j=0; j<counter; j++){
            tekrar = tekrar + (dizi[i] == unique[j]);
        }
        if (tekrar==0){
            unique[counter] = dizi[i];
            counter++;
        }
    }

    for (i=0, j=counter-1; i<j; i++, j--){
        int temp = unique[i];
        unique[i] = unique[j];
        unique[j] = temp;
    }

    printf("Benzersiz elemanlardan olusan ters cevrilmis dizi: \n");
    for(i=0; i<counter; i++){
        printf("%d ", unique[i]);
    }
    
    return 0;

}