// Matura-2008-Zadanie-5.a.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
using namespace std;

string reverse(string napis) {
    string s = "";
    for (int n = napis.length() - 1; n >= 0; n--) {
        char znak = napis[n];
        s = s + znak;
    }
    return s;

};
const int ROZMIAR_SLOWA = 1000;
string slowa[ROZMIAR_SLOWA];

int main()
{
    ifstream plik("slowa.txt");
    ofstream hasla("hasla_a.txt"), hasla_skr("slowa_a.txt");
    string max_slowo = "";
    string min_slowo = "";

    for (int licznik = 0; !plik.eof() && licznik < ROZMIAR_SLOWA; licznik++) {

        plik >> slowa[licznik];
    }
    for (int i = 0; i < ROZMIAR_SLOWA; i++) {
        string slowo = slowa[i];
        if (max_slowo.length() < slowo.length()) {
            max_slowo = slowo;
        }
        if (min_slowo.length() > slowo.length() || min_slowo == "" ) {
            min_slowo = slowo;
        }
    
        hasla << reverse(slowo) << '\n';
    }
    hasla_skr << max_slowo << '\t' << max_slowo.length() << '\n' << min_slowo << '\t' << min_slowo.length() << '\n';
    return 0;
}



