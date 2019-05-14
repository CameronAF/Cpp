#include "Mallard.h"

//mallard constructor - since there is no data in mallard it calls to duck constructor
Mallard::Mallard(const char *color) : Duck("Mallard", *&color)
{
}

//Mallard destructor - since there is no data in mallard it calls to duck destructor
Mallard::~Mallard()
{
	cout << "about to delete '" << _name << "',  '" << _color << "'\n";
}

// Mallard fly function -  displays Mallards fly capabilities
void Mallard::fly()
{
	cout << "I'm a '" << _name << "' and I fly\n";
}

// Mallard quack function -  displays Mallards sounds
void Mallard::quack()
{
	cout << "I'm a '" << _name << "' and I quack\n";
}