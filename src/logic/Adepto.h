#ifndef SRC_LOGIC_ADEPTO_H_
#define SRC_LOGIC_ADEPTO_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <stdlib.h>
#include "Bilhete.h"

using namespace std;
//class Bilhete;








class Adepto {
	int uid;
	string email;
	static int newID;
	Bilhete* bilhete;
	string nome;
	string nEquipa;

public:

	Adepto(string nome, string email, string nEq);
	//Adepto(string nome, Equipa* e1, vector<Bilhete*> bilhetes);
	Adepto();

	Adepto(string nome);

	unsigned int getID() const;

	string getNome() const;
	void setNome(string n);

	string getEquipa() const;
	void setEquipa(string nEq);

	string getEmail() const;
	void setEmail(string novoEmail);

	void setBilhete(Bilhete *b1);
	void inserirAdepto(Adepto &ad);
	//vector<Bilhete*> getBilhetes() const;


	string getInfo() const;

	//void Adepto::readFile(ifstream &filename);

	void imprime() const;

	bool operator ==(const Adepto &a1);





};










#endif /* SRC_LOGIC_ADEPTO_H_ */
