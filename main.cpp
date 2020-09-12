//
// José Carlos Esquerra Rivas - A00827879
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

#include "bitacora.h"

// Complejidad: O(n^2) <- Complejidad incluyendo la complejidad del getline
void leerArchivo(vector <bitacora*> &registros) {
    // Se lee el archivo "bitacora.txt"
    ifstream archBitacora("C:\\Users\\josee\\CLionProjects\\TC1031\\bitacora.txt");
    // Se declaran las variables de los atributos de los registros
    int dia;
    string line, valor, mes, hora, direccionIP, razonFalla;

    // Se lee cada linea del archivo y se guardan en un vector de bitacoras llamado registros
    if (archBitacora.is_open()) {
        // Se leen en archBitacora >> mes >> dia >> hora >> direccionIP
        while (archBitacora >> mes >> dia >> hora >> direccionIP) {
            // Se lee y guarda el resto de la linea en razonFalla
            getline(archBitacora,razonFalla);
            // Se guardan los elementos como atributos de elementos bitacora del vector registros
            registros.push_back(new bitacora(mes, dia, hora, direccionIP, razonFalla));
        }
        // Se cierra el archivo bitacora.txt para evitar daños
        archBitacora.close();
    }
}

// Complejidad: O(n)
void guardarArchivo(vector<bitacora*> registros) {
    ofstream archNuevaB("C:\\Users\\josee\\CLionProjects\\TC1031\\nuevaBitacora.txt");
    if (archNuevaB.is_open()) {
        // En un ciclo de 0 al tamaño del vector registros se imprimen los atributos de cada elemento separados por un espacio
        for (int i = 0; i < registros.size(); ++i) {
            archNuevaB << registros[i]->getMes() << " " << registros[i]->getDia() << " " << registros[i]->getHora() <<
            " " << registros[i]->getDireccionIP() << registros[i]->getRazonFalla() << endl;
        } archNuevaB.close(); // Se cierra archNuevaB para guardar cambios
    }
}

// Complejidad O(n^2)
int main() {

    // Crea el vector reegistros de tipo bitacora
    vector<bitacora*> registros;

    // Llama a la función leerArchivo
    leerArchivo(registros);

    // En un ciclo de 0 al numero de elementos en el vector registros se imprimmen los atributos de cada elemento bitacora con el método print
    for (int i = 0; i < registros.size(); ++i) {
        cout << "Registro " << i + 1 << endl;
        registros[i] -> print();
    }

    // Llama a la función guardarArchivo
    guardarArchivo(registros);

    return 0;
}
