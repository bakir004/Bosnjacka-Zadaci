#include <iostream>

using namespace std;

// Ulazna poruka se sastoji od ASCII karaktera gdje je svaki karakter predstavljen sa 7 bita.
// Izlazna kodirana poruka se sastoji od blokova nula.
// Blokovi se razdvajaju pomoću praznog mjesta.
// Dva susjedna bloka se koriste za predstavljanje serije bita koji imaju istu vrijednost (serija 
// jedinica ili serija nula):
// Prvi blok: je uvijek 0 ili 00. Ako je 0, onda serija sadrži samo jedinice, a ako je 00, onda 
// serija sadrži samo nule.
// Drugi blok: sadrži onoliko nula koliko se u seriji koju kodiramo nalazi jedinica ili nula.
// Na primjer, ako Chuck Norris želi poslati prvo slovo svog imena “C”, čija je binarna reprezentacija 
// 1000011, onda će se upotrebom ove tehnike dobiti:
//   0 0 (prva serija sadrži jednu jedinicu),
//   00 0000 (druga serija sadrži četiri nule),
//   0 00 (treća serija sadrži dvije jedinice).
// To znači da će Chuck Norris poslati 0 0 00 0000 0 00.

void reverseString(string &str) {
    for (int i = 0; i < str.length() / 2; i++)
    {
        char temp = str[i];
        str[i] = str[str.length() - 1 - i];
        str[str.length() - 1 - i] = temp;
    }
}

string intToBinary(int num) {
    string binaryNumber = "";
    while(num >= 1) {
        if(num % 2 == 0) {
            binaryNumber += "0";
        } else {
            binaryNumber += "1";
        }
        num /= 2;
    }
    while(binaryNumber.length() < 5) {
        binaryNumber += "0";
    }
    reverseString(binaryNumber);
    return binaryNumber;
}

string charToBinary(char letter) {
    string binaryLetter = "";
    int num;
    if((int)letter >= 65 && (int)letter <= 90) {
        num = (int)letter - 64;
        binaryLetter += "10";
    } else if ((int)letter >= 97 && (int)letter <= 122) {
        num = (int)letter - 96;
        binaryLetter += "11";
    }
    binaryLetter += intToBinary(num);
    return binaryLetter;
}

string charToUnary(char letter) {
    string binary = charToBinary(letter);
    string unary = "";
    int counter = 0;
    char lastChar;

    lastChar = binary[0];
    if(lastChar == '0') {
        unary += "00 0";
    } else {
        unary += "0 0";
    }
    for (int i = 1; i < binary.length(); i++)
    {
        lastChar = binary[i - 1];
        if(lastChar == binary[i]) {
            unary += "0";
        } else if(lastChar == '0' && binary[i] == '1') {
            unary += " 0 0";
        } else if(lastChar == '1' && binary[i] == '0') {
            unary += " 00 0";
        }
    }
    return unary;
}

void solve(string str) {
    for (int i = 0; i < str.length(); i++)
    {
        cout << charToUnary(str[i]) << " ";
    }
}

int main() {
    string inputString = "Ob";
    // cin >> inputString;

    solve(inputString);
    
}