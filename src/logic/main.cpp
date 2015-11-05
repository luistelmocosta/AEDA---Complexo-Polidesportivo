#include "Campeonato.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main(){


	Atleta* a1 = new Atleta("Luis", "Portugal", 30, 70, 170);
	Atleta* a2 = new Atleta("Alexandre", "Portugal", 30, 70, 170);
	a1->imprime();
	a2->imprime();

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

	vector <Equipa*> v;

	string despStr = "natacao";
	bool singular = true;
	Modalidade despp(despStr, 1);

	Prova p1(d1, "feup", 0, v, &despp);
	Prova p2(d2, "isep", 0, v, &despp);
	Prova p3(d3, "esep", 0, v, &despp);
	Prova p4(d4, "feup", 0, v, &despp);

	calend1.adicionaProva(&p1);
	calend1.adicionaProva(&p2);
	calend1.adicionaProva(&p3);
	calend1.adicionaProva(&p4);

	cout << "=======Teste de txt output========" << endl;

	//calend1.criaFich("Provas.txt");



	cout << "=======Teste de sequential search modalidades========" << endl;

	Atleta* a3 = new Atleta("Ze", "Portugal", 30, 70, 170);

	string moda1 = "futebol";
	string moda2 = "xadrez";
	string moda3 = "bilhar";
	string moda4 = "arraial";
	vector <Equipa*> vs;

	Modalidade *mod1 = new Modalidade(moda1,singular);
	Modalidade *mod2 = new Modalidade(moda2, singular);
	Modalidade *mod3 = new Modalidade(moda3, singular);
	Modalidade *mod4 = new Modalidade(moda4, singular);


	a3->inserirModalidade(*mod1);
	a3->inserirModalidade(*mod2);
	a3->inserirModalidade(*mod3);
	a3->inserirModalidade(*mod4);
	cout << a3->getModalidades().size() << endl;

	for (unsigned int i = 0; i< a3->getModalidades().size(); i++){
		cout << endl << a3->getModalidades()[i]->getNome() << endl;
	}

	Equipa equi1("feup","sads","fdsv");
	equi1.inserirAtleta(*a3);
	vs.push_back(&equi1);


	Prova p5(d1, "feup", 0, vs,mod1);

	cout << p5.getParticipante(0)->getNome();







}




