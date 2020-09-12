//
// Created by josee on 08/09/2020.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

#include "bitacora.h"

void leerArchivo(vector <bitacora*> &registros) {
    ifstream archBitacora("C:\\Users\\josee\\CLionProjects\\TC1031\\bitacora.txt"); // Lee el archivo
    // Se declaran las variables de los atributos de los registros
    string line, valor;
    int dia;
    string rF1, rF2, rF3, rF4, rF5, rF6;
    string mes, hora, direccionIP, razonFalla;

    if (archBitacora.is_open()) {
        while (archBitacora >> mes >> dia >> hora >> direccionIP) {
            getline(archBitacora,razonFalla);
            registros.push_back(new bitacora(mes, dia, hora, direccionIP, razonFalla));
        }
        archBitacora.close();
    }
}

void guardarArchivo(vector<bitacora*> registros) {
    ofstream archNuevaB("C:\\Users\\josee\\CLionProjects\\TC1031\\nuevaBitacora.txt");
    if (archNuevaB.is_open()) {
        for (int i = 0; i < registros.size(); ++i) {
            archNuevaB << registros[i]->getMes() << " " << registros[i]->getDia() << " " << registros[i]->getHora() <<
            " " << registros[i]->getDireccionIP() << registros[i]->getRazonFalla() << endl;
        } archNuevaB.close();
    }
}

int main() {
    vector<bitacora*> registros;

    leerArchivo(registros);

    for (int i = 0; i < registros.size(); ++i) {
        cout << "Registro " << i + 1 << endl;
        registros[i] -> print();
    }

    guardarArchivo(registros);

    return 0;
}
