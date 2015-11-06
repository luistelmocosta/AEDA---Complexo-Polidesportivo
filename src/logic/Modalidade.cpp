#include "Modalidade.h"
#include<iostream>

using namespace std;

Modalidade::Modalidade(string n, bool s) {
	nome=n;
	singular=s;

	if(nome=="Futebol")
		Desporto::setNome("Futebol");

	else if(nome=="Corrida 100m")
		Desporto::setNome("Corrida");
	else if(nome=="Corrida 200m")
		Desporto::setNome("Corrida");

	else if(nome=="Salto Altura")
		Desporto::setNome("Salto");
	else if(nome=="Salto Comprimento")
		Desporto::setNome("Salto");

	else if(nome=="Crawl 100m")
		Desporto::setNome("Crawl 100m");
	else if(nome=="Brucos 100m")
		Desporto::setNome("Brucos 100m");
	else if(nome=="Mariposa 100m")
		Desporto::setNome("Mariposa 100m");
	else if(nome=="Costas 100m")
		Desporto::setNome("Costas 100m");

	else if(nome=="Voleibol")
		Desporto::setNome("Voleibol");

	else if(nome=="Judo")
		Desporto::setNome("Combate");
}


Modalidade::~Modalidade() {
}

string Modalidade::getNome() const {
	return nome;
}

string Modalidade::getNomeDesporto() const{
	return Desporto::getNome();
}

bool Modalidade::getSingular() const {
	return singular;
}

bool Modalidade::operator ==(const Modalidade &mod){
	cout << "overload" << endl;
	return (this->nome == mod.getNome());

}

/*
int main(){

	//Desporto* d = new Modalidade("Corrida 100m", false);

	Modalidade* m = new Modalidade("Corrida 100m", false);

	cout << m->getNomeDesporto() << endl;
	cout << m->getNome() << endl;

	return 0;
}
*/
