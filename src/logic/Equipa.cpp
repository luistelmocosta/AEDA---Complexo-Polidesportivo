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

void Equipa::readFile(const string filename){

	string tmp;
	fstream fich;
	string nome, pais;
	unsigned int idade, peso, altura;

	fich.open(filename.c_str(), ios::in);

	if(fich.is_open()){

		while(!fich.eof()){
			getline(fich, nome);
			fich >> pais >> idade >> altura >> peso;
			if(fich.eof())
				break;
			Atleta * x = new Atleta (nome, pais, idade, peso, altura);

			getline(fich, nome);

			atletas.push_back(x);
		}
	}

	else
		throw UnableOpenFile(filename);

	fich.close();

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
