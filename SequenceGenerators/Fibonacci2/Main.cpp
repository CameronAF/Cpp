#include    <iostream>
#include    <iomanip>
using namespace std;

// User inputs a number
// That many numbers are displayed from the Fibonacci sequence

// Unlike Fibonacci1, this program used a Function, a dynamic array and dealocated memory after use

void Fibonacci(int);

int main( )
{
    cout << "How many numbers in the Fibonacci Series do you wish to display?\n"
		<< "Please keep it between 2 and 20 numbers\n";

	// n numbers in the Fibonacci Series
    int n;                          
    cin >> n;

	if( n < 2  ||  n > 20 )
    {
         cerr << "Size should be >= 2 and <= 20...\n";
         return 1;
    }

    Fibonacci( n );

    return 0;
}

void Fibonacci(int n)
{
	// allocate an array with size ints
	int *fib = new int[ n ];
	
	// prep Fibonacci Series
	fib[0] = 0;
	fib[1] = 1;
	int i;
	for(i=2; i<n; ++i)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}

	//display
	int count = 0;
	for(i=n-1; i>=0; --i)
	{
		cout << setw(5) << fib[i];
		++count;
		if(count%6 == 0)
		{
			cout << '\n';
		}
	}
	if(count%6 != 0)
	{
		cout << '\n';
	}
	// deallocate the array that arrayptr points to
	delete [ ] fib;
	return;
}