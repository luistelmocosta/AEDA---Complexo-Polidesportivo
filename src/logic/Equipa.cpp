#include "Equipa.h"
#include <iostream>


using namespace std;


Equipa::Equipa(string n, string p, string pat): nome(n), pais(p), patrocinador(pat) {
	pontuacao=0;
}

Equipa::Equipa() {
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


void Equipa::readFile(const string filename){


	string tmp;

	fstream fich;

	string nome, pais;
	unsigned int idade, peso, altura;

	fich.open(filename.c_str(), ios::in);

	if(fich.is_open()){

		while(!fich.eof()){

			getline(fich, nome);
			//cin.ignore();
			fich >> pais >> idade >> altura >> peso;
			if(fich.eof())
				break;
			Atleta x(nome,pais, idade, peso, altura);

			getline(fich, nome);



			atletas.push_back(x);


		}


	}

	else
		cout << "Unable to open file"; // podia ser uma exception!!

	fich.close();


	for(unsigned int i = 0; i < atletas.size(); i++){
		std::cout << atletas[i].getID() << endl;
		std::cout << atletas[i].getNome() << endl;
		cout << atletas[i].getIdade() << endl;
		cout << atletas[i].getPeso() << endl;
		cout << atletas[i].getPais() << endl;
		cout << atletas[i].getAltura() << endl << endl;
	}

}

