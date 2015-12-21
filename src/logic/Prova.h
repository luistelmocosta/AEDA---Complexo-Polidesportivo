#ifndef SRC_LOGIC_PROVA_H_
#define SRC_LOGIC_PROVA_H_

#include <vector>
#include "Equipa.h"
#include "Desporto.h"
#include "Utilities.h"
#include "Atleta.h"

class Equipa;
class Atleta;

class Prova{

	int id;
	static int newID;
	date data;
	string local;
	unsigned int duracao;   //min
	vector<Equipa*> vs;
	Modalidade* mod;
	Equipa* vencedor;
	bool provaT; 			// true -> Prova de Tempo (atletismo, natacao, etc) false -> Prova de pontos(futebol, basket, etc)
	bool completed;

public:
	Prova(){}
	Prova(date dat, string loc, unsigned int dur, vector <Equipa*> vsE, Modalidade* mod);

	unsigned int getID()const;

	date getData() const;
	void setData(date d);

	string getLocal() const;
	void setLocal(string l);

	unsigned int getDuracao() const;
	void setDuracao(unsigned int d);

	vector<Equipa*> getAdversarios() const;
	void setAdversarios(vector<Equipa*> vE);

	Modalidade* getModalidade() const;
	void setModalidade(Modalidade* m);

	Equipa* getVencedor() const;
	void setVencedor(Equipa* v);

	bool getCompleted() const;
	void setCompleted(bool b);

	bool getProvaTempo() const;
	void setProvaTemo(bool b);


	Atleta* getParticipante(int i) const;
	string getDataFormatada() const;
	void print();

	bool operator !=(const Prova &p)const;
    bool operator <(const Prova &p) const;
    bool operator >(const Prova &p)const;
    bool operator ==(const Prova &p)const;
};



#endif /* SRC_LOGIC_PROVA_H_ */
