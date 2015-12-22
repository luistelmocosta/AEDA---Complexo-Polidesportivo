#include "Bilhete.h"

using namespace std;

int Bilhete::newID = 0;

Bilhete::Bilhete(date v, Adepto* d, vector<int> p){


	uid = newID++;
	validade = v;
	dono = d;
	vendido = 0;
	provas = p;

}

Bilhete::Bilhete() : uid(newID++){}


int Bilhete::getID() const{
	return uid;
}

vector<int> Bilhete::getProvas() const{
	return provas;
}

string Bilhete::getEmailDono() const {

	return dono->getEmail();

}

string Bilhete::getDataFormatada() const {

	string dta = "";
	stringstream ss;

	ss << validade.dia;
	ss << "-";
	ss << validade.mes;
	ss << "-";
	ss << validade.ano;

	ss >> dta;

	return dta;
}

string Bilhete::getNomeDono() const {
	return dono->getNome();
}

void Bilhete::printProvas() const{

	cout << "ID: ";

	for(unsigned int i = 0; i < provas.size(); i++) {

		cout << provas[i] << ",";
	}
}

int Bilhete::getIdDono() const {

	return dono->getID();

}

/*void Bilhete::setDono(Adepto* a1){

	dono = a1;
}*/

/*string Bilhete::getInfo() const {
	string info;
	stringstream ss;
	ss << "Bilhete:" << endl;
	ss << "ID: " << uid << endl;
	ss << "Valido ate: " << validade.ano << endl;
	ss << "Preco: " << preco << endl;

	return ss.str() + info;
}*/
