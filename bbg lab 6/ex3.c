#include <stdio.h>

int main() {
    char strO[10] = "aabbca";
    char strT[10] = "xxyyzx";
    int i, j;
    int oneL, twoL;
    char oneCont, twoCont;
    int isIsomorphic = 1;

    i=0;
    while(strO[i] != '\0'){
        i++;
    }
    oneL = i;

    i=0;
    while(strT[i] != '\0'){
        i++;
    }
    twoL = i;

    i=0;
    while( (i< oneL) && isIsomorphic){
        if(str[i] != '0'){
            oneCont = strO[i];
            twoCont = strT[i];
            j = i + 1;

            while((j<twoL) && ((strO[j] == oneCont) || (strT[j] == twoCont)) && ((strO[j] != oneCont) && (strT[j] != twoCont))){
                if((strO[j] == oneCont) && (strT[j] == twoCont)) {
                    strO[j] = '0';
                    strT[j] = '0';
                }
                j++İ
            }

            if(j < twoL){
                isIsomorphic = 0;
            }
        }
        i++;
    }

    if(isIsomorphic){
        printf("It's isomorphic");
    } else {
        printf("It's not isomorphic");
    }

    return 0;
}