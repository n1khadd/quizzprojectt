﻿#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int sual_limit = 50;
string suallar[sual_limit];
string cavablar[sual_limit][3];
char duzgunCavablar[sual_limit];
int sualSayi = 0;

void yeniSualYarat() {
    if (sualSayi >= sual_limit) {
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
        cout << "Yanlis seçim.\n";
        return;
    }
    cout << "Suali redakte edin: ";
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
    int dogruSay = 0;
    int yanlisSay = 0;

    srand(time(0));

    for (int i = 0; i < sualSayi; i++) {
        int randomIndex = rand() % sualSayi;

        cout << "Sual: " << suallar[randomIndex] << endl;
        cout << "A) " << cavablar[randomIndex][0] << endl;
        cout << "B) " << cavablar[randomIndex][1] << endl;
        cout << "C) " << cavablar[randomIndex][2] << endl;

        char cavab;
        cout << "Cavabınızı daxil edin (A/B/C): ";
        cin >> cavab;

        if (cavab == duzgunCavablar[randomIndex]) {
            cout << "Doğru cavab!\n";
            dogruSay++;
        }
        else {
            cout << "Yanlış cavab! Düzgün cavab: " << duzgunCavablar[randomIndex] << endl;
            yanlisSay++;
        }
        cout << endl;
    }
    cout << "Doğru cavablar: " << dogruSay << endl;
    cout << "Yanlış cavablar: " << yanlisSay << endl;

    int toplamCavab = dogruSay + yanlisSay;
    if (toplamCavab > 0) {
        double faiz = (double)dogruSay / toplamCavab * 100;
        cout << "Doğru cavabların faizi: " << faiz << "%" << endl;
    }
    else {
        cout << "Heç bir cavab daxil edilməyib.\n";
    }
}

void adminMenu() {
    while (true) {
        cout << "\nAdmin Menyu\n";
        cout << "1. Yeni sual yarat\n";
        cout << "2. Suallara bax\n";
        cout << "3. Sualı redaktə et\n";
        cout << "4. Cixis\n";
        cout << "Seciminizi daxil edin: ";

        int secim;
        cin >> secim;

        switch (secim) {
        case 1:
            yeniSualYarat();
            break;
        case 2:
            suallaraBax();
            break;
        case 3:
            editSual();
            break;
        case 4:
            cout << "Admin menyusundan cixilir...\n";
            return;
        default:
            cout << "Yanlis secim!\n";
        }
    }
}

int main() {
    while (true) {
        cout << "\nGiris Menyu\n";
        cout << "1. Admin\n";
        cout << "2. Guest\n";
        cout << "3. Cixis\n";
        cout << "Seciminizi daxil edin: ";

        int rol;
        cin >> rol;

        if (rol == 1) {
            adminMenu();
        }
        else if (rol == 2) {
            guestMode();
        }
        else if (rol == 3) {
            cout << "Proqramdan cixilir...\n";
            break;
        }
        else {
            cout << "Yanlis rol secimi!\n";
        }
    }
}
