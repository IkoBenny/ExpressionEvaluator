/*/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * symboltable.h
 * Variable names begin with an alphabetic character, 
  followed by any number of alphanumeric characters.
  Variable names are case sensitive.This syntax 
  is described by BNF and regular expressions in the case study.*/

#pragma once
class SymbolTable
{
public:
	SymbolTable() {}
	void insert(string variable, int value);
	int lookUp(string variable) const;
private:
	struct Symbol
	{
		Symbol(string variable, int value)
		{
			this->variable = variable;
			this->value = value;
		}
		string variable;
		int value;
	};
	vector <Symbol> elements;
};