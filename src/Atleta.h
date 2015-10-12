#pragma once

#include <vector>
#include <string>

using namespace std;

struct Info{
	int peso;
	int altura;
} info;

class Atleta {
	string nome;
	string pais;
	info peso;
	info altura;


public:
	Atleta(string nome, string pais, info peso, info altura);
	int getID() const;
	int setID() const;
	void imprime() const;
	string getNome() const;
	string setNome() const;
	int getPontuacao();
	int setPontuacao();
	int getAltura() const;
	int getPeso() const;
	vector<Modalidade *> modalidades;
	vector<Prova*> provas;

};



