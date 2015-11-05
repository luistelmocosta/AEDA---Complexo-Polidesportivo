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
	e1.readFile(NOME_FICHEIRO);

	cout << "===============" << endl;

	Campeonato c1;
	cout << endl;
	c1.readFile(NOME_EQUIPAS);

	cout << "=======Teste de sobreposicoes========" << endl;

	Calendario calend1;
	date d1, d2, d3, d4;
	d1.ano = 2015;
	d1.mes = 8;
	d1.dia = 22;
	d1.hora = 5.0;

	d2.ano = 2010;
	d2.mes = 5;
	d2.dia = 22;
	d2.hora = 5.0;

	d3.ano = 2015;
	d3.mes = 8;
	d3.dia = 22;
	d3.hora = 5.0;

	d4.ano = 1900;
	d4.mes = 4;
	d4.dia = 2;
	d4.hora = 17.0;

	vector <Equipa> v;
	Modalidade* desp;

	Prova p1(d1, "feup", 0, v, desp);
	Prova p2(d2, "isep", 0, v, desp);
	Prova p3(d3, "esep", 0, v, desp);
	Prova p4(d4, "feup", 0, v, desp);

	calend1.adicionaProva(&p1);
	calend1.adicionaProva(&p2);
	calend1.adicionaProva(&p3);
	calend1.adicionaProva(&p4);

	cout << "=======Teste de txt output========" << endl;

	calend1.criaFich("Provas.txt");







}




