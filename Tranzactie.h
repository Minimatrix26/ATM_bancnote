//
// Created by Armand on 5/9/2023.
//

#ifndef LAB_4_5_SD_V1_TRANZACTIE_H
#define LAB_4_5_SD_V1_TRANZACTIE_H

#include <bits//stdc++.h>
#include <tuple>
#include <vector>
#include <string>

using namespace std;
class Tranzactie {
private:
    int idTranzactie;
    int suma;
    vector<tuple<int, int>> modalitateDePlata;
    string fileName;

public:
    Tranzactie();

    Tranzactie(int idTranzactieAtribuire, int sumaAtribuire, vector<tuple<int, int>> modalitateDePlata);

    ~Tranzactie();

    friend ostream &operator<<(ostream &os, Tranzactie &tranzactie);

    void saveTransactionToFile(const string& fileName);
};


#endif //LAB_4_5_SD_V1_TRANZACTIE_H
