#ifndef SRC_MODALIDADE_H_
#define SRC_MODALIDADE_H_

#include "Desporto.h"

using namespace std;

class Modalidade: public Desporto{

    string nome;
    bool singular; // true: não pode ser executada simultâneo ("modalidades de um desporto poderão não poder ser executadas em simultâneo")
    unsigned int nJogadores;

public:

    Modalidade(string n, bool s);
    Modalidade(){}
    virtual ~Modalidade();

    string getNome() const;
    string getNomeDesporto() const;

    bool getSingular() const;

    unsigned int getNJogadores() const;

    bool operator ==(const Modalidade &mod);
};

#endif /* SRC_MODALIDADE_H_ */
