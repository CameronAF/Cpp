#include    <iostream>
#include    <iomanip>
#include    <vector>
using namespace std;

#include    "Stack.h"

Stack::Stack( int max )      // constructor
{
    cout << "in Stack::Stack( " << max << " )\n";
    maxsize = max;
    stack   = new int[ maxsize ];
    top     = 0;            // top of stack is at index 0
}                           // stack is empty

Stack::Stack( const Stack &s )
{
    maxsize = s.maxsize;
                            // allocate stack for left side object
    stack = new int[ maxsize ];
                            // now copy right side object to left side object
    for( int i = 0; i < maxsize; ++i )
    {
        stack[ i ] = s.stack[ i ];
    }
	top = s.top;
}

Stack::~Stack( )     // destructor
{
    cout << "Stack::~Stack( )\n";
    delete [ ] stack;		// remember current pointer
}

void Stack::push( int i )   // push an int into a Stack
{
    if( ! full( ) )
    {
        cout << "push( " << i << " )\t at location "
             << top << '\n';
        stack[ top ] = i;
        ++top;              // advance to the next empty location
    }
}

int Stack::pop( )           // pop an int from a Stack
{
    if( empty( ) )
    {
        return -1;          // stack is empty; return -1
    }
    else
    {
        --top;
        cout << "pop( ) " << stack[ top ]
             << " at location " << top << '\n';
                            // return item at top of the stack
        return stack[ top ];
    }
}

                            // true if the stack is empty
bool Stack::empty( ) const
{
    return top <= 0 ? true : false;
}

							// true if the stack is full
bool Stack::full( ) const
{
    return top >= maxsize;
}                          // stack is empty


                            // current size of the stack
int Stack::size( ) const
{
    return top;
}

                            // operator << for a Stack object
ostream &operator <<( ostream &out, const Stack &s )
{
    for( int i = s.size( ) - 1; i >= 0; --i )
    {
        out << setw( 3 ) << i << setw( 5 ) << s.stack[ i ] << '\n';
    }

    return out;
}


