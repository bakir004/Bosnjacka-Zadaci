#include <iostream>

using namespace std;

// tipFunkcije imeFunkcije(tipParametra1 imeParametra1, tipParametra2 imeParametra2...)

int parnost(int broj) {
    if(broj % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    while(true) {
        int broj;
        cin >> broj;

        if(broj == 0) {
            break;
        } else {
            cout << parnost(broj) << "\n";
        }
    }
    
    cout << "kraj";
    return 0;
}