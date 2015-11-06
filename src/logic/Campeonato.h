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

class Campeonato{
	unsigned int id;
	string nome;
	date data;
	string pais;
	vector<Equipa*> equipas;
	vector<Desporto*> desportos;
	Calendario* calendario;
	// PRECISO?? vector<Modalidade *> modalidades;
public:
	Campeonato();
	Campeonato(string nome);
	unsigned int getID() const;
	string getNome() const;
	date getData() const;
	string getPais() const;

	vector<Equipa*> getEquipas() const;
	vector<Desporto*> getDeportos() const;

	Calendario* getCalendario() const;

	bool addEquipa();
	bool eliminaEquipa();

	void inserirEquipa(Equipa &e1);
	void readFile(string filename);
	bool findEquipa(string nomeEquipa);
	Atleta* findAtleta(string nomeAtleta);
	Desporto* findDesporto(string nomeDesporto);
	void imprimeAtletas() const;
	void imprimeEquipas() const;
	void adicionaEquipa();

	class ErroFicheiro {
	public:
		ErroFicheiro() {
		}
	};
};

#endif /* SRC_CAMPEONATO_H_ */
