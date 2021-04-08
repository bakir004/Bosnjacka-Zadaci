#include <iostream>
#include <vector>

using namespace std; 

void solve(int anja, int elma, int una, string boja) {
    int anjaTemp = anja, elmaTemp = elma, unaTemp = una;
    int elmaDajeAnji = 0, anjaDajeElmi = 0;

    int avgAnjaElma = (anja + elma) / 2;
    if(anja < elma - 1) {
        while(elma > anja) {
            elma--;
            anja++;
            elmaDajeAnji++;
        }
    }    
    
}

int main() {
    int aRed, aBlue, aYellow;
    int eRed, eBlue, eYellow;
    int uRed, uBlue, uYellow;

    cin >> aRed >> aBlue >> aYellow;
    cin >> eRed >> eBlue >> eYellow;
    cin >> uRed >> uBlue >> uYellow;

    solve(aRed, eRed, uRed, "crvenih");

    return 0;
}