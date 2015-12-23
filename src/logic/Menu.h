#ifndef SRC_LOGIC_MENU_H_
#define SRC_LOGIC_MENU_H_

#include "Campeonato.h"

using namespace std;

class Menu{

	Campeonato* campeonato;
	bool nomeFichDB;
	string FICHEIRO_ATLETAS;
	string FICHEIRO_EQUIPAS;
	string FICHEIRO_PROVAS;
	string FICHEIRO_ADEPTOS;
	string FICHEIRO_BILHETES;

public:

	Menu(){
		campeonato = new Campeonato();
		nomeFichDB = false;
	}
	virtual ~Menu(){}

	// #INIT
	void initMenu();
	void collectCampInfo();

	// #DATABASE
	void dataBaseMenu();
	int readDB();
	void criaDBMenu();

	// #MAINMENU
	void mainMenu();

	// #EQUIPAS
	void criaEquipaMenu();

	void gerirEquipaMenu();
	void verEquipas();
	void modificaEquipaMenu();
	void apagaEquipaMenu();

	// #ATLETAS
	void criaAtletaMenu();

	void gerirAtletaMenu();
	void verAtletas();			//em bruto
	void modificaAtletaMenu();
	void apagaAtletaMenu();

	// #PROVAS
	void criaProvaMenu();

	void gerirProvaMenu();
	void verProvas();
	void modificaProvaMenu();
	void apagaProvaMenu();

	void verClassificacoes();

	// #ADEPTO
	void espacoAdeptoMenu();
	void vendaBilhete();
	void compraBilhete();
	void criaAdeptoMenu();
	void registarAdepto();

	// #
	void clearScreen();

};

#endif /* SRC_LOGIC_MENU_H_ */
