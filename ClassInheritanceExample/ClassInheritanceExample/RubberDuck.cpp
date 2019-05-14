#include "RubberDuck.h"

//RubberDuck constructor - since there is no data in RubberDuck it calls to duck constructor
RubberDuck::RubberDuck(const char *color) : Duck("RubberDuck", *&color)
{
}

//RubberDuck destructor - since there is no data in RubberDuck it calls to duck destructor
RubberDuck::~RubberDuck()
{
	cout << "about to delete '" << _name << "',  '" << _color << "'\n";
}

// RubberDuck fly function -  displays RubberDuck fly capabilities
void RubberDuck::fly()
{
	cout << "I'm a '" << _name << "' and I do NOT fly\n";
}

// RubberDuck quack function -  displays RubberDuck sounds
void RubberDuck::quack()
{
	cout << "I'm a '" << _name << "' and I squeak\n";
}