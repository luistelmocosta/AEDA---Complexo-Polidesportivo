/*
 * main.h
 *
 *  Created on: 5 Nov 2015
 *      Author: luistelmocosta
 */

#ifndef SRC_LOGIC_MAIN_H_
#define SRC_LOGIC_MAIN_H_

#include "Campeonato.h"
#include "Utilities.h"

using namespace std;

bool debug=false;
Equipa e1;
Campeonato* c1 = new Campeonato("Main");

bool isNumber(string str);
int pedirValor();
void menu(Campeonato &c1);
void menuAtletas();
void removerAtleta(Equipa &e1);
void alteraAtleta();
void subMenuEquipas();
bool findNomeEmEquipas();


#endif /* SRC_LOGIC_MAIN_H_ */
