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

#ifndef ACT3_4_NODET_H
#define ACT3_4_NODET_H

//O(n)
long long ipToLong(string ip){ // convierte el ip de string a long long
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

struct ip{
    string ipi ; // ip sin el ":"
    int num ; // cantidad de veces que se repite ese ip
    long long ipiL ; // ip en long
    bool operator == (ip datos){ // sobrecarga del operador == (para que compare tanto el ip como la cantidad de repeticiones)
        if(ipi == datos.ipi && num == datos.num){
            return true ;
        }else{
            return false ;
        }
    }

    bool operator > (ip datos){ //sobrecarga del operador > (solo checa la cantidad de repeticiones)
        if( num > datos.num){
            return true ;
        }else if (num < datos.num) {
            return false ;
        }else{
            return ipiL < datos.ipiL ;
        }
    }
};

class NodeT{ // Nodo con datos de tipo ip, tiene tanto la ip como la cantidad de repeticiones
public:
    NodeT(ip data);
    NodeT(ip data, NodeT *left, NodeT *right);
    ip getData();
    void setData(ip Data);
    NodeT* getLeft();
    void setLeft(NodeT *left);
    NodeT* getRight();
    void setRight(NodeT *right) ;
private:
    ip data;
    NodeT *left;
    NodeT *right;

};

NodeT::NodeT(ip data){
    this-> data = data;
    this->left = nullptr;
    this->right = nullptr;
}
NodeT::NodeT(ip data, NodeT *left, NodeT *right){
    this-> data = data;
    this->left = left;
    this->right = right;
}

// O(1)
ip NodeT::getData(){
    return data;
}

// O(1)
void NodeT::setData(ip data){
    this-> data = data;
}

// O(1)
NodeT* NodeT::getLeft(){
    return left;
}

// O(1)
void NodeT::setLeft(NodeT *left){
    this -> left = left;
}

// O(1)
NodeT* NodeT::getRight(){
    return right;
}

// O(1)
void NodeT::setRight(NodeT *right){
    this-> right = right;
}

#endif //ACT3_4_NODET_H
