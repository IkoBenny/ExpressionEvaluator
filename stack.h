/*Benny Iko
 * 5/3/2020
 * Advanced Programming Languages
 * CMSC 330 7981
 * stack.h
 * Stack would be used for binary tree construction, and to hold input from file
*/
#pragma once
#include <string>
#ifndef Stack_H
#define Stack_H
using namespace std;

template <class T>
class Stack
{
	private:
		T *stackArray;
		int stackSize = 200;
		int top =-1;

	public:
		
		Stack() {
			stackArray = new T[stackSize];
		}

		~Stack() {
			delete[] stackArray;
		}
		
		Stack(int size) {
			stackSize = size;
			stackArray = new T[stackSize];
		}

		bool isEmpty() const;
		bool isFull() const;
		T pop();
		void push(const T&);

};
#endif // !Stack

