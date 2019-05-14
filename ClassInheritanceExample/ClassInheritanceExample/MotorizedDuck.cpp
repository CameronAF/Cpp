#include "MotorizedDuck.h"

//MotorizedDuck constructor - since there is no data in MotorizedDuck it calls to duck constructor
MotorizedDuck::MotorizedDuck(const char *color) : Duck("MotorizedDuck", *&color)
{
}

//MotorizedDuck destructor - since there is no data in MotorizedDuck it calls to duck destructor
MotorizedDuck::~MotorizedDuck()
{
	cout << "about to delete '" << _name << "',  '" << _color << "'\n";
}

// MotorizedDuck fly function -  displays MotorizedDuck fly capabilities
void MotorizedDuck::fly()
{
	cout << "I'm a '" << _name << "' and I fly w/ jet engine propulsion\n";
}

// MotorizedDuck quack function -  displays MotorizedDuck sounds
void MotorizedDuck::quack()
{
	cout << "I'm a '" << _name << "' and I sound like a Pratt & Whitney jet engine\n";
}