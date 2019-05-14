#pragma once
#include "Duck.h"

//MotorizedDuck inherited from duck 
class MotorizedDuck : public Duck
{
	public:
		MotorizedDuck(const char *);		//constructor
		~MotorizedDuck();					//destructor
		void fly();							//fly function
		void quack();						// quack function
};

