#include <iostream>
#include "Atleta.h"

using namespace std;

//unsigned int Atleta::ultimoID = 0;

Atleta::Atleta(string n, string pais, unsigned int i, unsigned int p, unsigned int a){
	inf.nome=n;
	inf.pais=pais;
	inf.idade=i;
	inf.peso=p;
	inf.altura=a;
	pontuacao=0;
}

void Atleta::imprime() const{

	//int n = 5;

	cout << "Nome: " << inf.nome << endl;
	cout << "Pais: " << inf.pais << endl;
	cout << "Idade: " << inf.idade << endl;
	cout << "Peso: " << inf.peso << endl;
	cout << "Altura: " << inf.altura << endl;
	cout << "Pontuacao: "<< pontuacao << endl;

	//return n;
}

unsigned int Atleta::getID() const{
	return id;
}

info Atleta::getInfo() const{
	return inf;
}

void Atleta::setInfo(info i){
	inf=i;
}

void Atleta::setPontuacao(float p){

	if(p < 0)
		throw ValorIncorrecto(p);

	pontuacao = p;

}

float Atleta::getPontuacao() const{
	return pontuacao;
}

Equipa Atleta::getEquipa() const{
	return *equipa;
}

void Atleta::setEquipa(const Equipa & eq){
	*equipa=eq;
}

/*vector<Prova*> Atleta::getProvas() const{
	return provas;
}

vector<Modalidade*>Atleta::getModalidades() const{
	return modalidades;
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

/*
void Atleta::readFile(ifstream& ficheiro_leitura){
	if(!ficheiro_leitura)
		throw ErroNoFicheiro();
	else{
		string nome, pais, temp1, temp2;
		string pais;
		Info i;

		getline(ficheiro_leitura, nome);
		getline(ficheiro_leitura, pais);
		getline(ficheiro_leitura, temp1);
		getline(ficheiro_leitura, temp2);

		i.peso = atoi(temp1.c_str());
		i.altura = atoi(temp2.c_str());

		Atleta a1(nome, pais, i.peso, i.altura);



	}

}*/

