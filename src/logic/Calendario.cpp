#include "Calendario.h"

using namespace std;

Calendario::Calendario(vector <Prova> p) {

	for(unsigned int i = 0; i<p.size();i++){

		provas.push_back(&p[i]);

	}
}

vector<Prova*> Calendario::getProvas() const {
	return provas;
}


void Calendario::checkProvas(){


	for(unsigned int i = 0; i < provas.size(); i++){

		date x = provas[i]->getData();
		string l = provas[i]->getLocal();
		float dur = provas[i]->getDuracao();
		for(unsigned int j = 0; j < provas.size(); j++){

			if(j == i){
				if(j+1 < provas.size())
					j++;
				else break;
			}

			if(l == provas[j]->getLocal() || (x.ano == provas[j]->getData().ano && x.dia == provas[j]->getData().dia && x.mes == provas[j]->getData().mes && x.hora == provas[j]->getData().hora)){
				Calendario::deleteProva(j);
				break;
			}

			if(provas[j]->getData().hora > x.hora && provas[j]->getData().hora < x.hora + dur){
				Calendario::deleteProva(j);
				break;
			}



		}

	}

}

void Calendario::deleteProva(int i){

	provas.erase(provas.begin()+i);

}
