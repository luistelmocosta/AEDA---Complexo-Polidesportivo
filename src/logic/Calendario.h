#ifndef SRC_CALENDARIO_H_
#define SRC_CALENDARIO_H_

#include <string>
#include <vector>
#include "Prova.h"

using namespace std;

class Calendario{

    vector<Prova*> provas;

public:
    Calendario(){}
    Calendario(vector <Prova*> p); // recebe um vetor para testar mas deve ser mudado para uma prova de cada vez
    vector<Prova*> getProvas() const;
    bool checkProva(Prova* p);
    void deleteProva(int i);
    bool adicionaProva (Prova* p);
    void criaFich(string nome);
    void criaProvas();

};

#endif /* SRC_CALENDARIO_H_ */
