#ifndef SRC_LOGIC_ATLETA_H_
#define SRC_LOGIC_ATLETA_H_

#include <tr1/unordered_set>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <stdlib.h>
#include "Utilities.h"
#include "Modalidade.h"

using namespace std;

class Prova;

class Atleta {

	int uid;
	static int newID;
	info inf;
	float pontuacao;
	string nEquipa;
	vector<Modalidade*> modalidades;
	vector<Prova*> provas;

public:
	Atleta(string n, string pais, unsigned int i, unsigned int p, unsigned int a);
	Atleta();
	Atleta(string nome);
	~Atleta();

	unsigned int getID() const;

	info getInfo() const;
	void setInfo(info i);

	string getNome() const;
	void setNome(string n);

	string getPais() const;
	void setPais(string p);

	unsigned int getIdade() const;
	void setIdade(int i);

	unsigned int getPeso() const;
	void setPeso(int p);

	unsigned int getAltura() const;
	void setAltura(int a);

 	float getPontuacao() const;
	void setPontuacao(float p);

	string getNEquipa() const;
	void setNEquipa(string nEq);

	vector<Modalidade*> getModalidades() const;
	void inserirModalidade(Modalidade &mod);

	vector<Prova*> getProvas() const;
	void inserirProva(Prova &prov);

	void imprime() const;
};


struct hash_atletas{
	int operator() (const Atleta & a1) const{
		return a1.getNome().size(); }

	bool operator() (const Atleta & a1, const Atleta & a2) const{
		return a1.getNome()==a2.getNome();}

};


typedef tr1::unordered_set<Atleta, hash_atletas, hash_atletas> Tabela;


class AtletasGuardados {
	Tabela atletas;

public:

	void inserirAtleta(Atleta &a1);
	void removerAtleta(string nome);
	int removerAtletas(int pontuacao);
	void alterarNacionalidade(string nome, string novaNacionalidade);
	void alterarPontuacao(string nome, int pontuacao);
	void showAtletas();
	bool existeAtleta(string nome);
	void readFile(ifstream& filename);
	void writeFile(ofstream& filename);

	class ErroNoFicheiro{
	public:
		ErroNoFicheiro(){

		}

	};
};



#endif /* SRC_LOGIC_ATLETA_H_ */
