#include    "Stack.h"

int main( )
{
    Stack s( 2 );           // create stack with space for 3 ints
    s.push( 10 );
    s.push( 20 );
    s.push( 30 );           // pushing one int too many
    cout << "stack s:\n" << s << '\n';

    {                       // start a new block
        Stack t( s );       // t contains a copy of s
        cout << "\nstack t:\n" << t << '\n';
        cout << "pop one element: " << t.pop( ) << '\n';
        cout << "\nstack t:\n" << t << '\n';
    }                       // end the new block

    cout << "\nstack s:\n" << s << '\n';
    cout << "pop one element: " << s.pop( ) << '\n';
    cout << "pop one element: " << s.pop( ) << '\n';
                            // poping one element too many
    cout << "pop one element too many: " << s.pop( ) << '\n';
                            // print an empty stack s
    cout << "\nstack s:\n" << s << '\n';

    return 0;
}

