/*
#ifndef SRC_LOGIC_LISTS_H_
#define SRC_LOGIC_LISTS_H_


#include "Lists.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <sstream>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_ESC 27
using namespace std;


void gotoxy(int x, int y);


int wherey();


template <class T>
int fazMenu(string titulo, vector<T*> options);


template <class T>
int fazMenu(string titulo, vector<T> options);


template <class T>
int fazMenu(string titulo, vector<T*> options, string Op1);


template <class T>
int search(const vector<T*> &v, T x);



//Menu implementation
template <class T>
int fazMenu(string titulo, vector<T*> options){
	cout << titulo << endl;
	int inicio = wherey();
	for (int i = 0; i < options.size(); i++)
		cout << "   " << (*options[i]) << endl;
	gotoxy(0, inicio);
	int op(0);

	while (true)
	{
		gotoxy(0, inicio + op);
		cout << "->";
		gotoxy(0, inicio + op);

		switch (_getch())
		{
		case KEY_ESC:
			return -1;
			break;
		case KEY_UP:
			if (op > 0)
				op--;
			break;
		case KEY_DOWN:
			if (op < options.size()-1)
				op++;
			break;
		case KEY_ENTER:
			return op;
			break;
		default:
			break;
		}

		cout << "  ";

	}
}

template <class T>
int fazMenu(string titulo, vector<T> options){
	cout << titulo << endl;
	int inicio = wherey();
	for (int i = 0; i < options.size(); i++)
		cout << "   " << (options[i]) << endl;
	gotoxy(0, inicio);
	int op(0);

	while (true)
	{
		gotoxy(0, inicio + op);
		cout << "->";
		gotoxy(0, inicio + op);

		switch (_getch())
		{
		case KEY_ESC:
			return -1;
			break;
		case KEY_UP:
			if (op > 0)
				op--;
			break;
		case KEY_DOWN:
			if (op < options.size()-1)
				op++;
			break;
		case KEY_ENTER:
			return op;
			break;
		default:
			break;
		}

		cout << "  ";

	}
}

template <class T>
int fazMenu(string titulo, vector<T*> options, string Op1){
	cout << titulo << endl;
	int inicio = wherey();
	for (int i = 0; i < options.size(); i++)
		cout << "   " << (*options[i]) << endl;
	cout << "   " << Op1 << endl;
	gotoxy(0, inicio);
	int op(0);

	while (true)
	{
		gotoxy(0, inicio + op);
		cout << "->";
		gotoxy(0, inicio + op);

		switch (_getch())
		{
		case KEY_ESC:
			return -1;
			break;
		case KEY_UP:
			if (op > 0)
				op--;
			break;
		case KEY_DOWN:
			if (op < options.size())
				op++;
			break;
		case KEY_ENTER:
			return op;
			break;
		default:
			break;
		}

		cout << "  ";

	}
}

template <class T>
int search(const vector<T*> &v, T x)
{
    for (unsigned int i = 0; i < v.size(); i++)
        if ((*v[i]) == x)
           return i;
    return -1;
}

inline string &tirar_espacos_fim(string &s) {
	s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
	return s;
}

bool comparar_strings(string s1, string s2);

string int_to_string(int i);

bool ficheiroExiste(const string &ficheiro);

class FicheiroInexistente
{
	string nome;
public:
	FicheiroInexistente() {}
	FicheiroInexistente(string n) : nome(n) {}
	string getNome() { return nome; }
};

class LoadFail
{
	string nome;
public:
	LoadFail() {}
	LoadFail(string n) : nome(n) {}
	string getNome() { return nome; }
};

class LoadProvasFail{
public:
	virtual string getMessage() const = 0;
	virtual ~LoadProvasFail() {}
};

class CaraterInvalido{
public:
	char c;
	CaraterInvalido(char ch) {c = ch;}
	char getChar()
	{
		return c;
	}
};

class generoErrado{
public:
	char g_prova;
	string atleta;
	generoErrado(char g, string a) : g_prova(g), atleta(a) {}
	char getGeneroProva()
	{
		return g_prova;
	}
	string getAtleta(){
		return atleta;
	}
};



#endif /* SRC_LOGIC_LISTS_H_ */

