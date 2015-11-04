#include "Equipa.h"
#include <iostream>
#include <iterator>

using namespace std;


Equipa::Equipa(string n, string p, string pat): nome(n), pais(p), patrocinador(pat) {
	pontuacao=0;
}

Equipa::Equipa() {
	pontuacao=0;
}

string Equipa::getNome() const {
	return nome;
}

string Equipa::getPais() const {
	return pais;
}

string Equipa::getPatrocinador() const {
	return patrocinador;
}

float Equipa::getPontuacao() const {
	return pontuacao;
}

void Equipa::setPontuacao(float p) {
	pontuacao=p;
}

vector<Atleta*> Equipa::getAtletas() const {
	return atletas;
}

void Equipa::inserirAtleta(Atleta &a1){
	atletas.push_back(&a1);
}

void Equipa::readFile(string filename){

	ifstream ficheiro_leitura(filename.c_str());

	if(!ficheiro_leitura)
		throw ErroNoFicheiro(filename);
	else {
		string nome, pais, temp1, temp2, temp3;
		int idade, altura, peso;

		while (!ficheiro_leitura.eof()) {

			getline(ficheiro_leitura, nome);
			getline(ficheiro_leitura, pais);
			getline(ficheiro_leitura, temp1);
			getline(ficheiro_leitura, temp2);
			getline(ficheiro_leitura, temp3);

			idade = atoi(temp1.c_str());
			peso = atoi(temp2.c_str());
			altura = atoi(temp3.c_str());

			Atleta *a1 = new Atleta(nome, pais, idade, peso, altura);
			inserirAtleta(*a1);
		}
	}



}

void Equipa::showAtletas(){

	vector<Atleta*>::iterator it;
	for(it = atletas.begin(); it != atletas.end() ;  ++it) {
		cout << (*it)->getID() << endl;
		cout << (*it)->getNome() << endl;
		cout << (*it)->getPais() << endl;
		cout << (*it)->getIdade() << endl;
		cout << (*it)->getPeso() << endl;
		cout << (*it)->getAltura() << endl << endl;
	}

}


bool Equipa::eliminaAtleta(unsigned int n){
	for(unsigned int i=0; i<atletas.size(); i++) {
		if(atletas[i]->getID() ==  n) {
			atletas.erase(atletas.begin()+i);
			//--Atleta::uid;
			return true;
		}
	}
	throw AtletaInexistente(n);
	return false;
}

bool Equipa::existeAtleta(string nome){


	vector<Atleta*>::iterator it;

	for(it = atletas.begin(); it != atletas.end(); ++it){
		if((*it)->getNome() == nome)
		{
			return true;
		}
	}

	cout << "Nao existe" << endl;
	throw AtletaInexistente(nome);
	return false;

}




