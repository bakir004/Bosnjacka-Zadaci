#include <iostream>

using namespace std;

int main() {

    int N, rez;
    cin >> N;
    rez = N;

    while(N > 1) {
        N--;
        rez *= N;
    }

    cout << rez;

    return 0;
}