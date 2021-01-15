#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

// Complejidad O(n)
// Lee el documento y almacena los datos en sus respectivas variables
void leerArchivo(vector<vector<int>> &listAdj, unordered_map<string, pair<int,int>> &nodos_ip, int &n, int &m) {

  // Se lee el archivo "bitacoraACT4_3_B.txt"
  ifstream asc("bitacoraACT4_3_B.txt");

  // Se declaran las variables de los atributos de los registros
	string dia, mes, hora;
  string ipi, motivo, ipi2;
	
	// Ip [] first = num , second = outdegree
	string aux ;
	asc >> n >> m ;
	

	for(int i = 0; i< n; i ++){
		asc >> aux ;
		pair<int, int> ip ;
		ip.first = i;
		ip.second = 0 ;
		nodos_ip[aux] = ip ;
	}

   //leer archivo en el formato establecido y almacenarlo en variables
	for (int j=0; j < m; j++){
		asc >> mes >> dia >> hora >> ipi >> ipi2 ;
		getline(asc,motivo);

		ipi = ipi.substr(0, ipi.find(':')) ;
		ipi2 = ipi2.substr(0, ipi2.find(':')) ;

		int numNodoSale = nodos_ip[ipi].first ;
		int numNodoEntra = nodos_ip[ipi2].first ;

		listAdj[numNodoSale].push_back(numNodoEntra) ;

		nodos_ip[ipi].second ++; // Se le suma 1 al outdegree
	}
	
  asc.close();
}

// Encuentra y despliega los nodos con mayor fan-out (Fan-out son las posibles salidas de una IP) y tambien muestra el IP del boot master(atacan a mas IP).
// Complejidad O(n)
void findFanout(vector<vector<int>> &listAdj, unordered_map<string, pair<int,int>> &nodos_ip) {

    int mayor = 0;
    vector<pair<string, pair<int,int>>> mayores;

    for (auto x : nodos_ip) {

        if (x.second.second > mayor) {
            mayor = x.second.second;
            mayores.clear();
            mayores.push_back(x);
        } else if (x.second.second == mayor) {
            mayores.push_back(x);
        }
    }

    cout << "Nodos con mayor fan-out: " << endl;
    cout << "Mayor fan-out: " << mayores[0].second.second << endl;

    for (int M = 0; M < mayores.size(); ++M) {
        cout << "Nodo: " << mayores[M].second.first << endl;
    }

		cout << endl;

    cout << "IP de Boot master: " << endl;
    for (int M = 0; M < mayores.size(); ++M) {
        cout << "IP: " << mayores[M].first << endl;
    }
}


int main() {
  //leer archivo "bitacoraACT4_3_B.txt"
    ifstream asc("bitacoraACT4_3_B.txt");
    int n, m;
    asc >> n >> m ;
    asc.close();

    vector<vector<int>> listAdj(m); // Declaramos la lista de adyacencia de tamaño n
		unordered_map<string, pair<int,int>> nodos_ip; // Declaramos un unordered_map que reciba como key el ip y como dato el struct nodo que contiene los nodos ip atacados y el outdegree del ip
		
    leerArchivo(listAdj, nodos_ip, n, m) ;
    findFanout(listAdj, nodos_ip);

    return 0;
}
