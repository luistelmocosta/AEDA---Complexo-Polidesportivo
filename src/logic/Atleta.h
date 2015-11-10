#ifndef SRC_LOGIC_ATLETA_H_
#define SRC_LOGIC_ATLETA_H_

#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include "Utilities.h"
#include "Equipa.h"
#include "Modalidade.h"

using namespace std;

class Atleta {

	int uid;
	static int newID;
	info inf;
	float pontuacao;
	//vector<Prova*> provas;
	string nEquipa;
	vector<Modalidade*> modalidades;		//"Requisitos Obrigatórios: Associar atletas de uma equipa às respectivas modalidades"

public:
	Atleta(string n, string pais, unsigned int i, unsigned int p, unsigned int a);
	Atleta();
	~Atleta();

	unsigned int getID() const;

	info getInfo() const;
	void setInfo(info i);

	string getNome() const;
	void setNome(string n);
	string getPais() const;
	void setPais(string p);
	unsigned int getIdade() const;
	void setIdade(int i);
	unsigned int getPeso() const;
	void setPeso(int p);
	unsigned int getAltura() const;
	void setAltura(int a);

 	float getPontuacao() const;
	void setPontuacao(float p);

	string getEquipa() const;
	void setEquipa(string equipa);

	vector<Modalidade*> getModalidades() const;
	void inserirModalidade(Modalidade &mod1);

	void imprime() const;
};

#endif /* SRC_LOGIC_ATLETA_H_ */
