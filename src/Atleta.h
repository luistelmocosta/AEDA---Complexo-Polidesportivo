#ifndef AEDA_PROJECTO_1_ATLETA_H
#define AEDA_PROJECTO_1_ATLETA_H

#include <vector>
#include <string>

using namespace std;

struct Info{
	int peso;
	int altura;
} info;

class Atleta {
	unsigned int id;
	string nome;
	string pais;
	info peso;
	info altura;
	float pontuacao;


public:
	Atleta(string nome, string pais, info peso, info altura);
	void imprime() const;
	string getNome() const;
	string setNome(string nnome) const;
	float getPontuacao() const;
	void setPontuacao(float p);
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

#endif //AEDA_PROJECTO_1_ATLETA_H



