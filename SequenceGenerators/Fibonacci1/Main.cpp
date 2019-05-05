#include <iostream>
#include <iomanip>
using namespace std;
#define SIZE 100 

// User inputs a number
// That many numbers are displayed from the Fibonacci sequence

int main()
{
	//prep variables
	cout << "How many numbers you would like displayed in the Fibonacci sequence:\n";
	int fill;
	cin >> fill;
	int fib[SIZE];
	fib[0] = 0;
	fib[1] = 1;

	//prep Fibonacci sequence
	int i;
	for(i=2; i<fill; ++i)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}

	//display
	int count = 0;
	for(i=0; i<fill; ++i)
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

	return 0;
}

