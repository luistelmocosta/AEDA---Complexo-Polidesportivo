#include "Calendario.h"
#include <iomanip>
//#include <string>

using namespace std;


Calendario::Calendario(vector <Prova*> p) {

	for(unsigned int i = 0; i<p.size();i++){
		provas.push_back(p[i]);
	}
}

vector<Prova*> Calendario::getProvas() const {
	return provas;
}

int Calendario::findProva(int id) {
	for(unsigned int i=0; i<provas.size(); i++){
		if(provas[i]->getId()==id)
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
	Prova* p;
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

void Calendario::showUmaProva(int i) const {

	cout << "ID : " << provas[i]->getId() << endl;
	cout << provas[i]->getModalidade()->getNomeDesporto() << endl;
	cout << provas[i]->getModalidade()->getNome()<< endl;
	cout << provas[i]->getLocal()<<endl;
	cout << provas[i]->getAdversarios()[0]->getNome() << " vs " << provas[i]->getAdversarios()[1]->getNome()<<endl;
	cout << provas[i]->getParticipante(0)->getNome() << "    " << provas[i]->getParticipante(1)->getNome()<<endl;
	cout << "Data: " << provas[i]->getDataFormatada()<< endl;


}

bool Calendario::adicionaProva (Prova* p){

	if(checkProva(p)){
		provas.push_back(p);
		return true;
	}

	else
		cout << "impossivel adicionar prova " << p->getLocal() << "(sobreposicao de provas)" << endl;

	return false;
}

void Calendario::deleteProva(int i){
	provas.erase(provas.begin()+i);
}

void Calendario::criaProvas(){

	cout << setw(10) << "Criador de Provas!" << endl;

	string input = "s";
	string restart;
	bool boaData = true;
	bool boaHora = false;
	bool boaDur = false;
	bool provaSobrep = true;
	date d1;

	while (input == "s" || input == "sim" || input == "Sim" || input == "SIM" || input =="S"){

		if(boaData){
			string modN;
			cout << "Nome da modalidade: "; //TODO verificar se a modalidade introduzida existe
			cin >> modN;
		}
		while(provaSobrep){

			string local;
			string data;
			cout << "Local da prova: ";
			cin >> local;

			stringstream datAss;

			cout << "Data da prova(DD-MM-AAAA): ";
			cin >> data;
			datAss << data;
			int dia=1, mes=1, ano=1;
			datAss >> dia >> mes >> ano;
			cout << dia << " " << mes << " " << ano << endl;
			if(dia < 1 || dia > 31|| mes < 1 || mes > 12 || ano < 1 || (dia > 30 && mes == 2) || (dia > 30 && mes == 4) || (dia > 30 && mes == 6) || (dia > 30 && mes == 9) || (dia > 30 && mes == 11)){
				cout << "Data invalida!";
				boaData = false;
			}

			else{

				boaData =true;

				d1.dia = dia;
				d1.mes = mes;
				d1.ano = ano;
				boaHora = false;

				while(!boaHora){

					float hora;
					cout << "A que horas comecara a prova?(formato 24h) ";
					cin >>hora;
					if(hora < 1 || hora > 24){
						cout << "Hora invalida!";
						boaHora =false;
					}
					else{
						boaHora= true;
						d1.hora = hora;
					}

				}
			}


			if(boaData && boaHora){
				int min;
				while(!boaDur){
					cout << "Qual a duracao da prova?(Em minutos) ";
					cin >> min;
					if(min < 1){
						cout<< endl << "Duracao invalida!";
						boaDur = false;
					}
					else
						boaDur = true;

				}
				string e1, e2;
				cout << "Nome da primeira equipa a participar: ";
				cin >> e1;
				//TODO verificar se equipa existe

				Equipa equi1(e1,"rio tinto","BigMac");

				cout << "Nome da segunda equipa a participar: ";
				cin >> e2;
				Equipa equi2(e2, "Gondomar", "BigTasty");
				vector<Equipa*> vs;
				vs.push_back(&equi1);
				vs.push_back(&equi2);
				Modalidade *m = new Modalidade("levantamento de copo",1);
				Prova p1(d1,local, min, vs,m);

				if(adicionaProva(&p1))
					provaSobrep=false;
				else{

					cout << endl << "Recomecar ou alterar data? (R/A)";
					cin >> restart;
					provaSobrep=true;
				}

			}

			if(restart == "R" || restart == "r")
				break;

		}

		cout << "Adicionar nova prova?(S/N)";
		cin >> input;
		if(input == "N" || input == "n")
			break;

	}

	string nomeFich;
	cout << "Com que nome gostaria de guardar as provas? ";
	cin >>nomeFich;

	criaFich(nomeFich);
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

	cout << "Ficheiro de provas gravado com o nome " << nome;


}

void Calendario::removeProva(){
	int n;
	cout << endl << "ID da prova a remover(0 para cancelar): ";
	cin >> n;

	if(n == 0)
		return;

	if(n > provas.size() || n < 0){
		cout << endl  << "Prova nao encontrada!" << endl;
		return;
	}


	provas.erase(provas.begin()+n-1);
}

void Calendario::showProvas()const{

	for (unsigned int i = 0; i < provas.size(); i++){
		cout << "ID : " << provas[i]->getId() << endl;
		cout << provas[i]->getModalidade()->getNomeDesporto() << endl;
		cout << provas[i]->getModalidade()->getNome()<< endl;
		cout << provas[i]->getLocal()<<endl;
		cout << provas[i]->getAdversarios()[0]->getNome() << " vs " << provas[i]->getAdversarios()[1]->getNome()<<endl;
		cout << provas[i]->getParticipante(0)->getNome() << "    " << provas[i]->getParticipante(1)->getNome()<<endl;
		cout << "Data: " << provas[i]->getDataFormatada()<< endl;

	}

}

/*
int main(){

	Calendario* c1;
	Modalidade* m;
	Prova* p;

	cout << "1" << endl;
	m->setNome("Abc");

	cout << "2" << endl;

	p->setModalidade(m);



	c1->getProvas().push_back(p);

	c1->findProva_Modal(m);

	return 0;
}*/
