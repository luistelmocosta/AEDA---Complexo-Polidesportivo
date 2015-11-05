/*
 * main.h
 *
 *  Created on: 5 Nov 2015
 *      Author: luistelmocosta
 */

#ifndef SRC_LOGIC_MAIN_H_
#define SRC_LOGIC_MAIN_H_

#include "Campeonato.h"

using namespace std;

bool debug=false;
Equipa e1;
Campeonato c1;

class ValorInvalido {
public:
	int valor;
	ValorInvalido(int valor): valor(valor) {}
};


bool isNumber(string str);
int pedirValor();
void menu(Campeonato &c1);
void menuAtletas();



#endif /* SRC_LOGIC_MAIN_H_ */
