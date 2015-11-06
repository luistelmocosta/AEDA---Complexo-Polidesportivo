#include "Prova.h"

Prova::Prova(date d, string l, unsigned int dur, vector <Equipa*> v, Modalidade* modal){

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

	data = d;
	local = l;
	duracao = dur;
	mod = modal;

	for (unsigned int i = 0; i < v.size(); i++){
		this->vs.push_back(v[i]);
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

Modalidade* Prova::getModalidade() const {
	return mod;
}

Equipa* Prova::getVencedor() const {
	return vencedor;
}

void Prova::setVencedor(Equipa* v){
	vencedor = v;
}

Atleta* Prova::getParticipante(int i) const{

	vector <Atleta*> atletasVec = vs[i]->getAtletas();
	int position;


	for(unsigned int j=0; j < atletasVec.size(); j++){

		vector <Modalidade*> modAtleta = atletasVec[j]->getModalidades();

		position = sequentialSearch(modAtleta, this->mod);
		if(position !=-1){
			return vs[i]->getAtletas()[j];
		}

	}

}

bool Prova::operator !=(const Prova &p){

	bool result = true;

	if (this->local == p.getLocal() || (this->getData().ano == p.getData().ano && this->getData().dia == p.getData().dia && this->getData().mes == p.getData().mes && this->getData().hora == p.getData().hora)){
		result = false;
	}

	/*if(this->getData().hora < p.getData().hora + p.getDuracao()){

		result = false;
	}*/

	//TODO verificar hora + duracao este esta mal feito

	return result;

}
