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


priority_queue<Equipa*, vector<Equipa*>, ComparaEquipa> Campeonato::getClassificacao() const{
	return classificacao;
}

TabelaBilhetes Campeonato::getBilhetes() const{
	return bilhetes;
}

vector<Adepto*> Campeonato::getAdeptos() const {
	return adeptos;
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

int Campeonato::findAdepto(unsigned int id) {

	for(unsigned int i = 0; i < adeptos.size(); i++) {
		if(adeptos[i]->getID() == id) {
			return i;
		}
	}
	return -1;
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

	ifstream ficheiro_leitura(filename.c_str());

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
	string equipa1;  // = calendario->getProvas()[id]->getAdversarios()[0]->getNome();
	string equipa2; //= calendario->getProvas()[id]->getAdversarios()[1]->getNome();

	BSTItrIn<Prova> it = calendario->getProvas();

	while(!it.isAtEnd()){

		if(it.retrieve().getID() == id){
			equipa1 = it.retrieve().getAdversarios()[0]->getNome();
			equipa2 = it.retrieve().getAdversarios()[1]->getNome();
			v = it.retrieve().getModalidade()->pontuacao(equipa1, equipa2);

			if(v == it.retrieve().getAdversarios()[0]->getNome())
				equipas[findEquipa(equipa1)]->setPontuacao(3);

			else if(v == it.retrieve().getAdversarios()[1]->getNome() )
				equipas[findEquipa(equipa2)]->setPontuacao(3);

			else{
				equipas[findEquipa(equipa1)]->setPontuacao(1);
				equipas[findEquipa(equipa2)]->setPontuacao(1);
			}

			break;
		}

		it.advance();
	}


}

int Campeonato::updateClassificacoes(){

	while(!classificacao.empty()){
		classificacao.pop();
	}

	for(unsigned i=0; i<equipas.size(); i++){
		if(equipas[i]->temMedalhas())
			classificacao.push(equipas[i]);
	}

	return 0;
}

void Campeonato::inserirAdepto(Adepto &ad) {
	adeptos.push_back(&ad);
}

void Campeonato::inserirBilhete(Bilhete &b1){


	TabelaBilhetes::iterator it = bilhetes.find(b1);

	if(it == bilhetes.end())
		bilhetes.insert(b1);
	else{
		bilhetes.erase(it);
		bilhetes.insert(b1);
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

			Adepto *ad1 = new Adepto(nome, email, equipa);
			inserirAdepto(*ad1);


		}
	}
}

void Campeonato::readFileBilhetes(string filename) {


	fstream infile(filename.c_str());
	string linha, dono;
	int dia, mes, ano;
	vector<int> campeonatoIds;
	BSTItrIn<Prova> it = calendario->getProvas();
	vector<Prova*> tmp;

	while (getline(infile, dono)) // get name and check status file stream
	{

		cout << dono << endl;
		// read in date
		getline(infile, linha);
		istringstream iss (linha);
		string tmpstr1;
		getline(iss, tmpstr1, '/');
		dia = atoi(tmpstr1.c_str());

		getline(iss, tmpstr1, '/');
		mes = atoi(tmpstr1.c_str());

		getline(iss, tmpstr1, '/');
		ano = atoi(tmpstr1.c_str());

		cout << dia << "/" << mes << "/" << ano << endl;

		date d;

		if(dia < 1 || dia > 31|| mes < 1 || mes > 12 || ano < 1 || (dia > 28 && mes == 2) || (dia > 30 && mes == 4) || (dia > 30 && mes == 6) || (dia > 30 && mes == 9) || (dia > 30 && mes == 11)){
			cout << "Data invalida!";
		}
		else{
			d.dia = dia;
			d.mes = mes;
			d.ano = ano;
		}

		// read in provas ids
		getline(infile, linha);
		istringstream iss2(linha);
		string tmpstr2;
		while (getline(iss2, tmpstr2, ','))

		{

			unsigned int provaID = atoi(tmpstr2.c_str());



			tmp.push_back(calendario->getProvaID(provaID));



			//campeonatoIds.push_back(atoi(tmpstr2.c_str()));
		}

		cout << endl;


		Adepto *a1 = new Adepto(dono);
		Bilhete *b1 = new Bilhete(d, a1, tmp);
		inserirBilhete(*b1);

		tmp.clear();

	}
}

/*
OUTPUT FILE FUNCS


 */

void Campeonato::outputFileAtletas(string filename){

	ofstream aFile;

	aFile.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);



	for (unsigned int i = 0; i < atletas.size(); ++i){

		aFile << atletas[i]->getNome() << endl
				<< atletas[i]->getPais() << endl
				<< atletas[i]->getIdade() << endl
				<< atletas[i]->getAltura() << endl
				<< atletas[i]->getPeso() << endl;
	}


}
void Campeonato::outputFileEquipas(string filename){

	ofstream eFile;

	eFile.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);



	for (unsigned int i = 0; i < equipas.size(); ++i){

		eFile << equipas[i]->getNome() << endl
				<< equipas[i]->getPais() << endl
				<< equipas[i]->getPatrocinador() << endl;
	}

}
void Campeonato::outputFileProvas(string filename){

	ofstream pFile;

	pFile.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);

	BSTItrIn<Prova> it = calendario->getProvas();

	while(!it.isAtEnd()){


		pFile << it.retrieve().getDataFormatada() << endl
				<< it.retrieve().getLocal() << endl
				<< it.retrieve().getDuracao() << endl
				<< it.retrieve().getAdversarios()[0]->getNome() << endl
				<< it.retrieve().getAdversarios()[1]->getNome() << endl
				<< it.retrieve().getVencedor() << endl
				<< it.retrieve().getModalidade()->getNome() << endl;

		it.advance();
	}

}
void Campeonato::outputFileAdeptos(string filename){

	ofstream aFile;

	aFile.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);



	for (unsigned int i = 0; i < adeptos.size(); ++i){

		aFile <<adeptos[i]->getNome() << endl
				<< adeptos[i]->getEmail() << endl
				<< adeptos[i]->getEquipa() << endl;

	}


}
void Campeonato::outputFileBilhetes(string filename){



}




void Campeonato::imprimeBilhetes(){


	TabelaBilhetes::iterator it = bilhetes.begin();

	cout << "===BILHETES===" << endl;


	while(it != bilhetes.end()) {

		cout << endl;
		cout << endl;
		cout << "Data de Validade: " << it->getDataFormatada() << endl;
		cout << "Dono do Bilhete: " << it->getNomeDono() << endl;
		cout << "Provas com acesso: ";
		it ->printProvas();

		cout << endl;
		it++;
	}
}
/*void Campeonato::removerBilhete(string nome){

	TabelaBilhetes::iterator it = bilhetes.begin();
	Adepto ad;

	while( it != bilhetes.end()) {
		if(it-> == nome)
			bilhetes.erase(it);
		it++;
	}
}*/


void Campeonato::venderBilhete(unsigned int id) {

	cout << "VOU VENDER" << endl;

	TabelaBilhetes::iterator it = bilhetes.begin();

	while( it != bilhetes.end()) {
		cout << "TESTE" << endl;
		cout << "ID DONO: " << it->getNomeDono() << endl;
		if(it->getIdDono() == id){

			bilhetes.erase(it);
		}
		it++;
	}

	cout << "VENDI " << endl;
}

void Campeonato::comprarBilhete(unsigned int id) {

}

void Campeonato::testPQ(){
	Equipa *e1, *e2, *e3;

	e1=new Equipa();
	e2=new Equipa();
	e3=new Equipa();

	vector<unsigned> v1, v2, v3;

	v1.push_back(100);
	v2.push_back(20);
	v3.push_back(500);

	e1->setMedalhas(v1);
	e2->setMedalhas(v2);
	e3->setMedalhas(v3);

	inserirEquipa(*e1);
	inserirEquipa(*e2);
	inserirEquipa(*e3);

	classificacao.push(equipas[0]);
	classificacao.push(equipas[1]);
	classificacao.push(equipas[2]);

	cout << equipas[0]->getMedalhas()[0] << endl;
	cout << equipas[1]->getMedalhas()[0] << endl;
	cout << equipas[2]->getMedalhas()[0] << endl;

	cout << "FINALMENTE PQ P" << endl;

	priority_queue<Equipa*, vector<Equipa*>, ComparaEquipa> aux = classificacao;

	while(!aux.empty()){
		cout << aux.top()->getMedalhas()[0] << endl;
		aux.pop();
	}
}
