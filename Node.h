//
// Created by Armand on 5/8/2023.
//

#ifndef LAB_4_5_SD_V1_NODE_H
#define LAB_4_5_SD_V1_NODE_H

template <typename T>
class List;

template <class T>
class Node {
private:
    T info;
    Node<T>* next;
    Node<T>* prev;
public:
    Node(T info, Node<T>* next, Node<T>* prev) : info(info), next(next), prev(prev){}
    Node(T info) : info(info){ next= nullptr; prev = nullptr;}
    friend class List<T>;
};


#endif //LAB_4_5_SD_V1_NODE_H
