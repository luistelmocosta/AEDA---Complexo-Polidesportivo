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
#include "Utilities.h"


class Bilhete{

	int uid;
	static int newID;
	date validade;
	string dono;
	bool vendido;

public:

	Bilhete(date validade, string dono, bool vendido);
	Bilhete();

	int getID() const;
	void setID(int id);

	date getValidade() const;
	void setValidade(date date);

	string imprimeBilhete() const;

	//Adepto* getDono() const;
	//void setDono (Adepto &a1);

	bool getEstado() const;
	bool setVendido(Bilhete &b1);
};



#endif /* SRC_LOGIC_BILHETE_H_ */
