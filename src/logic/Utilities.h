#ifndef SRC_UTILITIES_H_
#define SRC_UTILITIES_H_

#include <vector>

using namespace std;



/*
 	 *						*
 	 * 		UTILITARIOS		*
 	 *						*
*/

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





/*
 	 *			ALGORITMOS			*
 	 * 		PESQUISA e ORDENACAO	*
 	 *			VECTORES			*
*/

template <class Comparable>
int sequentialSearch(const vector<Comparable> &v, Comparable x)
{
    for (unsigned int i = 0; i < v.size(); i++)
        if(v[i] == x)
           return i;   // encontrou
    return -1;     // nao encontrou
}



template <class Comparable>
void insertionSort(vector<Comparable> &v)
{
    for (unsigned int p = 1; p < v.size(); p++)
    {
    	Comparable tmp = v[p];
    	int j;
    	for (j = p; j > 0 && tmp < v[j-1]; j--)
    		v[j] = v[j-1];
    	v[j] = tmp;
    }
}





/*
	 * 		TRATAMENTO			*
	 * 			de				*
	 * 		EXCEPCOES			*
*/

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
