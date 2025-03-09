#include <stdio.h>

int main(){
    char s[11];
    int g, a, y, isValid = 1;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Tarihi giriniz:");
    scanf("%s", s);

    g = (s[0]- '0')*10 + (s[1] - '0');
    a = (s[3]- '0')*10 + (s[4] - '0');
    y = (s[6] - '0')*1000 + (s[7] - '0')*100 + (s[8] - '0')*10 + (s[9] - '0');

    if(g < 1 || g> days[a - 1]){
        isValid = 0;
    }

    if(a < 1 || a > 12){
        isValid = 0;
    }

    if(y < 0 || y > 9999){
        isValid = 0;
    }

    if(y % 4 == 0 && a== 2 && g == 29){
        isValid = 1;
    }

    if(isvalid){
        printf("GECERLİ TARİH");
    }else{
        printf("GEÇERSİZ TARİH");
    }

    RETURN 0;
}