/*
 * Adepto.cpp
 *
 *  Created on: Dec 17, 2015
 *      Author: luiscosta
 */

#include <iostream>
#include "Adepto.h"

using namespace std;

int Adepto::newID = 0;

Adepto::Adepto(string n): uid(newID++){

	nome = n;
	//equipa == e1;



}

Adepto::Adepto(){

}


string Adepto::getNome() const{
	return nome;
}

void Adepto::setNome(string n){
	nome = n;
}

unsigned int Adepto::getID() const{
	return uid;
}



