#pragma once

#include <vector>
#include <string>

using namespace std;

class Equipa {
	string nome;
	string pais;
	string patrocinador;
	int pontuacao;
	vector <Atleta*> atletas;
public:
	Equipa(string nome, string pais, string patrocinador, int pontuacao);
	string getEquipa() const;
	bool addEquipa() const;
	bool eliminaEquipa()const;
	int getPontuacao() const;
	int setPontuacao() const;
	vector<Atleta*> getAtletas() const;
	string getPais() const;
	string getPatrocinador() const;

};
