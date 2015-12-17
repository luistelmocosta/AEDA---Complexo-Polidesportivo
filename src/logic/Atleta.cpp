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

Atleta::Atleta(){

}

Atleta::Atleta(string nome) {

	inf.nome = nome;

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

string Atleta::getNEquipa() const {
	return nEquipa;
}

void Atleta::setNEquipa(string nEq) {
	nEquipa=nEq;
}

vector<Modalidade*> Atleta::getModalidades() const{
	return modalidades;
}

void Atleta::inserirModalidade(Modalidade &mod){
	modalidades.push_back(&mod);
}

vector<Prova*> Atleta::getProvas() const {
	return provas;
}

void Atleta::inserirProva(Prova& prov) {
	provas.push_back(&prov);
}


void Atleta::imprime() const{
	cout << endl;
	cout << "ID: " << uid << endl;
	cout << "Nome: " << inf.nome << endl;
	cout << "Pais: " << inf.pais << endl;
	cout << "Idade: " << inf.idade << endl;
	cout << "Altura: " << inf.altura << endl;
	cout << "Peso: " << inf.peso << endl;
	cout << "Pontuacao: "<< pontuacao << endl;
	cout << "Equipa: " << nEquipa << endl;
	cout << endl;
}


//class AtletasGuardados

void AtletasGuardados::inserirAtleta(Atleta &a1){
	Tabela::iterator it = atletas.find(a1);

	if(it == atletas.end())
		atletas.insert(a1);
	else
	{
		atletas.erase(it);
		atletas.insert(a1);
	}
}

void AtletasGuardados::removerAtleta(string nome){
	Tabela::iterator it = atletas.begin();

	Atleta a1;

	while(it!= atletas.end())
	{
		if(it->getNome() == nome)
			atletas.erase(it);
		it++;
	}
}

int AtletasGuardados::removerAtletas(int pontuacao){

	int counter = 0;

	Tabela::iterator it = atletas.begin();

	while(it != atletas.end()){
		if(it->getPontuacao() < pontuacao){
			atletas.erase(it);
			counter++;
		}
		it++;
	}

	return counter;
}

void AtletasGuardados::alterarNacionalidade(string nome, string novaNacionalidade){

	Atleta a1(nome);

	Tabela::iterator it = atletas.find(a1);

	if(it == atletas.end()){
		throw AtletaInexistente(nome);
	}
	else
	{
		a1 = (*it);
		atletas.erase(it);
		a1.setPais(novaNacionalidade);
		atletas.insert(a1);

	}
}

void AtletasGuardados::alterarPontuacao(string nome, int pontuacao){

	Atleta a1(nome);

	Tabela::iterator it = atletas.find(a1);

	if(it == atletas.end())
		throw AtletaInexistente(nome);
	else{
		a1 = (*it);
		atletas.erase(it);
		a1.setPontuacao(pontuacao);
		atletas.insert(a1);
	}

}

bool AtletasGuardados::existeAtleta(string nome) {

	Atleta a1(nome);
	Tabela::iterator it=atletas.find(a1);

	if(it==atletas.end())
		return false;
	else return true;
}

void AtletasGuardados::showAtletas() {

	Tabela::iterator it=atletas.begin();

	while(it!=atletas.end()) {
		cout<<"Empresa: "<<it->getNome()<<", Pais: "<<it->getPais()<<", Idade: "<<it->getIdade()
						<< ", Altura: " << it->getAltura() << ", Peso: "<< it->getPeso() << ", Pontuacao: " << it->getPontuacao() << ", Equipa: " << it->getNEquipa() << endl;
		it++;
	}
}

void AtletasGuardados::readFile(ifstream& filename) {

	if(!filename)
		throw ErroNoFicheiro();
	else {
		string nome, pais, temp1, temp2, temp3, nEquipa;
				int idade, altura, peso;

		while (!filename.eof()) {

			getline(filename, nome);
			getline(filename, pais);
			getline(filename, temp1);
			getline(filename, temp2);
			getline(filename, temp3);
			getline(filename, nEquipa);

			idade = atoi(temp1.c_str());
			altura = atoi(temp2.c_str());
			peso = atoi(temp3.c_str());

			Atleta a1(nome, pais, idade, altura, peso);
			inserirAtleta(a1);
		}
	}
}

void AtletasGuardados::writeFile(ofstream& filename) {

	Tabela::iterator it=atletas.begin();

	while(it!=atletas.end()) {
		filename
		<<it->getNome()<<endl
		<<it->getPais()<<endl
		<<it->getIdade()<< endl
		<< it->getAltura() << endl
		<< it->getPeso() << endl
		<< it->getPontuacao() << endl
		<< it->getNEquipa() << endl;
		it++;
	}
}










