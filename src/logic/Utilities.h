#ifndef SRC_UTILITIES_H_
#define SRC_UTILITIES_H_

using namespace std;

struct info{				// CC atleta
	string nome;
	string pais;
	unsigned int idade;
	unsigned int peso;
	unsigned int altura;
};



struct date{				// a usar em prova, campeonato
	unsigned int dia;
	unsigned int mes;
	unsigned int ano;
};



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

#endif /* SRC_UTILITIES_H_ */
