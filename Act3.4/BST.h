/*
 * Act 3.4 - Actividad Integral de BST (Evidencia Competencia)
 * TC1031.14 - Equipo 14
 *
 * Maribel Alvarez Flores A00828510
 * Andrés Limón Calleja A01552116
 * José Carlos Esquerra Rivas A00827879
 *
 * 25/10/2020
 */

#ifndef ACT3_4_BST_H
#define ACT3_4_BST_H

#include "NodeT.h"

class BST{
public:
    BST();
    void visit(int num) ;
    void add(ip data);
private:
    NodeT *root;
    void preOrden(NodeT *r) ;
    void posOrden(NodeT *r) ;
    void ininOrden(NodeT *r, int &i) ;
};

BST::BST(){
    root = nullptr;
}

// O(n)
//Agrega al árbol binario un nodo con al IP en la posición correspondiente
void BST::add(ip data){
    NodeT *curr = root;
    NodeT *father = nullptr ;

    while (curr!=nullptr){
        if (curr -> getData() == data){
            return;
        }

        father = curr;
        curr = (curr-> getData() > data) ? curr -> getLeft() : curr -> getRight() ;

    }

    if (father == nullptr){
        root = new NodeT(data) ;
    }else{
        father->getData() > data ? father -> setLeft(new NodeT(data)) : father->setRight(new NodeT(data)) ;
    }
}

//O(n)
//Despliega en forma posOrden los elementos del BST
void BST::posOrden(NodeT *r){
    if (r != nullptr){
        posOrden (r->getLeft());
        posOrden (r->getRight());
        cout << r -> getData().num << " ";
    }
}

//O(n)
void BST:: ininOrden(NodeT *r,int &i){ // regresa los primeros 5 elementos del recorrido en inorden
    if (r != nullptr) {

        ininOrden (r->getRight(),i);
        if(i >= 5) return;
        cout << r->getData().num << " " ;
        cout << r -> getData().ipi << endl;
        i++;
        ininOrden (r->getLeft(),i);

    }
}

//O(n)
// Despliega en forma preOrden los elementos del BST
void BST::preOrden(NodeT *r){
    if (r != nullptr){
        cout << r -> getData().num << " ";
        preOrden(r->getLeft());
        preOrden(r->getRight()) ;
    }
}

//O(n)
//Desplegará cada uno de los datos almacenados en el BST dependiendo del parámetro en entrada:
/*
1. Preorder
2. Inorder
3. Postorder
*/
void BST::visit(int num){
    if (num == 1 ){
        preOrden(root) ;
    }else if (num == 2){
        int i = 0;
        ininOrden(root,i) ;
    }else if (num == 3){
        posOrden(root) ;
    } else {
        cout << "Opcion invalida "<<endl ;
    }

    cout << endl;
}

#endif //ACT3_4_BST_H