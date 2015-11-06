#ifndef SRC_EQUIPA_H_
#define SRC_EQUIPA_H_

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

#include "Atleta.h"

using namespace std;

class Atleta;

class Equipa {
	string nome;
	string pais;
	string patrocinador;
	float pontuacao;
	vector<Atleta*> atletas;
public:
	Equipa(string n, string p, string pat);
	Equipa();

	string getNome() const;
	string getPais() const;
	string getPatrocinador() const;

	float getPontuacao() const;
	void setPontuacao(float p);

	void inserirAtleta(Atleta &a1);
	vector<Atleta*> getAtletas() const;

	//void readFile(ifstream& ficheiro_leitura);
	bool eliminaAtleta(unsigned int n);
	void showAtletas() ;
	bool existeAtleta(string nome);
	void readFile(string filename);
	void escreveFicheiro(string filename);
	void adicionaAtleta();
	Atleta* getAtleta(unsigned int n);
};

class AtletaInexistente {
	public:
		int id;
		string nome;
		AtletaInexistente(int id) :
				id(id) {
		}
		AtletaInexistente(string nome)
		: nome(nome){

		}
	};

#endif /* SRC_EQUIPA_H_ */
