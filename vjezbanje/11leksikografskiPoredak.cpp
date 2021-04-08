#include <iostream>
#include <vector>

using namespace std; 

int getVal(char letter){
    return (int)letter-96;
}

bool lettersValid(string letters){
    return true;
}

int calculateValue(string letters){
    if(letters.length()==1){
        return getVal(letters[0]);
    } else if (letters.length()==2){
        if(lettersValid(letters))
        return getVal(letters[0]) * 26 - getVal(letters[0]) + getVal(letters[1]) - getVal(letters[0]);
        // bc 52 = n1 * 26 - 1 + n2 * 1 = 53
        //FIRSTNUM * 26 - (NUMBER_IN_ALPHABET) + SECOND_NUM_DIFF_FROM_BASE * 1
    }
    return 0;
}



int main() {

    
    // int brojac = 0;
    // int brojac2 = 0;
    // char n1, n2;
    // // brojac += n * (n + 1) / 2;
    // // cout << brojac << "\n";
    // int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0;
    // cin >> n1 >> n2;

    // for (int i = 1; i <= 26; i++)
    // {
    //     b1++;
    //     for (int j = i + 1; j <= 26; j++)
    //     {
    //         b2++;
    //         for (int k = j + 1; k <= 26; k++)
    //         {
    //             b3++;
    //             for (int l = k + 1; l <= 26; l++)
    //             {
    //                 b4++;
    //                 for (int m = l + 1; m <= 26; m++)
    //                 {
    //                     b5++;
    //                 }
    //             }
    //         } 
    //     }
    // }

    // for (int i = 0; i < 26; i++)
    // {
    //     brojac += 26 - i;
    // }
    // brojac = 26 * 27 / 2;
    string letters="ad";

    // cout<<calculateValue(letters);    
    // cout << b1 << "\n";
    // cout << b2 << "\n";
    // cout << b3 << "\n";
    // cout << b4 << "\n";
    // cout << b5 << "\n";

    // cout << brojac << "\n";

    return 0;
}




// a   1
// b   2
// c   3
// z   26
// ab  27
// ac  28
// az 51 = n1 * 26 + n2 * 1
// bc 52 = n1 * 26 - 1 + n2 * 1 = 53
// bf 55 = FIRSTNUM * 26 - (NUMBER_IN_ALPHABET) + SECOND_NUM_DIFF_FROM_BASE * 1
// yz 351 = n1 * 26
// abc 352
// xyz 2951
// abcd 2952
// TEST : abcz 2976 
// TEST : abde 2977
// wxyz 17901
// abcde 17902
// vwxyz   83681
// otro 0