#include "Modalidade.h"
#include<iostream>

using namespace std;

Modalidade::Modalidade(string n, bool s): nome(n), singular(s) {

	if(nome=="Futebol"){
		Desporto::setNome("Futebol");
		nJogadores = 22;
	}



	else if(nome=="Corrida 100m"){
		Desporto::setNome("Corrida");
		nJogadores = 8;
	}
	else if(nome=="Corrida 200m"){
		Desporto::setNome("Corrida");
		nJogadores = 8;
	}



	else if(nome=="Salto Altura"){
		Desporto::setNome("Salto");
		nJogadores = 8;
	}
	else if(nome=="Salto Comprimento"){
		Desporto::setNome("Salto");
		nJogadores = 8;
	}



	else if(nome=="Crawl 100m"){
		Desporto::setNome("Natacao");
		nJogadores = 8;
	}
	else if(nome=="Brucos 100m"){
		Desporto::setNome("Natacao");
		nJogadores = 8;
	}
	else if(nome=="Mariposa 100m"){
		Desporto::setNome("Natacao");
		nJogadores = 8;
	}
	else if(nome=="Costas 100m"){
		Desporto::setNome("Natacao");
		nJogadores = 8;
	}



	else if(nome=="Voleibol"){
		Desporto::setNome("Voleibol");
		nJogadores = 12;
	}



	else if(nome=="Judo"){
		Desporto::setNome("Combate");
		nJogadores = 2;
	}
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

unsigned int Modalidade::getNJogadores() const {
		return nJogadores;
}

bool Modalidade::operator ==(const Modalidade &mod){
	cout << "overload" << endl;
	return (this->nome == mod.getNome());

}

/*
int main(){

	//Desporto* d = new Modalidade("Corrida 100m", false);

	Modalidade* m = new Modalidade("Corrida 100m", false);


	cout << m->getNome() << endl;
	cout << m->getNomeDesporto() << endl;

	return 0;
}*/

