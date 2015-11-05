#include <iostream>
#include "Atleta.h"

using namespace std;

int Atleta::newID = 0;

//unsigned int Atleta::ultimoID = 0;

Atleta::Atleta(string n, string pais, unsigned int i, unsigned int p, unsigned int a) : uid(newID++){
	inf.nome=n;
	inf.pais=pais;
	inf.idade=i;
	inf.peso=p;
	inf.altura=a;
}

Atleta::~Atleta() {

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

string Atleta::getPais() const{
	return inf.pais;
}

vector<Modalidade*> Atleta::getModalidades() const{
	return modalidades;
}

unsigned int Atleta::getIdade() const{
	return inf.idade;
}

unsigned int Atleta::getPeso() const{
	return inf.peso;
}

unsigned int Atleta::getAltura() const{
	return inf.altura;
}

float Atleta::getPontuacao() const{
	return pontuacao;
}

void Atleta::setPontuacao(float p){

	if(p < 0)
		throw ValorIncorrecto(p);

	pontuacao = p;

}


void Atleta::imprime() const{

	cout << "Nome: " << inf.nome << endl;
	cout << "Pais: " << inf.pais << endl;
	cout << "Idade: " << inf.idade << endl;
	cout << "Peso: " << inf.peso << endl;
	cout << "Altura: " << inf.altura << endl;
	cout << "Pontuacao: "<< pontuacao << endl;

}

void Atleta::inserirModalidade(Modalidade &mod){

	modalidades.push_back(&mod);

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
