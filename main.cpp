// Actividad 1.3
// Numero de equipo : 14
/*
 * Integrantes:
 * Maribel Alvarez Flores A00828510
 * Andres Limon Calleja A01552116
 * José Carlos Esquerra Rivas A00827879
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "DoubleLinkedList.h"

// Complejidad: O(n^2) <- Complejidad incluyendo la complejidad del getline
void leerArchivo(DoubleLinkedList &lista) {
    // Se lee el archivo "bitacora.txt"
    ifstream archBitacora("C:\\Users\\josee\\CLionProjects\\TC1031\\bitacora.txt");
    // Se declaran las variables de los atributos de los registros
    string dia, mes, hora;
    string fechaHora, ip, motivo;
    info data;

    // Se lee cada linea del archivo y se guardan en un vector de bitacoras llamado registros
    if (archBitacora.is_open()) {
        // Se leen en archBitacora >> fechaHora >> ip
        while (archBitacora >> dia >> mes >> hora >> data.ip) {
            // Se lee y guarda el resto de la linea en motivo
            getline(archBitacora,data.motivo);

            data.fechaHora = dia + ' ' + mes + ' ' + hora;
            data.key = ipToLong(data.ip);
            // Se guardan los elementos como atributos de elementos bitacora del vector registros
            lista.addLast(data);
        }
        // Se cierra el archivo bitacora.txt para evitar daños
        archBitacora.close();
    }
}

//Complejidad   O(log2n)
int busqBin(DoubleLinkedList *lista, long long pos){
	int inicio = 0; // Variable que va a ir cambiando (el inicio)
	int fin = lista->getTamanio() ; //final de la lista - size
	int mit;
	long long Valormit;

	while (inicio <= fin){
		mit = (inicio+fin) / 2;
		Valormit = lista->get(mit).key ;
		if (pos == Valormit && lista->get(mit-1).key!=pos){
			return mit;
		}else if (pos > Valormit ){
			if(pos < lista->get(mit+1).key){
				return mit ;
			}
			inicio = mit+1;
		}else{
			if(pos > lista->get(mit-1).key){
				return mit ;
			}
			fin = mit -1 ;
		}
	}
	return -1;
}

// Complejidad: O(n)
void guardarArchivo(DoubleLinkedList &lista) {
    ofstream archNuevaB("C:\\Users\\josee\\CLionProjects\\TC1031\\nuevaBitacora.txt");
    if (archNuevaB.is_open()) {
        // En un ciclo de 0 al tamaño del vector registros se imprimen los atributos de cada elemento separados por un espacio
        for (int i = 0; i < lista.size(); ++i) {
            archNuevaB << lista.get(i).fechaHora << " " << lista.get(i).ip << lista.get(i).motivo << endl;
        } archNuevaB.close(); // Se cierra archNuevaB para guardar cambios
    }
}


int main() {
    string ipi, ipf;
    long long ini, fini;
    int ki,kf;


    // Crea el vector reegistros de tipo bitacora
    DoubleLinkedList lista;

    // Llama a la función leerArchivo
    leerArchivo(lista);

    lista.sort();
    lista.print();

    //Pide al usuario el ip inicial y final a buscar
    cout << "Ingresa el ip de inicio de la busqueda "<<endl ;
    cin >> ipi;
    cout << "Ingresa el ip de final de la busqueda "<<endl ;
    cin >> ipf;

    ini = ipToLong(ipi);
    fini = ipToLong(ipf);

    ki = busqBin(&lista,ini);
    kf = busqBin(&lista,fini);

    cout << endl;

    DoubleLinkedList *l = &lista;

    cout << "RESULTADO DE LA BUSQUEDA" <<endl;
    for (int i=ki; i<=kf;i++){
        cout << "--------------------------------" << endl;
        cout << l->get(i).fechaHora << " ";
        cout << l->get(i).ip << " ";
        cout << l->get(i).key;
        cout << l->get(i).motivo << endl;
    }

    guardarArchivo(lista);

    return 0;
}