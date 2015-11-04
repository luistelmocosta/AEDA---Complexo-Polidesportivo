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
	Calendario calendario;
											// PRECISO?? vector<Modalidade *> modalidades;
public:
	unsigned int getID() const;
	string getNome() const;
	date getData() const;
	string getPais() const;

	vector<Equipa*> getEquipas() const;
	vector<Desporto*> getDeportos() const;

	Calendario getCalendario() const;

	bool addEquipa();
	bool eliminaEquipa();

	void readFile(const string filename);
};

#endif /* SRC_CAMPEONATO_H_ */
