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
	vector<unsigned int> medalhas;		// [0]-ouro	 [1]-prata	[2]-bronze
	bool doping;

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

	vector<unsigned int> getMedalhas() const;
	void setMedalhas(vector<unsigned int> m);

	bool getDoping() const;
	void setDoping(bool b);

	bool temMedalhas();

	void inserirAtleta(Atleta &a1);
	bool eliminarAtleta(unsigned int id);
	int existeAtleta(string nome);					//retorna numero de atletas com nome nome que ha na equipa;
	int existeAtletaID(unsigned int id);			//retorna posicao do atleta no vector. se nao existir retorna -1;

	void showAtletas();
	void imprime();

	bool operator<(const Equipa &e) const;
	bool operator==(const Equipa &e) const;

};

struct ComparaEquipa{

	bool operator()(const Equipa* lhs, const Equipa* rhs) const{

		if(lhs->getMedalhas()[0] < rhs->getMedalhas()[0])
			return true;
		if(lhs->getMedalhas()[0] > rhs->getMedalhas()[0])
			return false;
		else{
			if(lhs->getMedalhas()[1] < rhs->getMedalhas()[1])
				return true;
			if(lhs->getMedalhas()[1] > rhs->getMedalhas()[1])
				return false;
			else{
				if(lhs->getMedalhas()[2] < rhs->getMedalhas()[2])
					return true;
				else return false;
			}
		}
	}

};

#endif /* SRC_LOGIC_EQUIPA_H_ */
