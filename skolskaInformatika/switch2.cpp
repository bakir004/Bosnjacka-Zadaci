#include <iostream>

using namespace std;

int main() {
    int a, b;
    char op;

    printf("Unesite broj, operator, broj: ");
    scanf("%d", &a);
    scanf("%c", &op);
    scanf("%d", &b);

    switch(op) {
        case '+':
            printf("%d", (a + b));
            break;
        case '-':
            printf("%d", (a - b));
            break;
        case '*':
            printf("%d", (a * b));
            break;
        case '/':
            printf("%.2f", ((float)a / (float)b));
            break;
        default: 
            printf("Operator nije validan");
            break;
    }
}