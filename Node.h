//
// Created by josee on 06/10/2020.
//

#ifndef TC1031_NODE_H
#define TC1031_NODE_H
struct info {
    long key;
    string fechaHora;
    string ip;
    string motivo;
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
}
Node :: Node(info data, Node *prev, Node *next) {
    this -> data = data;
    this -> next = next;
    this -> prev = prev;
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
}
void Node :: setNext(Node *next) {
    this -> next = next;
}
void Node :: setPrev(Node *prev) {
    this -> prev = prev;
}

#endif //TC1031_NODE_H
