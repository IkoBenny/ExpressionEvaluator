/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * operand.cpp
 * The program reads in the arithmetic expression and encodes the expression as a binary tree.
 * After the expression has been read in, the variable assignments are read in and the variables
 * and their values of the variables are placed into the symbol table. Finally the expression is evaluated recursively
*/

#include <cctype>
#include <iostream>
#include <list>
#include <string>
using namespace std;
#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse()
{
	char paren;
	int value;

	cin >> ws;
	if (isdigit(cin.peek()))
	{
		cin >> value;
		Expression* literal = new Literal(value);
		return literal;
	}
	if (cin.peek() == '(')
	{
		cin >> paren;
		return SubExpression::parse();
	}
	else
		return new Variable(parseName());
	return 0;
}