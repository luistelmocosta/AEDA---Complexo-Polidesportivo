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
    unsigned int duracao;   //"Cada prova terá um tempo de duracao."
    vector<Equipa*> vs;     //par: quem se defronta (Nao percebo isto nao bastava duas strings?)
    Desporto* desporto; //ou Modalidade mod ou nenhum (De que interessa saber que desporto. so precisa de saber local/hora e quem e o vencedor)?
    Equipa* vencedor;

public:
    Prova(date d, string l, unsigned int dur, vector <Equipa> v, Desporto* desp);

    date getData() const;
    string getLocal() const;
    unsigned int getDuracao() const;

    vector<Equipa*> getAdversarios() const;

    Desporto* getDesporto() const;
    Equipa* getVencedor() const;
    void setVencedor(Equipa* v);
};

#endif /* SRC_PROVA_H_ */
