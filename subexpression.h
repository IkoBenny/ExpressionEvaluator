/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * subexpression.cpp
 * The program reads in the arithmetic expression and encodes the expression as a binary tree.
 * After the expression has been read in, the variable assignments are read in and the variables
 * and their values of the variables are placed into the symbol table. Finally the expression is evaluated recursively
*/
#include "expression.h"
#pragma once
class SubExpression : public Expression
{
public:
	SubExpression(Expression* left);
	SubExpression(Expression* left, Expression* right);
	SubExpression(Expression* left, Expression* right, Expression* condition);
	static Expression* parse();
protected:
	Expression* left;
	Expression* right;
	Expression* condition;
};