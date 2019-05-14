#include	"Duck.h"

//Duck Methods
//duck construuctor
Duck::Duck(const char *name, const char *color)
{
	_name = new char[strlen(name) + 1];			//initialize name
	strcpy(_name, name);
	_color = new char[strlen(color) + 1];		//initialize type
	strcpy(_color, color);
}

//Duck destructer
Duck::~Duck()
{
	delete[] _name;
	delete[] _color;
}

//duck swim function - should always be called
void Duck::swim()
{
	cout << "I'm a '" << _name << "' duck and all ducks float\n";
}

//duck fly function -should never get called
void Duck::fly()
{
	cout << "No information is avalable\n";
}

//duck quack function - should never get called
void Duck::quack()
{
	cout << "No information is avalable\n";
}

//output name and color
ostream &operator <<(ostream &out, const Duck &read)
{
	out << "\n" << read._name << ",  " << read._color << "\n";
	return out;
}
