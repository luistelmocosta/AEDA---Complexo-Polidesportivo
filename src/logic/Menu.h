#ifndef SRC_LOGIC_MENU_H_
#define SRC_LOGIC_MENU_H_

#include "Campeonato.h"

using namespace std;

bool debug=false;

Campeonato* campeonato = new Campeonato();

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

// #
void clearScreen();

int main();

#endif /* SRC_LOGIC_MENU_H_ */
