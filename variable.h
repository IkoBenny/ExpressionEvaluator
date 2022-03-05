/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * variable.h
 * The arithmetic expressions are fully parenthesized infix expressions
 * containing integer literals and variables.
*/
#pragma once
class Variable : public Operand
{
public:
	Variable(string name)
	{
		this->name = name;
	}
	int evaluate();
private:
	string name;
};