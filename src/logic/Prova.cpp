#include "Prova.h"

date Prova::getData() const {
	return data;
}

string Prova::getLocal() const {
	return local;
}

unsigned int Prova::getDuracao() const {
	return duracao;
}

vector<Equipa*> Prova::getAdversarios() const {
	return vs;
}

Desporto* Prova::getDesporto() const {
	return desporto;
}

Equipa* Prova::getVencedor() const {
	return vencedor;
}
