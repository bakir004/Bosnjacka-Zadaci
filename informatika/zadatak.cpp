#include <iostream>

int main() {
    int broj, sumaCifara = 0;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &broj);
        
        int cifra = broj % 10;
        broj /= 10;
        sumaCifara += cifra;
        cifra = broj % 10;
        broj /= 10;
        sumaCifara += cifra;
        cifra = broj % 10;
        sumaCifara += cifra;

        if(sumaCifara > 8)
            printf("Zbir cifara ovog broja je veci od 8\n");

        sumaCifara = 0;
    }
    
}