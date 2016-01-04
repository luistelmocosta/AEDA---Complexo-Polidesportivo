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

struct Medalhas{
	unsigned ouro;
	unsigned prata;
	unsigned bronze;
};

class Equipa {

	string nome;
	string pais;
	string patrocinador;
	float pontuacao;
	vector<Atleta*> atletas;
	Medalhas medalhas;
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

	Medalhas getMedalhas() const;
	void setMedalhasOuro(unsigned o);
	void setMedalhasPrata(unsigned p);
	void setMedalhasBronze(unsigned b);

	//void setMedalhas();

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
		if(lhs->getMedalhas().ouro < rhs->getMedalhas().ouro)
			return true;
		if(lhs->getMedalhas().ouro > rhs->getMedalhas().ouro)
			return false;
		else{
			if(lhs->getMedalhas().prata < rhs->getMedalhas().prata)
				return true;
			if(lhs->getMedalhas().prata > rhs->getMedalhas().prata)
				return false;
			else{
				if(lhs->getMedalhas().bronze < rhs->getMedalhas().bronze)
					return true;
				else return false;
			}
		}
	}

};

#endif /* SRC_LOGIC_EQUIPA_H_ */
