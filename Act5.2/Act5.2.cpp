/*
* TC1031.14 - Equipo 14
* Act 5.2 - Actividad Integral sobre el uso de códigos hash
* Maribel Alvarez Flores A00828510
* Andres Limon Calleja A01552116
* Jose Carlos Esquerra Rivas A00827879
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/* Hacer una aplicación que:

* Lea el archivo de entrada "bitacoraACT5_2.txt"

* Crear una tabla hash cuya llave sea el ip (sin puerto) y cuyo valor sea un resumen de ese dominio. Este resumen deberá incluir, el número de accesos, así como las fechas y razones de la falla.

* Realiza un método que dado un ip regrese el valor asociado a él desplegando la información de una manera adecuada
*/

//Lee el documento y almacena los datos en sus respectivas variables
// Complejidad O(n)
void leerArchivo(unordered_map<string, pair<int, pair<vector<string>, vector<string>>>> &hashtable) {
  // Se lee el archivo "bitacoraACT5_2.txt"
	ifstream archivo("bitacoraACT5_2.txt");
	
	string dia, mes, hora, fecha ;
	string motivo ;
	string ip ;

	while (archivo >> mes >> dia >> hora >> ip) {
    getline (archivo, motivo);
		
		fecha = mes + " " + dia + " " + hora ;
		ip = ip.substr(0, ip.find(':')) ;
		hashtable[ip].second.first.empty() ? hashtable[ip].first = 1 : hashtable[ip].first++ ;
    hashtable[ip].second.first.push_back(fecha);
    hashtable[ip].second.second.push_back(motivo) ;
	}
  archivo.close(); 
}

//Despliega un resumen de ese dominio. Este resumen  incluye el numero de acceos, fecha y motivo. 
// Complejidad O(n)
void print(string ipi, unordered_map<string, pair<int, pair<vector<string>, vector<string>>>> hashtable) {
  	cout << "Numero de accesos: " << hashtable[ipi].first << endl;

		for(int i = 0; i < hashtable[ipi].second.first.size() ; i ++){
      cout << "Fecha: " << hashtable[ipi].second.first[i] << "   ";
      cout << "Motivo: " << hashtable[ipi].second.second[i] << endl;
		}

}

int main() {
  unordered_map<string, pair<int, pair<vector<string>, vector<string>>>> hashtable;
  leerArchivo(hashtable) ;
  string ipi;
	cin >> ipi ;
  print(ipi, hashtable);

  return 0;
}

// 224.182.134.50