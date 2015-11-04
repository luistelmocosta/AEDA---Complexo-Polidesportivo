#include "Prova.h"

Prova::Prova(date d, string l, unsigned int dur, vector <Equipa> v, Desporto* desp){


/*
	fstream fich;

	fich.open("Provas.txt", ios::in);

	if(fich.is_open()){

		while(!fich.eof()){
			getline(fich, nome);
			// le resto
			if(fich.eof())
				break;

			Prova p;
			getline(fich, nome);

			provas.push_back(x);
		}
	}

	else
		throw UnableOpenFile(filename);
	fich.close();
*/


	this->data = d;
	this->local = l;
	this->duracao = dur;
	this->desporto = desp;

	for (unsigned int i = 0; i < v.size(); i++){
		this->vs.push_back(&v[i]);
	}


}

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

void Prova::setVencedor(Equipa* v){

	this->vencedor = v;

}
