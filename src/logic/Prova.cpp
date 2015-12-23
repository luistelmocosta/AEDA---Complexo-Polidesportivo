#include "Prova.h"

int Prova::newID = 0;

Prova::Prova(date dat, string loc, unsigned int dur, vector <Equipa*> vsE, Modalidade* mod):id(newID++){
	data = dat;
	local = loc;
	duracao = dur;
	this->mod = mod;
	this->vs=vsE;
	completed=false;
}




/*
 *
 * 		GETS/SETS
 *
 */

unsigned int Prova::getID()const {
	return id;
}

date Prova::getData() const {
	return data;
}

void Prova::setData(date d){
	data=d;
}

string Prova::getLocal() const {
	return local;
}

void Prova::setLocal(string l){
	local=l;
}

unsigned int Prova::getDuracao() const {
	return duracao;
}

void Prova::setDuracao(unsigned int d){
	duracao=d;
}

vector<Equipa*> Prova::getAdversarios() const {
	return vs;
}

void Prova::setAdversarios(vector<Equipa*> vE){
	vs=vE;
}

Modalidade* Prova::getModalidade() const {
	return mod;
}

void Prova::setModalidade(Modalidade* m){
	mod=m;
}

Equipa* Prova::getVencedor() const {
	return vencedor;
}

void Prova::setVencedor(Equipa* v){
	vencedor=v;
}

bool Prova::getProvaTempo() const{
	return provaT;
}
void Prova::setProvaTempo(bool b){
	provaT=b;
}

bool Prova::getCompleted() const{
	return completed;
}

void Prova::setCompleted(bool b){
	completed=b;
}

unsigned Prova::controloDoping(){

	unsigned doping_control;
	unsigned counter=0;

	srand(time(NULL));

	for(unsigned i=0; i<vs.size(); i++){
		doping_control = rand() % 100;
		if(doping_control>80){					//20% probabilidade ter doping
			vs[i]->setDoping(true);
			counter++;
		}
		else vs[i]->setDoping(false);
	}

	return counter;

}


/*
 *
 * 		MANIPULAR MEMBROS-DADOS
 *
 */

Atleta* Prova::getParticipante(int i) const{

	vector <Atleta*> atletasVec = vs[i]->getAtletas();
	int position;


	for(unsigned int j=0; j < atletasVec.size(); j++){

		vector <Modalidade*> modAtleta = atletasVec[j]->getModalidades();

		position = sequentialSearch(modAtleta, this->mod);
		if(position !=-1){
			return vs[i]->getAtletas()[j];
		}
	}

	throw ParticipanteInexistente();
}

string Prova::getDataFormatada() const {

	string dta = "";
	stringstream ss;

	ss << data.dia;
	ss << "-";
	ss << data.mes;
	ss << "-";
	ss << data.ano;

	ss >> dta;

	return dta;
}


/*
 *
 * 		PRINT
 *
 */

void Prova::print(){
	cout << "ID : " << getID() << endl;
	cout << "Data: " << getDataFormatada() << endl;
	cout << "Local: " << getLocal() << endl;
	cout << "Modalidade: " << getModalidade()->getNome() << endl;
	cout << "Duracao (min): " << getDuracao() << endl;
}

/*
 *
 * 		OPERADORES
 *
 */

bool Prova::operator !=(const Prova &p)const{

	bool result = true;

	if (this->local == p.getLocal() || (this->getData().ano == p.getData().ano && this->getData().dia == p.getData().dia && this->getData().mes == p.getData().mes && this->getData().hora == p.getData().hora)){
		result = false;
	}

	/*if(this->getData().hora < p.getData().hora + p.getDuracao()){
		result = false;
	}*/

	return result;
}

bool Prova::operator<(const Prova&rp) const{

	bool result = false;

	if(data.ano < rp.data.ano){
		result = true;
	}

	if(data.ano == rp.data.ano){

		if(data.mes < rp.data.mes){
			result = true;
		}

		if(data.mes == rp.data.mes){

			if(data.dia < rp.data.dia){
				result = true;
			}

		}

	}
	return result;


}

ostream& operator<<(ostream& os, const Prova& p)
{
	os <<"ID: " <<p.getID() << endl
			<< "Data: "<< p.getDataFormatada() << endl
			<< "Local: "<< p.getLocal() << endl
			<< "Modalidade: " << p.getModalidade()->getNome() << endl
			<< "Duracao: " << p.getDuracao() << endl;
	return os;
}


/*bool Prova::operator>(const Prova &p){

	bool result = false;

	if(this->data.ano > p.data.ano){

		result = true;

	}

	if(this->data.ano == p.data.ano){

		if(this->data.mes < p.data.mes){
			result = true;
		}

		if(this->data.mes == p.data.mes){

			if (this->data.dia < p.data.dia){
				result = true;
			}
		}

	}
	return result;

}*/





