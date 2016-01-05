#include <iostream>
#include <iterator>
#include "Equipa.h"


Equipa::Equipa(string n, string p, string pat): nome(n), pais(p), patrocinador(pat) {
	pontuacao=0;
	medalhas.ouro=0;
	medalhas.prata=0;
	medalhas.bronze=0;
	doping=false;
}

Equipa::Equipa() {
	pontuacao=0;
	medalhas.ouro=0;
	medalhas.prata=0;
	medalhas.bronze=0;
	doping=false;
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

Medalhas Equipa::getMedalhas() const{
	return medalhas;
}

void Equipa::setMedalhasOuro(unsigned o){
	medalhas.ouro=o;
}

void Equipa::setMedalhasPrata(unsigned p){
	medalhas.prata=p;
}

void Equipa::setMedalhasBronze(unsigned b){
	medalhas.bronze=b;
}

void Equipa::setMedalhasPorPontuacao(){
	unsigned p = pontuacao;

	// 10 pontos: ouro // 5 pontos: prata // 3 pontos: bronze

	while(p > 0){

		while(p >= 10){
			p -= 10;
			medalhas.ouro++;
		}

		while(p >= 5){
			p -= 5;
			medalhas.prata++;
		}

		while(p >= 3){
			p -= 3;
			medalhas.bronze++;
		}
	}
}

bool Equipa::getDoping() const{
	return doping;
}
void Equipa::setDoping(bool b){
	doping=b;
}

bool Equipa::temMedalhas(){
	return (medalhas.ouro>0 || medalhas.prata>0 || medalhas.bronze>0);
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

bool Equipa::operator<(const Equipa &e) const{ // para insertion sort


}

bool Equipa::operator==(const Equipa &e) const{
	return (medalhas.ouro == e.getMedalhas().ouro && medalhas.prata == e.getMedalhas().prata && medalhas.bronze == e.getMedalhas().bronze);
}
