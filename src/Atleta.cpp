#include "Atleta.h"

using namespace std;

unsigned int Atleta::ultimoID = 0;

Atleta::Atleta(string Nome, string Pais, info Peso, info Altura, int Pontuacao) :
		nome(Nome), pais(Pais), peso(Peso), altura(Altura), pontuacao(Pontuacao), id(++ultimoID) {}

int Atleta::imprime() const{

	int n = 5;

	cout << "Nome: " << nome << endl;
	cout << "Pais: " << pais << endl;
	cout << "Peso: " << peso << endl;
	cout << "Altura: " << altura << endl;
	cout << "Pontuacao: "<< pontuacao << endl;

	return n;
}

unsigned int Atleta::getID() const{
	return id;
}

string Atleta::getNome() const{
	return nome;
}

string Atleta::setNome(string nnome)const{
	nome = nnome;
}

void Atleta::setPontuacao(int ptc){
	pontuacao = ptc;

	if(ptc < 0)
		throw ValorIncorrecto(ptc);
}

float getPontuacao() const{
	return pontuacao;
}

vector<Prova*> Atleta::getProvas() const{
	return provas;
}

vector<Modalidade*>Atleta::getModalidades()const{
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
}

void Atleta::readFile(ifstream& ficheiro_leitura){
	if(!ficheiro_leitura)
		throw ErroNoFicheiro();
	else{
		string nome, pais, temp1, temp2;
		string pais;
		info peso;
		info altura;

		getline(ficheiro_leitura, nome);
		getline(ficheiro_leitura, pais);
		getline(ficheiro_leitura, temp1);
		getline(ficheiro_leitura, temp2);

		peso = atoi(temp1.c_str());
		altura = atoi(temp2.c_str());

		Atleta a1(nome, pais, peso, altura);



	}
}
