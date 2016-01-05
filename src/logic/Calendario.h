#ifndef SRC_LOGIC_CALENDARIO_H_
#define SRC_LOGIC_CALENDARIO_H_

#include <string>
#include <vector>
#include "BST.h"
#include "Prova.h"
#include "Campeonato.h"

using namespace std;

class Campeonato;

class Calendario{

	BST<Prova*> provasBST;
    //vector<Prova*> provas;
    vector <string> modalidades;
    vector <string> atletas;
    vector <string> equipas;
    string nomeF;

public:
    Calendario(): provasBST(new Prova()){}
    Calendario(vector <Prova*> p, vector <string> m, vector <string> a, vector <string> e, string nF);

    BST<Prova*> getProvas() const;
    Prova* getProvaID(int id);
    //void setProvas(vector<Prova*> vp);

    vector<string> getModalidades() const;
    void setModalidades(vector<string> vm);

    vector<string> getAtletas() const;
    void setAtletas(vector<string> va);

    vector<string> getEquipas() const;
    void setEquipas(vector<string> ve);

    string getNomeFich() const;
    void setNomeFich(string nF);


    int findProva(int id);
    vector<Prova*> findProva_Data(date d);
    vector<Prova*> findProva_Local(string loc);
    vector<Prova*> findProva_Modal(Modalidade* m);
    vector<Prova*> findProva_Vence(Equipa* e);

    bool checkProva(Prova &p);
    bool inserirProva (Prova &p);
    void eliminarProva(int id);

    void showUmaProva(int i) const;
    void showProvas() const;

    /*bool fichExiste(string n);
    void criaFich(bool alterar, bool adicionar);*/
};

#endif /* SRC_LOGIC_CALENDARIO_H_ */
