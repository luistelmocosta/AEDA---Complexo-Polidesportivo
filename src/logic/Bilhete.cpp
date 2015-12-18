/*
 * Bilhete.cpp
 *
 *  Created on: Dec 17, 2015
 *      Author: luiscosta
 */
#include "Bilhete.h"

using namespace std;

int Bilhete::newID = 0;

Bilhete::Bilhete(date v, string d, bool sold) : uid(newID++){

	validade = v;
	dono = d;
	sold = false;

}

Bilhete::Bilhete() : uid(newID++){}


int Bilhete::getID() const{
	return uid;
}




