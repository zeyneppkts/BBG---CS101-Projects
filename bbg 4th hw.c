#include <stdio.h>
#define SIZE 100

int main(){

    /*Matrisi ve değişkenleri tanımladım*/
    int rows, cols, i, j, path = 0, len, flag, x, y, temp, a, b;
    int matrix[SIZE][SIZE];
    int visited[SIZE][SIZE];  /*visited adında yeni bir matris tanımlayarak yol hesaplarken her hücrenin 
    daha önceden ziyaret edilip edilmediğini kotrol etmek için kullandım*/
    
    /*Matrisin sütun ve satır sayılarını kullanıcıdan tanımlamasını istedim*/
     do{
        printf("Matrisin satir sayisini giriniz (max%d):", SIZE);
        scanf("%d", &rows);
    }while (rows > SIZE);
    
     do{
        printf("Matrisin sutun sayisini giriniz (max%d):", SIZE);
        scanf("%d", &cols);
    }while (cols > SIZE);
    
    //Matrisin elemanlarını kullanıcıdan aldım
    printf("Matris elemanlarini giriniz: \n");
    
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("Matris[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    /*Eğer varsa yolların uzunluklarını ve numaralarını kaydetmek için yol uzunluğu ve yol numarası adında iki yeni dizi tanımladım.*/
    int path_len[rows], path_num[rows];
    
    /*Girilen matrisi yazdırdım*/
    printf("Girilen matris: \n");
    
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    /*İlk sütundaki yolları bulup yolların son sütuna kadar devam edip 
    etmediğini kontrol ettim. Son satıra ulaşan yolları ilgili dizilerin içine kaydettim*/
    for(i = 0; i < rows; i++){
        

        /*visited matrisinin bütün elemanlarını 0'a eşitledim. 
        Ziyaret edildiğinde 1 olarak değiştirip o hücreye geri dönülmemesini sağladım*/
        for (a = 0; a < rows; a++) {
            for (b = 0; b < cols; b++) {
                visited[a][b] = 0;
            }
        }

        if(matrix[i][0] != 0){
            temp = matrix[i][0]; /*Bulduğum yolun numarasını kabetmemek için temp değişkenine atadım*/
            len = 0;   /*len, flag ve y değişkenlerini 0'a eşitleyip her döngü için baştan başlattım*/
            flag = 0;
            x = i;
            y = 0;

            while(y < cols && !flag){
                if(!visited[x][y] && matrix[x][y] == temp){
                    visited[x][y] = 1;
                    len++;

                    /*Etrafındaki bütün hücreleri kontrol edip eğer daha önce o hücrede bulunmamışsa oraya ilerlemesini sağladım*/
                    if(y < cols - 1 && matrix[x][y + 1] == temp && !visited[x][y + 1] ){
                        y++;  /*Sağdaki hücre aynı sayı ise o hücreye ilerletiyor*/

                    } else if (x > 0 && matrix[x - 1][y] == temp && !visited[x - 1][y]){
                        x--; /*Üstündeki hücre aynı sayı ise o hücreye ilerletiyor*/

                    } else if (x < rows - 1 && matrix[x + 1][y] == temp && !visited[x + 1][y]){
                        x++; /*Altındaki hücre aynı sayı ise o hücreye ilerletiyor*/

                    } else if (y > 0 && matrix[x][y - 1] == temp && !visited[x][y - 1]){
                        y--; /*Solundaki hücre aynı sayı ise o hücreye ilerletiyor*/

                    }else if (x > 0 && y < cols - 1 && matrix[x - 1][y + 1] == temp && !visited[x - 1][y + 1]){
                        x--;
                        y++;  /*Üst sağ çaprazındaki hücre aynı sayı ise o hücreye ilerletiyor*/

                    } else if (x < rows - 1 && y < cols - 1 && matrix[x + 1][y + 1] == temp && !visited[x + 1][y + 1] ){
                        x++;
                        y++; /*Alt  sağ çaprazındaki hücre aynı sayı ise o hücreye ilerletiyor*/

                    } else if(x > 0 && y > 0 && matrix[x - 1][y - 1] == temp && !visited[x - 1][y - 1]){
                        x--;
                        y--;  /*Üst sol çaprazındaki hücre aynı sayı ise o hücreye ilerletiyor*/

                    } else if(x < rows - 1 && y > 0 && matrix[x + 1][y - 1] == temp && !visited[x + 1][y - 1]){
                        x++;
                        y--;  /*Üst  sağ çaprazındaki hücre aynı sayı ise o hücreye ilerletiyor*/

                    } else {
                        flag = 1;  /*Çevresindeki hiçbir hücrede aynı eleman yoksa flagi 1 yapıp döngüden çıktım*/
                    }
                } else {
                    flag =  1; /*Hücre daha önceden ziyaret edilmişşe ya da yola devam etmek istediğim elemana 
                    eşit değilse döngüden çıkması için flagi 1'e eşitledim*/
                }
            }

            /*Yolun sonuna geldiğinde son sütundaysa yol numarasını ve yol uzunluğunu kaydettim*/
            if(y == cols - 1){
                path_num[path] = temp;
                path_len[path] = len;
                path++;
            }
        }
    }

    printf("\n");

    if(path == 0){
        printf("Son sutuna kadar devam eden yol bulunamadi.\n");
    }

    //Son sütuna ulaşabilen yolları yazdırdım
    for(i = 0; i < path; i++){
        printf("Yol %d -> Uzunluk %d\n", path_num[i], path_len[i]);
    }
    
    return 0;
}
