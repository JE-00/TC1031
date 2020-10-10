//
// Created by josee on 06/10/2020.
//

#ifndef TC1031_NODE_H
#define TC1031_NODE_H

long long ipToLong(string ip){
    int idx = 0;
    long long datoFinal = 0;
    long dato = 0;
    while (idx < ip.size()){
        if (ip[idx] != '.' && ip[idx] != ':'){
            dato = dato*10 + ip[idx] - '0';
        }
        else{
            datoFinal = datoFinal*1000 + dato;
            dato = 0;
        }
        idx++;
    }
    datoFinal = datoFinal*10000 + dato;
    return datoFinal;
}

struct info {
    string fechaHora;
    string ip;
    string motivo;
    long long key = ipToLong(ip);
};

class Node{
public:
    Node(info data);
    Node(info data, Node *prev, Node *next);
    info getData();
    Node* getNext();
    Node* getPrev();
    void setData(info data);
    void setNext(Node *next);
    void setPrev(Node *prev);
private:
    info data;
    Node *next;
    Node *prev;
};

Node :: Node(info data) {
    this -> data = data;
    this -> next = nullptr; //this no necesario
    this -> prev = nullptr;
    data.key = ipToLong(data.ip);
}
Node :: Node(info data, Node *prev, Node *next) {
    this -> data = data;
    this -> next = next;
    this -> prev = prev;
    data.key = ipToLong(data.ip);
}

info Node :: getData() {
    return data;
}
Node* Node :: getNext() {
    return next;
}
Node* Node :: getPrev() {
    return prev;
}
void Node ::setData(info data) {
    this -> data = data;
    data.key = ipToLong(data.ip);
}
void Node :: setNext(Node *next) {
    this -> next = next;
}
void Node :: setPrev(Node *prev) {
    this -> prev = prev;
}

#endif //TC1031_NODE_H
