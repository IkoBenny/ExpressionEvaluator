/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * input.h
 * Specification file for Input Class. This class Statements of the expression language 
 * consist of an arithmetic expression followed by a list of assignments. 
 * Assignments are separated from the expression and each other by commas. 
 * A semicolon terminates the expression. The arithmetic expressions are 
 * fully parenthesized infix expressions containing integer literals and variables.
 * This class reads in the arithmetic expression. Variable assignments are read in
 * and the variables and their values of the variables are placed into the symbol table.
 * The program should accept input from a file, allowing for multiple expressions arranged one per line.*/

#pragma once
#include <string>
#include "stack.h"
class Input {
public:
	static char* stringToChar(string&);
	void popStackContents();
	int getAmountOfExpressions();
	void getCommas();
	string& getAnExpression();
	void getExpressions();
	void getFileInput();
	int getFirstCommaPositionAfterSemiColon(int);
	void getSemiColons();
	Input() {}
	Stack<string> expressions;
private:
	string lines;
	static const int SIZE = 500;
	int commaLocations[SIZE];
	int commaLocationsPointer;
	int semiColonLocations[SIZE];
	int semiColonLocationsPointer;
};