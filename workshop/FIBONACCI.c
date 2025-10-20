/*
SELAMLAARRR!!
Fibonacci sayı dizisiyle C dilinde ne gibi programlar
yapabildiğimizi biliyor muydunuz??
Hadi gelin birlikte bugün 3 farklı Fibonacci programına
bakarak öğrenelim. :))))
*/

// 1- TEMEL SEVİYE FIBONACCI PROGRAMI

// n'e kadar olan fibonacci sayılarını yazdıran program

#include <stdio.h>

int fibonacci(int n){
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
//fibonacci fonksiyonunu yazdık. şimdi ana fonksiyona geçelim.

int main(){
    //kullanıcıdan bir sayı alalım.
    int n;
    printf("Bir sayi giriniz: ");
    scanf("%d", &n);

    //n'e kadar olan Fibonacci sayılarını yazdıralım.
    for(int i=0; i<n; i++){
        printf("%d ", fibonacci(i));
    }

   

//hadi kodumuzu çalıştıralım!

// 2- ORTA SEVİYE FIBONACCI PROGRAMI

//diegonal toplamları fibonacci olan Pascal Piramidini çizelim!

//n kadar katlı piramidimiz olsun.

printf("\n\nPascal Piramidi:\n");
for(int i=0; i<n; i++){
    int val = 1;
    //boşluklar
    for(int j=0; j<n-i; j++) printf(" ");
    //değerler
    for(int j=0; j<=i; j++){
        printf("%d ", val);
        val = val * (i - j) / (j + 1);
    }
    printf("\n");
}

 return 0;
}

//haydi kodumuzu çalıştıralım!

//harika şimdiii
// 3- İLERİ SEVİYE FIBONACCI PROGRAMI
