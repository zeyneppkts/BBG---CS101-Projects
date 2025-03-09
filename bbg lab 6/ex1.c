#include <stdio.h>

int main () {
    char stringOne[10]="anagram";
    char stringTwo[10]="grammar";
    int k=3;
    int i,j;
    int Diff=0;
    int strOneL, strTwoL;

    i=0;
    while(stringOne[i] != '\0') {
        i++;
    }

    strOneL=i;

    i=0;
    while(stringTwo[i != '\0']) {
        i++;
    }

    strTwoL=i;

    printf(%d %d , strOneL, strTwoL);

    if(strOneL != strTwoL) {
        printf("Two strings are not k-anagrams");
        return 0;
    }

    i=0;
    while((i < strOneL) && (Diff <= k)) {
        j = 0;

        while((j<strTwoL) && (stringOne[i] != stringTwo[j])){
            j++;
        }

        if(j!=strTwoL) {
            stringOne[i] = '0';
            stringTwo[j] = '0';
        }else{
            Diff++;
        }
        i++;
    }

    printf("Diff count: %d", Diff);

    if(Diff <= k) {
        printf("Two strings are k-anagrams");
    }

    return 0;
}