#ifndef SRC_EQUIPA_H_
#define SRC_EQUIPA_H_

#include <vector>
#include <string>

#include "Atleta.h"

using namespace std;

class Atleta;

class Equipa {
	string nome;
	string pais;
	string patrocinador;
	float pontuacao;
	vector<Atleta> atletas;
public:
	Equipa(string n, string p, string pat);
	Equipa();
	void readFile(const string filename);
	string getNome() const;
	string getPais() const;
	string getPatrocinador() const;
	float getPontuacao() const;
	void setPontuacao(float p);
	vector<Atleta*> getAtletas() const;
};

#endif /* SRC_EQUIPA_H_ */
