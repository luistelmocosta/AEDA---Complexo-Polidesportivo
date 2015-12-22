#ifndef SRC_LOGIC_CAMPEONATO_H_
#define SRC_LOGIC_CAMPEONATO_H_


#include <tr1/unordered_set>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include "Equipa.h"
#include "Desporto.h"
#include "Calendario.h"
#include "Utilities.h"
#include "Atleta.h"
#include "Adepto.h"


using namespace std;


struct eqAdepto {
	bool operator() (const Adepto &a1, const Adepto &a2) const{
		return a1.getID() == a2.getID();
	}
};

struct hAdepto{
	int operator() (const Adepto &a1) const{
		return a1.getID();
	}


};

typedef tr1::unordered_set<Adepto, hAdepto, eqAdepto> TabelaBilhetes;


class Calendario;

class Campeonato{

	TabelaBilhetes bilhetes;

	string nome;
	date data;
	string pais;
	vector<Atleta*> atletas;
	vector<Equipa*> equipas;
	vector<Desporto*> desportos;
	Calendario* calendario;

	priority_queue<Equipa*> classificacao;

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
	priority_queue<Equipa*> getClassificacao() const;

	void inserirEquipa(Equipa &e);
	bool eliminarEquipa(string nome);


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
	void readFileBilhetes(string filename);



	void realizarProva(int id);
	void ordenaClassificacoes();

	void inserirAdepto(Adepto &ad);
	void removerAdepto(string nome);
	int removerAdeptos(date dataValidade);
	void alterarEmail(string nome, string email);
	void showAdeptos();
	bool existeAdepto(string nome);
};

#endif /* SRC_LOGIC_CAMPEONATO_H_ */
