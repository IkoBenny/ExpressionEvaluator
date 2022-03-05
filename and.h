/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * and.h
 * The arithmetic expressions are fully parenthesized infix expressions containing 
 * integer literals and variables. The valid arithmetic operators are +, –, *, /. 
 * Tokens can be separated by any number of spaces.Extended the program so that it 
 * supports relational, logical and conditional expression operators
*/

#pragma once
class And : public SubExpression
{
public:
	And(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() && right->evaluate();
	}
};