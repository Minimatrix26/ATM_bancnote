#include <iostream>
#include "Node.h"
#include "List.h"
#include "Colectie.h"
#include "ATM.h"
using namespace std;

int main() {
//    Colectie colectie;
//    colectie.adauga(10, 30);
//    colectie.adauga(50, 10);
//    List<int> bancnote = colectie.getAll();
//    List<int> occs = colectie.getAparitii();
//    for(int i = 0; i < bancnote.size(); i++)
//        cout << bancnote.get_at(i) << " : " << occs.get_at(i) << endl;
//
//    cout << "Dupa schimbare, colectia contine:" << endl;
//    Colectie someCol;
//    someCol.adauga(10,25);
//    someCol.adauga(50, 5);
//    List<int> someOccs = someCol.getAparitii();
//
//    for(int i = 0; i < someOccs.size(); i++)
//        cout << someOccs.get_at(i) << " ";
//    cout << endl;
//
//    colectie.setNewOccs(someOccs); // aici, se face asignarea lui 'counts' cu 'someOccs'
//    occs = colectie.getAparitii();         // dar tot trebuie apelat din nou getAparitii(), altfel, 'counts' va ramane versiunea anterioara
////  sau asa    occs = colectie.setNewOccs_2(someOccs);                                     // vom apela getAll() si getAparitii in functia de afisarea colectiei din clasa ATM
//    for(int i = 0; i < occs.size(); i++)
//        cout << bancnote.get_at(i) << " : " << occs.get_at(i) << endl;

//    Colectie colectie;
//    colectie.adauga(10,50);
//    colectie.adauga(50,10);
//    List<int> bancnote = colectie.getAll();
//    List<int> occs = colectie.getAparitii();
//
//    cout << "Aceasta este colectia noastra initial:" << endl;
//    for(int i = 0; i < colectie.dim(); i++)
//        cout << bancnote.get_at(i) << " : " << occs.get_at(i) << endl;
//
//    cout << "Vom modifica colectia, decrementand niste occs, astfel colectia va fi:" << endl;
//
//    Colectie newCol;
//    newCol.adauga(10, 25);
//    newCol.adauga(50, 5);
//    List<int> newOccs = newCol.getAparitii();
//
//    //occs = colectie.setNewOccs_2(newOccs);
//    colectie.setNewOccs(newOccs);
//    List<int> otherOccs = colectie.getAparitii();
//
//    for(int i = 0; i < colectie.dim(); i++)
//        cout << bancnote.get_at(i) << " : " << otherOccs.get_at(i) << endl;
//        //cout << bancnote.get_at(i) << " : " << occs.get_at(i) << endl;

    ATM atm;
    atm.runATM();
    // merge, avem vector de tranzactii,
    // colectia se modifica at. cand efectuam o plata

    // merge si din fisier, se actualizeaza bancnotele, putem afisa tranzactiile si cand sunt efectuate pe moment
    // eu zic ca e done

return 0;

}
