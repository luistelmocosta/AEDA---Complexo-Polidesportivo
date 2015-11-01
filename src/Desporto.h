#ifndef AEDA_PROJECTO_1_DESPORTO_H
#define AEDA_PROJECTO_1_DESPORTO_H


#include <vector>
#include <string>
#include "Equipa.h"
#include "Modalidade.h"
using namespace std;

class Desporto{

private:
	string nome;
	//vector <Modalidade*> modalidades;
	// ??? tipoPontuacao;  "Cada desporto terá um determinado tipo de pontuação"


public:
	Desporto(string nome, float pont);
	virtual ~Desporto();
	string getNome() const;
	//vector <Modalidade*> getModalidades() const;


};

#endif //AEDA_PROJECTO_1_DESPORTO_H