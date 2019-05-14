#include "DecoyDuck.h"

//DecoyDuck constructor - since there is no data in DecoyDuck it calls to duck constructor
DecoyDuck::DecoyDuck(const char *color) : Duck("DecoyDuck", *&color)
{
}

//DecoyDuck destructor - since there is no data in DecoyDuck it calls to duck destructor
DecoyDuck::~DecoyDuck()
{
	cout << "about to delete '" << _name << "',  '" << _color << "'\n";
}

// DecoyDuck fly function -  displays DecoyDuck fly capabilities
void DecoyDuck::fly()
{
	cout << "I'm a '" << _name << "' and I do NOT fly\n";
}

// DecoyDuck quack function -  displays DecoyDuck sounds
void DecoyDuck::quack()
{
	cout << "I'm a '" << _name << "' and I'm silent\n";
}