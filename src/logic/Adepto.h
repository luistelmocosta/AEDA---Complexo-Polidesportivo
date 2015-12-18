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

//using namespace __gnu_cxx;
using namespace std;

/*
struct hash_bilhetes{
	int operator() (const Bilhete &b1) const{
		return b1.getID(); }

	bool operator() (const Bilhete & b1, const Bilhete & b2) const{
		return b1.getID() == b2.getID();}

};

typedef tr1::unordered_set<Bilhete, hash_bilhetes, hash_bilhetes> TabelaBilhetes;*/

class Bilhete;

class Adepto {
	//TabelaBilhetes bilhetes;
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

	unsigned int getID() const;

	string getNome() const;
	void setNome(string n);

	string getEquipa() const;
	void setEquipa(string nEq);

	string getEmail() const;
	void setEmail(string novoEmail);

	//vector<Bilhete*> getBilhetes() const;
	void inserirBilhete(Bilhete &b1);

	void removerBilhete(Bilhete &b1);

	string getInfo() const;

	//void Adepto::readFile(ifstream &filename);

	void imprime() const;

};










#endif /* SRC_LOGIC_ADEPTO_H_ */
