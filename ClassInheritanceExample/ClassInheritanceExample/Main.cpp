#include    "Mallard.h"
#include    "RubberDuck.h"
#include    "DecoyDuck.h"
#include    "MotorizedDuck.h"

int main()
{
    Duck *duck[4];

    duck[0] = new Mallard( "brownish/green" );
    duck[1] = new RubberDuck( "yellow" );
    duck[2] = new DecoyDuck( "brown/black" );
    duck[3] = new MotorizedDuck( "blue/silver" );

    for( int i = 0; i < 4; ++i )
    {
        cout << "\n" << *duck[i];

        duck[i]->fly();
        duck[i]->quack();
        duck[i]->swim();

        delete duck[i];
    }

    return 0;
}
