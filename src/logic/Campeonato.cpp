#include "Campeonato.h"

Campeonato::Campeonato(){
	calendario = new Calendario();
}

Campeonato::Campeonato(string nome): nome(nome) {
	calendario = new Calendario();
}


/*
 *
 * 		GETS/SETS
 *
 */

string Campeonato::getNome() const {
	return nome;
}

void Campeonato::setNome(string n){
	nome=n;
}

date Campeonato::getData() const {
	return data;
}

void Campeonato::setData(string d){

}

string Campeonato::getPais() const {
	return pais;
}

void Campeonato::setPais(string p){
	pais=p;
}

vector<Atleta*> Campeonato::getAtletas() const{
	return atletas;
}

vector<Equipa*> Campeonato::getEquipas() const {
	return equipas;
}

vector<Desporto*> Campeonato::getDeportos() const {
	return desportos;
}

Calendario* Campeonato::getCalendario() const {
	return calendario;
}


/*
 *
 * 		MANIPULAR EQUIPAS E ATLETAS
 *
 */

void Campeonato::inserirEquipa(Equipa &e){
	equipas.push_back(&e);
}


bool Campeonato::eliminarEquipa(string nome) {

	if(findEquipa(nome)<0)
		return false;
	else{
		equipas.erase(equipas.begin() + findEquipa(nome));
		return true;
	}
}

void Campeonato::inserirAtleta(Atleta& a) {
	atletas.push_back(&a);
}

bool Campeonato::eliminarAtleta(unsigned int id) {

	if(findAtleta(id)<0)
		return false;
	else {
		atletas.erase(atletas.begin() + findAtleta(id));
		return true;
	}
}

void Campeonato::inserirAdepto(Adepto &ad){
	adeptos.push_back(&ad);
}


/*
 *
 * 		PESQUISAR ATLETAS, EQUIPAS, DESPORTOS
 *
 */

int Campeonato::findAtleta(unsigned int id) {

	for(unsigned int i=0; i< atletas.size(); i++){
		if(atletas[i]->getID()==id)
			return i;
	}
	return -1;
}

int Campeonato::findEquipa(string nomeEquipa){

	for(unsigned int i = 0; i < equipas.size(); i++){
		if(equipas[i]->getNome() == nomeEquipa){
			//cout << nomeEquipa << " na posicao " << i << endl;
			return i;
		}
	}
	return -1;
}

int Campeonato::findDesporto(string nomeDesporto){

	for(unsigned int i = 0; i < desportos.size(); i++){
		if(desportos[i]->getNome() == nomeDesporto){
			cout << nomeDesporto << " na posicao " << i << endl;
			return i;
		}
	}
	return -1;
}

vector<Atleta*> Campeonato::findAtletaVect(string nomeAtleta) {
	vector<Atleta*> aux;
	for(unsigned int i=0; i<atletas.size(); i++){
		if(atletas[i]->getNome()==nomeAtleta)
			aux.push_back(atletas[i]);
	}
	return aux;
}


/*
 *
 * 		PRINT
 *
 */

void Campeonato::imprimeEquipas() const{
	for(unsigned int i = 0; i < equipas.size(); i++){
		equipas[i]->imprime();
	}
	cout << endl << endl;
}

void Campeonato::imprimeUmaEquipa(string nome) {
	int pos = findEquipa(nome);

	if(pos<0)
		throw EquipaInexistente(nome);
	else equipas[pos]->imprime();
}

void Campeonato::imprimeAtletas() const {
	for(unsigned int i = 0; i < atletas.size(); i++){
		atletas[i]->imprime();
	}
	cout << endl << endl;
}

void Campeonato::imprimeAtletasPorEquipa() const{
	for(unsigned int i = 0; i < equipas.size(); i++){
		equipas[i]->showAtletas();
	}
	cout << endl;
}

void Campeonato::imprimeAdeptos() const{
	cout << "hello2" << endl;
	for(unsigned int i = 0; i < adeptos.size(); i++){
		adeptos[i]->imprime();
	}
	cout << endl << endl;
}


/*
 *
 * 		READ FILES
 *
 */

void Campeonato::readFileAtletas(string filename){

	ifstream ficheiro_leitura(filename.c_str());

	if(!ficheiro_leitura)
		throw ErroNoFicheiro(filename);
	else {
		string nome, pais, temp1, temp2, temp3, nEquipa;
		int idade, altura, peso;

		while (!ficheiro_leitura.eof()) {

			getline(ficheiro_leitura, nome);
			getline(ficheiro_leitura, pais);
			getline(ficheiro_leitura, temp1);
			getline(ficheiro_leitura, temp2);
			getline(ficheiro_leitura, temp3);
			getline(ficheiro_leitura, nEquipa);

			idade = atoi(temp1.c_str());
			altura = atoi(temp2.c_str());
			peso = atoi(temp3.c_str());

			Atleta *a1 = new Atleta(nome, pais, idade, altura, peso);
			a1->setNEquipa(nEquipa);
			for(unsigned int i = 0; i < equipas.size(); i++){
				if(equipas[i]->getNome() == nEquipa){
					equipas[i]->inserirAtleta(*a1);
					break;
				}
			}
			inserirAtleta(*a1);
		}
	}
}

void Campeonato::readFileEquipas(string filename){

	ifstream ficheiro_leitura (filename.c_str());

	if(!ficheiro_leitura)
		throw ErroNoFicheiro(filename);
	else {
		string nome, pais, patrocinador;

		while (!ficheiro_leitura.eof()) {

			getline(ficheiro_leitura, nome);
			getline(ficheiro_leitura, pais);
			getline(ficheiro_leitura, patrocinador);

			Equipa *e1 = new Equipa(nome, pais, patrocinador);
			inserirEquipa(*e1);
		}
	}
}

void Campeonato::readFileAdeptos(string filename) {

	ifstream ficheiro_leitura (filename.c_str());

	if(!ficheiro_leitura)
		throw ErroNoFicheiro(filename);
	else {
		string nome;
		string email, equipa;

		while (!ficheiro_leitura.eof()) {

			getline(ficheiro_leitura, nome);
			getline(ficheiro_leitura, email);
			getline(ficheiro_leitura, equipa);

			Adepto *a1 = new Adepto(nome, email, equipa);
			inserirAdepto(*a1);
		}
	}
}

void Campeonato::readFileProvas(string filename) {

	ifstream ficheiro_leitura(filename.c_str());

	if(!ficheiro_leitura)
		throw ErroNoFicheiro(filename);
	else{
		string data, local, durtmp, adv1, adv2, venc, modal;
		unsigned int duracao;

		while (!ficheiro_leitura.eof()){

			getline(ficheiro_leitura, data);
			getline(ficheiro_leitura, local);
			getline(ficheiro_leitura, durtmp);
			getline(ficheiro_leitura, adv1);
			getline(ficheiro_leitura, adv2);
			getline(ficheiro_leitura, venc);
			getline(ficheiro_leitura, modal);

			duracao=atoi(durtmp.c_str());

			stringstream dataSs;
			date d;
			dataSs << data;
			int dia, mes, ano;
			char tmp;
			dataSs >> dia >> tmp >> mes >> tmp >> ano;

			if(dia < 1 || dia > 31|| mes < 1 || mes > 12 || ano < 1 || (dia > 28 && mes == 2) || (dia > 30 && mes == 4) || (dia > 30 && mes == 6) || (dia > 30 && mes == 9) || (dia > 30 && mes == 11)){
				cout << "Data invalida!";
			}
			else{
				d.dia = dia;
				d.mes = mes;
				d.ano = ano;
			}

			vector<Equipa*> vs;

			if(findEquipa(adv1)!=-1 && findEquipa(adv2)!=-1){
				vs.push_back(getEquipas()[findEquipa(adv1)]);
				vs.push_back(getEquipas()[findEquipa(adv2)]);
				Modalidade* m= new Modalidade(modal, false);
				Prova* p = new Prova(d, local, duracao, vs, m);

				//calendario->adicionaProva(*p);
				//calendario->getProvas().push_back(p);
				//cout << calendario->getProvas()[0]->getLocal() << endl;
				//inserirProva(*p);
				calendario->inserirProva(*p);
				//cout << calendario->getProvas()[0]->getLocal() << endl;
			}
			else
				throw EquipaInexistente("abc");

			if(!ficheiro_leitura.eof())
				break;
		}

	}
	//getCalendario()->showProvas();
}

void Campeonato::realizarProva(int id){
	string v;
	string equipa1 = calendario->getProvas()[id]->getAdversarios()[0]->getNome();
	string equipa2 = calendario->getProvas()[id]->getAdversarios()[1]->getNome();

	v = calendario->getProvas()[id]->getModalidade()->pontuacao(equipa1,equipa2);


	if (v == calendario->getProvas()[id]->getAdversarios()[0]->getNome()){
		equipas[findEquipa(equipa1)]->setPontuacao(3);
	}

	else if (v == calendario->getProvas()[id]->getAdversarios()[1]->getNome())
		equipas[findEquipa(equipa2)]->setPontuacao(3);

	else{
		equipas[findEquipa(equipa1)]->setPontuacao(1);
		equipas[findEquipa(equipa2)]->setPontuacao(1);
	}

}

void Campeonato::ordenaClassificacoes(){
	insertionSort(equipas);
}
