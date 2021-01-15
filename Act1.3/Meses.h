#ifndef Meses_h
#define Meses_h

class Meses{
private: 
	string mes;
	int dia ;
	int key;
public:
	Meses() ;
	Meses(string mes, int dia) ;
	int getKey () ;
	string getMes() ;

};

Meses::Meses(){
	mes = "01" ;
	dia = 1 ;
}

Meses::Meses(string mes, int dia){
	this -> mes = mes ;
	this -> dia = dia;
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

string Meses::getMes(){
	return mes ;
}

int Meses::getKey () {
	return key ;
}

#endif