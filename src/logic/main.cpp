#include "Campeonato.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main(){


	/*Atleta* a1 = new Atleta("Luis", "Portugal", 30, 70, 170);
	//Atleta* a2 = new Atleta("Alexandre", "Portugal", 30, 70, 170);
	a1->imprime();
	a2->imprime();*/

	string NOME_FICHEIRO = "Atletas.txt";
	string NOME_EQUIPAS = "Equipas.txt";
	//ifstream filename(NOME_FICHEIRO.c_str());
	//ifstream fileteam(NOME_EQUIPAS.c_str());

	Equipa e1; //= Equipa("Ola", "Pais", "Pat");
	//e1.readFile(filename);
	//e1.showAtletas();
	//e1.eliminaAtleta(1);
	//e1.showAtletas();
	//Atleta *a1 = new Atleta("Luis", "Portugal", 25, 173, 60);
	//e1.inserirAtleta(*a1);


	e1.readFile(NOME_FICHEIRO);
	e1.showAtletas();



	e1.showAtletas();
	//e1.existeAtleta("Alexandre Ribeiro");

	cout << "===============" << endl;

	Campeonato c1;
	cout << endl;


	cout << "===============" << endl;

}




