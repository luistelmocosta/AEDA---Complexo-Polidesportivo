/*
#include "Lists.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;


void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int wherey()
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   return csbi.dwCursorPosition.Y;
}

string remove_spaces(string input)
{
  input.erase(std::remove(input.begin(),input.end(),' '),input.end());
  return input;
}

bool comparar_strings(string s1, string s2)
{

	for(unsigned int i = 0; i < s1.size(); i++)
		s1[i] = toupper(s1[i]);

	for(unsigned int i = 0; i < s2.size(); i++)
		s2[i] = toupper(s2[i]);

	if (s1 == s2)
		return true;
	else return false;
}

string int_to_string(int n)
{
ostringstream outstr;
outstr << n;
return outstr.str();
}

*/
