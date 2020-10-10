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
// addFirst
void DoubleLinkedList :: addFirst(info data) {
    if (head != nullptr) { // Si head no es null, significa que ya hay nodos en la linkedlist

        Node *nodo = new Node (data, head->getPrev(), head); // Si ya hay nodos, creamos un nodo que reemplazara al head actual
                                                            // su prev será null y su next será el head anterior
        head -> setPrev(nodo); // el nuevo nodo se vuelve el previo de head
        head = nodo; // el nuevo nodo se convierte en head

    } else { // Si head es null entonces no hay nodos y se debe crear el primer nodo

        head = tail = new Node (data, nullptr, nullptr); // En el primer nodo head = tail porque es un único elemento
                                                                    // su prev y next serán null porque apuntan a nada
    }
    tamanio++; // Pues su tamaño sube en uno
}

// addLast
void DoubleLinkedList ::addLast(info data) {
    if (tail != nullptr) { // Si tail no es null, significa que ya hay nodos en la linkedlist
        Node *nodo = new Node (data, tail, nullptr); // Si ya hay nodos, creamos un nodo que reemplazara al tail actual
                                                                    // su prev será el tail anterior y su next será el nullptr
        tail->setNext(nodo); // el nuevo nodo se convierte en el siguiente de tail
        tail = nodo; // el nuevo nodo se convierte en tail (la neta aqui no sé que hice pero ya funciona jajajaja wuu) ¯\_(ツ)_/¯

    } else { // Si tail es null entonces no hay nodos y se debe crear el primer(y por consecuencia último) nodo

        tail = head = new Node (data, nullptr, nullptr); // En el primer nodo head = tail porque es un único elemento
                                                                    // su prev y next serán null porque apuntan a nada
    }
    tamanio++; // Pues su tamaño sube en uno
}

int DoubleLinkedList ::size() {
    return tamanio;
}
// Bubble sort mexicaneado
void DoubleLinkedList :: sort() {

    Node *curr1 = head; // Nodo apuntador 1, almacena el nodo en el que se trabaja

    Node *curr2 = nullptr; // Nodo apuntador 2, almacena el valor del apuntador 1 anterior

    Node *aux = nullptr; // Nodo auxiliar para intercambiar valores

    bool interruptor = false; // Interruptor que indica si se hizo el intercambio

    if (head == nullptr) return; // Si head es un null, la lista está vacía, no hay que buscar, se sale de función

    do {

        interruptor = false; // Siempre inicia en falso, porque no se ha hecho el cambio

        while (curr1 -> getNext() != curr2) { // Mientras el siguiente del nodo en curr1 sea distinto al actual, entra al while

            if (curr1 -> getData().key > curr1->getNext()->getData().key) { // Si la key del nodo actual es mayo a la del siguiente, entra

                aux->setData(curr1->getData()); // Aux toma el valor de curr1

                curr1->setData(curr1->getNext()->getData()); // curr1 toma el valor del siguiente

                curr1->getNext()->setData(aux->getData()); // el siguiente de curr1 toma el valor de curr1 almacenado en aux

                interruptor = true; // Se hizo el cambio correctamente
            }
            curr1 = curr1 ->getNext(); // curr1 avanza un lugar

        } curr2 = curr1; // cuando curr1 sea distinto al actual, curr2 (actual) toma el valor de curr1

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
