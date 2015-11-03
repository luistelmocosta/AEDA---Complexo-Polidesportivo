#include "Campeonato.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main(){


	//Atleta a1 = Atleta("Luis", "Portugal", 30, 70, 170);
	//Atleta a2 = Atleta("Alexandre", "Portugal", 30, 70, 170);
	string NOME_FICHEIRO = "Atletas.txt";
	string NOME_EQUIPAS = "Equipas.txt";
	ifstream filename(NOME_FICHEIRO.c_str());

	Equipa e1; //= Equipa("Ola", "Pais", "Pat");
	e1.readFile(NOME_FICHEIRO);

	cout << "===============" << endl;

	Campeonato c1;
	cout << endl;
	c1.readFile(NOME_EQUIPAS);

}




