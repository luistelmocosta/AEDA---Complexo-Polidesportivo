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

/*struct hash_adeptos{
	int operator() (const Adepto &a1) const{
		return a1.getEmail().size(); }

	bool operator() (const Adepto & a1, const Adepto & a2) const{
		return a1.getEmail() == a2.getEmail();}

};


typedef tr1::unordered_set<Adepto, hash_adeptos, hash_adeptos> TabelaAdeptos;*/

class Bilhete{
	//TabelaAdeptos adeptos;

	int uid;
	static int newID;
	date validade;
	float preco;
	bool vendido;
	vector<Prova*> provas;

public:

	Bilhete(date validade, bool vendido);
	Bilhete();

	int getID() const;
	void setID(int id);

	date getValidade() const;
	void setValidade(date date);

	string imprimeBilhete() const;

	string getInfo() const;

	//Adepto* getDono() const;
	//void setDono (Adepto* a1);

	bool getEstado() const;
	bool setVendido(Bilhete &b1);

	void inserirBilhete(Bilhete &b1);
};



#endif /* SRC_LOGIC_BILHETE_H_ */
