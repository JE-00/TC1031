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
    int size();
    void sort();
    void print();
private:
    Node *head;
    Node *tail;
    int tamanio;
};

DoubleLinkedList :: DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    tamanio = 0;
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
        head = tail = new Node (data, head, tail);
    }
    tamanio++;
}

void DoubleLinkedList ::addLast(info data) {
    if (tail != nullptr) {
        tail = new Node (data, tail, tail->getNext());
    } else {
        tail = head = new Node (data, head, tail);
    }
    tamanio++;
}

int DoubleLinkedList ::size() {
    return tamanio;
}

void DoubleLinkedList ::sort() {
    Node *curr1 = head;
    Node *curr2 = nullptr;
    Node *aux = nullptr;
    bool interruptor = false;

    if (head == nullptr) return;
    do {
        interruptor = false;
        while (curr1 -> getNext() != curr2) {
            if (curr1 -> getData().key > curr1->getNext()->getData().key) {
                aux->setData(curr1->getData());
                curr1->setData(curr1->getNext()->getData());
                curr1->getNext()->setData(aux->getData());
                interruptor = true;
            }
            curr1 = curr1 ->getNext();
        } curr2 = curr1;
    } while (interruptor);
}

void DoubleLinkedList ::print() {
    cout << "Linked List:" << endl;
    Node *curr = head;
    while (curr != nullptr) {
        cout << "--------------------------------" << endl;
        cout << curr->getData().fechaHora << " ";
        cout << curr->getData().ip << " ";
        cout << curr->getData().key;
        cout << curr->getData().motivo << endl;

        curr = curr->getNext();
    }
}

#endif //TC1031_DOUBLELINKEDLIST_H
