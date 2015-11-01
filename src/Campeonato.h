#ifndef AEDA_PROJECTO_1_CAMPEONATO_H
#define AEDA_PROJECTO_1_CAMPEONATO_H


#include <vector>
#include <string>
#include "Equipa.h"
#include "Desporto.h"
#include "Calendario.h"

using namespace std;

struct Data{
	int dia;
	int mes;
	int ano;
} data;

class Campeonato{
	unsigned int id;
	string nome;
	data data;
	string pais;
	vector<Equipa*> pontuacoes;
	vector<Desporto*> desportos;
	Calendario calendario;
public:
	string getNome() const;
	data getData() const;
	string getPais() const;
	Calendario getCalendario() const;
	bool addEquipa();
	bool eliminaEquipa();
	//vector <Equipa*> getPont() const;
};

#endif //AEDA_PROJECTO_1_CAMPEONATO_H