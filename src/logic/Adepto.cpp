/*
 * Adepto.cpp
 *
 *  Created on: Dec 17, 2015
 *      Author: luiscosta
 */


#include "Adepto.h"

using namespace std;

int Adepto::newID = 0;

Adepto::Adepto(string n): uid(newID++){

	nome = n;
	//equipa == e1;

}

Adepto::Adepto(){

}



unsigned int Adepto::getID() const{
	return uid;
}

string Adepto::getNome() const{
	return nome;
}

void Adepto::setNome(string n){
	nome = n;
}

string Adepto::getEquipa() const{
	return nEquipa;
}

void Adepto::setEquipa(string nEq){

	nEquipa = nEq;
}


void Adepto::inserirBilhete(Bilhete &b1) {
	TabelaBilhetes::iterator it = bilhetes.find(b1);

	if(it == bilhetes.end())
		bilhetes.insert(b1);
	else
	{
		bilhetes.erase(it);
		bilhetes.insert(b1);
	}
}

void Adepto::removerBilhete(Bilhete &b1){
	TabelaBilhetes::iterator it = bilhetes.begin();

	while(it!=bilhetes.end()) {
		if(it->getID()== b1.getID())
			bilhetes.erase(it);
		it++;
	}
}







