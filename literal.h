/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * literal.h
 * Literal specification. The arithmetic expressions are fully parenthesized infix expressions
 * containing integer literals and variables.
*/

#pragma once
class Literal : public Operand
{
public:
	Literal(int value)
	{
		this->value = value;
	}
	int evaluate()
	{
		return value;
	}
private:
	int value;
};