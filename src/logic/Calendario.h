#ifndef SRC_LOGIC_CALENDARIO_H_
#define SRC_LOGIC_CALENDARIO_H_

#include <string>
#include <vector>
#include "Prova.h"
#include "Campeonato.h"

using namespace std;

class Campeonato;

class Calendario{

    vector<Prova*> provas;
    vector <string> modalidades;
    vector <string> atletas;
    vector <string> equipas;
    string nomeF;

public:
    Calendario(){}
    Calendario(vector <Prova*> p, vector <string> m, vector <string> a, vector <string> e, string nome);

    vector<Prova*> getProvas() const;
    vector<string> getModalidades() const;
    vector<string> getAtletas() const;
    vector<string> getEquipas() const;
    string getNomeFich() const;

    int findProva(int id);
    vector<Prova*> findProva_Data(date d);
    vector<Prova*> findProva_Local(string loc);
    vector<Prova*> findProva_Modal(Modalidade* m);
    vector<Prova*> findProva_Vence(Equipa* e);

    bool checkProva(Prova &p);

    bool adicionaProva (Prova &p);
    void deleteProva(int id);
    void removeProva();			//pede id pela cli

    void criaProvas(Campeonato &c1);
    void showUmaProva(int i) const;
    void showProvas() const;

    bool fichExiste(string n);
    void criaFich(bool alterar, bool adicionar);
};

#endif /* SRC_LOGIC_CALENDARIO_H_ */
