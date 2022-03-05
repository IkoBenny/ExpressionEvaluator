/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * input.cpp
 * This class handles file operations,Getting lines, and filename.
 * The program should accept input from a file, allowing for multiple expressions arranged one per line.*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
#include "input.h"
#include "stack.h"

	//returns total amount of Expressions in file
	int Input::getAmountOfExpressions()
{
		int count = 0;
		for (int i = 0; i < commaLocations[i]; i++)
			++count;
		return count;
}
	//returns last expression on stack
	string& Input::getAnExpression() {
		string temp = expressions.pop();
		return temp;
	}
	//stores locations of all assignment variables
	void Input::getCommas()
	{
		//loop input to save where all expressions end and all assignments begin
		for (int i = 0; i < lines.size(); i++) {
			if (lines.at(i) == ',') {
				commaLocations[commaLocationsPointer++] = i;
			}
		}
	}
	//gets lines of input from file and saves it to a string
	void Input::getExpressions() {
		//gets first expression from the file and pushes on stack
		int s = semiColonLocations[0];
		int c = commaLocations[0];
		int argument1 = 0;
		int argument2 = 0;
		string exp = lines.substr(0, c);
		expressions.push(exp);
		for (int i = 0; i < semiColonLocationsPointer; i++) {
			//gets next  and subsequent expressions
			s = semiColonLocations[i];
			c = getFirstCommaPositionAfterSemiColon(s);
			argument1 = s + 1;
			argument2 = (c - 1) - s;
			exp = lines.substr(argument1, argument2);
			expressions.push(exp);
		}
	}
	//gets input from file and assigns to a string
	void Input::getFileInput() {
		fstream inputFile;
		string filename;
		char input[SIZE];

		//prompt user for filename
		cout << "Enter a file name with no quotations, like this-> input.txt: ";
		cin >> filename;

		//open file in input mode
		inputFile.open(filename, ios::in);
		if (!inputFile) {
			cout << "ERROR:Cannot open file.\n";
		}

		//get a line from the file
		inputFile.getline(input, SIZE, ';');
		lines.assign(input);


		while (!inputFile.eof()) {
			//while there are more lines continue...
			lines.append(";");
			inputFile.getline(input, SIZE, ';');
			lines.append(input);
		}

		//close the file
		inputFile.close();
		getSemiColons();
		getCommas();
	}
	//helper function to get an expression
	int Input::getFirstCommaPositionAfterSemiColon(int value)
	{
		int position = 0;
		//find first comma location after the last semicolon
		for (int i = 0; i < commaLocationsPointer; i++)
			if (commaLocations[i] > value) {
				position = commaLocations[i];
				break;
			}
		return position;
	}
	//helper function to get variables
	void Input::getSemiColons() {
		//loop input to save where all expressions end
		for (int i = 0; i < lines.size(); i++) {
			if (lines.at(i) == ';') {
				semiColonLocations[semiColonLocationsPointer++] = i;
			}
		}

	}
	//pops all contents of stack
	void Input::popStackContents() {
		while (!expressions.isEmpty()) {
			cout << expressions.pop();
		}
	}
	//turns a string into a char
	char* Input::stringToChar(string& s) {
			vector<char> v(s.size() + 1);
			memcpy(&v.front(), s.c_str(), s.size() + 1);
			char* c = v.data();
			return c;
	}

