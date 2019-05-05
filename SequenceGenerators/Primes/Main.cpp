#include    <iostream>
#include    <iomanip>
#include    <vector>
using namespace std;

// User inputs a number
// A series of Primes up to that number are displayed

// function that converts a vecter of integers to a verctor of only prime numbers in that given vector
void Eratos( int length, vector< int > &v );
// creating a operator like cin or cout to display vectors
ostream &operator <<( ostream &, const vector< int > & );

int main( )
{
    // directions and errer message
	cout << "This program is used to display prime numbers bwtween 2 and 300\n"
         << "Please enter the upper most range to search for prime numbers\n";
    int num;
	cin >> num;
	if( num < 2  ||  num > 300 )
    {
         cerr << "Size should be >= 2 and <= 300...\n";
         return 1;
    }

	// empty vector of ints
	vector< int > v;          
	// place numbers 2 through num in vector
	int size;
	size=num-1;
	int i;
	for(i=0; i<size ; ++i)
	{
        v.push_back( i+2 );     
	}
	Eratos(size, v);
	// call << operator and display vector
	cout << v;
	return 0;

}

// remove non-prime integers from a vector
void Eratos( int length, vector< int > &v )
{
	int i;
	int k;
	//compare 2 items in vector using two loops
	for(i=0; i < length; ++i)
	{
		for(k=i+1; k < length; ++k)
		{
			// if a number is divisable, remove it from the vecor
			if(v[k] % v[i] == 0)
			{
				v.erase( v.begin( ) + k );
				--length;
			}
		}
	}
	return;
}

ostream &operator <<( ostream &out, const vector< int > &v )
{
	int count=0;
	for( unsigned int i = 0; i < v.size(); ++i )
    {
        out << setw( 5 ) << v[ i ];
		++count;
		if(count%10 == 0)
		{
			cout << '\n';
		}
	}
	if(count%10 != 0)
	{
		cout << '\n';
	}
    return out;
}