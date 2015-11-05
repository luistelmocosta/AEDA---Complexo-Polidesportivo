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
    Modalidade* mod; //ou Modalidade mod
    Equipa* vencedor;

public:
    Prova(date d, string l, unsigned int dur, vector <Equipa> v, Modalidade* modal);
    date getData() const;
    string getLocal() const;
    unsigned int getDuracao() const;
    vector<Equipa*> getAdversarios() const;
    Modalidade* getModalidade() const;
    Equipa* getVencedor() const;
    Atleta* getParticipante(int i)const;
    void setVencedor(Equipa* v);
    bool operator !=(const Prova &p);


};

#endif /* SRC_PROVA_H_ */
