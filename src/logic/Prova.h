#ifndef SRC_PROVA_H_
#define SRC_PROVA_H_

#include <vector>
#include "Equipa.h"
#include "Desporto.h"
#include "Utilities.h"

class Equipa;

class Prova{
    date data;
    string local;
    unsigned int duracao;   //"Cada prova terá um tempo de duração."
    vector<Equipa*> vs;     //par: quem se defronta
    Desporto* desporto; //ou Modalidade mod;
    Equipa* vencedor;

public:
    date getData() const;
    string getLocal() const;
    unsigned int getDuracao() const;
    vector<Equipa*> getAdversarios() const;
    Desporto* getDesporto() const;
    Equipa* getVencedor() const;
};

#endif /* SRC_PROVA_H_ */
