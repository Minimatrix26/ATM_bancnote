//
// Created by Armand on 5/8/2023.
//

#ifndef LAB_4_5_SD_V1_LIST_H
#define LAB_4_5_SD_V1_LIST_H
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class List {
private:
    /* definiti o reprezentare inlantuita pe elementele din lista */
    Node<T>* first;
    Node<T>* last; // DLL (double linked list), in curs7_p Copie se afla SLL (simple linked list)

public:
    /// constructor implicit
    List () {
        this->first = nullptr;
        this->last = nullptr;
    }

    /// \return dimensiunea listei
    int size() const;

    ///  verifica daca lista e vida
    /// \return true, daca lista e vida, altfel returneaza false
    bool is_empty() const;

    /// adaugare element la sfarsit
    /// \param e - elementul adaugat
    void push_back(T e);

    /// adaugare element la inceput (un fel de set_at(0, e))
    /// \param e
    void push_front(T e);

    ///
    /// \param i - pozitia unui elem in lista , 0<=i<size()
    /// \return  elementul de pe pozitia i
    /// \raise   exceptie daca i nu e valid
    T get_at(int i) const;

    // modifica element de pe pozitia i si returneaza vechea valoare
    //arunca exceptie daca i nu e valid
    T update(int i, T e);


    // adaugare element pe o pozitie i
    //arunca exceptie daca i nu e valid
    void set_at(int i, T e);

    // sterge element de pe o pozitie i si returneaza elementul sters
    //arunca exceptie daca i nu e valid
    T delete_at(int i);

    // cauta element si returneaza prima pozitie pe care apare (sau -1)
    int search(T e)  const;

    // returnare iterator
//    Iterator iterator() const;
    List<T> getAll();

    List<T>& operator=(const List<T>& other);

//    List(const List<T>& other);

    ///
    /// destructor
    ~List();

};

//template<class T>
//List<T>::List(const List<T> &other) {
//    Node<T>* current = other.first;
//    Node<T>* prev = nullptr;
//    while (current != nullptr) {
//        Node<T>* newNode = new Node<T>(current->info);
//        if (prev == nullptr) {
//            first = newNode;
//        } else {
//            prev->next = newNode;
//            newNode->prev = prev;
//        }
//        prev = newNode;
//        current = current->next;
//    }
//}

template<class T>
List<T> &List<T>::operator=(const List<T> &other) {
    if (this != &other) {
        // curatam lista curenta
        while (first != nullptr) {
            Node<T>* temp = first;
            first = first->next;
            delete temp;
        }

        // facem o copie a elementelor din lista 'other' (deep copy)
        Node<T>* current = other.first;
        Node<T>* prev = nullptr;
        while (current != nullptr) {
            Node<T>* newNode = new Node<T>(current->info);
            if (prev == nullptr) {
                first = newNode;
            }
            else {
                prev->next = newNode;
                newNode->prev = prev;
            }
            prev = newNode;
            current = current->next;
        }
    }

    return *this;
}

template<class T>
List<T> List<T>::getAll() {
    List<T> result;

    Node<T>* crt = first;
    while(crt != nullptr)
    {
        result.push_back(crt->info);
        crt = crt->next;
    }

    return result;
}

template<class T>
void List<T>::push_front(T e) {
    auto newNode = new Node<T>(e);
    // daca lista este goala (first == nullptr, last == nullptr)
    if(first == nullptr)
    {
        first = newNode;
        last = newNode;
    }
    else{ // daca lista are deja elemente
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    }
}

template<class T>
List<T>::~List() {

    while(first != nullptr)
    {
        Node<T>* node = first;
        first = first->next;
        delete node;
    }
}

template<class T>
T List<T>::delete_at(int i) {
    if( i < 0 || i>= size())
        throw std::invalid_argument("Pozitia nu este valida!");

    int noElements = 0;
    Node<T>* crt = first;
    while(noElements < i)
    {
        noElements ++;
        crt = crt->next;
    }

    T e = crt->info;
    if(crt->prev != nullptr)
        crt->prev->next = crt->next;
    else
        first = crt->next;

    if(crt->next != nullptr)
        crt->next->prev = crt->prev;
    else
        last = crt->prev;

    delete crt;
    return e;


//    Node<T> *crt = first;
//    Node<T> *prev;
//    Node<T> *newNode;
//
//    if(i > 0){
//        while(noElements < i){
//            noElements ++;
//            prev = crt;
//            crt = crt->next;
//        }
//        newNode = crt;
//        prev->next = crt->next;
//        T e = newNode->info;
//        delete newNode;
//        return e;
//    }
//    else
//    {
//        newNode = first;
//        first = newNode->next;
//        T e = newNode->info;
//        delete newNode;
//        return e;
//    }
}

template<class T>
void List<T>::set_at(int i, T e) {
    if( i < 0 || i>= size())
        throw std::invalid_argument("Pozitia nu este valida!");

    Node<T>* newNode = new Node<T>(e);
    if(i == 0) // newNode vine in locul lui first
    {
        newNode->next = first;
        first->prev = newNode; // if(first != nullptr) ?
        first = newNode;
    }
    else
    {
        Node<T>* crt = first;
        int noELements = 0;
        while(noELements < i - 1)
        {
            crt = crt->next;
            noELements ++;
        }
        newNode->next = crt->next;
        newNode->prev = crt;
        crt->next->prev = newNode; // if(crt->next != nullptr) ?
        crt->next = newNode;
    }
}

template<class T>
int List<T>::search(T e) const { // done, la fel
    Node<T>* node = first;
    int contor = 0;
    while(node != nullptr)
    {
        if(node->info == e)
            return contor;
        node = node->next;
        contor++;
    }
    return -1;
}

template<class T>
T List<T>::update(int i, T e) { //done (la fel ca la lista simplu inlantuita)
    if(i < 0 || i >= size())
        throw invalid_argument("Pozitia e invalida!");
    Node<T>* crt = first;
    int noE = 0;
    while (noE < i){ // ca la get_at, ne ducem exact pe elem de pe pozitia i
        crt = crt->next;
        noE++;
    }
    T old_value = crt->info;
    crt->info = e;

    return old_value;
}

template<class T>
T List<T>::get_at(int i) const { // done (la fel ca la lista simplu inlantuita)
    if(i < 0 || i >= size())
        throw invalid_argument("Pozitia e invalida!");
    Node<T>* crt = first;
    int noE = 0;
    while (noE < i){ // ne ducem cu crt exact pe elem de pe pozitia i
        crt = crt->next;
        noE++;
    }
    return crt->info;
}

template<class T>
void List<T>::push_back(T e) { // done
    Node<T>* newNode = new Node<T>(e);
    if(first == nullptr){
        first = newNode;
        last = newNode;
    }
    else{ // adaugam la sfarsit
//        Node<T>* last = first;
//        while (last->next != nullptr){
//            last= last->next;
//        }
//        last->next = newNode;
//        newNode->prev = last;
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }

}

template<class T>
bool List<T>::is_empty() const {
    return first == nullptr;
}

template<class T>
int List<T>::size() const { // done
    int contor = 0;
    Node<T>* last = first;
    while(last != nullptr)
    {
        contor++;
        last = last->next;
    }
    return contor;
}

#endif //LAB_4_5_SD_V1_LIST_H
