#include <iomanip>
//#include <string>
#include "Calendario.h"


Calendario::Calendario(vector <Prova*> p, vector <string> m, vector <string> a,vector <string> e, string nF):provasBST(Prova()) {



	//provas=p;

	modalidades=m;
	atletas=a;
	equipas=e;
	nomeF = nF;



}


/*
 *
 * 		GETS/SETS
 *
 */

BST<Prova> Calendario::getProvas() const {
	return provasBST;
}

/*void Calendario::setProvas(vector<Prova*> vp) {
	provas=vp;
}*/

vector<string> Calendario::getModalidades() const{
	return modalidades;
}

void Calendario::setModalidades(vector<string> vm) {
	modalidades=vm;
}

vector<string> Calendario::getAtletas() const{
	return atletas;
}

void Calendario::setAtletas(vector<string> va) {
	atletas=va;
}

vector<string> Calendario::getEquipas() const{
	return equipas;
}

void Calendario::setEquipas(vector<string> ve) {
	equipas=ve;
}

string Calendario::getNomeFich() const{
	return nomeF;
}

void Calendario::setNomeFich(string nF) {
	nomeF=nF;
}


/*
 *
 * 		PESQUISAR PROVAS
 *
 */

Prova* Calendario::getProvaID(int id) {
	BSTItrIn<Prova> it = provasBST;

	while (!it.isAtEnd()) {
		if (it.retrieve().getID() == id) {
			return &it.retrieve();
		}

		it.advance();
	}
	Prova NOT_FOUND;
	return &NOT_FOUND;
}

int Calendario::findProva(int id){

	BSTItrIn<Prova> it = provasBST;

	while (!it.isAtEnd()) {
		if (it.retrieve().getID() == id) {
			return id;
		}

		it.advance();
	}
	return -1;

}

vector<Prova*> Calendario::findProva_Data(date d) {

	vector<Prova*> aux;

	BSTItrIn<Prova> it = provasBST;

	while (!it.isAtEnd()) {
		if (it.retrieve().getData().ano == d.ano && it.retrieve().getData().mes == d.mes &&
				it.retrieve().getData().dia == d.dia && it.retrieve().getData().hora == d.hora) {

			aux.push_back(&(it.retrieve()));

		}

		it.advance();
	}




	return aux;
}

vector<Prova*> Calendario::findProva_Local(string loc) {

	vector<Prova*> aux;

	BSTItrIn<Prova> it = provasBST;

	while(!it.isAtEnd()){
		if(it.retrieve().getLocal()==loc)
			aux.push_back(&it.retrieve());
		it.advance();
	}
	return aux;
}

vector<Prova*> Calendario::findProva_Modal(Modalidade* m) {
	Prova* p = new Prova();
	int i;
	p->setModalidade(m);
	vector<Prova*> aux;
	vector<Prova*> copy;


	BSTItrIn<Prova> it = provasBST;

	while(!it.isAtEnd()){
		copy.push_back(&it.retrieve());
		it.advance();
	}


	while(sequentialSearch(copy, p)!=-1){
		i = sequentialSearch(copy, p);
		aux.push_back(copy[i]);
		copy.erase(copy.begin() + i);
	}
	cout << aux[0]->getModalidade()->getNome();
	cout << aux[1]->getModalidade()->getNome();
	return aux;
}

vector<Prova*> Calendario::findProva_Vence(Equipa* e) {
	vector<Prova*> aux;

	BSTItrIn<Prova> it = provasBST;

	while(!it.isAtEnd()){
		if(it.retrieve().getVencedor()->getNome() == e->getNome())
			aux.push_back(&it.retrieve());
		it.advance();
	}

	return aux;
}


/*
 *
 * 		MANIPULAR PROVAS
 *
 */

bool Calendario::checkProva(Prova &p){

	bool isDiff = false; //prova diferente das restantes

	if (provasBST.isEmpty())
		isDiff = true;
	else{

		Prova test = provasBST.find(p);
		if(test.getID() != p.getID())
			isDiff = true;

		else isDiff = false;

	}


	return isDiff;
}

bool Calendario::inserirProva (Prova &p){

	if(checkProva(p)){
		provasBST.insert(p);
		return true;
	}
	else{
		cout << "Impossivel adicionar prova no local " << p.getLocal() << "(sobreposicao de provas)" << endl;
		return false;
	}
}

void Calendario::eliminarProva(int id){

	int pos=findProva(id);

	if(pos<0)
		throw ProvaInexistente(id);
	else {

		BSTItrIn<Prova> it = provasBST;

		while (!it.isAtEnd()) {
			if (it.retrieve().getID() == id) {
				provasBST.remove(it.retrieve());
				break;
			}

			it.advance();
		}

	}

}


/*
 *
 * 		PRINT
 *
 */

void Calendario::showUmaProva(int i) const {

	BSTItrIn<Prova> it = provasBST;

	while (!it.isAtEnd()) {
		if (it.retrieve().getID() == i) {

			cout << it.retrieve();


			break;
		}

		it.advance();
	}

	/*

	//cout << "ID : " << provas[i]->getID() << endl;
	cout << "ID: " << provasBST.find()
					cout << "Data: " << provas[i]->getDataFormatada() << endl;
	cout << "Local: "<< provas[i]->getLocal() << endl;
	//cout << "Modalidade: " << provas[i]->getModalidade()->getNome() << endl;
	cout << "Duracao (min): " << provas[i]->getDuracao() << endl;*/
}

void Calendario::showProvas()const{
	BSTItrIn<Prova> it = provasBST;

	while (!it.isAtEnd()) {


		cout << it.retrieve();
		it.advance();
	}
}

