#ifndef SRC_CAMPEONATO_H_
#define SRC_CAMPEONATO_H_

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
	date getData() const;
	string getPais() const;

	vector<Atleta*> getAtletas() const;
	vector<Equipa*> getEquipas() const;
	vector<Desporto*> getDeportos() const;

	Calendario* getCalendario() const;

	void adicionaEquipa();
	bool eliminaEquipa();

	void adicionaAtleta();
	void removerAtleta();

	void inserirEquipa(Equipa &e1);
	void alteraEquipa();

	void readFileAtletas(string filename);
	void readFileEquipas(string filename);
	void readFileProvas(string filename);

	void imprimeUmaEquipa();

	int findEquipa(string nomeEquipa);				//return index if success
	int findAtleta(unsigned int id);				//else
	int findDesporto(string nomeDesporto);			//return -1

	vector<Atleta*> findAtletaVect(string nomeAtleta);	//return a vector, in case there are several athletes with the same name

	void imprimeAtletas() const;
	void imprimeEquipas() const;
	void imprimeAtletasPorEquipa() const;
	void ordenaClassificacoes();


};

#endif /* SRC_CAMPEONATO_H_ */
