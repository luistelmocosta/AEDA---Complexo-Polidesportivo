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

string Modalidade::pontuacao(string e1, string e2){
	float p1, p2;
	string empate = "";
	if(Desporto::getNome() == "Futebol"){
		cout << "Golos da equipa " << e1 << ": ";
		cin >> p1;

		cout << "Golos da equipa " << e2 << ": ";
		cin >> p2;

		if(p1 > p2){
			cout << "A equipa " << e1 << " e a vencedora!!" << endl;
			return e1;
		}
		else if(p2 > p1){
			cout << "A equipa " << e2 << " e a vencedora!!" << endl;
			return e2;
		}
	}

	if(Desporto::getNome() == "Corrida" || Desporto::getNome() == "Natacao"){
		cout << "Tempo da equipa " << e1 << " (em segundos)";
		cin >> p1;

		cout << "Tempo da equipa " << e2 << " (em segundos)";;
		cin >> p2;

		if(p1 > p2){
			cout << "A equipa " << e1 << " e a vencedora!!" << endl;
			return e1;
		}
		else if(p2 > p1){
			cout << "A equipa " << e2 << " e a vencedora!!" << endl;
			return e2;
		}
	}

	if(Desporto::getNome() == "Salto"){
		cout << "Altura maxima da equipa " << e1 << ": ";
		cin >> p1;

		cout << "Altura maxima da equipa" << e2 << ": ";
		cin >> p2;

		if(p1 > p2){
			cout << "A equipa " << e1 << " e a vencedora!!" << endl;
			return e1;
		}
		else if(p2 > p1){
			cout << "A equipa " << e2 << " e a vencedora!!" << endl;
			return e2;
		}
	}

	if(Desporto::getNome() == "Combate"){
		cout << "Pontuacao da equipa " << e1 << ": ";
		cin >> p1;

		cout << "Pontuacao da equipa " << e2 << ": ";
		cin >> p2;

		if(p1 > p2){
			cout << "A equipa " << e1 << " e a vencedora!!" << endl;
			return e1;
		}
		else if(p2 > p1){
			cout << "A equipa " << e2 << " e a vencedora!!" << endl;
			return e2;
		}

	}

	cout << "Empate!!" << endl;
	return empate;
}
