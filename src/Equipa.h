#ifndef AEDA_PROJECTO_1_EQUIPA_H
#define AEDA_PROJECTO_1_EQUIPA_H

#include <vector>
#include <string>

using namespace std;

class Equipa {
	string nome;
	string pais;
	string patrocinador;
	float pontuacao;
	vector <Atleta*> atletas;
public:
	Equipa(string nome, string pais, string patrocinador, float pontuacao);
	string getNome() const;
	string getPais() const;
	string getPatrocinador() const;
	float getPontuacao() const;
	void setPontuacao(float p);
	vector<Atleta*> getAtletas() const;

};


#endif //AEDA_PROJECTO_1_EQUIPA_H