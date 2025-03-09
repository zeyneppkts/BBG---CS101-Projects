#include <stdio.h>
#include <string.h>

int main() {
    char numberO[10]="10101", numberT[10]="111", Result[11];
    int oneL, twoL;
    int i, j;
    int overBit=0;

    i=0;
    while(numberO[i] != '\0') {
        i++;
    }
    oneL=i;

    while(numberT[i] != '\0'){
        i++;
    }
    twoL=i;

    if(twoL > oneL) {
        strcpy(Result, numberO);
        strcpy(numberO, numberT);
        strcpy(numberT, Result);

        i = oneL;
        oneL = twoL;
        twoL = i;
    }

    Result[oneL +1] = '\0';

    j = twoL - 1;
    for(i = oneL; i > 0; i--) {
        if(j >= 0) {
            if((numberO[i] == '1') && (numberT[j] == '1')) {
                if(overBit == 1) {
                    Result[i + 1] = '1';
                    overBit = 1;
                } else{
                    Result[i + 1] = '0';
                    overBit = 1;
                } else if((numberO[i] == '0') && (numberT[j] == '0')){
                    if(overBit == 1) {
                    Result[i + 1] = '1';
                    overBit = 0;
                } else{
                    Result[i + 1] = '0';
                    overBit = 0;
                } else {
                    if(overBit == 1) {
                        Result[i+1] = '0';
                        overBit = 
                    }
                }
            }
        }
    }

    if(overBit == 1) {
        Result[0] = '1';
    } else {
        Result[0] = '0';
    }

    printf("number1: %s, number2: %s\n", numberO, numberT);



    return 0;
}