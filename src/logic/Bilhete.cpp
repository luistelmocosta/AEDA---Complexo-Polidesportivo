#include "Bilhete.h"

using namespace std;

int Bilhete::newID = 0;

Bilhete::Bilhete(date v, string d, vector<int> p){


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

void Bilhete::imprime() const{

	cout << endl;
	cout << "Data de Validade: " << validade.dia <<"/" << validade.mes <<"/" << validade.ano << endl;
	cout << "Dono do Bilhete: " << dono << endl;
	cout << "Provas: :";
	cout << endl;
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

