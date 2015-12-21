#include <iomanip>
//#include <string>
#include "Calendario.h"


Calendario::Calendario(vector <Prova*> p, vector <string> m, vector <string> a,vector <string> e, string nF):provasBST(Prova()) {



	provas=p;

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

vector<Prova*> Calendario::getProvas() const {
	return provas;
}

void Calendario::setProvas(vector<Prova*> vp) {
	provas=vp;
}

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

int Calendario::findProva(int id) {
	for(unsigned int i=0; i<provas.size(); i++){
		if(provas[i]->getID()==id)
			return i;
	}
	return -1;
}

vector<Prova*> Calendario::findProva_Data(date d) {

	vector<Prova*> aux;

	for(unsigned int i=0; i<provas.size(); i++){
		if(provas[i]->getData().ano==d.ano && provas[i]->getData().mes==d.mes &&
				provas[i]->getData().dia==d.dia && provas[i]->getData().hora==d.hora){
			aux.push_back(provas[i]);
		}
	}
	return aux;
}

vector<Prova*> Calendario::findProva_Local(string loc) {

	vector<Prova*> aux;

	for(unsigned int i=0; i<provas.size(); i++){
		if(provas[i]->getLocal()==loc)
			aux.push_back(provas[i]);
	}
	return aux;
}

vector<Prova*> Calendario::findProva_Modal(Modalidade* m) {
	Prova* p = new Prova();
	int i;
	p->setModalidade(m);
	vector<Prova*> aux;
	vector<Prova*> copy = provas;
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

	for(unsigned int i = 0; i < provas.size(); i++){
		if(provas[i]->getVencedor()->getNome()==e->getNome())
			aux.push_back(provas[i]);
	}
	return aux;
}


/*
 *
 * 		MANIPULAR PROVAS
 *
 */

bool Calendario::checkProva(Prova &p){

	bool isDiff = true; //prova diferente das restantes

	if (provas.empty())
		return true;
	else{
		for(unsigned int i = 0; i < provas.size(); i++){
			if(*provas[i]!=p)
				isDiff = true;
			else{
				isDiff = false;
				break;
			}
		}
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
	else provas.erase(provas.begin() + pos);

}


/*
 *
 * 		PRINT
 *
 */

void Calendario::showUmaProva(int i) const {
	cout << "ID : " << provas[i]->getID() << endl;
	cout << "Data: " << provas[i]->getDataFormatada() << endl;
	cout << "Local: "<< provas[i]->getLocal() << endl;
	//cout << "Modalidade: " << provas[i]->getModalidade()->getNome() << endl;
	cout << "Duracao (min): " << provas[i]->getDuracao() << endl;
}

void Calendario::showProvas()const{
	cout << "Numero de provas: " << provas.size() << endl;
	for(unsigned int i = 0; i < provas.size(); i++){
		cout << "ID : " << provas[i]->getID() << endl;
		cout << "Data: " << provas[i]->getDataFormatada() << endl;
		cout << "Local: " << provas[i]->getLocal() << endl;
		//cout <<"Modalidade: " << provas[i]->getModalidade()->getNome()<< endl;
		cout << "Duracao (min): " << provas[i]->getDuracao() << endl;
		//cout << provas[i]->getModalidade()->getNomeDesporto() << endl;
		//cout << provas[i]->getAdversarios()[0]->getNome() << " vs " << provas[i]->getAdversarios()[1]->getNome()<<endl;
		//cout << provas[i]->getParticipante(0)->getNome() << "    " << provas[i]->getParticipante(1)->getNome()<<endl;
		cout << endl;
	}
	cout << endl;
}

