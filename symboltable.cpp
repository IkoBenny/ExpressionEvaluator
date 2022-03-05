/*/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * symboltable.cpp
 * Variable names begin with an alphabetic character,
  followed by any number of alphanumeric characters.
  Variable names are case sensitive.This syntax
  is described by BNF and regular expressions in the case study.*/
#include <string> 
#include <vector> 
using namespace std;
#include "symboltable.h"

void SymbolTable::insert(string variable, int value)
{
	const Symbol& symbol = Symbol(variable, value);
	elements.push_back(symbol);
}

int SymbolTable::lookUp(string variable) const
{
	for (int i = 0; i < elements.size(); i++)
		if (elements[i].variable == variable)
			return elements[i].value;
	return -1;
}