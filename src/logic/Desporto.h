#ifndef SRC_DESPORTO_H_
#define SRC_DESPORTO_H_

#include <vector>
#include <string>

using namespace std;

class Desporto{

	string nome;

public:
	Desporto(){}
	Desporto(string n):nome(n){}
	virtual ~Desporto(){}

	virtual void setNome(string n){nome=n;}

	virtual unsigned int getNJogadores() const = 0;

	virtual string getNome() const {return nome;}
	virtual void calcPont(){}
};


#endif /* SRC_DESPORTO_H_ */
