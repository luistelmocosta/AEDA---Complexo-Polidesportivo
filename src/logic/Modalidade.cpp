#include "Modalidade.h"
#include<iostream>

using namespace std;

Modalidade::Modalidade(string n, bool s) {
	nome=n;
	singular=s;

	if(nome=="Futebol")
		super::setNome("Futebol");

	else if(nome=="Corrida 100m")
		super::setNome("Corrida");
	else if(nome=="Corrida 200m")
		super::setNome("Corrida");

	else if(nome=="Salto Altura")
		super::setNome("Salto");
	else if(nome=="Salto Comprimento")
		super::setNome("Salto");

	else if(nome=="Crawl 100m")
		super::setNome("Crawl 100m");
	else if(nome=="Brucos 100m")
		super::setNome("Brucos 100m");
	else if(nome=="Mariposa 100m")
		super::setNome("Mariposa 100m");
	else if(nome=="Costas 100m")
		super::setNome("Costas 100m");

	else if(nome=="Voleibol")
		super::setNome("Voleibol");

	else if(nome=="Judo")
		super::setNome("Combate");
}


Modalidade::~Modalidade() {
}

string Modalidade::getNome() const {
	return nome;
}

string Modalidade::getNomeDesporto() const{
	return super::getNome();
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

	 Desporto* d = new Modalidade("Futebol", false);

	cout << d->getNome() << endl;

	return 0;
}*/
