/*
 * Adepto.h
 *
 *  Created on: Dec 17, 2015
 *      Author: luiscosta
 */

#ifndef SRC_LOGIC_ADEPTO_H_
#define SRC_LOGIC_ADEPTO_H_

#include <tr1/unordered_set>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <stdlib.h>

class Bilhete;

using namespace std;

class Adepto {
	int uid;
	static int newID;
	string nome;
	string equipa;
	vector<Bilhete*> bilhetes;

public:

	Adepto(string nome);
	//Adepto(string nome, Equipa* e1, vector<Bilhete*> bilhetes);
	Adepto();

	unsigned int getID() const;

	string getNome() const;
	void setNome(string n);

	string getEquipa() const;
	void setEquipa(string equipa);

	vector<Bilhete*> getBilhetes() const;
	void inserirBilhete(Bilhete &b1);


	void imprime() const;

};










#endif /* SRC_LOGIC_ADEPTO_H_ */
