#include <stdio.h>

int fibonacci(int n){
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    //kullanıcıdan bir sayı alalım.
    int n;
    printf("Bir sayi giriniz: ");
    scanf("%d", &n);

    //n'e kadar olan Fibonacci sayılarını yazdıralım.
    for(int i=0; i<n; i++){
        printf("%d ", fibonacci(i));
    }

    //dioganal toplamları fibonacci olan Pascal Piramidini çizelim!
    // n kadar katlı piramidimiz olsun.
    printf("\n\nPascal Piramidi:\n");
    for (int i = 0; i < n; i++) {
        int val = 1;
        // boşluklar
        for (int j = 0; j < n - i; j++) printf(" ");
        // değerler
        for (int j = 0; j <= i; j++) {
            printf("%d ", val);
            val = val * (i - j) / (j + 1);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}



