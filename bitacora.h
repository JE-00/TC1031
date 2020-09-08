//
// Created by josee on 08/09/2020.
//

#ifndef TC1031_BITACORA_H
#define TC1031_BITACORA_H


class bitacora {
private:
    string mes;
    int dia;
    string hora;
    string direccionIP;
    string razonFalla;
public:
    bitacora();
    bitacora(string mes, int dia, string hora, string direccionIP, string razonFalla);

    void setMes(string mes);
    void setDia(int dia);
    void setHora(string hora);
    void setDireccionIP(string direccionIP);
    void setRazonFalla(string razonFalla);

    string getMes();
    int getDia();
    string getHora();
    string getDireccionIP();
    string getRazonFalla();

    void print();
};

bitacora ::bitacora() {
    mes = "Ene";
    dia = 1;
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

#endif //TC1031_BITACORA_H
