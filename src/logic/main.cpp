#include "Menu.h"


int main(){

	Menu menu;
	menu.initMenu();

	return 0;
}


/*
 *
 * 	NAO APAGAR
 *

int main(){
	Campeonato c;

	vector<unsigned> eq1, eq2, eq3;
	eq1.push_back(10);
	eq2.push_back(100);
	eq3.push_back(50);

	Equipa e1, e2, e3;
	e1.setMedalhas(eq1);
	e2.setMedalhas(eq2);
	e3.setMedalhas(eq3);

	c.inserirEquipa(e1);
	c.inserirEquipa(e2);
	c.inserirEquipa(e3);

	c.getClassificacao().push(c.getEquipas()[0]);
	c.getClassificacao().push(c.getEquipas()[1]);
	c.getClassificacao().push(c.getEquipas()[2]);

	while(!c.getClassificacao().empty()){

		cout << c.getClassificacao().top()->getMedalhas()[0] << endl;
		c.getClassificacao().pop();
	}

	//cout << c.getEquipas()[0]->getMedalhas()[0] << c.getEquipas()[1]->getMedalhas()[0] << c.getEquipas()[2]->getMedalhas()[0];

}*/

