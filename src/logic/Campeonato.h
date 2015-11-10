#ifndef SRC_LOGIC_CAMPEONATO_H_
#define SRC_LOGIC_CAMPEONATO_H_

#include <vector>
#include <string>
#include "Equipa.h"
#include "Desporto.h"
#include "Calendario.h"
#include "Utilities.h"
#include "Atleta.h"
#include <iostream>

using namespace std;

class Calendario;

class Campeonato{

	string nome;
	date data;
	string pais;
	vector<Atleta*> atletas;
	vector<Equipa*> equipas;
	vector<Desporto*> desportos;
	Calendario* calendario;

public:
	Campeonato();
	Campeonato(string nome);

	string getNome() const;
	void setNome(string n);
	date getData() const;
	string getPais() const;

	vector<Atleta*> getAtletas() const;
	vector<Equipa*> getEquipas() const;
	vector<Desporto*> getDeportos() const;
	Calendario* getCalendario() const;

	void insereAtleta(Atleta &a);
	void adicionaAtleta();
	void removerAtleta();

	void adicionaEquipa();
	void inserirEquipa(Equipa &e1);
	void alteraEquipa();
	bool eliminaEquipa();

	void readFileAtletas(string filename);
	void readFileEquipas(string filename);
	void readFileProvas(string filename);
	void writeFileAtletas(string filename);

	int findAtleta(unsigned int id);			//return index if success
	int findEquipa(string nomeEquipa);			//else
	int findDesporto(string nomeDesporto);		//return -1

	vector<Atleta*> findAtletaVect(string nomeAtleta);	//return a vector, in case there are several athletes with the same name

	void imprimeAtletas() const;
	void imprimeEquipas() const;
	void imprimeUmaEquipa();
	void imprimeAtletasPorEquipa() const;
	void ordenaClassificacoes();
};

#endif /* SRC_LOGIC_CAMPEONATO_H_ */
