//
// Created by josee on 08/09/2020.
//

#ifndef TC1031_BITACORA_H
#define TC1031_BITACORA_H


class bitacora {
// Se declaran atributos privados, la key es un código para faciliar el manejo de los registros
private:
    int key;
    string mes;
    int dia;
    string hora;
    string direccionIP;
    string razonFalla;
// Se declaran los métodos, en el constructor no se usa el key porque este se produce dentro del contructor
public:
    bitacora();
    bitacora(string mes, int dia, string hora, string direccionIP, string razonFalla);

    void setKey(string mes, int dia);
    void setMes(string mes);
    void setDia(int dia);
    void setHora(string hora);
    void setDireccionIP(string direccionIP);
    void setRazonFalla(string razonFalla);

    int getKey();
    string getMes();
    int getDia();
    string getHora();
    string getDireccionIP();
    string getRazonFalla();

    void print();
};

bitacora ::bitacora() {
    key = 0101;
    mes = "Ene";
    dia = 01;
    hora = "00:00:00";
    direccionIP = "111.22.333.444:555";
    razonFalla = "Failed password for illegal user guest, root or admin";
}
bitacora :: bitacora(string mes, int dia, string hora, string direccionIP, string razonFalla) {
    this -> mes = mes;
    this -> dia = dia;
    this -> hora = hora;
    this -> direccionIP = direccionIP;
    this -> razonFalla = razonFalla;
    if (mes == "Ene") {
        key = stoi("01")*100+dia;
    } else if (mes == "Feb") {
        key = stoi("02")*100+dia;
    } else if (mes == "Mar"){
        key = stoi("03")*100+dia;
    } else if (mes == "Abr"){
        key = stoi("04")*100+dia;
    } else if (mes == "May"){
        key = stoi("05")*100+dia;
    } else if (mes == "Jun"){
        key = stoi("06")*100+dia;
    } else if (mes == "Jul"){
        key = stoi("07")*100+dia;
    } else if (mes == "Ago"){
        key = stoi("08")*100+dia;
    } else if (mes == "Sep"){
        key = stoi("09")*100+dia;
    } else if (mes == "Oct"){
        key = stoi("10")*100+dia;
    } else if (mes == "Nov"){
        key = stoi("11")*100+dia;
    } else if (mes == "Dic"){
        key = stoi("12")*100+dia;
    }
}

void bitacora :: setKey(string mes, int dia) {
    if (mes == "Ene") {
        key = stoi("01")*100+dia;
    } else if (mes == "Feb") {
        key = stoi("02")*100+dia;
    } else if (mes == "Mar"){
        key = stoi("03")*100+dia;
    } else if (mes == "Abr"){
        key = stoi("04")*100+dia;
    } else if (mes == "May"){
        key = stoi("05")*100+dia;
    } else if (mes == "Jun"){
        key = stoi("06")*100+dia;
    } else if (mes == "Jul"){
        key = stoi("07")*100+dia;
    } else if (mes == "Ago"){
        key = stoi("08")*100+dia;
    } else if (mes == "Sep"){
        key = stoi("09")*100+dia;
    } else if (mes == "Oct"){
        key = stoi("10")*100+dia;
    } else if (mes == "Nov"){
        key = stoi("11")*100+dia;
    } else if (mes == "Dic"){
        key = stoi("12")*100+dia;
    }
}
void bitacora :: setMes(string mes) {
    this -> mes = mes;
}
void bitacora :: setDia(int dia) {
    this -> dia = dia;
}
void bitacora :: setHora(string hora) {
    this -> hora = hora;
}
void bitacora :: setDireccionIP(string direccionIP) {
    this -> direccionIP = direccionIP;
}
void bitacora :: setRazonFalla(string razonFalla) {
    this -> razonFalla = razonFalla;
}
int bitacora :: getKey() {
    return key;
}
string bitacora :: getMes() {
    return mes;
}
int bitacora :: getDia() {
    return dia;
}
string bitacora :: getHora() {
    return hora;
}
string bitacora :: getDireccionIP() {
    return direccionIP;
}
string bitacora :: getRazonFalla() {
    return razonFalla;
}
void bitacora :: print() {
    cout << "Mes: " << mes << endl;
    cout << "Día: " << dia << endl;
    cout << "Hora: " << hora << endl;
    cout << "Dirección IP: " << direccionIP << endl;
    cout << "Razón de falla: " << razonFalla << endl;
    cout << "Key producida: " << key << endl;
}

#endif //TC1031_BITACORA_H
