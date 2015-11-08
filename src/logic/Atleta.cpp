#include <iostream>
#include "Atleta.h"

using namespace std;

int Atleta::newID = 0;

Atleta::Atleta(string n, string pais, unsigned int i, unsigned int a, unsigned int p): uid(newID++){
	inf.nome=n;
	inf.pais=pais;
	inf.idade=i;
	inf.altura=a;
	inf.peso=p;
	pontuacao=0;
}

Atleta::~Atleta(){

}

unsigned int Atleta::getID() const{
	return uid;
}

info Atleta::getInfo() const {
	return inf;
}

void Atleta::setInfo(info i) {
	inf=i;
}

string Atleta::getNome() const{
	return inf.nome;
}

void Atleta::setNome(string n) {
	inf.nome=n;
}

string Atleta::getPais() const{
	return inf.pais;
}
void Atleta::setPais(string p) {
	inf.pais=p;
}

unsigned int Atleta::getIdade() const{
	return inf.idade;
}

void Atleta::setIdade(int i) {
	inf.idade=i;
}

unsigned int Atleta::getPeso() const{
	return inf.peso;
}

void Atleta::setPeso(int p) {
	inf.peso=p;
}

unsigned int Atleta::getAltura() const{
	return inf.altura;
}

void Atleta::setAltura(int a) {
	inf.altura=a;
}

float Atleta::getPontuacao() const{
	return pontuacao;
}

void Atleta::setPontuacao(float p){

	if(p < 0)
		throw ValorInvalido(p);

	pontuacao = p;

}

string Atleta::getEquipa() const {
	return nEquipa;
}

void Atleta::setEquipa(string nE) {
	nEquipa=nE;
}

vector<Modalidade*> Atleta::getModalidades() const{
	return modalidades;
}

void Atleta::inserirModalidade(Modalidade &mod){
	modalidades.push_back(&mod);
}


void Atleta::imprime() const{

	cout << "Nome: " << inf.nome << endl;
	cout << "Pais: " << inf.pais << endl;
	cout << "Idade: " << inf.idade << endl;
	cout << "Altura: " << inf.altura << endl;
	cout << "Peso: " << inf.peso << endl;
	cout << "Pontuacao: "<< pontuacao << endl;
	cout << "Equipa: " << nEquipa << endl;

}

/*vector<Prova*> Atleta::getProvas() const{
	return provas;
}


bool Atleta::eliminaProva(string prova){
	for (unsigned int i = 0; i < provas.size(); i++){
		if(provas[i] == prova){
			provas.erase(provas.begin() + i);
			return true;
		}
	}
	return false;
}*/
