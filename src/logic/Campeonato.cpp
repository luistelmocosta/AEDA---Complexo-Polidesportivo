#include "Campeonato.h"

Campeonato::Campeonato() {}

Campeonato::Campeonato(string nome): nome(nome) {}

string Campeonato::getNome() const {
	return nome;
}

date Campeonato::getData() const {
	return data;
}

string Campeonato::getPais() const {
	return pais;
}

vector<Atleta*> Campeonato::getAtletas() const{
	return atletas;
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

void Campeonato::adicionaEquipa(){
	string nome, pais, patrocinio;

	cout << "Insira o nome da equipa a criar: ";
	cin.ignore();
	getline(cin, nome);
	cout << endl;

	cout << "Insira o pais da equipa a criar: ";
	cin.ignore();
	getline(cin, pais);
	cout << endl;

	cout << "Insira o patocinador da equipa a criar";
	cin.ignore();
	getline(cin, patrocinio);
	cout << endl;


	Equipa *e1 = new Equipa(nome, pais, patrocinio);
	inserirEquipa(*e1);
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

void Campeonato::readFileEquipas(string filename){

	ifstream ficheiro_leitura (filename.c_str());

	if(!ficheiro_leitura)
		throw ErroNoFicheiro(filename);
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
}

void Campeonato::readFileAtletas(string filename){
	ifstream ficheiro_leitura(filename.c_str());

		if(!ficheiro_leitura)
			throw ErroNoFicheiro(filename);
		else {
			string nome, pais, temp1, temp2, temp3;
			int idade, altura, peso;

			while (!ficheiro_leitura.eof()) {

				getline(ficheiro_leitura, nome);
				getline(ficheiro_leitura, pais);
				getline(ficheiro_leitura, temp1);
				getline(ficheiro_leitura, temp2);
				getline(ficheiro_leitura, temp3);

				idade = atoi(temp1.c_str());
				peso = atoi(temp2.c_str());
				altura = atoi(temp3.c_str());

				Atleta *a1 = new Atleta(nome, pais, idade, peso, altura);
				atletas.push_back(a1);
			}
		}
}

int Campeonato::findEquipa(string nomeEquipa){

	for(unsigned int i = 0; i < equipas.size(); i++){
		if(equipas[i]->getNome() == nomeEquipa){
			cout << nomeEquipa << " na posicao " << i << endl;
			return i;
		}
	}
	return -1;
}

int Campeonato::findAtleta(unsigned int id) {

	for(unsigned int i=0; i< atletas.size(); i++){
		if(atletas[i]->getID()==id){
			cout << id << " na posicao " << i << endl;
			return i;
		}
	}
	return -1;
}

int Campeonato::findDesporto(string nomeDesporto){

	for(unsigned int i = 0; i < desportos.size(); i++){
		if(desportos[i]->getNome() == nomeDesporto){
			cout << nomeDesporto << " na posicao " << i << endl;
			return i;
		}
	}
	return -1;
}

vector<Atleta*> Campeonato::findAtletaVect(string nomeAtleta) {
	vector<Atleta*> aux;
	for(unsigned int i=0; i<atletas.size(); i++){
		if(atletas[i]->getNome()==nomeAtleta)
			aux.push_back(atletas[i]);
	}
	return aux;
}

void Campeonato::imprimeAtletas() const {
	for(unsigned int i = 0; i < atletas.size(); i++){
		cout << atletas[i]->getID() << endl;
		cout << atletas[i]->getNome() << endl;
		cout << atletas[i]->getPais() << endl;
		cout << atletas[i]->getIdade() << endl;
		cout << atletas[i]->getPeso() << endl;
		cout << atletas[i]->getAltura() << endl << endl;
	}
	cout << endl;
}

void Campeonato::imprimeEquipas() const{
	for(unsigned int i = 0; i < equipas.size(); i++){
		cout << equipas[i]->getNome() << endl;
		cout << equipas[i]->getPais() << endl;
		cout << equipas[i]->getPatrocinador() << endl;
	}
	cout << endl;
}

void Campeonato::imprimeAtletasPorEquipa() const{
	for(unsigned int i = 0; i < equipas.size(); i++){
		equipas[i]->showAtletas();
	}
	cout << endl;
}

void Campeonato::ordenaClassificacoes(){

	insertionSort(equipas);

}


