/*Triversi oyunu reversi oyununun 3 kişilik versiyonudur. Amaç oyun tahtasına farklı renkteki taşları koyarak diğer renleri
kendi rengine çevirmektir. Oyun sonunda tahtada en çok sayıda taşı olan oyuncu oyunu kazanır. Ben de kodumu bu yönergelere 
göre yazdım.*/

#include <stdio.h>
#define MAX 23

int main(){
    /*Değişkenlerimi ve oyun tahtasını burada tanımladım.*/
    int N, i, j, r, c, hamle, temp_r, temp_c, flag, K_oyuncu = 0, S_oyuncu = 0, M_oyuncu = 0;
    char tahta[MAX][MAX], sira;

    printf("Triversi oyununa hoşgeldiniz! \n");
    printf("Oyun Kurallari:\n");
    printf("1. Oyuna Kirmizi oyuncu baslar ve sonrasinda Sari ve Mavi olarak devam eder.\n");
    printf("2. Kirmizi oyuncu oyuna baslarken tasini ortaya en yakin noktalardan birine koymak zorundadir.\n");
    printf("3. Her oyuncu tasini tahtadaki eski taslardan en az biriyle temas edecek sekilde koymalidir.\n");
    printf("4. Oyun tahtasinda bos alan kalmadiginda oyun sonlanir \n");
    printf("5. Oyun sonunda tahtada en cok tasi bulunan oyuncu oyunu kazanir. \n");

    /*Kullanıcıdan oyun tahtasının boyunu alıp max 23 olarak sınırladım*/
    printf("\nOyun tahtasinin boyutunu giriniz (Max: %d):", MAX);
    do{
        scanf("%d", &N);
    } while( N > 23);

    /*Oyun oynayışı kolaylığı için tahtadaki boş hücreleri * karakteriyle doldurdum*/
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tahta[i][j] = '*';
        }
    }


    /*Oyuna ilk başlayanın kırmızı ve tahtanın orta noktasına yakın olması gerektiği için buna yönelik kontrolleri ekledim*/
    if( N % 2 != 0){
        tahta[N/2][N/2] = 'K';
    } else{
        printf("Kirmizi tasi orta hucrelerden hangisine koymak istiyorsunuz:");
        do{
            scanf("%d %d", &r, &c);
        }while((r < (N / 2) - 1 || r > N / 2) || (c < (N / 2) - 1 || c > N / 2));
        tahta[r][c] = 'K';
    }
    hamle = 1;

    /*Kırmızı oyuncu taşını orta noktaya koyduktan sonra oyun tahtasını oynayanların görmesi için yazdırdım*/
    printf("Oyun tahtasi: \n");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%c ", tahta[i][j]);
        }
        printf("\n");
    }

    /*Oyunun oynanışını bir while döngüsü içinde çözdüm. hamle sayısını her bir sonraki oyuncuya geçtiğinde bir arttırarak
    hamle sayısı tahtadaki hücre sayısına ulaştığında oyunu bitirdim*/
    while(hamle < N*N){
        hamle++;

        /*Sıradaki oyuncunu rengini belirlemek için hamle sayısının 3 ile olan modunu kullandım*/
        if(hamle % 3 == 1){
            printf("Kirmizi oyuncunun tasini koymak istedigi hucre:");
            sira = 'K';
        } else if(hamle % 3 == 2){
            printf("Sari oyuncunun tasini koymak istedigi hucre:");
            sira = 'S';
        } else{
            printf("Mavi oyuncunun tasini koymak istedigi hucre:");
            sira = 'M';
        }

        /*Her oyuncunun taşını koymak istediği hücrenin başka bir hücreyle bağlantısı olması için olan kontrolleri ekledim*/
        do {
            scanf("%d %d", &r, &c);
            flag = 0;

            if (r >= 0 && r < N && c >= 0 && c < N && tahta[r][c] == '*') {
                if ((r > 0 && tahta[r - 1][c] != '*') || (r < N - 1 && tahta[r + 1][c] != '*') || (c > 0 && tahta[r][c - 1] != '*') || (c < N - 1 && tahta[r][c + 1] != '*') || (r > 0 && c > 0 && tahta[r - 1][c - 1] != '*') || (r > 0 && c < N - 1 && tahta[r - 1][c + 1] != '*') || (r < N - 1 && c > 0 && tahta[r + 1][c - 1] != '*') || (r < N - 1 && c < N - 1 && tahta[r + 1][c + 1] != '*')) {
                    flag = 1;
                }
            }

            if (!flag) {
                printf("Tasi baska taslarla temas edecek sekilde koymalisiniz! Tekrar deneyin: ");
            }
        } while (!flag);

        tahta[r][c] = sira;

        /*Her tahtaya taş koyulduğunda oyun tahtasının son halini tekrar yazdırdım*/
        printf("Tas koyulduktan sonra oyun tahtasi:\n");
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                printf("%c ", tahta[i][j]);
            }
            printf("\n");
        }

        /*Yeni koyulan taşın etrafındaki 8 yönün kontrollerini ve eğer varsa renk değişimlerini sağladım*/
        /*Taşın koyulduğu hücrenin solu kontrolü*/
        i = r, j = c - 1, flag = 0;
        while(j >= 0 && tahta[i][j] != '*'){
            if(tahta[i][j] == sira){
                temp_c = j;
                flag = 1;
                j = - 1;
            }else j--;
        }

        if(flag){
            for(j = temp_c + 1; j < c; j++){
                    tahta[i][j] = sira;
            }
        }

        /*Taşın koyulduğu hücrenin sağı kontrolü*/
        flag = 0, j = c + 1;
        while(j < N && tahta[i][j] != '*'){
            if(tahta[i][j] == sira){
                temp_c = j;
                flag = 1;
                j = N;
            }else j++;
        }

        if(flag){
            for(j = c + 1; j < temp_c; j++){
                tahta[i][j] = sira;
            }
        }

        /*Taşın koyulduğu hücrenin üst tarafının kontrolü*/
        j = c, i = r - 1, flag = 0;
        while(i >= 0 && tahta[i][j] != '*'){
            if(tahta[i][j] == sira){
                temp_r = i;
                flag = 1;
                i = - 1;
            }else i--;
        }

        if(flag){
            for(i = temp_r + 1; i < r; i++){
                tahta[i][j] = sira;
            }
        }

        /*Taşın koyulduğu hücrenin alt tarafının kontrolü*/
        flag = 0, i = r + 1;
        while(i < N && tahta[i][j] != '*'){
            if(tahta[i][j] == sira){
                temp_r = i;
                flag = 1;
                i = N;
            }else i++;
        }

        if(flag){
            for(i = r + 1; i < temp_r; i++){
                tahta[i][j] = sira;
            }
        }

        /*Taşın koyulduğu hücrenin sol yukarı çapraz kontrolü*/
        flag = 0, i = r - 1, j = c - 1;
        while(i >= 0 && j >= 0 && tahta[i][j] != '*'){
            if(tahta[i][j] == sira){
                temp_r = i;
                temp_c = j;
                flag = 1;
                i = - 1, j = - 1;
            }else i--, j--;
        }

        if(flag){
            for(i = temp_r + 1, j = temp_c + 1; i < r  && j < c; i++, j++){
                tahta[i][j] = sira;
            }
        }

        /*Taşın koyulduğu hücrenin sağ aşağı çapraz kontrolü*/
        flag = 0, i = r + 1, j = c + 1;
        while(i < N && j < N && tahta[i][j] != '*'){
            if(tahta[i][j] == sira){
                temp_r = i;
                temp_c = j;
                flag = 1;
                i = N, j = N;
            }else i++, j++;
        }

        if(flag){
            for(i = r + 1, j = c + 1; i < temp_r && j < temp_c; i++, j++){
                tahta[i][j] = sira;
            }
        }

        /*Taşın koyulduğu hücrenin sağ yukarı çapraz kontrolü*/
        flag = 0, i = r - 1, j = c + 1;
        while(j < N && i >= 0 && tahta[i][j] != '*'){
            if(tahta[i][j] == sira){
                temp_r = i;
                temp_c = j;
                flag = 1;
                j = N, i = - 1;
            }else i--, j++;
        }

        if(flag){
            for(i = r - 1, j = c + 1; i > temp_r && j < temp_c; i--, j++){
                tahta[i][j] = sira;
            }
        }

        /*Taşın koyulduğu hücrenin sol aşağı çapraz kontorlü*/
        flag = 0, i = r + 1, j = c - 1;
        while(i < N && j >= 0 && tahta[i][j] != '*'){
            if(tahta[i][j] == sira){
                temp_r = i;
                temp_c = j;
                flag = 1;
                i = N, j = - 1;
            }else i++, j--;
        }

        if(flag){
            for(i = temp_r -  1, j = temp_c + 1; i > r && j < c; i--, j++){
                tahta[i][j] = sira;
            }
        }
        
        /*Rerk değişinleri sonucunda tahtanı son halini yazdırdım*/
        printf("Renk degisimleri sonrasi oyun tahtasi:\n");
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                printf("%c ", tahta[i][j]);
            }
            printf("\n");
        }

    }

    /*Oyun tahtasını son bir kez daha dolanarak her renkteki taşlardan kaçar tane olduğunun bilgisini alıp yazdırdım*/
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(tahta[i][j] == 'K'){
                K_oyuncu ++;
            }else if(tahta[i][j] == 'S'){
                S_oyuncu++;
            }else{
                M_oyuncu++;
            }
        }
    }

    printf("Kirmizi oyuncunun oyun tahtasindaki tas sayisi: %i \n", K_oyuncu);
    printf("Sari oyuncunun oyun tahtasindaki tas sayisi: %i \n", S_oyuncu);
    printf("Mavi oyuncunun oyun tahtasindaki tas sayisi: %i \n", M_oyuncu);

    /*Renklerden hangisinin sayısı fazlaysa o oyuncunun kazandığı bilgisini yazdırdım*/
    if(K_oyuncu > S_oyuncu && K_oyuncu > M_oyuncu){
        printf("Oyunu kazanan oyuncu: Kirmizi");
    }else if(S_oyuncu > K_oyuncu && S_oyuncu > M_oyuncu){
        printf("Oyunu kazanan oyuncu: Sari");
    }else if(M_oyuncu > K_oyuncu && M_oyuncu > S_oyuncu){
        printf("Oyunu kazanan oyuncu: Mavi");
    }else printf("Oyunu kazanan yok!");


    return 0;
}