//
// Created by Armand on 5/9/2023.
//

#include "Tranzactie.h"
#include <iostream>

Tranzactie::Tranzactie() {
    this->idTranzactie = 0;
    this->suma = 0;
}

Tranzactie::Tranzactie(int idTranzactieAtribuire, int sumaAtribuire, vector<tuple<int, int>> modalitateDePlata)
{
    this->idTranzactie = idTranzactieAtribuire;
    this->suma = sumaAtribuire;
    this->modalitateDePlata = modalitateDePlata; /// vector de tupluri de forma (bancnota, cate bancnote de tip bancnota folosite)
}

Tranzactie::~Tranzactie() = default;

ostream &operator<<(ostream &os, Tranzactie &tranzactie) {

    os <<"ID Tranzactie: " << tranzactie.idTranzactie << "\n";
    os << "Suma:" << tranzactie.suma << "\n";
    os << "Mod de plata: ";
    for(int i = 0; i < tranzactie.modalitateDePlata.size(); i++)
        os << get<0>(tranzactie.modalitateDePlata[i]) << 'x' << get<1>(tranzactie.modalitateDePlata[i]) << " ";
    cout << endl;
    return os;
}

void Tranzactie::saveTransactionToFile(const string &fileName) {
    std::ofstream file(fileName);
    if(file.is_open())
    {
        file.clear();
        //for(int)
        file << idTranzactie << endl;
        file << suma << endl;
        for(const auto& modalitate : modalitateDePlata)
        {
            file << std::get<0>(modalitate) << " " << std::get<1>(modalitate) << " ";
        }
        //file << endl;
        //file.close();
    }
}
