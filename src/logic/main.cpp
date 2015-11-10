#include "Campeonato.h"
#include "main.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main(){


	vector <string> moda;
	string moda1 ="Futebol";
	string moda2 = "Natacao";
	string moda3 = "Corrida";
	moda.push_back(moda1);
	moda.push_back(moda2);
	moda.push_back(moda3);

	vector <string> equi;
	string equi1 = "Benfica";
	string equi2 = "Porto";
	string equi3 = "Sporting";
	equi.push_back(equi1);
	equi.push_back(equi2);
	equi.push_back(equi3);

	vector <string> atl;
	vector <Prova*> p;

	string FICHEIRO_ATLETAS = "txt_data/Atletas.txt";
	string FICHEIRO_EQUIPAS = "txt_data/Equipas.txt";
	string FICHEIRO_PROVAS = "txt_data/Provas.txt";
	string nCampeonato, nEquipa, pais, patrocinio;

	try{
		c1->readFileAtletas(FICHEIRO_ATLETAS);
	}
	catch (ErroNoFicheiro &e){

		cout << "Tentativa de abrir o ficheiro falhou.\n";
		cout << "Insira o nome para a Equipa a ser criada: " << endl;
		cin >> nEquipa;
		cout << "Insira o pais da equipa a criar: " << endl;
		cin >> pais;
		cout << "Insira o patrocinio da equipa a criar: " << endl;
		cin >> patrocinio;
		Equipa* e_aux = new Equipa(nEquipa, pais, patrocinio);
		c1->inserirEquipa(*e_aux);
		cout << endl;
	}

	try{
		c1->readFileEquipas(FICHEIRO_EQUIPAS);
	}
	catch (ErroNoFicheiro &e){

		cout << "Tentativa de abrir o ficheiro falhou.\n";
		cout << "Insira o nome para o campeonato a ser criado: " << endl;
		cin >> nCampeonato;
		c1->setNome(nCampeonato);
		cout << endl;
	}

	try{
		c1->readFileProvas(FICHEIRO_PROVAS);
	}
	catch (ErroNoFicheiro &e){

	}

	cout << c1->getNome() << endl << endl;
	menu(*c1);

	return 0;
}

bool isNumber(string str)
{
	bool ret = false;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
			ret = true;
		else
			return false;
	}
	return ret;
}

int pedirValor()
{

	stringstream ss;
	string str;
	int res;

	try
	{
		do
		{
			cout << "Insira um limite: ";
			cin >> str;
		} while (!isNumber(str));

		res = atoi(str.c_str());

		if (res < 0)
			throw ValorInvalido(res);
	} catch (ValorInvalido &v)
	{
		cout << "Valor invalido" << endl << endl;
		res = pedirValor();
	}
	return res;
}

void removerAtleta(Equipa &e1){
	string str;
	int nr;
	bool valid = true;
	do
	{
		cout << "Insira o numero do atleta que pretende eliminar: " << endl;
		cin >> str;
	} while (!isNumber(str));

	nr = atoi(str.c_str());

	Atleta *a1;

	try{
		a1 = e1.getAtleta(nr);
	} catch (AtletaInexistente &e){
		valid = false;
		cout << "Nao existe nenhum atleta com o numero:  " << e.id << endl;
		return;
	}

	e1.eliminaAtleta(nr);
}

/*void alteraAtleta(Campeonato* c1){
	int id;
	int pos;
	string input;
	int input_aux;
	float pont;

	cout << "Insira o ID do atleta a alterar: " << endl;
	cin >> id;

	pos=c1->findAtleta(id);

	if(pos==-1)
		throw AtletaInexistente(id);
	else{
		c1->getAtletas()[pos]->imprime();
		cout << endl;
		cout << "Insira o campo que pretende alterar: " << endl;
		cin >> input;

		if(input=="Nome"){
			cout << "Insira o nome que pretende atribuir: " << endl;
			cin >> input;
			c1->getAtletas()[pos]->setNome(input);
		}
		else if(input=="Pais"){
			cout << "Insira o país que pretende atribuir: " << endl;
			cin >> input;
			c1->getAtletas()[pos]->setPais(input);
		}
		else if(input=="Idade"){
			cout << "Insira a idade que pretende atribuir: " << endl;
			cin >> input_aux;
			c1->getAtletas()[pos]->setIdade(input_aux);
		}
		else if(input=="Peso"){
			cout << "Insira o peso que pretende atribuir: " << endl;
			cin >> input_aux;
			c1->getAtletas()[pos]->setPeso(input_aux);
		}
		else if(input=="Altura"){
			cout << "Insira a altura que pretende atribuir: " << endl;
			cin >> input_aux;
			c1->getAtletas()[pos]->setAltura(input_aux);
		}
		else if(input=="Pontuacao"){
			cout << "Insira a pontuacao que pretende atribuir: " << endl;
			cin >> pont;
			c1->getAtletas()[pos]->setPontuacao(pont);
		}
		else if(input=="Equipa"){
			cout << "Insira o nome da equipa que pretende atribuir: " << endl;
			cin >> input;
			c1->getAtletas()[pos]->setEquipa(input);
		}

		c1->getAtletas()[pos]->imprime();
	}
}*/

void menuAtletas(){
	bool menub = true;
	stringstream ss;
	int option;
	string str;
	do
	{
		cout << endl;
		cout << "1. Listagem de Atletas" << endl;
		cout << "2. Adicionar Atleta" << endl;
		cout << "3. Remover Atleta" << endl;
		cout << "4. Alterar Atleta" << endl;
		cout << "5. Menu Anterior" << endl;
		cout << "6. Sair" << endl;

		cout << "\nEscolha uma opcao: ";
		cin >> str;
		ss << str;
		ss >> option;
		cout << endl;

		switch (option)
		{
		case 1:
			c1->imprimeAtletas();
			//cout << endl;
			break;
		case 2:
			c1->adicionaAtleta();
			cout << endl;
			break;
		case 3:
			//unsigned int id;
			c1->removerAtleta();
			cout << endl;
			break;
		case 4:
			c1->imprimeAtletas();
			cout << endl;

			findNomeEmAtletas();
			break;

		case 5:
			menu(*c1);
			break;
		case 6:
			menub = false;
			cout << endl;
			return;
			break;
		default:
			cout << "Opcao invalida. Tente outra vez.\n" << endl;
			ss.clear();
			str.clear();
			break;
		}
		ss.clear();
	} while (menu);
}


bool findNomeEmAtletas(){

	unsigned int id;

	cout << "Insira o ID do atleta que pretende alterar: ";
	cin.ignore();
	cin >> id;
	unsigned int i =c1->findAtleta(id);

	cout << i << endl;

	if(i!=-1){
		subMenuAtletas(*c1->getAtletas()[i]);
		return true;
	}
	else return false;


}

bool findNomeEmEquipas(){

	string inputE;

	cout << "Insira o nome da equipa que pretende alterar: ";
	cin.ignore();
	getline(cin, inputE);
	int i =c1->findEquipa(inputE);

	if(c1->findEquipa(inputE)!=-1){
		subMenuEquipas(*c1->getEquipas()[i]);
		return true;
	}
	else return false;
}

void subMenuAtletas(Atleta &a1){

	bool menub = true;

	do{
		stringstream ss;
		int option;
		string str;
		string change;
		int changeINT;

		cout << "O que deseja alterar na Atleta? " << endl;
		cout << "1. Nome" << endl;
		cout << "2. Pais" << endl;
		cout << "3. Idade" << endl;
		cout << "4. Altura" << endl;
		cout << "5. Peso" << endl;
		cout << "6. Pontuacao" << endl;
		cout << "7. Equipa" << endl;
		cout << "8. Menu Anterior" << endl;
		cout << "9. Menu Principal" << endl;

		cout << endl;

		cout << "\nEscolha uma opcao: ";
		cin >> str;
		ss << str;
		ss >> option;
		cout << "\n";

		switch (option){
		case 1:
			cout << endl;
			cout << "Insira o novo nome do Atleta: ";
			cin.ignore();
			getline(cin, change);
			a1.setNome(change);
			break;
		case 2:
			cout << endl;
			cout << "Insira o novo pais do Atleta: ";
			cin.ignore();
			getline(cin, change);
			a1.setPais(change);
			break;
		case 3:
			cout << endl;
			do
			{
				cout << "Insira a nova idade do Atleta: ";
				cin >> change;
			} while (!isNumber(change));

			changeINT = atoi(change.c_str());

			a1.setIdade(changeINT);
			break;
		case 4:
			cout << endl;

			do
			{
				cout << "Insira a nova altura do Atleta: ";
				cin >> change;
			} while (!isNumber(change));

			changeINT = atoi(change.c_str());
			a1.setAltura(changeINT);
			break;
		case 5:
			cout << endl;
			do
			{
				cout << "Insira o novo peso do Atleta: ";
				cin >> change;
			} while (!isNumber(change));

			changeINT = atoi(change.c_str());
			a1.setPeso(changeINT);
			break;
		case 6:
			cout << endl;
			do
			{
				cout << "Insira a nova pontuacao do Atleta: ";
				cin >> change;
			} while (!isNumber(change));

			changeINT = atoi(change.c_str());
			a1.setPontuacao(changeINT);
			break;
		case 7:
			cout << endl;
			cout << "Insira a nova equipa do Atleta: ";
			cin.ignore();
			getline(cin, change);
			a1.setEquipa(change);
			break;
		case 8:
			menuAtletas();
			break;
		case 9:
			menu(*c1);
			break;
		default:
			cout << "Opcao invalida. Tente outra vez.\n" << endl;
			ss.clear();
			str.clear();
			break;
		}
		ss.clear();
	} while(menub);
}




void subMenuEquipas(Equipa &e1){

	bool menub = true;

	do{
		stringstream ss;
		int option;
		string str;
		string change;

		cout << "O que deseja alterar na equipa? " << endl;
		cout << "1. Nome" << endl;
		cout << "2. Pais" << endl;
		cout << "3. Patrocinador" << endl;
		cout << "4. Menu Principal" << endl;

		cout << "\nEscolha uma opcao: ";
		cin >> str;
		ss << str;
		ss >> option;
		cout << "\n";

		switch (option){
		case 1:
			cout << "Insira o novo nome da Equipa: ";
			cin.ignore();
			getline(cin, change);
			e1.setNome(change);
			break;
		case 2:
			cout << "Insira o novo pais da Equipa: ";
			cin.ignore();
			getline(cin, change);
			e1.setPais(change);
			break;
		case 3:
			cout << "Insira o novo patrocinio da Equipa: ";
			cin.ignore();
			getline(cin, change);
			e1.setPatrocinador(change);
			break;
		case 4:
			menu(*c1);
			break;
		default:
			cout << "Opcao invalida. Tente outra vez.\n" << endl;
			ss.clear();
			str.clear();
			break;
		}
		ss.clear();
	} while(menub);
}

void subMenuCalendario(Campeonato &c1){

	bool subMC = true;


	while (subMC){
		int id = -1, option;

		bool idInvalido = true;
		while(idInvalido){
			cout << "ID da prova a realizar ou alterar: ";
			cin >> id;
			id--;
			if(id < 0 || id > c1.getCalendario()->getProvas().size())
				cout << "ID invalido!" << endl;
			else
				idInvalido = false;

		}

		c1.getCalendario()->showUmaProva(id);

		string str;
		stringstream ss;
		cout << endl;
		cout << "1. Realizar prova" << endl;
		cout << "2. Alterar local" << endl;
		cout << "3. Alterar data" << endl;
		cout << "4. Alterar duracao" << endl;;
		cout << "5. Menu anterior" << endl;

		cout << "\nEscolha uma opcao: ";
		cin >> str;
		ss << str;
		ss >> option;
		cout << "\n";
		int i;

		switch(option){
		case 1:
			c1.getCalendario()->getProvas()[id]->realizarProva();
			break;
		case 2:
			c1.getCalendario()->getProvas()[id]->alterarLocal();
			c1.getCalendario()->criaFich(1,0);
			break;
		case 3:
			c1.getCalendario()->getProvas()[id]->alterarData();
			c1.getCalendario()->criaFich(1,0);
			break;
		case 4:
			c1.getCalendario()->getProvas()[id]->alterarDuracao();
			c1.getCalendario()->criaFich(1,0);
			break;
		case 5:
			subMC = false;
			break;
		default:
			cout << "Opcao invalida. Tente outra vez.\n" << endl;
			ss.clear();
			str.clear();
			break;
		}
		ss.clear();
	}

	menu(c1);
}

void menuCalendario(Campeonato &c1){


	bool menuC = true;
	while (menuC){
		string str;
		stringstream ss;
		int option;
		cout << endl;
		cout << "1. Listagem das provas" << endl;
		cout << "2. Adicionar Prova" << endl;
		cout << "3. Alterar Prova" << endl;
		cout << "4. Remover uma Prova" << endl;
		cout << "5. Menu Anterior" << endl;

		cout << "\nEscolha uma opcao: ";
		cin >> str;
		ss << str;
		ss >> option;
		cout << "\n";

		switch(option){
		case 1:
			c1.getCalendario()->showProvas();
			break;
		case 2:
			c1.getCalendario()->criaProvas(c1); //falta o append
			break;
		case 3:
			c1.getCalendario()->showProvas();
			subMenuCalendario(c1);
			break;
		case 4:
			c1.getCalendario()->showProvas();
			c1.getCalendario()->removeProva(); //atualizar ficheiro
			break;
		case 5:
			menuC = false;
			break;
		default:
			cout << "Opcao invalida. Tente outra vez.\n" << endl;
			ss.clear();
			str.clear();
			break;
		}
		ss.clear();
	}


	menu(c1);

}

void menu(Campeonato &c1){

	bool menu = true;

	do{
		stringstream ss;
		int option;
		string str;

		cout << "1. Listagem das equipas" << endl;
		cout << "2. Adicionar Equipa" << endl;
		cout << "3. Alterar Equipa" << endl;
		cout << "4. Consultar uma Equipa" << endl;
		cout << "5. Remover uma Equipa" << endl;
		cout << "6. Atletas" << endl;
		cout << "7. Calendario" << endl;
		cout << "8. Sair" << endl;

		cout << "\nEscolha uma opcao: ";
		cin >> str;
		ss << str;
		ss >> option;
		cout << endl;


		switch (option)
		{
		case 1:
			c1.imprimeEquipas();
			break;
		case 2:
			c1.adicionaEquipa();
			break;
		case 3:
			//c1.alteraEquipa();
			findNomeEmEquipas();
			break;
		case 4:
			c1.imprimeUmaEquipa();
			break;
		case 5:
			c1.eliminaEquipa();
			break;
		case 6:
			menuAtletas();
			break;
		case 7:
			//c1.getCalendario()->showProvas();
			//c1.getCalendario()->criaProvas();
			menuCalendario(c1);
			break;
		case 8:
			menu = false;
			cout << endl;
			return;
			break;
		default:
			cout << "Opcao invalida. Tente outra vez.\n" << endl;
			ss.clear();
			str.clear();
			break;
		}
		ss.clear();
	} while(menu);

}






/*Atleta* a1 = new Atleta("Luis", "Portugal", 30, 70, 170);
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
	Equipa equipaParaFicheiro1("FEUP","putas e vinho verde","bolicao");
	Equipa equipaParaFicheiro2("ISEP","20 a aeda","chipicao");
	v.push_back(&equipaParaFicheiro1);
	v.push_back(&equipaParaFicheiro2);

	string despStr = "natacao";
	bool singular = true;
	Modalidade despp(despStr, 1);

	Prova p1(d1, "feup", 0, v, &despp);
	Prova p2(d2, "isep", 0, v, &despp);
	Prova p3(d3, "esep", 0, v, &despp);
	Prova p4(d4, "feup", 0, v, &despp);

	p1.setVencedor(&equipaParaFicheiro1);
	p2.setVencedor(&equipaParaFicheiro1);
	p3.setVencedor(&equipaParaFicheiro1);
	p4.setVencedor(&equipaParaFicheiro1);

	calend1.adicionaProva(&p1);
	calend1.adicionaProva(&p2);
	calend1.adicionaProva(&p3);
	calend1.adicionaProva(&p4);


	cout << "=======Teste de txt output========" << endl;



	calend1.criaFich("Provas.txt");



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

	cout << p5.getParticipante(0)->getNome();*/









