/*
 * Bilhete.h
 *
 *  Created on: Dec 17, 2015
 *      Author: luiscosta
 */

#ifndef SRC_LOGIC_BILHETE_H_
#define SRC_LOGIC_BILHETE_H_

#include <tr1/unordered_set>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "Atleta.h"
#include "Adepto.h"



struct hash_adeptos{
	int operator() (const Adepto &a1) const{
		return a1.getNome().size(); }

	bool operator() (const Adepto & a1, const Adepto & a2) const{
		return a1.getNome()==a2.getNome();}

};


typedef tr1::unordered_set<Adepto, hash_adeptos, hash_adeptos> Tabela;


class Bilhete{

	Tabela bilhetes;
	int uid;
	static int newID;
	date validade;
	Adepto* dono;
	bool vendido;

public:

	Bilhete(date validade, Atleta* dono, bool vendido);

	unsigned int getID() const;
	void setID(int id);

	date getValidade() const;
	void setValidade(date date);

	Adepto* getDono() const;
	void setDono (Adepto &a1);

	bool getEstado() const;
	bool setVendido(Bilhete &b1);
};



#endif /* SRC_LOGIC_BILHETE_H_ */
