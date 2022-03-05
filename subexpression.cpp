/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * subexpression.cpp
 * The program reads in the arithmetic expression and encodes the expression as a binary tree.
 * After the expression has been read in, the variable assignments are read in and the variables
 * and their values of the variables are placed into the symbol table. Finally the expression is evaluated recursively
*/


#include <iostream>
using namespace std;
#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "more.h"
#include "less.h"
#include "equal.h"
#include "and.h"
#include "or.h"
#include "condition.h"
#include "not.h"

SubExpression::SubExpression(Expression* left)
{
	this->left = left;
}

SubExpression::SubExpression(Expression* left, Expression* right)
{
	this->left = left;
	this->right = right;
}

SubExpression::SubExpression(Expression* left, Expression* right, Expression* condition)
{
	this->left = left;
	this->right = right;
	this->condition = condition;
}

Expression* SubExpression::parse()
{
	Expression* left;
	Expression* right;
	char operation, paren;

	left = Operand::parse();
	cin >> operation;
	right = Operand::parse();
	cin >> paren;
	switch (operation)
	{
	case '+':
		return new Plus(left, right);
	case '-':
		return new Minus(left, right);
	case '*':
		return new Times(left, right);
	case '/':
		return new Divide(left, right);
	case '&':
		return new And(left,right);
	case '|':
		return new Or(left, right);
	case '=':
		return new Equal(left, right);
	case '>':
		return new More(left, right);
	case '<':
		return new Less(left, right);
	case '!':
		return new Not(left);
	case ':':
		Expression* condition = Operand::parse();
		return new Condition(left, right, condition);
	}
	return 0;
}