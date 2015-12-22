#ifndef SRC_LOGIC_BILHETE_H_
#define SRC_LOGIC_BILHETE_H_

#include <tr1/unordered_set>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "Utilities.h"
#include "Prova.h"

class Bilhete{

	int uid;
	static int newID;
	date validade;
	float preco;
	bool vendido;
	string dono;
	vector<int> provas;

public:

	Bilhete(date validade, string dono, vector<int> provas);
	Bilhete();

	vector<int> getProvas() const;
	void imprime() const;

	int getID() const;

	/*void setID(int id);

	date getValidade() const;
	void setValidade(date date);

	string imprimeBilhete() const;

	string getInfo() const;

	//Adepto* getDono() const;


	bool getEstado() const;
	bool setVendido(Bilhete &b1);

	void inserirBilhete(Bilhee &b1);*/


};



#endif /* SRC_LOGIC_BILHETE_H_ */
