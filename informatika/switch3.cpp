#include <iostream>

using namespace std;

int main() {
    int mjesec;

    printf("Unesite broj mjeseca: ");
    scanf("%d", &mjesec);

    switch(mjesec) {
        case 1:
            printf("Januar\n");
        case 2:
            printf("Februar\n");
        case 3:
            printf("Mart\n");
        case 4:
            printf("April\n");
        case 5:
            printf("Maj\n");
        case 6:
            printf("Juni\n");
        case 7:
            printf("Juli\n");
        case 8:
            printf("August\n");
        case 9:
            printf("Septembar\n");
        case 10:
            printf("Oktobar\n");
        case 11:
            printf("Novembar\n");
        case 12:
            printf("Decembar\n");
            break;

        default: 
            printf("Ne postoji %d-ti mjesec...", mjesec);
            break;
    }
}