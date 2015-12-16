#ifndef SRC_LOGIC_MODALIDADE_H_
#define SRC_LOGIC_MODALIDADE_H_

#include "Desporto.h"

using namespace std;

class Modalidade: public Desporto{

    string nome;
    bool singular; // true: nao pode ser executada simultaneo ("modalidades de um desporto poderao nao poder ser executadas em simultaneo")
    unsigned int nJogadores;

public:

    Modalidade(string n, bool s);
    Modalidade(){}
    virtual ~Modalidade();

    string getNome() const;
    string getNomeDesporto() const;

    bool getSingular() const;

    unsigned int getNJogadores() const;
    string pontuacao(string e1, string e2);

    bool operator ==(const Modalidade &mod);
};

#endif /* SRC_LOGIC_MODALIDADE_H_ */
