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
    int getTamanio();
    info get(int pos);
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
void DoubleLinkedList :: addLast(info data) {
    Node *prevTail, *newTail;
    if (head == nullptr) {
        newTail = new Node(data);
        head = newTail;
        tail = nullptr;
    } else {
        if (tail == nullptr) {
            tail = new Node(data);
            head->setNext(tail);
            tail->setPrev(head);
        } else {
            prevTail = tail;
            newTail = new Node(data);

            newTail->setPrev(prevTail);
            prevTail->setNext(newTail);
            tail = newTail;
        }
    }
    /*if (tail != nullptr) { // Si tail no es null, significa que ya hay nodos en la linkedlist
        Node *nodo = new Node (data); // Si ya hay nodos, creamos un nodo que reemplazara al tail actual
                                                                    // su prev será el tail anterior y su next será el nullptr
        //aux->setNext(nodo); // el nuevo nodo se convierte en el siguiente de tail
        nodo->setPrev(tail);
        aux->setNext(nodo);


        tail = nodo; // el nuevo nodo se convierte en tail (la neta aqui no sé que hice pero ya funciona jajajaja wuu) ¯\_(ツ)_/¯


    } else { // Si tail es null entonces no hay nodos y se debe crear el primer(y por consecuencia último) nodo

        Node *nodo = new Node (data, nullptr, nullptr);
        tail = head = nodo; // En el primer nodo head = tail porque es un único elemento
                                                                    // su prev y next serán null porque apuntan a nada
    }*/
    tamanio++; // Pues su tamaño sube en uno
}

int DoubleLinkedList ::size() {
    return tamanio;
}

// Intento de quicksort mexicaneado
Node* particion(Node *curr1, Node *curr2) {
    long long elempivote = curr2->getData().key; // elempivote toma el valor del key del curr2 (segundo limite de la particion)

    Node *aux = curr1->getPrev(); // aux es un nodo que toma el valor del pivote

    info temp; // temp es una variable para facilitar el intercambio de datos entre nodos

    for (Node *i = curr1; i != curr2; i = i->getNext()) { // Del curr1 al curr2, i va recorriendo nodos

        if (i->getData().key <= elempivote) { // Si la key nodo actual en i es menor o igual que la del elempivote (o sea a la del ultimo)

            aux = (aux == nullptr) ? curr1 : aux -> getNext(); // Si aux no es null toma el valor de curr1 sino avanza un nodo

            // Se hace el cambio de datos entre los nodos en i y aux
            temp = aux->getData(); // temp toma el valor del dato en aux

            aux->setData(i->getData()); // el dato aux toma el vlaor del dato en i

            i->setData(temp); // el dato en i toma el valor de temp
        }
    }
    aux = (aux == nullptr) ? curr1 : aux -> getNext(); // Si aux es null toma el valor de curr1, sino avanza un nodo

    // Se hace el cambio de datos entre los nodos en curr2 y aux
    temp = aux->getData(); // temp toma el valor del dato en aux

    aux->setData(curr2->getData()); // el dato aux toma el valor del dato en curr2

    curr2->setData(temp); // el dato en curr2 toma el valor de temp

    return aux; // se regresa aux para que se tome como el valor del pivote
}
void quicksort(Node *curr1, Node *curr2) {
    Node *pivote; // pivote -> el nodo alrededor del que se basa el sort
    if (curr2 != nullptr && curr1 != curr2 && curr1 != curr2 ->getNext()) { // si curr2 no es null, ni curr1 es igual a ...
                                                                            // curr2, ni curr1 es igual al siguiente de curr2

        pivote = particion(curr1, curr2); // pivote toma el valor del nodo que regrese la partición de curr1 a curr2

        quicksort(curr1, pivote->getPrev()); // se hace recursividad de curr1 a uno antes del pivote

        quicksort(pivote->getNext(), curr2); // se hace recursividad de uno despues del pivote a curr2
    }
}
void DoubleLinkedList :: sort() {
    Node *curr1 = head; // i -> curr1 es el inicio de la doublelinkedlist

    Node *curr2 = tail; // f -> curr2 es el final de la doublelinkedlist

    quicksort(curr1, curr2); // Se llama al quicksort, lo hice aparte porque no supe como hacer recursivo el método sort jaja
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

info DoubleLinkedList::get(int pos){
    Node *curr = head ;
    for (int i=0; i<pos; i++){
        curr = curr ->getNext() ;
    }
    return curr->getData();
}

int DoubleLinkedList ::getTamanio() {
    return tamanio;
}

#endif //TC1031_DOUBLELINKEDLIST_H
