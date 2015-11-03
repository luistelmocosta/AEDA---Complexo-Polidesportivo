#include "Campeonato.h"

unsigned int Campeonato::getID() const {
	return id;
}

string Campeonato::getNome() const {
	return nome;
}

date Campeonato::getData() const {
	return data;
}

string Campeonato::getPais() const {
	return pais;
}

vector<Equipa> Campeonato::getEquipas() const {
	return equipas;
}

vector<Desporto*> Campeonato::getDeportos() const {
	return desportos;
}

Calendario Campeonato::getCalendario() const {
	return calendario;
}

bool Campeonato::addEquipa() {
	/*
	 *
	 * return 	true se pode adicionar equipa
	 * 			false caso contrario
	 *
	 */
}

bool Campeonato::eliminaEquipa() {
	/*
	 *
	 * return	true se eliminou com sucesso
	 * 			false caso contrario
	 *
	 */
}

void Campeonato::readFile(const string filename){

	string tmp;
	fstream fich;
	string nome, pais, pat;

	fich.open(filename.c_str(), ios::in);

	if(fich.is_open()){

		while(!fich.eof()){
			getline(fich, nome);
			//cin.ignore();
			fich >> pais >> pat;
			if(fich.eof())
				break;
			Equipa x(nome,pais,pat);

			getline(fich, nome);

			equipas.push_back(x);
		}
	}

	else
		cout << "Unable to open file"; // podia ser uma exception!!
	fich.close();


	cout << equipas[0].getNome() << endl;
	cout << equipas[0].getPais() << endl;

}


