#ifndef     _DUCKS_H
#define     _DUCKS_H

#define _CRT_SECURE_NO_WARNINGS
#include    <iostream>
using namespace std;

// parent class
class Duck
{
	public:
		Duck(const char *, const char *);		//constructor
		virtual ~Duck();						//destructor
		virtual void swim();					//will always be called 
		virtual void fly();						//should never be called
		virtual void quack();					//should never be called
		friend ostream &operator <<(ostream &out, const Duck &read);

	protected:
		char *_name;
		char *_color;
};

#endif
