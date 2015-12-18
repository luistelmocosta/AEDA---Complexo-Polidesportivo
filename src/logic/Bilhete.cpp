#include "Bilhete.h"

using namespace std;

int Bilhete::newID = 0;

Bilhete::Bilhete(date v, bool sold) : uid(newID++){

	validade = v;
	//dono = d;
	sold = false;

}

Bilhete::Bilhete() : uid(newID++){}


int Bilhete::getID() const{
	return uid;
}

/*void Bilhete::setDono(Adepto* a1){

	dono = a1;
}*/

string Bilhete::getInfo() const {
	string info;
	stringstream ss;
	ss << "Bilhete:" << endl;
	ss << "ID: " << uid << endl;
	ss << "Valido ate: " << validade.ano << endl;
	ss << "Preco: " << preco << endl;

	return ss.str() + info;
}

