#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int MAX_SUALLAR = 50;
string suallar[MAX_SUALLAR];
string cavablar[MAX_SUALLAR][3];
char duzgunCavablar[MAX_SUALLAR];
int sualSayi = 0;

void yeniSualYarat() {
    if (sualSayi >= MAX_SUALLAR) {
        cout << "Maksimum sual sayına çatdınız!\n";
        return;
    }

    cout << "Yeni sualı daxil edin: ";
    string sual;
    cin >> sual;

    cout << "Cavab A: ";
    string cavabA;
    cin >> cavabA;

    cout << "Cavab B: ";
    string cavabB;
    cin >> cavabB;

    cout << "Cavab C: ";
    string cavabC;
    cin >> cavabC;

    cout << "Düzgün cavabı seçin (A/B/C): ";
    char dogruCavab;
    cin >> dogruCavab;

    suallar[sualSayi] = sual;
    cavablar[sualSayi][0] = cavabA;
    cavablar[sualSayi][1] = cavabB;
    cavablar[sualSayi][2] = cavabC;
    duzgunCavablar[sualSayi] = dogruCavab;