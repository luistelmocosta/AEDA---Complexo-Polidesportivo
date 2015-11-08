#ifndef SRC_CALENDARIO_H_
#define SRC_CALENDARIO_H_

#include <string>
#include <vector>
#include "Prova.h"

using namespace std;

class Calendario{

	string nomeFicheiro;
    vector<Prova*> provas;
    vector<string> modalidades;
    vector<string> equipas;
    vector<string> atletas;

public:
    Calendario(){}
    Calendario(vector <Prova*> p,vector<string> m, vector<string> e, string nomeF);

    string getNomeFich() const;
    vector<string> getModalidades() const;
    vector<string> getEquipas() const;
    vector<string> getAtletas() const;
    vector<Prova*> getProvas() const;
    void showProvas() const;
    void showUmaProva(int i) const;
    bool checkProva(Prova* p);
    bool adicionaProva (Prova* p);
    void removeProva();
    void alteraProva(int i);
    bool fichExiste(const string& nome);


    void criaProvas(); //TODO RECEBE CAMPEONATO

    void criaFich(string nome);
};

#endif /* SRC_CALENDARIO_H_ */
