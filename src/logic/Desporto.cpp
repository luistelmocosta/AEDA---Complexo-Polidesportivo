#include "Desporto.h"

Desporto::Desporto(string n): nome(n){
}

Desporto::~Desporto() {
}

string Desporto::getNome() const {
	return nome;
}

