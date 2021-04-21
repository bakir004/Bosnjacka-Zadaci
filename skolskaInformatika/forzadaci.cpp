#include <iostream>
#include <cmath>
#include <limits>

int main() {

    // 1. ======================================================

    // int suma = 0;

    // for (int i = 1; i < 30; i++)
    // {
    //     if(i % 9 == 0)
    //         suma += i;
    // }
    // printf("Suma %d\n\n", suma);

    // 2. ======================================================

    // int n, broj;

    // scanf("%d", &n);
    
    // int min = INT_MAX;
    // int max = INT_MIN;

    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &broj);
    //     if(broj > max)
    //         max = broj;
    //     if(broj < min)
    //         min = broj;
    // }
    // printf("Najveci %d, najmanji %d \n\n", max, min);

    // 3. ======================================================

    // for (int i = 20; i < 100; i++)
    // {
    //     if(i % 11 == 0) {
    //         if(i == 77)
    //             printf("sedamdeset sedam ");
    //         else
    //             printf("%d ", i);
    //     }
    // }
    // printf("\n\n");
    
    // 4. ======================================================

    // int brojac = 0;
    // for (int i = 5; i < 150; i++)
    // {
    //     if(i % 13 == 0)
    //         brojac++;
    // }
    // printf("%d\n\n", brojac);

    // 5. ======================================================

    // int n, broj;

    // scanf("%d", &n);

    // int brojac = 0, zbir = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &broj);
    //     if(broj % 2 == 0) {
    //         brojac++;
    //         zbir += broj;
    //     }
    // }
    // printf("Parnih %d, zbir %d \n\n", brojac, zbir);

    // 6. ======================================================

    // int n, broj;

    // scanf("%d", &n);

    // int suma = 0, brojac = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &broj);
    //     brojac++;
    //     suma += broj;
    // }
    // printf("Aritmeticka sredina %f", (float)suma / (float)brojac);

    // 7. ======================================================

    // #include <iostream>

    // int broj, sumaCifara = 0;

    // for (int i = 0; i < 10; i++)
    // {
    //     scanf("%d", &broj);
        
    //     int cifra = broj % 10;
    //     broj /= 10;
    //     sumaCifara += cifra;
    //     cifra = broj % 10;
    //     broj /= 10;
    //     sumaCifara += cifra;
    //     cifra = broj % 10;
    //     sumaCifara += cifra;

    //     if(sumaCifara > 8)
    //         printf("Zbir cifara ovog broja je veci od 8\n");

    //     sumaCifara = 0;
    // }

    // 8. ======================================================

    // int n, broj;

    // scanf("%d", &n);

    // int brojacNeparnih = 0, brojacParnih = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &broj);
    //     if(broj % 2 == 0)
    //         brojacParnih++;
    //     else 
    //         brojacNeparnih++;
    // }
    // printf("Neparnih: %d, Parnih: %d", brojacNeparnih, brojacParnih);

    // 9. ======================================================

    // int brojac = 0;

    // for (int i = 5; i < 50; i++)
    // {
    //     if(i % 3 == 0 || i % 5 == 0)
    //         brojac++;
    // }
    
    // printf("Brojeva djeljivih sa 3 ili 5 je: %d", brojac);

    // 10. ======================================================

    // for (int i = 1; i < 20; i++)
    // {
    //     if(i % 2 == 1)
    //         printf("%f", (float)(sqrt(i)));
    // }

    // 11. ======================================================

    // program moze rijesit za visecifrene brojeve
    // for (int i = 0; i < 10; i++)
    // {
    //     int broj, suma = 0, brojac = 0;
    //     scanf("%d", &broj);
    //     while(broj >= 1) {
    //         int cifra = broj % 10;
    //         broj /= 10;
    //         suma += cifra;
    //         brojac++;
    //     }
    //     printf("%f\n", (float)(suma / brojac));
    //     brojac = 0;
    //     suma = 0;
    // }
}
