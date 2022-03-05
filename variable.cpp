/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * variable.cpp
 * The arithmetic expressions are fully parenthesized infix expressions
 * containing integer literals and variables.
*/
#include <strstream>
#include <vector>
using namespace std;

#include "expression.h"
#include "operand.h"
#include "variable.h"
#include "symboltable.h"

extern SymbolTable symbolTable;

int Variable::evaluate()
{
	return symbolTable.lookUp(name);
}