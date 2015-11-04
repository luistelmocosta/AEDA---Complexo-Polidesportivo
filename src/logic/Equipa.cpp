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

void Equipa::readFile(ifstream& ficheiro_leitura){

	if(!ficheiro_leitura)
		throw ErroNoFicheiro();
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
			altura = atoi(temp2.c_str());
			peso = atoi(temp2.c_str());

			Atleta *a1 = new Atleta(nome, pais, idade, altura, peso);
			inserirAtleta(*a1);
		}
	}


	vector<Atleta*>::iterator it;
	for(it = atletas.begin(); it != atletas.end() ;  ++it) {
		cout << (*it)->getID() << endl;
		cout << (*it)->getNome() << endl;
		cout << (*it)->getPais() << endl;
		cout << (*it)->getIdade() << endl;
		cout << (*it)->getPeso() << endl;
		cout << (*it)->getAltura() << endl;
	}

}
