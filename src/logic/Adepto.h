/*
 * Adepto.h
 *
 *  Created on: Dec 17, 2015
 *      Author: luiscosta
 */

#ifndef SRC_LOGIC_ADEPTO_H_
#define SRC_LOGIC_ADEPTO_H_

#include <tr1/unordered_set>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <stdlib.h>
#include "Bilhete.h"


using namespace std;


struct hash_bilhetes{
	int operator() (const Bilhete &b1) const{
		return b1.getID(); }

	bool operator() (const Bilhete & b1, const Bilhete & b2) const{
		return b1.getID() == b2.getID();}

};


typedef tr1::unordered_set<Bilhete, hash_bilhetes, hash_bilhetes> TabelaBilhetes;

class Adepto {
	TabelaBilhetes bilhetes;
	int uid;
	static int newID;
	string nome;
	string nEquipa;

public:

	Adepto(string nome);
	//Adepto(string nome, Equipa* e1, vector<Bilhete*> bilhetes);
	Adepto();

	unsigned int getID() const;

	string getNome() const;
	void setNome(string n);

	string getEquipa() const;
	void setEquipa(string nEq);

	//vector<Bilhete*> getBilhetes() const;
	void inserirBilhete(Bilhete &b1);

	void removerBilhete(Bilhete &b1);


	void imprime() const;

};










#endif /* SRC_LOGIC_ADEPTO_H_ */
