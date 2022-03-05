/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * module3.cpp
 * The program reads in the arithmetic expression and encodes the expression as a binary tree.
 * After the expression has been read in, the variable assignments are read in and the variables
 * and their values of the variables are placed into the symbol table. Finally the expression is evaluated recursively
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
#include "binarytree.h"
#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"
#include "input.h"

SymbolTable symbolTable;
void parseAssignments();

int main()
{
	Expression* expression;
	/*Input in;
	in.getFileInput();
	in.getExpressions();*/

	/*for (int i = 0; i < in.getAmountOfExpressions; i++) {
		cin >> in.stringToChar(in.getAnExpression());
		expression = SubExpression::parse();
		cout << "Value = " << expression->evaluate() << endl;
	}*/
	char paren, comma;
	cout << "Enter expression: ";
	cin >> paren;
	expression = SubExpression::parse();
	cin >> comma;
	parseAssignments();
	cout << "Value = " << expression->evaluate() << endl;
	return 0;
}

void parseAssignments()
{
	char assignop, delimiter;
	string variable;
	int value;
	do
	{
		variable = parseName();
		cin >> ws >> assignop >> value >> delimiter;
		symbolTable.insert(variable, value);
	} while (delimiter == ',');
}




		