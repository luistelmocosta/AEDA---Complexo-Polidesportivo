#include <iostream>
#include <iterator>
#include "Equipa.h"


Equipa::Equipa(string n, string p, string pat): nome(n), pais(p), patrocinador(pat) {
	pontuacao=0;
}

Equipa::Equipa() {
	pontuacao=0;
}


/*
 *
 * 		GETS/SETS
 *
 */

string Equipa::getNome() const {
	return nome;
}

void Equipa::setNome(string novoNome) {
	nome=novoNome;
}

string Equipa::getPais() const {
	return pais;
}

void Equipa::setPais(string novoPais) {
	pais=novoPais;
}

string Equipa::getPatrocinador() const {
	return patrocinador;
}

void Equipa::setPatrocinador(string novoPatrocinio) {
	patrocinador=novoPatrocinio;
}

float Equipa::getPontuacao() const {
	return pontuacao;
}

void Equipa::setPontuacao(float p) {
	pontuacao = pontuacao + p;
}

vector<Atleta*> Equipa::getAtletas() const {
	return atletas;
}

Atleta* Equipa::getAtleta(unsigned int id){

	int pos = existeAtletaID(id);

	if(pos<0)
		throw AtletaInexistente(id);
	else return atletas[pos];
}


/*
 *
 * 		MANIPULAR ATLETAS
 *
 */

void Equipa::inserirAtleta(Atleta &a1){
	atletas.push_back(&a1);
}

bool Equipa::eliminarAtleta(unsigned int id){

	int pos = existeAtletaID(id);

	if(pos<0)
		return false;
	else {
		atletas.erase(atletas.begin() + pos);
		return true;
	}

}

int Equipa::existeAtleta(string nome){

	int counter=0;

	vector<Atleta*>::iterator it;

	for(it = atletas.begin(); it != atletas.end(); ++it){
		if((*it)->getNome() == nome){
			counter++;
		}
	}

	return counter;
}

int Equipa::existeAtletaID(unsigned int id){

	for(unsigned int i=0; i<atletas.size(); i++){
		if(atletas[i]->getID()==id)
			return i;
	}

	return -1;
}

void Equipa::showAtletas(){

	for(unsigned int i=0; i<atletas.size(); i++){
		atletas[i]->imprime();
	}
}


/*
 *
 * 		PRINT
 *
 */

void Equipa::imprime() {
	cout << endl;
	cout << "Nome: " << nome << endl;
	cout << "Pais: " << pais << endl;
	cout << "Patrocinador: " << patrocinador << endl;
	cout << "Pontuacao: " << pontuacao << endl;
	cout << endl;
}


/*
 *
 * 		OPERADORES
 *
 */

bool Equipa::operator<(const Equipa &e){ // para insertionSort

	if(this->pontuacao > e.pontuacao)
		return true;
	else if(this->pontuacao == e.pontuacao)
		return (this->nome > e.nome);

	return false;
}

