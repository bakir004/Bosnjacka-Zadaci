#include <iostream>
#include <vector>

using namespace std;

// Na ulazu programa se nalazi neka rečenica dužine najviše 2000 karaktera. Vaš zadatak je da 
// ispišete na ekran unesenu rečenicu transformisanu na sljedeći način:
//  Malo početno slovo svake riječi treba zamijeniti odgovarajućim velikim slovom.
//  Riječ u kojoj se pojavljuje najveći broj velikih ili malih slova A treba zamijeniti riječju 
// OVDJE. Ako se u čitavoj rečenici ne pojavljuje niti jedno slovo A, ne treba raditi 
// zamjenu. Ako se pojavljuje nekoliko riječi sa istim (najvećim) brojem slova A treba 
// zamijeniti prvu takvu riječ gledano s lijeva.
//  Svaka riječ duža od devet slova zamijenjena je sa prva tri slova i znakom tačka (npr. 
// riječ "skracenica" treba ispisati kao "skr.")
// Pretpostavlja se da je riječ neki niz znakova koji je sa obje strane omeđen znakom razmaka, 
// početkom ili krajem stringa. Ne trebate provjeravati da li se riječi sastoje iz slova ili sadrže i 
// neke znakove interpunkcije, trebate jednostavno pretpostaviti da su svi znakovi slova, a 
// znakove interpunkcije računati u riječ

void capitalizeWords(string &sentence) {
    if((int)sentence[0] >= 97 && (int)sentence[0] <= 122) {
        sentence[0] -= 32;
    }
    for (int i = 1; i < sentence.length(); i++) {
        if(sentence[i - 1] == ' ' && (int)sentence[i] >= 97 && (int)sentence[i] <= 122) {
            sentence[i] -= 32;
        }
    }
}

void replaceWordWithMostA(string &sentence) {
    string wordWithMostA;
    string word = "";
    int mostA = 0, currentA = 0;
    int index, wordLength;
    sentence += ' ';

    for (int i = 0; i < sentence.length(); i++) {
        if(sentence[i] == ' ') {
            if(currentA > mostA) {
                mostA = currentA;
                wordWithMostA = word;
                index = i - word.length();
                wordLength = word.length();
            }
            word = "";
            currentA = 0;
        } else {
            word += sentence[i];
            if(sentence[i] == 'A' || sentence[i] == 'a') {
                currentA++;
            }
        }
    }
    string newSentence = "";
    for (int i = 0; i < sentence.length(); i++) {
        if(i == index) {
            newSentence += "OVDJE";
            i += wordLength - 1;
        } else {
            newSentence += sentence[i];
        }
    }
    sentence = newSentence;
}

void shortenWords(string &sentence) {
    string word = "";
    string newSentence = "";
    sentence += ' ';

    for (int i = 0; i < sentence.length(); i++) {
        if(sentence[i] == ' ') {
            if(word.length() > 9) {
                newSentence += word.substr(0, 3) + '.' + ' ';
            } else {
                newSentence += word + " ";
            }
            word = "";
        } else {
            word += sentence[i];
        }
    }
    sentence = newSentence;
}

int main() {
    string sentence = "Dobro dosli na kantonalno takmicenje iz informatike u Sarajevu.";

    // getline(cin, sentence);

    capitalizeWords(sentence);
    replaceWordWithMostA(sentence);
    shortenWords(sentence);

    cout << sentence;
}