#include <stdio.h>

int main(void) {
    int sayi, tpolam;
    printf("Pozitif bir sayi girin: ");
    scanf("%d", &sayi);

    if (sayi<=0)
    {
        printf("Lutfen pozitif bir sayi girin.\n");
        return 1;
    }

    while (sayi>=10)
    {
        int toplam=0;
        while (sayi>0)
        {
            toplam = toplam + sayi%10;
            sayi = sayi/10;
        }
        printf("Basamaklarin toplami: %d\n", toplam);
        sayi = toplam;
    }
    printf("Tek basamakli sayiya ulasildi: %d\n", sayi);

    return 0;
}