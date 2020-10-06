//
// Created by josee on 06/10/2020.
//

#ifndef TC1031_DOUBLELINKEDLIST_H
#define TC1031_DOUBLELINKEDLIST_H

#include "Node.h"

class DoubleLinkedList {
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void addFirst(info data);
    void addLast(info data);
    void sort();
    void print();
private:
    Node *head;
    Node *tail;
    int size;
};

DoubleLinkedList :: DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}
DoubleLinkedList :: ~DoubleLinkedList() {
    Node *curr1 = head;
    Node *curr2 = tail;
    while (head != nullptr && tail != nullptr) {
        head = head ->getNext();
        delete curr1;
        curr1 = head;
        tail = tail -> getPrev();
        delete curr2;
        curr2 = tail;
    }
}
void DoubleLinkedList :: addFirst(info data) {
    if (head != nullptr) {
        head = new Node (data, head -> getPrev(), head);
    } else {
        head = new Node (data, head, tail);
    }
    size++;
}

void DoubleLinkedList ::addLast(info data) {
    if (tail != nullptr) {
        tail = new Node (data, tail, tail->getNext());
    } else {
        tail = new Node (data, head, tail);
    }
    size++;
}

void DoubleLinkedList ::sort() {
    int temp;
    bool interruptor = true;
    for (int pas = 0; pas < size - 1 && interruptor; ++pas) {
        interruptor = false;
        for (int j = 0; j < size - 1 - pas; ++j) { // Estoy trabajando en esto - J
            if (vec[j+1] < vec[j]) {
                temp = vec[j+1];
                vec[j+1] = vec[j];
                vec[j] = temp;
                interruptor = true;
            }
        }
    }
}

void DoubleLinkedList ::print() {
    cout << "Linked List:" << endl;
    Node *curr = head;
    while (curr != nullptr) {
        cout << "--------------------------------" << endl;
        cout << curr->getData().fechaHora << " ";
        cout << curr->getData().ip << " ";
        cout << curr->getData().key << " ";
        cout << curr->getData().motivo << endl;

        curr = curr->getNext();
    }
}

#endif //TC1031_DOUBLELINKEDLIST_H
