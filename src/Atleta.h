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
	float pontuacao;
	static unsigned int ultimoId;
	unsigned int id;


public:
	Atleta(string nome, string pais, info peso, info altura);
	void imprime() const;
	string getNome() const;
	string setNome(string nnome) const;
	int getPontuacao();
	void setPontuacao();
	unsigned int getAltura() const;
	unsigned int getPeso() const;
	vector<Modalidade *> modalidades;
	vector<Prova*> provas;

	class ValorIncorrecto {
	public:
		int v;
		ValorIncorrecto(int v) :
			v(v) {
		}
	};


	void readFile(ifstream& ficheiro_leitura);
	void writeFile(ofstream& ficheiro_escrita);

	class ErroNoFicheiro{
	public:
		ErroNoFicheiro(){}

	};
};



