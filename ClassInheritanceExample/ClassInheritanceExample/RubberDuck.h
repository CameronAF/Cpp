#pragma once
#include "Duck.h"

//RubberDuck inherited from duck
class RubberDuck : public Duck
{
	public:
		RubberDuck(const char *);			//constructor
		~RubberDuck();						//destructor
		void fly();							//fly function
		void quack();						// quack function
};

