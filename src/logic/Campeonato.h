#ifndef SRC_LOGIC_CAMPEONATO_H_
#define SRC_LOGIC_CAMPEONATO_H_


#include <tr1/unordered_set>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include <deque>

#include "Equipa.h"
#include "Desporto.h"
#include "Calendario.h"
#include "Utilities.h"
#include "Bilhete.h"


using namespace std;

struct eqBilhete {
	bool operator() (const Bilhete &b1, const Bilhete &b2) const{
		return b1.getID() == b2.getID();
	}
};

struct hBilhete{
	int operator() (const Bilhete &b1) const{
		return b1.getID();
	}


};

typedef tr1::unordered_set<Bilhete, hBilhete, eqBilhete> TabelaBilhetes;


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
	vector<Adepto*> adeptos;
	priority_queue<Equipa*, vector<Equipa*>, ComparaEquipa> classificacao;

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
	priority_queue<Equipa*, vector<Equipa*>, ComparaEquipa> getClassificacao() const;
	TabelaBilhetes getBilhetes() const;
	vector<Adepto*> getAdeptos() const;

	void inserirEquipa(Equipa &e);
	bool eliminarEquipa(string nome);


	void inserirAtleta(Atleta &a);
	bool eliminarAtleta(unsigned int id);

	int findAtleta(unsigned int id);			//return index if success
	int findEquipa(string nomeEquipa);			//else
	int findDesporto(string nomeDesporto);		//return -1
	int findAdepto(unsigned int id);
	Bilhete* findBilheteByAdeptoID(unsigned int id);
	Adepto* findAdeptoByName(string name);
	int findBilhete(unsigned int id);
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

	void outputFileAtletas(string filename);
	void outputFileEquipas(string filename);
	void outputFileProvas(string filename);
	void outputFileAdeptos(string filename);
	void outputFileBilhetes(string filename);



	void realizarProva(int id);
	int updateClassificacoes();

	void inserirAdepto(Adepto &ad);
	void removerBilhete(string nome);
	int removerBilhetes(date dataValidade);
	void alterarEmail(string nome, string email);
	void showBilhetes();
	bool existeBilhete(string nome);


	void inserirBilhete(Bilhete &b1);
	void imprimeBilhetes();
	void venderBilhete(unsigned int id);
	void comprarBilhete(unsigned int id);

	void testPQ();

};

#endif /* SRC_LOGIC_CAMPEONATO_H_ */
