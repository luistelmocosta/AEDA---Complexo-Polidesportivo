#ifndef SRC_MODALIDADE_H_
#define SRC_MODALIDADE_H_

#include "Desporto.h"

using namespace std;

class Modalidade: public Desporto{

private:
    string nome;
    bool singular; // true: não pode ser executada simultâneo ("modalidades de um desporto poderão não poder ser executadas em simultâneo")

public:
    Modalidade(string n, bool s);
    virtual ~Modalidade();
    string getNome() const;
    bool getSingular() const;

};

#endif /* SRC_MODALIDADE_H_ */
