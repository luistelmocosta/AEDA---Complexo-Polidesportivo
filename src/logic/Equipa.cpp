#include "Equipa.h"
#include <iostream>
#include <iterator>

using namespace std;


Equipa::Equipa(string n, string p, string pat): nome(n), pais(p), patrocinador(pat) {
	pontuacao=0;
}

Equipa::Equipa() {
	pontuacao=0;
}

string Equipa::getNome() const {
	return nome;
}

string Equipa::getPais() const {
	return pais;
}

string Equipa::getPatrocinador() const {
	return patrocinador;
}

float Equipa::getPontuacao() const {
	return pontuacao;
}

void Equipa::setPontuacao(float p) {
	pontuacao=p;
}

Atleta* Equipa::getAtleta(unsigned int n){

	for(vector<Atleta *>::iterator it=atletas.begin(); it!=atletas.end(); it++)
			if((*it)->getID()==n)
				return *it;

		throw AtletaInexistente(n);
}

vector<Atleta*> Equipa::getAtletas() const {
	return atletas;
}

void Equipa::inserirAtleta(Atleta &a1){
	atletas.push_back(&a1);
}
void Equipa::adicionaAtleta(){
	string nome, pais;
	int idade, peso, altura;
	cout << "Nome: ";
	cin >> nome;
	cout << endl;
	cin.ignore();
	cout << "Pais: ";
	cin >> pais;
	cout << endl;
	cin.ignore();
	cout << "Idade: ";
	cin >> idade;
	cout << endl;
	cin.ignore();
	cout << "Peso: ";
	cin >> peso;
	cout << endl;
	cin.ignore();
	cout << "Altura: ";
	cin >> altura;
	cout << endl;
	cin.ignore();
	Atleta *a1 = new Atleta(nome, pais, idade, peso, altura);
	inserirAtleta(*a1);
}

void Equipa::readFile(string filename){

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
			inserirAtleta(*a1);
		}
	}
}

void Equipa::showAtletas(){

	vector<Atleta*>::iterator it;
	for(it = atletas.begin(); it != atletas.end() ;  ++it) {
		cout << (*it)->getID() << endl;
		cout << (*it)->getNome() << endl;
		cout << (*it)->getPais() << endl;
		cout << (*it)->getIdade() << endl;
		cout << (*it)->getPeso() << endl;
		cout << (*it)->getAltura() << endl << endl;
	}

}

bool Equipa::eliminaAtleta(unsigned int n){
	for(unsigned int i=0; i<atletas.size(); i++) {
		if(atletas[i]->getID() ==  n) {
			atletas.erase(atletas.begin()+i);
			//--Atleta::uid;
			return true;
		}
	}
	throw AtletaInexistente(n);
	return false;
}

bool Equipa::existeAtleta(string nome){

	vector<Atleta*>::iterator it;

	for(it = atletas.begin(); it != atletas.end(); ++it){
		if((*it)->getNome() == nome)
		{
			return true;
		}
	}

	cout << "Nao existe" << endl;
	throw AtletaInexistente(nome);
	return false;

}

/*void Equipa::escreveFicheiro(string filename) {
	ofstream ficheiro_escrita(filename.c_str());
	vector<Atleta*>::iterator it;

	while(it!=atletas.end()) {
		cout << (*it)->getNome();
		ficheiro_escrita<<(*it)->getNome()<<endl<<(*it)->getIdade()<<endl<<(*it)->getPeso()<<endl << (*it)->getAltura();
		it++;
	}
}*/




