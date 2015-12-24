#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Campeonato.h"
#include "Utilities.h"





void Menu::initMenu(){

	cout << "# Campeonatos Polidesportivos #" << endl << endl;

	while(campeonato->getNome()=="" || campeonato->getPais()==""){
		collectCampInfo();
	}

	clearScreen();
	dataBaseMenu();

}

void Menu::collectCampInfo(){
	string nomeC, dataC, paisC;

	cout << "Insira o nome do Campeonato a criar: ";
	cin >> nomeC;
	cout << "Insira a data de inicio do Campeonato: ";
	cin >> dataC;
	cout << "Insira o pais-anfitriao do Campeonato: ";
	cin >> paisC;
	cout << endl;

	campeonato->setNome(nomeC);
	campeonato->setData(dataC);
	campeonato->setPais(paisC);
}


/*
 * 	#DATABASE
 */

void Menu::dataBaseMenu(){
	int input;

	cout << "1. Utilizar Base Dados existente" << endl;
	cout << "2. Criar Base Dados" << endl;
	cin >> input;

	clearScreen();

	if(input==1){
		readDB();
		mainMenu();
	}
	else if(input==2)
		criaDBMenu();
	else dataBaseMenu();

}

int Menu::readDB(){

	FICHEIRO_ATLETAS = "txt_data/Atletas_default.txt";
	FICHEIRO_EQUIPAS = "txt_data/Equipas_default.txt";
	FICHEIRO_PROVAS = "txt_data/Provas_default.txt";
	FICHEIRO_ADEPTOS = "txt_data/Adeptos_default.txt";
	FICHEIRO_BILHETES = "txt_data/Bilhetes_default.txt";


	try{
		campeonato->readFileAtletas(FICHEIRO_ATLETAS);
		campeonato->readFileEquipas(FICHEIRO_EQUIPAS);
		campeonato->readFileProvas(FICHEIRO_PROVAS);
		campeonato->readFileAdeptos(FICHEIRO_ADEPTOS);
		campeonato->readFileBilhetes(FICHEIRO_BILHETES);
	}
	catch (ErroNoFicheiro &e){
		cout << "Tentativa de abrir o ficheiro falhou.\n";
		return -1;
	}

	return 0;
}

void Menu::criaDBMenu(){

	int input;

	if(nomeFichDB==false){
		cout << "Nome do ficheiro onde os atletas criados serao guardadas: ";
		cin >>FICHEIRO_ATLETAS;

		cout << "Nome do ficheiro onde as equipas criados serao guardadas: ";
		cin >>FICHEIRO_EQUIPAS;

		cout << "Nome do ficheiro onde as provas criados serao guardadas: ";
		cin >>FICHEIRO_PROVAS;

		cout << "Nome do ficheiro onde os adeptos criados serao guardadas: ";
		cin >>FICHEIRO_ADEPTOS;

		cout << "Nome do ficheiro onde os bilhetes criados serao guardadas: ";
		cin >>FICHEIRO_BILHETES;

		nomeFichDB=true;
	}


	cout << "1. Criar Equipa" << endl;
	cout << "2. Criar Atleta" << endl;
	cout << "3. Criar Prova" << endl;
	cout << "4. Avancar" << endl;

	cin >> input;

	switch(input){

	case 1: criaEquipaMenu();
	criaDBMenu();
	break;

	case 2: criaAtletaMenu();
	criaDBMenu();
	break;

	case 3:criaProvaMenu();
	criaDBMenu();
	break;

	case 4: mainMenu();
	break;

	default: cout << "Opcao invalida." << endl;
	}

}


/*
 * 	#MAINMENU
 */

void Menu::mainMenu(){

	int input;

	cout << "1. Gerir Equipas" << endl;
	cout << "2. Gerir Atletas" << endl;
	cout << "3. Gerir Provas" << endl;
	cout << "4. Ver Calendario" << endl;
	cout << "5. Classificacoes" << endl;
	cout << "6. Espaco Adepto" << endl;
	cout << "7. Sair" << endl;

	cin >> input;

	clearScreen();

	switch(input){
	case 1: gerirEquipaMenu();
	break;

	case 2: gerirAtletaMenu();
	break;

	case 3: gerirProvaMenu();
	break;

	case 4:
		calendarioMenu();
		break;

	case 5: verClassificacoes();
	break;

	case 6:	espacoAdeptoMenu();
	break;

	case 7:
		campeonato->outputFileAdeptos(FICHEIRO_ADEPTOS);
		campeonato->outputFileAtletas(FICHEIRO_ATLETAS);
		//campeonato->outputFileBilhetes(FICHEIRO_BILHETES);
		campeonato->outputFileEquipas(FICHEIRO_EQUIPAS);
		campeonato->outputFileProvas(FICHEIRO_PROVAS);


		break;

	default: mainMenu();
	break;

	}
}


/*
 * 	#EQUIPAS
 */

void Menu::criaEquipaMenu(){
	string nome, pais, pat;

	cout << "==Criador Equipas==" << endl;

	cout << "Nome da Equipa: " << endl;
	cin >> nome;

	cout << "Pais da Equipa: " << endl;
	cin >> pais;

	cout << "Patrocinador da Equipa: " << endl;
	cin >> pat;

	Equipa *e = new Equipa(nome, pais, pat);
	campeonato->inserirEquipa(*e);

	clearScreen();

}

void Menu::gerirEquipaMenu(){

	int input;

	cout << "1. Ver Equipas" << endl;
	cout << "2. Criar Equipa" << endl;
	cout << "3. Modificar Equipa" << endl;
	cout << "4. Apagar Equipa" << endl;
	cout << "5. Voltar atras" << endl;

	cin >> input;

	switch(input){

	case 1: clearScreen();
	verEquipas();
	gerirEquipaMenu();
	break;

	case 2: clearScreen();
	criaEquipaMenu();
	gerirEquipaMenu();
	break;

	case 3: clearScreen();
	modificaEquipaMenu();
	gerirEquipaMenu();
	break;

	case 4: clearScreen();
	apagaEquipaMenu();
	gerirEquipaMenu();
	break;

	case 5: clearScreen();
	mainMenu();
	break;

	default: break;
	}

}

void Menu::verEquipas(){
	campeonato->imprimeEquipas();
}

void Menu::modificaEquipaMenu(){

	int pos;
	string input;

	cout << "Insira o nome da equipa a alterar: " << endl;
	cin >> input;

	pos=campeonato->findEquipa(input);

	if(pos<0)
		throw EquipaInexistente(input);
	else{
		campeonato->getEquipas()[pos]->imprime();
		cout << "Insira o campo que pretende alterar: " << endl;
		cin >> input;

		if(input=="Nome" || input=="nome"){
			cout << "Insira o nome que pretende atribuir: " << endl;
			cin >> input;
			campeonato->getEquipas()[pos]->setNome(input);
		}
		else if(input=="Pais" || input=="pais"){
			cout << "Insira o pais que pretende atribuir: " << endl;
			cin >> input;
			campeonato->getEquipas()[pos]->setPais(input);
		}
		else if(input=="Patrocinador" || input=="patrocinador"){
			cout << "Insira o patrocinador que pretende atribuir: " << endl;
			cin >> input;
			campeonato->getEquipas()[pos]->setPatrocinador(input);
		}
		else if(input=="Pontuacao" || input=="pontuacao"){
			float pont;
			cout << "Insira a pontuacao que pretende atribuir: " << endl;
			cin >> pont;
			campeonato->getEquipas()[pos]->setPontuacao(pont);
		}
		else cout << "Campo invalido!" << endl;

	}
}

void Menu::apagaEquipaMenu(){

	string input;

	cout << "Insira o nome da equipa a eliminar: " << endl;
	cin >> input;

	if(campeonato->eliminarEquipa(input)){
		cout << "Equipa " << input << " eliminada com sucesso." << endl;
	}
	else cout << "Nao foi possivel apagar a equipa " << input << "." << endl;

}


/*
 * 	#ATLETAS
 */

void Menu::criaAtletaMenu(){
	info i;
	string equipa;

	cout << "==Criador Atletas==" << endl;

	cout << "Nome: " << endl;
	cin >> i.nome;

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

	Atleta *a = new Atleta();
	a->setInfo(i);
	a->setNEquipa(equipa);

	if(campeonato->findEquipa(equipa) > -1){
		campeonato->getEquipas()[campeonato->findEquipa(equipa)]->inserirAtleta(*a);
	}

	campeonato->inserirAtleta(*a);

	clearScreen();

}

void Menu::gerirAtletaMenu(){

	int input;

	cout << "1. Ver Atletas" << endl;
	cout << "2. Criar Atleta" << endl;
	cout << "3. Modificar Atleta" << endl;
	cout << "4. Apagar Atleta" << endl;
	cout << "5. Voltar atras" << endl;

	cin >> input;

	switch(input){

	case 1: clearScreen();
	verAtletas();
	gerirAtletaMenu();
	break;

	case 2: clearScreen();
	criaAtletaMenu();
	gerirAtletaMenu();
	break;

	case 3: clearScreen();
	modificaAtletaMenu();
	gerirAtletaMenu();
	break;

	case 4: clearScreen();
	apagaAtletaMenu();
	gerirAtletaMenu();
	break;

	case 5: clearScreen();
	mainMenu();
	break;

	default: gerirAtletaMenu();
	break;
	}

}

void Menu::verAtletas(){
	campeonato->imprimeAtletas();
}

void Menu::modificaAtletaMenu(){
	unsigned int id;
	int pos;
	string input;
	float input_numb;

	cout << "Insira o id do atleta a alterar: " << endl;
	cin >> id;

	pos=campeonato->findAtleta(id);

	if(pos<0)
		throw AtletaInexistente(id);
	else{
		campeonato->getAtletas()[pos]->imprime();
		cout << "Insira o campo que pretende alterar: " << endl;
		cin >> input;

		if(input=="Nome" || input=="nome"){
			cout << "Insira o nome que pretende atribuir: " << endl;
			cin >> input;
			campeonato->getAtletas()[pos]->setNome(input);
		}
		else if(input=="Pais" || input=="pais"){
			cout << "Insira o pais que pretende atribuir: " << endl;
			cin >> input;
			campeonato->getAtletas()[pos]->setPais(input);
		}
		else if(input=="Idade" || input=="idade"){
			cout << "Insira a idade que pretende atribuir: " << endl;
			cin >> input_numb;
			campeonato->getAtletas()[pos]->setIdade(input_numb);
		}
		else if(input=="Altura" || input=="altura"){
			cout << "Insira a altura que pretende atribuir (cm): " << endl;
			cin >> input_numb;
			campeonato->getAtletas()[pos]->setAltura(input_numb);
		}
		else if(input=="Peso" || input=="peso"){
			cout << "Insira o peso que pretende atribuir (kg): " << endl;
			cin >> input_numb;
			campeonato->getAtletas()[pos]->setPeso(input_numb);
		}
		else if(input=="Pontuacao" || input=="pontuacao"){
			cout << "Insira a pontuacao que pretende atribuir: " << endl;
			cin >> input_numb;
			campeonato->getAtletas()[pos]->setPontuacao(input_numb);
		}
		else if(input=="Equipa" || input=="equipa"){
			cout << "Insira o nome da equipa que pretende atribuir: " << endl;
			cin >> input;
			campeonato->getAtletas()[pos]->setNEquipa(input);
		}
		else cout << "Campo invalido!" << endl;

	}
}

void Menu::apagaAtletaMenu(){

	unsigned int id;

	cout << "Insira o id do atleta a eliminar: " << endl;
	cin >> id;

	if(campeonato->eliminarAtleta(id)){
		cout << "Atleta com id " << id << " eliminado com sucesso." << endl;
	}
	else cout << "Nao foi possivel apagar o atleta com id " << id << "." << endl;
}


/*
 * 	#PROVAS
 *
 */

void Menu::criaProvaMenu(){

	string input;
	unsigned int durac;
	Prova *p = new Prova();

	cout << "==Criador Provas==" << endl;

	cout << "Data: " << endl;
	cin >> input;
	//TODO convert string to date

	cout << "Local: " << endl;
	cin >> input;
	p->setLocal(input);

	cout << "Duracao: " << endl;
	cin >> durac;
	p->setDuracao(durac);

	cout << "Modalidade: " << endl;
	cin >> input;
	//TODO

	cout << "Equipas Adversarias: " << endl;
	cin >> input;
	//TODO

	campeonato->getCalendario()->inserirProva(*p);

	clearScreen();
}

void Menu::gerirProvaMenu(){

	int input;

	cout << "1. Ver Provas" << endl;
	cout << "2. Criar Prova" << endl;
	cout << "3. Modificar Prova" << endl;
	cout << "4. Apagar Prova" << endl;
	cout << "5. Voltar atras" << endl;

	cin >> input;

	switch(input){

	case 1: clearScreen();
	verProvas();
	gerirProvaMenu();
	break;

	case 2: clearScreen();
	criaProvaMenu();
	gerirProvaMenu();
	break;

	case 3: clearScreen();
	modificaProvaMenu();
	gerirProvaMenu();
	break;

	case 4: clearScreen();
	apagaProvaMenu();
	gerirProvaMenu();
	break;

	case 5: clearScreen();
	mainMenu();
	break;

	default: gerirAtletaMenu();
	break;
	}
}

void Menu::verProvas(){
	campeonato->getCalendario()->showProvas();
}

void Menu::modificaProvaMenu(){

	unsigned int aux;
	int pos;
	string input;

	cout << "Insira o id da prova a alterar: " << endl;
	cin >> aux;

	pos=campeonato->getCalendario()->findProva(aux);

	if(pos<0)
		throw ProvaInexistente(aux);
	else{
		campeonato->getCalendario()->showUmaProva(pos);
		cout << "Insira o campo que pretende alterar: " << endl;
		cin >> input;

		if(input=="Data" || input=="data"){
			cout << "Insira a data que pretende atribuir: " << endl;
			cin >> input;
			//TODO
			//campeonato->getCalendario()->getProvas()[pos]->setData();
		}
		else if(input=="Local" || input=="local"){
			cout << "Insira o local que pretende atribuir: " << endl;
			cin >> input;
			campeonato->getCalendario()->getProvaID(pos)->setLocal(input);
		}
		else if(input=="Modalidade" || input=="modalidade"){
			cout << "Insira a modalidade que pretende atribuir: " << endl;
			cin >> input;
			//TODO
			//campeonato->getCalendario()->getProvas()[pos]->setModalidade();
		}
		else if(input=="Duracao" || input=="duracao"){
			cout << "Insira a duracao que pretende atribuir: " << endl;
			cin >> aux;
			campeonato->getCalendario()->getProvaID(pos)->setDuracao(pos);
		}
		else cout << "Campo invalido!" << endl;

	}

}

void Menu::apagaProvaMenu(){

	unsigned int id;

	cout << "Insira o id da prova a eliminar: " << endl;
	cin >> id;

	if(campeonato->getCalendario()->findProva(id)<0)
		cout << "Prova com id " << id << " nao existe." << endl;
	else{
		campeonato->getCalendario()->eliminarProva(id);
		cout << "Prova com id " << id << " eliminada com sucesso." << endl;
	}

}


/*
 * CALENDARIO
 */

void Menu::calendarioMenu(){



	char input;

	while(input != 'n'){
		campeonato->getCalendario()->showProvas();
		cout << "Deseja simular a prova seguinte? (s/n) ";
		cin >> input;

		if(input == 's'){

			campeonato->realizarProva();

		}


		else if (input == 'n'){
			clearScreen();
			mainMenu();
		}
	}

}








void Menu::verClassificacoes(){
	campeonato->updateClassificacoes();

	priority_queue<Equipa*, vector<Equipa*>, ComparaEquipa> copia = campeonato->getClassificacao();

	while(!copia.empty()){
		Equipa* aux = copia.top();
		cout << aux->getNome() << " Ouro: " << aux->getMedalhas()[0] << " Prata: " << aux->getMedalhas()[1] << " Bronze: " << aux->getMedalhas()[2] << endl;
		copia.pop();
	}
}

/*
 * 	#ADEPTOS
 *
 */

void Menu::criaAdeptoMenu(){
	string nome, email, equipa;

	cout << "==Criador Adepto==" << endl;

	cout << "Nome: " << endl;
	cin.ignore();
	getline(cin, nome);

	cout << "Email: " << endl;
	cin >> email;

	cout << "Equipa preferida: " << endl;
	cin >> equipa;


	Adepto *ad = new Adepto(nome, email, equipa);


	campeonato->inserirAdepto(*ad);

	clearScreen();

}


void Menu::registarAdepto() {

	string nResposta;

	cin >> nResposta;
	if(nResposta == "Sim" || nResposta == "S" || nResposta == "sim" ||
			nResposta == "s"){
		clearScreen();
		criaAdeptoMenu();
		espacoAdeptoMenu();
	}
	else if(nResposta == "Nao" || nResposta == "N" || nResposta == "nao" ||
			nResposta == "n")
	{
		clearScreen();
		espacoAdeptoMenu();
	}
	else{
		cout << "Resposta Invalida. Tente Novamente ";
		registarAdepto();
	}

}

void Menu::vendaBilhete() {


	int id, pos;
	cout << "===VENDA DE BILHETES===" << endl;
	cout << endl;

	cout << "ID do Adepto que pretende efectuar uma venda: ";
	cin >> id;

	pos=campeonato->findAdepto(id);
	cout << pos;

	if(pos<0)
		throw AdeptoInexistente(id);
	else{

		campeonato->venderBilhete(id);
	}

}

void Menu::compraBilhete() {

	int id, pos;

	cout << "===COMPRA DE BILHETES===" << endl;
	cout << endl;

	cout << "ID do Adepto que pretende efectuar uma compra: ";
	cin >> id;

	pos=campeonato->findAdepto(id);

	if(pos<0){
		cout << "Adepto nao existe! Deseja realizar um registo? " << endl;

		registarAdepto();

	}

	else{


		cout << endl;
		campeonato->comprarBilhete(id);
	}



}

void Menu::compraProvaMenu() {

	int idProva;

	cout << "Qual a prova que deseja adquirir: ";
	cin >> idProva;


}

void Menu::espacoAdeptoMenu(){

	int input;
	int id;

	cout << "==Espaco Adepto==" << endl;

	cout << "1. Comprar Prova" << endl;
	cout << "2. Mostrar Bilhetes" << endl;
	cout << "3. Mostrar adeptos" << endl;
	cout << "4. Efectuar venda de bilhete" << endl;
	cout << "5. Efectuar compra de bilhete" << endl;
	cout << "6. Menu Anterior" << endl;
	cout << endl;

	cin >> input;

	switch(input){

	case 1:
		clearScreen();
		campeonato->imprimeAdeptos();
		cout << endl;
		cout <<"ID do adepto que pretende comprar um bilhete: ";
		cin >> id;
		cout << endl;
		verProvas();
		campeonato->comprarProva(id);
		espacoAdeptoMenu();
		break;
	case 2:
		clearScreen();
		campeonato->imprimeBilhetes();
		cout << endl;
		espacoAdeptoMenu();
		break;
	case 3:
		campeonato->imprimeAdeptos();
		cout << endl;
		espacoAdeptoMenu();
		break;
	case 4:
		clearScreen();
		compraBilhete();
		espacoAdeptoMenu();
		break;
	case 5:
		clearScreen();
		campeonato->imprimeAdeptos();
		cout << endl;
		cout <<"ID do adepto que pretende comprar um bilhete: ";
		cin >> id;
		cout << endl;
		campeonato->imprimeBilhetes();
		campeonato->comprarBilhete(id);
		espacoAdeptoMenu();
		break;
	case 6:
		clearScreen();
		mainMenu();

	default:
		espacoAdeptoMenu();
		break;
	}

}


/*
 * 	#
 */


void Menu::clearScreen(){
	cout << string(50, '\n');
}






/*void Calendario::removeProva(){
	unsigned int n;
	cout << endl << "ID da prova a remover(0 para cancelar): ";
	cin >> n;

	if(n == 0)
		return;
	else if(n > provas.size() || n < 0){
		cout << endl  << "Prova nao encontrada!" << endl;
		return;
	}
	provas.erase(provas.begin()+n);
}

void Calendario::criaProvas(Campeonato &c1){

	cout << "Criador de Provas!" << endl;

	vector<Equipa*> vs;

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

			/*for (unsigned int i = 0; i < getModalidades().size(); i++){
				if(getModalidades()[i] == modN)
					boaMod = true;*/
/*			boaMod = true;

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

			// Equipa 1
			string nEquipa;
			bool boaEquipa = false;
			while(!boaEquipa){

				cout << "Nome da primeira equipa a participar: ";
				cin.ignore();
				getline(cin, nEquipa);

				int find;
				find = c1.findEquipa(nEquipa);

				if(find != -1){

					boaEquipa = true;
				}
				else{
					cout << "Equipa nao encontrada!" << endl;
				}
			}
			vs.push_back(c1.getEquipas()[c1.findEquipa(nEquipa)]);

			boaEquipa = false;

			while (!atletaEncontrado){

				cout << "Nome do atleta da equipa " << nEquipa <<": ";

				cin.ignore();
				getline(cin,nAtleta);


				for(unsigned int i = 0; i < c1.getAtletas().size(); i++){
					if (c1.getAtletas()[i]->getNome() == nAtleta){
						atletaEncontrado = true;
						break;
					}
				}

				if (!atletaEncontrado)
					cout << "Atleta nao encontrado!" << endl;

			}
			atletaEncontrado = false;

			// Equipa 2

			while(!boaEquipa){
				cout << "Nome da segunda equipa a participar: ";
				cin.ignore();
				getline(cin,nEquipa);
				int find;
				find = c1.findEquipa(nEquipa);

				if(find != -1){
					boaEquipa = true;
				}
				else{
					cout << "Equipa nao encontrada!" << endl;
				}
			}


			vs.push_back(c1.getEquipas()[c1.findEquipa(nEquipa)]);

			while (!atletaEncontrado){

				cout << "Nome do atleta da equipa " << nEquipa <<": ";
				cin.ignore();
				getline(cin,nAtleta);

				for(unsigned int i = 0; i < c1.getAtletas().size(); i++){
					if (c1.getAtletas()[i]->getNome() == nAtleta){
						atletaEncontrado = true;
						break;
					}
				}

				if (!atletaEncontrado)
					cout << "Atleta nao encontrado!" << endl;

			}




			Modalidade *m = new Modalidade(modN,0);
			Prova* p1= new Prova(d1,local, min, vs,m);



			if(inserirProva(*p1)){
				cout << "Prova adicionada com sucesso!!" << endl;
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
			/*if(input != "S" || input !="N" || input !="s" ||input !="n")
				cout << "Input invalido." << endl;
			else*/
/*	bomInput =true;
		}
	}

}*/
