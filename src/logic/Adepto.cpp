#include "Adepto.h"

using namespace std;

int Adepto::newID = 0;

Adepto::Adepto(string n, string mail, string nEq): uid(newID++){

	nome = n;
	email = mail;
	nEquipa = nEq;
	//equipa == e1;

}

Adepto::Adepto(string n) {

	nome = n;
}

Adepto::Adepto(){

}



unsigned int Adepto::getID() const{
	return uid;
}

string Adepto::getNome() const{
	return nome;
}

void Adepto::setNome(string n){
	nome = n;
}

string Adepto::getEquipa() const{
	return nEquipa;
}

void Adepto::setEquipa(string nEq){

	nEquipa = nEq;
}

string Adepto::getEmail() const{
	return email;
}

void Adepto::setEmail(string novoEmail){
	email = novoEmail;
}



void Adepto::imprime() const{
	cout << endl;
	cout << "ID: " << uid << endl;
	cout << "Nome: " << nome << endl;
	cout << "Email: " << email << endl;
	cout << "Equipa: " << nEquipa << endl;
	cout << endl;
}







