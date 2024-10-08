#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int MAX_SUALLAR = 10;
string suallar[MAX_SUALLAR];
string cavablar[MAX_SUALLAR][3];
char duzgunCavablar[MAX_SUALLAR];
int sualSayi = 0;

void yeniSualYarat() {
    if (sualSayi >= MAX_SUALLAR) {
        cout << "Maksimum sual sayına çatdınız!\n";
        return;
    }
