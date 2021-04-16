#include <iostream>

int main() {
    int n, max, min, i, broj;

    scanf("%d", &n);

    scanf("%d", &broj);

    min = broj;
    max = broj;

    for (i = 1; i < n; i++) {
        scanf("%d", &broj);
        
        if(broj < min)
            min = broj;

        if(broj > max)
            max = broj;
    }

    printf("najmanji %d, najveci %d", min, max);
}