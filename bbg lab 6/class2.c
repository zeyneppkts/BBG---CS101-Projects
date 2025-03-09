#include <stdio.h>
#

int main(){

    for(int i = 0; i < M1.length; i++){
        for(int j = 0; j < M2[0].length; j++){
            for(int k = 0; k < M2.length; k++){
                mult[i][j] += M1[i][k]*M2[k][j];
            }
        }
    }
}