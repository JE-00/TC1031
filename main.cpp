// Actividad 1.3
// Numero de equipo  : 14
/*
 * Integrantes:
 * Maribel Alvarez Flores A00828510
 * Andres Limon Calleja A01552116
 * José Carlos Esquerra Rivas A00827879
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

#include "Meses.h"
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

// O(n)
int une(vector<bitacora*> &vec, vector<bitacora*> &aux, int ini, int fin){
    int m = (ini + fin)/2;
    int i = ini, j = m + 1, k = ini ;
    int cant = 0 ;

    while (i <= m && j<=fin){
        cant ++ ;
        if (vec[i]->getKey() <= vec[j]->getKey()){
            aux[k++] = vec[i++] ;
        }else{
            aux[k++] = vec[j++] ;
        }
    }
    while (i <= m){
        aux[k++] = vec[i++] ;
    }

    while (j <= fin){
        aux[k++] = vec[j++] ;
    }

    for (int z = ini; z<= fin; z++){
        vec[z] = aux[z] ;
    }
    return cant ;
}

//Esta funcion acomoda un vector de forma ascendente por medio del metodo de merge, este metodo hace uso de la recursividad y de una funcion extra que es la de "une"
// MEJOR Y PEOR CASO: O(n log n)
int merge (vector<bitacora*> &vec, vector<bitacora*> &aux, int ini, int fin){
    int cant = 0;
    if (ini < fin){
        int m = (ini + fin) / 2 ;
        cant += merge (vec,aux, ini, m);
        cant += merge (vec, aux, m+1, fin);
        cant += une(vec,aux, ini,fin);
    }
    return cant ;
}

// Esta funcion utiliza el metodo de la busqueda binaria para encontrar un dato en un vector que es buscado por el usuario
//  O(log2n)
int busqBin(vector <bitacora*> &v, Meses fecha, int &cantidadBs, string iof){
    int ini = 0, fin = v.size() -1, mit, dato;
    int valorMit ;
    cantidadBs = 0;
    while (ini <= fin){
        mit = (ini + fin)/2 ;
        valorMit = v[mit]->getKey() ;
        // si la fecha que se esta buscando es la fecha inicial entonces se utiliza esta parte del codigo
        if (iof == "inicio"){
            if (fecha.getKey() == valorMit && v[mit-1]->getKey() != valorMit) {
                return mit ;
            }else if  (fecha.getKey() > valorMit){
                ini = mit + 1;
            }else{
                fin = mit - 1;
            }
            // si la fecha que se esta buscando es la ultima se utiliza esta parte del codigo
        }else{
            if (fecha.getKey() == valorMit && v[mit+1]->getKey() != valorMit) {
                return mit ;
            }else if  (fecha.getKey() < valorMit){
                fin = mit - 1;
            }else{
                ini = mit + 1;
            }
        }
    }
    return -1;
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

int main() {
    int cantidadBs, n , dia;
    string mes ;
    string iof = "inicio" ;
    int ini, fini ;


    // Crea el vector reegistros de tipo bitacora
    vector<bitacora*> registros;

    // Llama a la función leerArchivo
    leerArchivo(registros);

    n = registros.size() ;
    vector<bitacora*> aux(n) ;

    //Despliega la cantidad de comparaciones que realizo el metodo merge para ordenar nuestro vector
    cout << merge(registros, aux, 0, n-1) <<endl;

    //Pide al usuario la fecha inicial a buscar
    cout << "Ingresa el mes del inicio de la busqueda "<<endl ;
    cin >> mes ;
    cout << "Ingresa el dia de inicio de la busqueda "<<endl ;
    cin >> dia ;

    Meses inicio(mes,dia);

    //Pide al usuario la fecha final a buscar
    cout << "Ingresa el mes de fin de la busqueda"<<endl ;
    cin >> mes ;
    cout << "Ingresa el dia de fin de la busqueda "<<endl ;
    cin >> dia ;

    Meses fin(mes,dia);


    //Busca el primer indice en donde encuentre la fecha buscada por el usuario
    ini = busqBin(registros, inicio, cantidadBs, iof);
    iof ="fin" ;
    //Busca el ultimo indice en donde encuentre la fecha buscada por el usuario
    fini = busqBin(registros, fin, cantidadBs, iof);

    //Despliega los atributos de el rango de fechas buscadas por el usuario
    for (int i = ini ; i < fini; i++){
        registros[i] -> print() ;
    }

    //Llama a la funcion guardarArchivo
    guardarArchivo(registros);

    return 0;
}