#include    <iostream>
#include    <iomanip>
#include    <string>
using namespace std;

typedef string stack_element;

#ifndef     STACK_h

class SNode
{
	public:
		stack_element data;
		SNode *next;
};

class Stack
{
	public:
		Stack();
		Stack(const Stack &);
		~Stack();
		stack_element & top();
		void pop();
		void push(const stack_element &);
		void print();
	private:
		SNode *s_top;
};

#endif