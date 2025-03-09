#include <stdio.h>
#define ARRAY_SIZE 100

int main(void) {
    int N, k, i, counter1 = 0, counter2 = 0, temp;
    float delay_sum1 = 0, delay_sum2 = 0;

    /*Kullanıcıdan uçak sayısı, pistlerden kalkma aralıkları, uçakların numaraları ve uçakların kalkış saati taleplerini alıyorum*/
    printf("Ucak sayisini giriniz: ");
    scanf("%d", &N);

    printf("Pistlerden kac dakika arayla ucak kalkicak? ");
    scanf("%d", &k);

    int uc_num[ARRAY_SIZE], kalk_sa[ARRAY_SIZE], pist1_uc[ARRAY_SIZE], pist1_sa[ARRAY_SIZE], pist2_uc[ARRAY_SIZE], pist2_sa[ARRAY_SIZE];

    printf("Ucak numaralarini giriniz: ");
    for(i = 0; i < N; i++){
        scanf("%d", &uc_num[i]);
    }

    printf("Ucak kalkis taleplerini giriniz: ");
    for(i = 0; i < N; i++){
        scanf("%d", &kalk_sa[i]);
    }


    /*Uçakları ve kalkış taleplerini dengeli olması için çift sayı indisliler pist 1'e, tek sayı indisliler pist 2'ye gelecek şekilde dağıtıyorum.*/
    for(i = 0; i < N; i++){
        if(i % 2 == 0){
            pist1_uc[counter1] = uc_num[i];
            pist1_sa[counter1] = kalk_sa[i];
            counter1++;
        } else {
            pist2_uc[counter2] = uc_num[i];
            pist2_sa[counter2] = kalk_sa[i];
            counter2++;
        }
    }

    /*Pist 1 için kalkış saatlerinin verilen kalkış aralığına uygun olucak şekilde ayarlama yapıyorum ve 1. pist için olan ortalama gecikme zamanını hesaplıyotum.*/
    for(i = 0; i < counter1 - 1; i++){
        temp = pist1_sa[i + 1];

        if ((pist1_sa[i + 1] - pist1_sa[i]) < k){
            pist1_sa[i + 1] = pist1_sa[i] + k;
            delay_sum1 = delay_sum1 + (pist1_sa[i + 1] - temp);
        }
    }
    if (counter1 > 0){
    delay_sum1 = delay_sum1 / counter1;
    }

    /*Yukarıdaki işlemin aynısını pist 2 için yapıyorum*/
    for(i = 0; i < counter2 - 1; i++){
        temp = pist2_sa[i + 1];

        if ((pist2_sa[i + 1] - pist2_sa[i]) < k){
            pist2_sa[i + 1] = pist2_sa[i] + k;
            delay_sum2 = delay_sum2 + (pist2_sa[i + 1] - temp);
        }
    }
    if (counter2 > 0){
    delay_sum2 = delay_sum2 / counter2;
    }

    /*Yaptğım bütün ayarlamaları ve hesaplamaları yazdırıyorum.*/
    printf("1. pistte bulunan ucaklar: \n");
    for(i = 0; i < counter1; i++){
        printf("%d ", pist1_uc[i]);
    }
    printf("\n1. pistte bulunan ucaklarin saatleri: \n");
    for(i = 0; i < counter1; i++){
        printf("%d ", pist1_sa[i]);
    }
    printf("\n1. pist icin ortalama gecikme zamani: %f \n", delay_sum1);


    printf("2. pistte bulunan ucaklar: \n");
    for(i = 0; i < counter2; i++){
        printf("%d ", pist2_uc[i]);
    }
    printf("\n2. pistte bulunan ucaklarin saatleri: \n");
    for(i = 0; i < counter2; i++){
        printf("%d ", pist2_sa[i]);
    }
    printf("\n2. pist icin ortalama gecikme zamani: %f \n", delay_sum2);


    return 0;
}