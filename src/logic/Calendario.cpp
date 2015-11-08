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

	cout << "Criador de Provas!" << endl;

	string input = "s";
	string restart;
	string nAtleta;
	string modN;
	bool boaMod = false;
	bool boaData = false;
	bool boaHora = false;
	bool boaDur = false;
	bool atletaEncontrado = false;
	bool provaSobrep = true;
	date d1;

	while (input == "s" || input == "sim" || input == "Sim" || input == "SIM" || input =="S"){

		while(!boaMod){

			cout << "Nome da modalidade: ";
			cin >> modN;

			for (unsigned int i = 0; i < getModalidades().size(); i++){
				if(getModalidades()[i] == modN)
					boaMod = true;
			}
			if(!boaMod)
				cout << "Nome da modalidade nao encontrad!!" << endl;

		}
		while(provaSobrep){

			string local;
			string data;
			cout << "Local da prova: ";
			cin >> local;

			while(!boaData){

				stringstream dataSs;

				cout << "Data da prova(DD-MM-AAAA): ";
				cin >> data;
				dataSs << data;
				int dia=1, mes=1, ano=1;
				char tmp;
				dataSs >> dia >> tmp >> mes >> tmp >> ano;


				if(dia < 1 || dia > 31|| mes < 1 || mes > 12 || ano < 1 || (dia > 28 && mes == 2) || (dia > 30 && mes == 4) || (dia > 30 && mes == 6) || (dia > 30 && mes == 9) || (dia > 30 && mes == 11)){
					cout << "Data invalida!";
					boaData = false;
				}

				else{

					boaData =true;

					d1.dia = dia;
					d1.mes = mes;
					d1.ano = ano;

				}
			}

			while(!boaHora){

				float hora;
				cout << "A que horas comecara a prova?(formato 24h) ";
				cin >>hora;
				if(hora < 1 || hora > 24){
					cout << "Hora invalida!" << endl;
					boaHora =false;
				}
				else{
					boaHora= true;
					d1.hora = hora;
				}

			}




			int min;
			while(!boaDur){
				cout << "Qual a duracao da prova?(Em minutos) ";
				cin >> min;
				if(min < 1){
					cout << "Duracao invalida!" << endl;
					boaDur = false;
				}
				else
					boaDur = true;

			}
			string nEquipa;
			bool boaEquipa = false;
			// Equipa 1
			while(!boaEquipa){

				cout << "Nome da primeira equipa a participar: ";
				cin >> nEquipa;
				for(unsigned int k = 0; k < getEquipas().size(); k++){
					if(getEquipas()[k] == nEquipa)
						boaEquipa = true;
				}
				if(!boaEquipa)
					cout << "Equipa nao encontrada!" << endl;
			}

			Equipa equi1(nEquipa,"temp","temp");
			boaEquipa = false;

			while (!atletaEncontrado){

				cout << "Nome do atleta da equipa " << equi1.getNome() <<": ";

				cin >> nAtleta;

				for (unsigned int k = 0; k < getAtletas().size(); k++){
					if(getAtletas()[k] == nAtleta)
						atletaEncontrado = true;
				}

				if (!atletaEncontrado)
					cout << "Atleta nao encontrado!" << endl;

			}
			atletaEncontrado = false;

			Atleta a1(nAtleta, "temp", 0 ,0 ,0);

			// Equipa 2

			while(!boaEquipa){
				cout << "Nome da segunda equipa a participar: ";
				cin >> nEquipa;
				for(unsigned int k = 0; k < getEquipas().size(); k++){
					if(getEquipas()[k] == nEquipa)
						boaEquipa = true;
				}
				if(!boaEquipa)
					cout << "Equipa nao encontrada!" << endl;
			}


			Equipa equi2(nEquipa, "temp", "temp");

			while (!atletaEncontrado){

				cout << "Nome do atleta da equipa " << equi2.getNome() <<": ";

				cin >> nAtleta;

				for (unsigned int k = 0; k < getAtletas().size(); k++){
					if(getAtletas()[k] == nAtleta)
						atletaEncontrado = true;
				}

				if (!atletaEncontrado)
					cout << "Atleta nao encontrado!" << endl;

			}

			Atleta a2(nAtleta, "temp",0,0,0);

			vector<Equipa*> vs;

			Modalidade *m = new Modalidade(modN,0);
			Prova p1(d1,local, min, vs,m);


			if(adicionaProva(&p1)){
				provaSobrep=false;
			}
			else{ // falhou por reposicao
				cout << endl << "Recomecar ou Alterar dados desta modalidade? (R/A)";
				cin >> restart;
				provaSobrep=true;
			}


			boaData = false;
			boaHora = false;
			boaDur = false;
			boaMod = false;

			if(restart == "R" || restart == "r")
				break;

		}
		provaSobrep = true;
		bool bomInput =false;

		while(!bomInput){
			cout << "Adicionar nova prova?(S/N)";
			cin >> input;
			if(input != "S" || input !="N" || input !="s" ||input !="n")
				cout << "Input invalido." << endl;
			else
				bomInput =true;
		}

	}

	string nomeFich;
	if(!fichExiste(this->nomeFicheiro)){
		cout << "Com que nome gostaria de guardar o ficheiro das provas? ";
		cin >> nomeFich;
		nomeFich =+ ".txt";
		nomeFicheiro = nomeFich;
		criaFich(0, 0); // criar um ficheiro novo
	}
	else{
		cout << "Provas adicionadas ao ficheiro " << getNomeFich() << endl;
		criaFich(0, 1); // alterar um ficheiro existente

	}


}

void Calendario::criaFich(bool alterar, bool adicionar){
	
	ofstream provasFich;
	
	if (adicionar && !alterar){
		provasFich.open(this->nomeFicheiro.c_str(), std::fstream::app);
	}
	else if(!adicionar && alterar){

		if( remove( this->nomeFicheiro.c_str() ) != 0 ){
			cout <<  "Erro a apagar ficheiro" << endl;
			provasFich.open(this->nomeFicheiro.c_str(), std::fstream::out);
		}
		else
			provasFich.open(this->nomeFicheiro.c_str(), std::fstream::out);
	}

	vector<Prova*>::iterator it;

	for(it=provas.begin(); it!= provas.end(); it++) {

		provasFich << (*it)->getModalidade()->getNome() << endl << (*it)->getAdversarios()[0]->getNome() << " vs " << (*it)->getAdversarios()[1]->getNome()<< endl;
		provasFich << "Local: " << (*it)->getLocal() <<endl;
		provasFich << "Duracao: " << (*it)->getDuracao() << endl;
		provasFich << "Vencedor: " << (*it)->getVencedor()->getNome() << "!!" << endl << endl;

	}

	out << "Ficheiro de provas gravado com o nome " << this->nomeFicheiro << endl;


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
