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
#include <iostream>
#include <string>
#include <fstream>

using namespace std ;

#include "BST.h"

// struct para almacenar la info recibida de bitacoraOrdenada
struct info {
    string fechaHora;
    string ip;
    string motivo;
};

//O(n^2)
void leerArchivo(BST &total) {
    // Se lee el archivo "bitacoraOrdenada.txt"
    ifstream archBitacora("bitacoraOrdenada.txt");
    // Se declaran las variables de los atributos de los registros
    string dia, mes, hora;
    string ipi, motivo;
    // Se declara la variable tipo info que almacene lo recibido de los registros
    info data;
    // Variables auxiliares para conteo, comparación y almacenamiento temporal de valores
    string aux, a, b ;
    int  contador = 1;
    int size = 0;
    // Variable tipo ip para agregar al arbol total
    ip auxi ;

    // Se lee cada linea del archivo y se guardan en un vector de bitacoras llamado registros
    if (archBitacora.is_open()) {
        // Se leen en archBitacora >> fechaHora >> ip
        while (archBitacora >> dia >> mes >> hora >> ipi) {
            // Si el tamaño del arbol, representado por size, no es cero, aux toma el valor del ip del data anterior
            if (size != 0){
                aux = data.ip ;
            }
            // Se lee y guarda el resto de la linea en motivo
            getline(archBitacora,motivo);
            // Se asignan los valores recibidos a los atributos de data
            data.ip = ipi ;
            data.motivo = motivo ;
            data.fechaHora = dia + ' ' + mes + ' ' + hora;
            // Se toman los ip del data actual y su anterior para compararlos
            a = aux.substr(0,aux.find(":")) ;
            b = data.ip.substr(0,data.ip.find(":")) ;
            // Si ambas ip son iguales y el tamaño no es cero, se aumenta en uno el contador de ip
            if (a == b && size !=0 ){
                contador ++;
            // Si no son iguales pero size si es diferente a 0, auxi toma los valores a, contador y a en long
            }else if (size!=0){
                auxi.ipi = a ;
                auxi.num = contador ;
                auxi.ipiL = ipToLong(a) ;
                // Se agrega auxi al arbol total
                total.add(auxi) ;
                // El contador de ip vuelve a uno
                contador = 1 ;
            }
            // El tamaño del arbol, aumenta en uno
            size ++;
        }
        // Si size es mayor a cero, que significa que el arbol tiene elementos
        // Se añade el último elemento, que se omitió por no compararlo
        if (size > 0){
            // Se asginan a auxi los valores de b, contador y b en long
            auxi.ipi = b;
            auxi.num = contador ;
            auxi.ipiL = ipToLong(b) ;
            // Se agrega auxi al arbol total
            total.add(auxi) ;
        }
        // Se cierra el archivo bitacoraOrdenada.txt para evitar daños
        archBitacora.close();
    }
}

int main() {
    // Creamos el Arbol de Búsqueda Binaria total
    BST total;

    // Leemos el archivo y lo almacenamos en el arbol
    leerArchivo(total);

    // Se muestra el arbol en preorden
    //total.visit(1);

    // Se muestran las cinco ip con más registros
    total.visit(2);
}