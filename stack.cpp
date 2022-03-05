/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * stack.cpp
 * Stack is used to store file input.Stack using templates,The program reads in the arithmetic expression and encodes the expression as a binary tree.
 * After the expression has been read in, the variable assignments are read in and the variables
 * and their values of the variables are placed into the symbol table. Finally the expression is evaluated recursively
*/
#include <iostream>
#include <string>
#include "stack.h"
#include "expression.h"
#include "subexpression.h"
//  
template <class T> 
void Stack<T>::push(const T &value) {
	if (isFull()) {
		cout << "The stack is full." << endl;
	}

	else
	{
		top++;
		stackArray[top] = value;
	}
}

template <class T>
 T Stack<T>::pop(){
	T temp;

	if (isEmpty()) {
		cout << "The stack is empty" << endl;
	}

	else {
		temp = stackArray[top];
		top--;
	}
	return temp;
}

template <class T> 
bool Stack<T>::isFull() const {
	bool status;

	if (top == stackSize - 1)
		status = true;
	else
		status = false;

	return status;
}

template <class T> 
bool Stack<T>::isEmpty() const {
	bool status;

	if (top == -1)
		status = true;
	else
		status = false;

	return status;
}

template class Stack<string>;


