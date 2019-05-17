#include    <iostream>
#include    <iomanip>
using namespace std;


class Stack
{
  public:
    Stack( int );           // constructor
    Stack( const Stack & ); // constructor
    ~Stack( );              // destructor

    void push( int );       // push an int into a Stack
    int  pop( );            // pop an int from a Stack

    bool empty( ) const;    // is the Stack empty?
    bool full( ) const;     // is the Stack full?

    int capacity( ) const;  // capacity of the stack
    int size( ) const;      // current size of the stack

    friend ostream &operator <<( ostream &, const Stack & );

  private:
    int *stack;             // pointer to local stack of ints

    int top;                // top of stack (next avail. loc.)
    int maxsize;            // max size of the stack
};

