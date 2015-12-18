#ifndef SRC_LOGIC_CAMPEONATO_H_
#define SRC_LOGIC_CAMPEONATO_H_

#include <vector>
#include <string>
#include "Equipa.h"
#include "Desporto.h"
#include "Calendario.h"
#include "Utilities.h"
#include "Atleta.h"
#include "Adepto.h"
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
	vector<Adepto*> adeptos;
	Calendario* calendario;

public:
	Campeonato();
	Campeonato(string nome);

	string getNome() const;
	void setNome(string n);

	date getData() const;
	void setData(string d);

	string getPais() const;
	void setPais(string p);

	vector<Atleta*> getAtletas() const;
	vector<Equipa*> getEquipas() const;
	vector<Desporto*> getDeportos() const;
	Calendario* getCalendario() const;

	void inserirEquipa(Equipa &e);
	bool eliminarEquipa(string nome);

	void inserirAdepto(Adepto &ad);

	void inserirAtleta(Atleta &a);
	bool eliminarAtleta(unsigned int id);

	int findAtleta(unsigned int id);			//return index if success
	int findEquipa(string nomeEquipa);			//else
	int findDesporto(string nomeDesporto);		//return -1

	vector<Atleta*> findAtletaVect(string nomeAtleta);	//return a vector, in case there are several athletes with the same name

	void imprimeEquipas() const;
	void imprimeUmaEquipa(string nome);

	void imprimeAtletas() const;
	void imprimeAtletasPorEquipa() const;

	void imprimeAdeptos() const;

	void readFileAtletas(string filename);
	void readFileEquipas(string filename);
	void readFileProvas(string filename);
	void readFileAdeptos(string filename);

	void realizarProva(int id);
	void ordenaClassificacoes();
};

#endif /* SRC_LOGIC_CAMPEONATO_H_ */
