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

bool Calendario::adicionaProva (Prova* p){

	if(checkProva(p)){
		provas.push_back(p);
		return true;
	}

	else
		cout << "impossivel adicionar prova " << p->getLocal() << "(sobreposicao de provas)" << endl;

	return false;
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
