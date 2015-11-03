#include <iostream>
#include "Atleta.h"

using namespace std;

int Atleta::newID = 0;

//unsigned int Atleta::ultimoID = 0;

Atleta::Atleta(string n, string pais, unsigned int i, unsigned int p, unsigned int a) :
	nome(n), pais(pais), idade(i), peso(p), altura(a), uid(newID++){

}

/*void Atleta::imprime() const{

	//int n = 5;

	cout << "Nome: " << inf.nome << endl;
	cout << "Pais: " << inf.pais << endl;
	cout << "Idade: " << inf.idade << endl;
	cout << "Peso: " << inf.peso << endl;
	cout << "Altura: " << inf.altura << endl;
	cout << "Pontuacao: "<< pontuacao << endl;

	//return n;
}*/

unsigned int Atleta::getID() const{
	return uid;
}

string Atleta::getPais() const{
	return pais;
}

unsigned int Atleta::getPeso() const{
	return peso;
}

unsigned int Atleta::getAltura() const{
	return altura;
}

unsigned int Atleta::getIdade() const{
	return idade;
}


string Atleta::getNome() const{
	return nome;
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







/*void Construtora::lerFicheiro(ifstream& filename) {

	if (!filename)
		throw ErroFicheiro();
	else {

		string tmp;
		stringstream ss;

		getline(filename, tmp);
		this->nome = tmp;

		getline(filename, tmp);
		getline(filename, tmp);

		while (!filename.eof()) {
			Obra o1;
			lerFicheiroTrabalho(o1, filename);

			adicionaObra(o1);
		}
	}

}*/
