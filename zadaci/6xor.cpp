#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Dat je neki niz prirodnih brojeva. Ako na svaki član tog niza primijenimo operaciju binarni XOR 
// (ekskluzivna disjunkcija) sa nekim prirodnim brojem X dobićemo neki drugi niz prirodnih 
// brojeva.
// Recimo da niz glasi 4 2 3 1. Ako je X=6 dobićemo niz 2 4 5 6.
// Vaš zadatak je da napravite program koji za uneseni niz provjerava da li postoji X takvu da se 
// nakon primjene XOR dobije niz koji je sortiran u rastućem poretku (ali ne strogo rastućem, 
// dakle dozvoljeno je da dva susjedna člana budu jednaka). U prethodnom primjeru za niz 4 2 3 
// 1 postoji takvo X i ono iznosi 6.

// pretpostavljam da brojevi u binarnom prikazu imaju isti broj bitova kao u primjeru,
// i da X mora imati broj bitova <= broju bitova u brojevima u nizu

void reverseString(string &str) {
    for (int i = 0; i < str.length() / 2; i++){
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
    reverseString(binaryNumber);
    return binaryNumber;
}

void fillBinary(string &num, int fill) {
    reverse(num.begin(), num.end());
    while(num.length() < fill) {
        num+="0";
    }
    reverse(num.begin(), num.end());
}

int binaryToInt(string binary) {
    int counter = 0, num = 0;
    for (int i = binary.size() - 1; i >= 0; i--) {
        if(binary[i] == '1') {
            num += pow(2, counter);
        }
        counter++;
    }
    return num;
}

string XOR(string binary1, string x) {
    string binaryRes = "";

    for (int i = 0; i < binary1.length(); i++) {
        if(binary1[i] == x[i]) {
            binaryRes += "0";
        } else {
            binaryRes += "1";
        }
    }
    return binaryRes;
}

bool checkIfAscending(vector<string> binaryNums) {
    vector<int> nums;
    for (int i = 0; i < binaryNums.size(); i++) {
        nums.push_back(binaryToInt(binaryNums[i]));
    }
    for (int i = 1; i < nums.size(); i++) {
        if(nums[i - 1] > nums[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    // int n;
    // vector<int> numbers;

    vector<int> numbers = {4,2,3,1};
    vector<string> binaryNums;

    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     int num;
    //     cin >> num;
    //     numbers.push_back(num);
    // }

    for (int i = 0; i < numbers.size(); i++) {
        binaryNums.push_back(intToBinary(numbers[i]));
    }

    int largestSize = 0;
    for (int i = 0; i < binaryNums.size(); i++) {
        if(binaryNums[i].length() > largestSize)
            largestSize = binaryNums[i].length();
    }
    for (int i = 0; i < binaryNums.size(); i++) {
        fillBinary(binaryNums[i], largestSize);
    }

    int maxX = pow(2, largestSize) - 1;

    for (int i = 1; i < maxX; i++) {
        string binaryX = intToBinary(i);
        fillBinary(binaryX, largestSize);
        vector<string> binaryNumsAfterXOR;

        for (int j = 0; j < binaryNums.size(); j++) {
            binaryNumsAfterXOR.push_back(XOR(binaryNums[j], binaryX));
        }

        if(checkIfAscending(binaryNumsAfterXOR)) {
            cout << "X: " << binaryToInt(binaryX);
            return 0;
        }
    }
    
    cout << "X doesn't exist";
}