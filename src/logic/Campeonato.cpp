#include "Campeonato.h"

Campeonato::Campeonato() {}

Campeonato::Campeonato(string nome): nome(nome) {
	Calendario* c = new Calendario;
	calendario = c;
}

string Campeonato::getNome() const {
	return nome;
}

void Campeonato::setNome(string n){
	nome=n;
}

date Campeonato::getData() const {
	return data;
}

string Campeonato::getPais() const {
	return pais;
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

void Campeonato::adicionaEquipa(){
	string nome, pais, patrocinio;

	cout << "Insira o nome da equipa a criar: ";
	cin.ignore();
	getline(cin, nome);
	cout << endl;

	cout << "Insira o pais da equipa a criar: ";
	cin.ignore();
	getline(cin, pais);
	cout << endl;

	cout << "Insira o patocinador da equipa a criar: ";
	cin.ignore();
	getline(cin, patrocinio);
	cout << endl;


	Equipa *e1 = new Equipa(nome, pais, patrocinio);
	inserirEquipa(*e1);
}

bool Campeonato::eliminaEquipa() {
	string str;
	cout << "Nome da equipa a eliminar: ";
	cin >> str;
	int i = findEquipa(str);
	if(i == -1){
		cout << "Equipa nao encontrada" << endl;
		return false;
	}
	else{
		equipas.erase(equipas.begin()+i);
		return true;
	}
}

void Campeonato::inserirEquipa(Equipa &e1){
	equipas.push_back(&e1);
}

void Campeonato::alteraEquipa(){
	int pos;
	string input;
	int input_aux;
	float pont;

	cout << "Insira o nome da equipa a alterar: " << endl;
	cin >> input;

	pos=findEquipa(input);

	if(pos==-1)
		throw EquipaInexistente(input);
	else{
		getEquipas()[pos]->imprime();
		cout << endl;
		cout << "Insira o campo que pretende alterar: " << endl;
		cin >> input;

		if(input=="Nome"){
			cout << "Insira o nome que pretende atribuir: " << endl;
			cin >> input;
			getAtletas()[pos]->setNome(input);
		}
		else if(input=="Pais"){
			cout << "Insira o país que pretende atribuir: " << endl;
			cin >> input;
			getAtletas()[pos]->setPais(input);
		}
		else if(input=="Idade"){
			cout << "Insira a idade que pretende atribuir: " << endl;
			cin >> input_aux;
			getAtletas()[pos]->setIdade(input_aux);
		}
		else if(input=="Peso"){
			cout << "Insira o peso que pretende atribuir: " << endl;
			cin >> input_aux;
			getAtletas()[pos]->setPeso(input_aux);
		}
		else if(input=="Altura"){
			cout << "Insira a altura que pretende atribuir: " << endl;
			cin >> input_aux;
			getAtletas()[pos]->setAltura(input_aux);
		}
		else if(input=="Pontuacao"){
			cout << "Insira a pontuacao que pretende atribuir: " << endl;
			cin >> pont;
			getAtletas()[pos]->setPontuacao(pont);
		}
		else if(input=="Equipa"){
			cout << "Insira o nome da equipa que pretende atribuir: " << endl;
			cin >> input;
			getAtletas()[pos]->setEquipa(input);
		}

		getAtletas()[pos]->imprime();
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
			a1->setEquipa(nEquipa);
			for(unsigned int i = 0; i < equipas.size(); i++){
				if(equipas[i]->getNome() == nEquipa){
					equipas[i]->inserirAtleta(*a1);
					break;
				}
			}
			atletas.push_back(a1);
		}
	}
}

void Campeonato::inserirProva(Prova &p1){
	calendario->getProvas().push_back(&p1);
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
				cout << p->getData().ano << endl;
				//calendario->adicionaProva(*p);
				//calendario->getProvas().push_back(p);
				//cout << calendario->getProvas()[0]->getLocal() << endl;
				//inserirProva(*p);
				calendario->addProva(*p);
			}
			else
				throw EquipaInexistente("abc");

			if(!ficheiro_leitura.eof())
						break;
		}

	}

	//getCalendario()->showProvas();
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

void Campeonato::adicionaAtleta() {

	info i;
	string equipa;

	cout << "Nome: " << endl;
	cin.ignore();
	getline(cin, i.nome);
	//cin >> i.nome;
	cout << "Pais: " << endl;
	cin >> i.pais;
	cout << "Idade: " << endl;
	cin >> i.idade;
	cout << "Altura: " << endl;
	cin >> i.altura;
	cout << "Peso: " << endl;
	cin >> i.peso;
	cout << "Equipa: " << endl;
	cin >> equipa;

	Atleta *a = new Atleta(i.nome, i.pais, i.idade, i.altura, i.peso);
	a->setEquipa(equipa);

	if(findEquipa(equipa)!=-1){
		equipas[findEquipa(equipa)]->inserirAtleta(*a);
	}

	atletas.push_back(a);
}

void Campeonato::removerAtleta() {

	unsigned int id;

	cout << "Insira o ID do atleta a remover: " << endl;
	cin >> id;

	if(findAtleta(id)!=-1){
		atletas.erase(atletas.begin() + findAtleta(id));
	}

}

void Campeonato::imprimeUmaEquipa() {
	string n;
	int i;

	bool found = false;

	while(!found){

		cout << "Nome da equipa a consultar (0 para sair): ";
		cin >> n;

		i = this->findEquipa(n);

		if(n== "0")
			return;

		if(i == -1)
			//else if(i == -1)
			cout << "Equipa nao encontrada!" << endl;
		else{
			found=true;
			equipas[i]->showAtletas();
		}


	}

}

int Campeonato::findAtleta(unsigned int id) {

	for(unsigned int i=0; i< atletas.size(); i++){
		if(atletas[i]->getID()==id){
			cout << id << " na posicao " << i << endl;
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

void Campeonato::imprimeAtletas() const {
	for(unsigned int i = 0; i < atletas.size(); i++){
		atletas[i]->imprime();
	}
	cout << endl << endl;
}

void Campeonato::imprimeEquipas() const{
	for(unsigned int i = 0; i < equipas.size(); i++){
		cout << endl;
		cout << "Nome: " << equipas[i]->getNome() << endl;
		cout << "Pais: " << equipas[i]->getPais() << endl;
		cout << "Patrocinador: " << equipas[i]->getPatrocinador() << endl;
	}
	cout << endl << endl;
}

void Campeonato::imprimeAtletasPorEquipa() const{
	for(unsigned int i = 0; i < equipas.size(); i++){
		equipas[i]->showAtletas();
	}
	cout << endl;
}

void Campeonato::ordenaClassificacoes(){

	insertionSort(equipas);

}



