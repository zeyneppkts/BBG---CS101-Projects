#include <stdio.h>

int main(void) {
    int x, y;

    printf("Koordinatlari giriniz: ");
    scanf("%d %d", &x, &y);
    

    if (x>0 && y>0)
        printf("(%d, %d) noktasi 1. bolgededir.\n", x, y );
    else if (x<0 && y>0)
        printf("(%d, %d) noktasi 2. bolgededir.\n", x, y );
    else if (x<0 && y<0)
        printf("(%d, %d) noktasi 3. bolgededir.\n", x, y );
    else if (x>0 && y<0)
        printf("(%d, %d) noktasi 4. bolgededir.\n", x, y );
    else if (x==0 && y==0)
        printf("(%d, %d) noktasi orijindedir.\n", x, y );
    return 0;
}