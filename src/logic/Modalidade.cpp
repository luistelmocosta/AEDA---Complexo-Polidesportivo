#include "Modalidade.h"

Modalidade::Modalidade(string n, bool s): nome(n) {
	singular=s;
}

Modalidade::~Modalidade() {
}

string Modalidade::getNome() const {
	return nome;
}

bool Modalidade::getSingular() const {
	return singular;
}

