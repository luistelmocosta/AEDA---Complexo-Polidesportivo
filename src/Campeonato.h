#pragma once
#include <vector>
#include <string>

using namespace std;

struct Data{
	int dia;
	int mes;
	int ano;
} data;

class Campeonato{
	string nome;
	data data;
	string pais;
	vector<Equipa*> pontuacoes;
public:
	string getNome() const;
	string getData() const;
	string getPais()const;
	vector <Equipa*> getPont() const;
};
