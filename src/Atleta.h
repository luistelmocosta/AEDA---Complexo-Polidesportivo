#ifndef SRC_ATLETA_H_
#define SRC_ATLETA_H_

#include <vector>
#include <string>

#include "Utilities.h"
#include "Equipa.h"
#include "Modalidade.h"

using namespace std;

class Equipa;

class Atleta {

	unsigned int id;
	info inf;
	float pontuacao;
	Equipa *equipa;
	//vector<Prova*> provas;
	vector<Modalidade *> modalidades;		//"Requisitos Obrigatórios: Associar atletas de uma equipa às respectivas modalidades"

public:
	Atleta(string n, string pais, unsigned int i, unsigned int p, unsigned int a);
	Atleta();
	~Atleta();

	unsigned int getID() const;

	info getInfo() const;
	void setInfo(info i);

	float getPontuacao() const;
	void setPontuacao(float p);

	Equipa getEquipa() const;
	void setEquipa(const Equipa & eq);

	void imprime() const;

};

#endif /* SRC_ATLETA_H_ */
