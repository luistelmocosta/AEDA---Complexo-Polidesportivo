#include "Modalidade.h"
#include<iostream>

using namespace std;

Modalidade::Modalidade(string n, bool s) {
	this->singular=s;
	this->nome = n;
}

Modalidade::~Modalidade() {
}

string Modalidade::getNome() const {
	return nome;
}

bool Modalidade::getSingular() const {
	return singular;
}


bool Modalidade::operator ==(const Modalidade &mod){
	cout << "overload" << endl;
	return (this->getNome() == mod.getNome());

}
