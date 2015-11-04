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

vector<Equipa*> Campeonato::getEquipas() const {
	return equipas;
}

vector<Desporto*> Campeonato::getDeportos() const {
	return desportos;
}

Calendario* Campeonato::getCalendario() const {
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

void Campeonato::inserirEquipa(Equipa &e1){
	equipas.push_back(&e1);
}

void Campeonato::readFile(ifstream& ficheiro_leitura){

	if(!ficheiro_leitura)
		throw ErroNoFicheiro();
	else {
		string nome, pais, patrocinador;

		while (!ficheiro_leitura.eof()) {

			getline(ficheiro_leitura, nome);
			getline(ficheiro_leitura, pais);
			getline(ficheiro_leitura, patrocinador);


			Equipa *e1 = new Equipa(nome, pais, patrocinador);
			inserirEquipa(*e1);
		}
	}


	vector<Equipa*>::iterator it;
	for(it = equipas.begin(); it != equipas.end() ;  ++it) {
		cout << (*it)->getNome() << endl;
		cout << (*it)->getPais() << endl;
		cout << (*it)->getPatrocinador() << endl;
	}

}

