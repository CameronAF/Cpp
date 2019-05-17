#include    <iostream>
#include    <iomanip>
using namespace std;

#include    "vec.h"


ostream &operator <<( ostream &out, const Vec &v )
{
    for( int i = 0; i < v.size( ); ++i )
    {
        out << setw( 5 ) << v[ i ];
    }

    return out;
}


int main( )
{
    Vec v;                  // v is an object of type Vec

    v.push_back( 10 );      // push 5 ints into v
    v.push_back( 20 );
    v.push_back( 30 );
    v.push_back( 40 );
    v.push_back( 50 );

    v.push_back( 60 );      // try to push one element too many
    cout << "after initializing v:\n" << v << '\n';

    v.pop_back( );          // remove the last element of v
    cout << "after popping last element of v:\n" << v << '\n';

    v.erase( 0 );           // erase the first element of v
    cout << "after erasing first element of v:\n" << v << '\n';

    v.insert( 0, 60 );      // insert value 60 at index 0
    cout << "after inserting 60 at index 0 of v:\n" << v << '\n';

    v.erase( 1 );           // erase the second element of v
    cout << "after erasing second element of v:\n" << v << '\n';

                            // erase the last element of v
    v.erase( v.size( ) - 1 );
    cout << "after erasing the last element of v:\n" << v << '\n';

    v.erase( 0 );           // erase the first  element of v
    cout << "after erasing the 1st element of v:\n" << v << '\n';

    v.insert( 0, 10 );      // insert 10 at position 0
    v.insert( 1, 20 );      // insert 20 at position 1
    v.insert( 3, 40 );      // insert 40 at position 3
    cout << "after inserting three elements in v:\n" << v << '\n';

    v.insert( 5, 50 );      // try to insert 50 at position 5; invalid!
    cout << "after trying to insert 50 at an invalid loc in v:\n"
         << v << '\n';

    v.erase( 0, 2 );        // erase two elements beginning a loc. 0
    cout << "after erasing two elements starting at 0:\n" << v << '\n';

    v.erase( 3, 1 );        // erase one elements beginning a loc. 3
    cout << "after attempting to erase one element starting at 3:\n"
         << v << '\n';      // no changes; position is invalid

    v.erase( 1, 1 );        // erase one elements beginning a loc. 1
    cout << "after erasing one element starting at 1:\n"
         << v << '\n';

    v.insert( 0, 10 );      // insert 10 at position 0
    v.insert( 1, 20 );      // insert 20 at position 1
    v.insert( 3, 40 );      // insert 40 at position 3
    cout << "after inserting three elements in v:\n" << v << "\n\n";

    v.erase( 4, 2 );        // invalid erase; no location 4
    cout << "no change in v after invalid erase location:\n"
         << v << "\n\n";

    v.erase( 3, 4 );        // invalid erase; no 4 elements starting at 3
    cout << "no change in v after invalid erase range:\n"
         << v << "\n\n";

    v.erase( 0, 4 );        // erase all four elements in v
    cout << "after erasing all elements in v:\n" << v << "\n";

    v.push_back( 10 );      // insert 10 at position 0
    v.push_back( 20 );      // insert 20 at position 1
    v.push_back( 30 );      // insert 30 at position 2
    cout << "after inserting three elements in v:\n" << v << '\n';

    return 0;
}

