#ifndef SRC_ATLETA_H_
#define SRC_ATLETA_H_

#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include "Utilities.h"
#include "Equipa.h"
#include "Modalidade.h"

using namespace std;

class Equipa;

class Atleta {
	int uid;
	static int newID;
	info inf;
	/*string nome;
	unsigned int peso;
	string pais;
	unsigned int altura;
	unsigned int idade;*/
	float pontuacao;
	//vector<Prova*> provas;
	vector<Modalidade *> modalidades;		//"Requisitos Obrigatórios: Associar atletas de uma equipa às respectivas modalidades"

	class ErroNoFicheiro{



	};

public:
	Atleta(string n, string pais, unsigned int i, unsigned int p, unsigned int a);
	//Atleta();
	//~Atleta();

	unsigned int getID() const;

	info getInfo() const;
	void setInfo(info i);

	string getNome() const;
	string getPais() const;
	unsigned int getIdade() const;
	unsigned int getPeso() const;
	unsigned int getAltura() const;

 	float getPontuacao() const;
	void setPontuacao(float p);

	void imprime() const;

};

#endif /* SRC_ATLETA_H_ */
