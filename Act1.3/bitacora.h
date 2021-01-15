//
// Created by josee on 08/09/2020.
//

#ifndef TC1031_BITACORA_H
#define TC1031_BITACORA_H


class bitacora {
// Se declaran atributos privados, la key es un cÃ³digo para facilitar el manejo de los registros
private:
    int key;
    string mes;
    int dia;
    string hora;
    string direccionIP;
    string razonFalla;
// Se declaran los mÃ©todos, en el constructor con parametros no se recibe el key porque este se produce dentro del contructor
public:
    // Constructores
    bitacora();
    bitacora(string mes, int dia, string hora, string direccionIP, string razonFalla);

    // Setters, se usan para modificar los atributos de acuerdo a parÃ¡metros
    void setKey(string mes, int dia);
    void setMes(string mes);
    void setDia(int dia);
    void setHora(string hora);
    void setDireccionIP(string direccionIP);
    void setRazonFalla(string razonFalla);

    // Getters, se usan para obtener los valores de los atributos
    int getKey();
    string getMes();
    int getDia();
    string getHora();
    string getDireccionIP();
    string getRazonFalla();

    // MÃ©todo print, para facilitar impresiÃ³n de cada registro
    void print();
};

// MÃ©todo constructor vacÃ­o
bitacora ::bitacora() {
    key = 0101;
    mes = "Ene";
    dia = 01;
    hora = "00:00:00";
    direccionIP = "111.22.333.444:555";
    razonFalla = "Failed password for illegal user guest, root or admin";
}
// MÃ©todo constructor con parÃ¡metros
bitacora :: bitacora(string mes, int dia, string hora, string direccionIP, string razonFalla) {
    this -> mes = mes;
    this -> dia = dia;
    this -> hora = hora;
    this -> direccionIP = direccionIP;
    this -> razonFalla = razonFalla;
    // Para crear las keys se toma la string del mes y se le asigna un valor numerico del 1 al 12 dependiendo del mes
    if (mes == "Jan") {
        key = stoi("01")*100+dia;
    } else if (mes == "Feb") {
        key = stoi("02")*100+dia;
    } else if (mes == "Mar"){
        key = stoi("03")*100+dia;
    } else if (mes == "Apr"){
        key = stoi("04")*100+dia;
    } else if (mes == "May"){
        key = stoi("05")*100+dia;
    } else if (mes == "Jun"){
        key = stoi("06")*100+dia;
    } else if (mes == "Jul"){
        key = stoi("07")*100+dia;
    } else if (mes == "Aug"){
        key = stoi("08")*100+dia;
    } else if (mes == "Sep"){
        key = stoi("09")*100+dia;
    } else if (mes == "Oct"){
        key = stoi("10")*100+dia;
    } else if (mes == "Nov"){
        key = stoi("11")*100+dia;
    } else if (mes == "Dec"){
        key = stoi("12")*100+dia;
    }
}

// Setter de la key - Para crear las keys se toma la string del mes y se le asigna un valor numerico del 1 al 12 dependiendo del mes
void bitacora :: setKey(string mes, int dia) {
    if (mes == "Jan") {
        key = stoi("01")*100+dia;
    } else if (mes == "Feb") {
        key = stoi("02")*100+dia;
    } else if (mes == "Mar"){
        key = stoi("03")*100+dia;
    } else if (mes == "Apr"){
        key = stoi("04")*100+dia;
    } else if (mes == "May"){
        key = stoi("05")*100+dia;
    } else if (mes == "Jun"){
        key = stoi("06")*100+dia;
    } else if (mes == "Jul"){
        key = stoi("07")*100+dia;
    } else if (mes == "Aug"){
        key = stoi("08")*100+dia;
    } else if (mes == "Sep"){
        key = stoi("09")*100+dia;
    } else if (mes == "Oct"){
        key = stoi("10")*100+dia;
    } else if (mes == "Nov"){
        key = stoi("11")*100+dia;
    } else if (mes == "Dec"){
        key = stoi("12")*100+dia;
    }
}

// Setter de mes, se recibe un string y se asigna al atributo mes
void bitacora :: setMes(string mes) {
    this -> mes = mes;
}
// Setter de dia, se recibe un int y se asigna al atributo dia
void bitacora :: setDia(int dia) {
    this -> dia = dia;
}
// Setter de hora, se recibe un string y se asigna al atributo hora
void bitacora :: setHora(string hora) {
    this -> hora = hora;
}
// Setter de direccionIP, se recibe un string y se asigna al atributo direccionIP
void bitacora :: setDireccionIP(string direccionIP) {
    this -> direccionIP = direccionIP;
}
// Setter de razonFalla, se recibe un string y se asigna al atributo razonFalla
void bitacora :: setRazonFalla(string razonFalla) {
    this -> razonFalla = razonFalla;
}
// Getter de key, regresa el valor de la key generada
int bitacora :: getKey() {
    return key;
}
// Getter de mes, regresa el valor del atributo mes
string bitacora :: getMes() {
    return mes;
}
// Getter de dia, regresa el valor del atributo dia
int bitacora :: getDia() {
    return dia;
}
// Getter de hora, regresa el valor del atributo hora
string bitacora :: getHora() {
    return hora;
}
// Getter de direccionIP, regresa el valor del atributo direccionIP
string bitacora :: getDireccionIP() {
    return direccionIP;
}
// Getter de razonFalla, regresa el valor del atributo razonFalla
string bitacora :: getRazonFalla() {
    return razonFalla;
}
// MÃ©todo print, muestra los atributos en pantalla
void bitacora :: print() {
    cout << "Mes: " << mes << endl;
    cout << "Dia: " << dia << endl;
    cout << "Hora: " << hora << endl;
    cout << "Direccion IP: " << direccionIP << endl;
    cout << "Razon de falla: " << razonFalla << endl;
    cout << "Key producida: " << key << endl;
}

#endif //TC1031_BITACORA_H