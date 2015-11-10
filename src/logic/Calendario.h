#ifndef SRC_LOGIC_CALENDARIO_H_
#define SRC_LOGIC_CALENDARIO_H_

#include <string>
#include <vector>
#include "Prova.h"
#include "Campeonato.h"

using namespace std;


class Campeonato;
class Calendario{

	string nomeF;
    vector<Prova*> provas;
    vector <string> modalidades;
    vector <string> atletas;
    vector <string> equipas;

public:
    Calendario(){}
    Calendario(vector <Prova*> p, vector <string> m, vector <string> a, vector <string> e, string nome);

    vector<Prova*> getProvas() const;
    vector<string> getModalidades() const;
    vector<string> getEquipas() const;
    vector<string> getAtletas() const;
    string getNomeFich() const;



    int findProva(int id);
    vector<Prova*> findProva_Data(date d);
    vector<Prova*> findProva_Local(string loc);
    vector<Prova*> findProva_Modal(Modalidade* m);
    vector<Prova*> findProva_Vence(Equipa* e);
    bool addProva(Prova &p);

    bool checkProva(Prova &p);
    void showUmaProva(int i) const;
    bool fichExiste(string n);
    bool adicionaProva (Prova &p);
    void deleteProva(int i);
    void removeProva();


    void criaProvas(Campeonato &c1);
    void showProvas() const;

    void criaFich(bool alterar, bool adicionar);
};

#endif /* SRC_LOGIC_CALENDARIO_H_ */
