#include <iostream>

using namespace std;

int main() {
    // 1. zadatak - tablica mnozenja

    // for (int i = 1; i <= 10; i++) {
    //     for (int j = 1; j <= 10; j++) {
    //         cout << i << "x" << j << "=" << i*j << "\n";
    //     }
    // }

    // 2. zadatak - kvadrat

    // int N;
    // cin >> N;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }
    
    // 3. zadatak - trougao

    // int N;
    // cin >> N;

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N - i; j++) {
    //         cout << "*";
    //     }
    //     cout << "\n";
    // }

    // 4. zadatak - trougao 2

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        
        for (int j = 0; j < N - i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    

    return 0;
}