#pragma once
#include <vector>
#include <string>
#include "Equipa.h"
#include "Modalidade.h"
using namespace std;

class Desporto{

private:
	string nome;
	vector <Modalidade*> modalidades;
	vector <Equipa*> equipas;

public:
	Desporto(string nome, float pont);
	string getNome() const;
	vector <Modalidade*> getModalidades() const;
	vector<Equipa*> getEquipas() const;

};
