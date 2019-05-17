#include    <iostream>
#include    <iomanip>
using namespace std;

#include    "vec.h"

Vec::Vec()          // constructor
{
	cout << "in Vec::Vec( )\n";
	loc = 0;                // loc refers to the next empty location
}

void Vec::push_back( int i )
{
	if( loc >= 5 )
    {
        cerr << "object of type Vec is full...\n";
    }
    else
    {
        cout << "push_back( " << i << " )\t at location "
             << loc << '\n';
        array[ loc ] = i;
        ++loc;              // advance to the next empty location
    }
}

void Vec::pop_back( )           // pop an int from a Stack
{
    cout << "pop_back( ) at location " << loc-1 << '\n'; 
	if (loc == 0)
	{
		cout << "Vec is empty";
	}
	else
	{
		--loc;
	}
	return;
}

void Vec::erase( int idx )  // erase element at position idx
{
	cout << "erase( " << idx << " )\n";
	int i;
	for(i=idx; i<loc; ++i)
	{
		array[i]=array[i+1];
	}
	--loc;
	return;
}

    // optional:            // erase howmany elements starting at idx
void Vec::erase( int idx, int howmany )
{
	cout << "erase( " << idx << ", "<< howmany << " )\n";
	int i;
	int execute = 0;
	if (idx >= loc)
	{
		return;
	}
	if (idx+howmany > loc)
	{
		return;
	}
	for(i=idx; i<loc-howmany; ++i)
	{
		array[i]=array[i+howmany];
	}
	loc = loc - howmany;
	return;
}

                            // insert a value at position idx
void Vec::insert( int idx, int value )
{
	cout << "insert( " << idx << ", "<< value << " )\n";
	if( idx >= 5 )
	{
		return;
	}
	int i;
	int temp1;
	int temp2 = value;
	for(i=idx; i<=loc; ++i )
	{
		temp1 = array[i];
		array[i] = temp2;
		temp2 = temp1;
	}
	++loc;
	return;
}


// size of the object
int Vec::size() const
{
	return loc;
}

// return a copy of element at index i
int Vec::operator [ ](int i) const
{
	if (i >= 0 && i < loc)
	{                       // i is within the range of elements in array
		return array[i];
	}
	else
	{
		return -1;          // invalid index; return -1
	}
}
