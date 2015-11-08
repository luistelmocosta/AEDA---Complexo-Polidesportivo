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

    int findProva(int id);
    vector<Prova*> findProva_Data(date d);
    vector<Prova*> findProva_Local(string loc);
    vector<Prova*> findProva_Modal(Modalidade* m);
    vector<Prova*> findProva_Vence(Equipa* e);

    bool checkProva(Prova* p);
    void showUmaProva(int i) const;

    bool adicionaProva (Prova* p);
    void deleteProva(int i);
    void removeProva();


    void criaProvas();
    void showProvas() const;

    void criaFich(string nome);
};

#endif /* SRC_CALENDARIO_H_ */
