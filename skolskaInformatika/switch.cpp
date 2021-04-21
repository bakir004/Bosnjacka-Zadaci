#include <iostream>

using namespace std;

int main() {
    int n;
    printf("Unesite broj od 1 do 5: ");
    scanf("%d", &n);

    switch(n) {
        case 1:
            printf("Jedan");
            break;
        case 2:
            printf("Dva");
            break;
        case 3:
            printf("Tri");
            break;
        case 4:
            printf("Cetiri");
            break;
        case 5:
            printf("Pet");
            break;
        default: 
            printf("Unos nije validan");
            break;
    }
}