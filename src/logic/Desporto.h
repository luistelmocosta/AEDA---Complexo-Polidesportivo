#ifndef SRC_DESPORTO_H_
#define SRC_DESPORTO_H_

#include <vector>
#include <string>

using namespace std;

class Desporto{

private:
	string nome;
	//vector <Modalidade*> modalidades;
	// ??? tipoPontuacao;  "Cada desporto terá um determinado tipo de pontuação"

public:
	Desporto(string n);
	Desporto(){}
	virtual ~Desporto();
	string getNome() const;
	//vector <Modalidade*> getModalidades() const;

};


#endif /* SRC_DESPORTO_H_ */
