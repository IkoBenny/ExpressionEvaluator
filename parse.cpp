/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * parse.cpp
 * The program reads in the arithmetic expression and encodes the expression as a binary tree.
 * After the expression has been read in, the variable assignments are read in and the variables
 * and their values of the variables are placed into the symbol table. Finally the expression is evaluated recursively
*/
#include <cctype> 
#include <iostream> 
#include <string> 
using namespace std;

#include "parse.h"

string parseName()
{
	char alnum;
	string name = "";

	cin >> ws;
	while (isalnum(cin.peek()))
	{
		cin >> alnum;
		name += alnum;
	}
	return name;
}