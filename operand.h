/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * operand.h
 * The arithmetic expressions are fully parenthesized infix expressions
 * containing integer literals and variables.
*/
#pragma once
#include "pch.h"
class Operand : public Expression
{
public:
	static Expression* parse();
};