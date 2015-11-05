#include "Calendario.h"

using namespace std;


Calendario::Calendario(vector <Prova*> p) {

	for(unsigned int i = 0; i<p.size();i++){
		provas.push_back(p[i]);
	}
}

vector<Prova*> Calendario::getProvas() const {
	return provas;
}


bool Calendario::checkProva(Prova* p){

	bool isDiff = true; //prova diferente das restantes

	for(unsigned int i = 0; i < provas.size(); i++){

		if(*provas[i]!=*p){
			isDiff = true;
		}
		else{
			isDiff = false;
			break;
		}




	}


	return isDiff;

}

void Calendario::deleteProva(int i){
	provas.erase(provas.begin()+i);
}

void Calendario::adicionaProva (Prova* p){
	if(checkProva(p))
		provas.push_back(p);

	else
		cout << "impossivel adicionar prova " << p->getLocal() << "(sobreposicao de provas)" << endl;

}

void Calendario::criaFich(string nome){

	ofstream provasFich(nome.c_str());

	vector<Prova*>::iterator it;

	for(it=provas.begin(); it!= provas.end(); it++) {

		provasFich << (*it)->getModalidade()->getNome() << endl << (*it)->getAdversarios()[0]->getNome() << " vs " << (*it)->getAdversarios()[1]->getNome()<< endl;
		provasFich << "Local: " << (*it)->getLocal() <<endl;
		provasFich << "Duracao: " << (*it)->getDuracao() << endl;
		provasFich << "Vencedor: " << (*it)->getVencedor()->getNome() << "!!" << endl << endl;

	}


}




