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
    
    sualSayi++;
    cout << "Sual əlavə olundu.\n";
}
void suallaraBax() {
    if (sualSayi == 0) {
        cout << "Heç bir sual yoxdur!\n";
        return;
    }
    for (int i = 0; i < sualSayi; i++) {
        cout << i + 1 << ". " << suallar[i] << endl;
        cout << "A) " << cavablar[i][0] << endl;
        cout << "B) " << cavablar[i][1] << endl;
        cout << "C) " << cavablar[i][2] << endl;
        cout << "Düzgün cavab: " << duzgunCavablar[i] << endl;
    }
}
void editSual() {
    suallaraBax();
    if (sualSayi == 0) return;

    int secim;
    cout << "Redaktə etmək istədiyiniz sual nömrəsini seçin: ";
    cin >> secim;
    if (secim < 1 || secim > sualSayi) {
        cout << "Yanlış seçim.\n";
        return;
    }
    cout << "Yeni sualı daxil edin: ";
    string yeniSual;
    cin >> yeniSual;

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

    int index = secim - 1;
    suallar[index] = yeniSual;
    cavablar[index][0] = cavabA;
    cavablar[index][1] = cavabB;
    cavablar[index][2] = cavabC;
    duzgunCavablar[index] = dogruCavab;

    cout << "Sual yeniləndi.\n";
}
void guestMode() {
    if (sualSayi == 0) {
        cout << "Heç bir sual yoxdur!\n";
        return;
    }
