#ifndef AEDA_PROJECTO_1_PROVA_H
#define AEDA_PROJECTO_1_PROVA_H

#include <vector>
#include "Equipa.h"

class Prova{
    string data;
    string local;
    unsigned int duracao;   //"Cada prova terá um tempo de duração."
    vector<Equipa*> vs;     //par: quem se defronta
    //Desporto desporto ou Modalidade mod;
    Equipa vencedor;
};


#endif //AEDA_PROJECTO_1_PROVA_H
