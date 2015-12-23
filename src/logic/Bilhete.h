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
#include "Adepto.h"

class Bilhete{

	int uid;
	static int newID;
	date validade;
	float preco;
	bool vendido;
	Adepto* dono;
	vector<Prova*> provas;

public:

	Bilhete(date validade, Adepto* dono, vector<Prova*> provas);
	Bilhete(int uid);
	Bilhete();

	vector<Prova*> getProvas() const;

	//void setProva(Prova* p);
	date getData() const;

	int getID() const;
	unsigned int getIdDono() const;
	void setDono(Adepto *ad);
	string getDataFormatada() const;
	string getEmailDono() const;
	string getNomeDono() const;
	void printProvas() const;
	void addProvas(vector<Prova*> p);



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
