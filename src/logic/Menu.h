#ifndef SRC_LOGIC_MENU_H_
#define SRC_LOGIC_MENU_H_

#include "Campeonato.h"

using namespace std;

class Menu{

	Campeonato* campeonato;

public:

	Menu(){
		campeonato = new Campeonato();
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

	// #ADEPTO
	void espacoAdeptoMenu();

	// #
	void clearScreen();

};

#endif /* SRC_LOGIC_MENU_H_ */
