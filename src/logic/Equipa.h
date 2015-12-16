#ifndef SRC_LOGIC_EQUIPA_H_
#define SRC_LOGIC_EQUIPA_H_

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
	void setNome(string novoNome);

	string getPais() const;
	void setPais(string novoPais);

	string getPatrocinador() const;
	void setPatrocinador(string novoPatrocinio);

	float getPontuacao() const;
	void setPontuacao(float p);

	vector<Atleta*> getAtletas() const;
	Atleta* getAtleta(unsigned int id);


	void inserirAtleta(Atleta &a1);
	bool eliminarAtleta(unsigned int id);
	int existeAtleta(string nome);					//retorna numero de atletas com nome nome que ha na equipa;
	int existeAtletaID(unsigned int id);			//retorna posicao do atleta no vector. se nao existir retorna -1;

	void showAtletas();
	void imprime();

	bool operator<(const Equipa &e);
};

#endif /* SRC_LOGIC_EQUIPA_H_ */
