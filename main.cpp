//
// Created by josee on 08/09/2020.
//
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

#include "bitacora.h"

int main() {
    vector<bitacora*> registros;

    ifstream archBitacora("C:\\Users\\josee\\CLionProjects\\TC1031\\bitacora.txt");
    string line, valor;
    char delim = ' ';
    int col, dia;
    string mes, hora, direccionIP, razonFalla;

    if (archBitacora.is_open()) {
        getline(archBitacora, line);
        //cout << "entra al if";
        while (getline(archBitacora, line)) {
            stringstream ss(line);
            col = 0;
            //cout << "entra al while";
            while (getline(ss, valor, delim)) {
                //cout << "entra al segundo while";
                switch (col) {
                    case 0:
                        mes = valor;
                        break;
                    case 1:
                        dia = stoi(valor);
                        break;
                    case 2:
                        hora = valor;
                        break;
                    case 3:
                        direccionIP = valor;
                        break;
                    case 4:
                        razonFalla = valor;
                        break;
                } col++;
            } registros.push_back(new bitacora(mes, dia, hora, direccionIP, razonFalla));
        } archBitacora.close();
    }

    for (int i = 0; i < registros.size(); ++i) {
        cout << "Registro " << i << endl;
        registros[i] -> print();
    }

    return 0;
}
