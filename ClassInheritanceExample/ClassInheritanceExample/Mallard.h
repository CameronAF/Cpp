#pragma once
#include "Duck.h"

//Mallard inherited from duck
class Mallard : public Duck
{
	public:
		Mallard(const char *);				//constructor
		~Mallard();							//destructor
		void fly();							//fly function
		void quack();						// quack function
};

