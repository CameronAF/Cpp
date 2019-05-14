#pragma once
#include "Duck.h"

//DecoyDuck inherited from duck 
class DecoyDuck : public Duck
{
	public:
		DecoyDuck(const char *);			//constructor
		~DecoyDuck();						//destructor
		void fly();							//fly function
		void quack();						// quack function
};

