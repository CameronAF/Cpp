#include    <iostream>
#include    <fstream>
#include    <string>
#include    <stack>
#include	<filesystem>
using namespace std;

// function prototypes

ifstream get_ifs( );


int main( )
{
    ifstream ifs = get_ifs( );
    char c;                                     // input character

    while( (c = ifs.peek( ) ) != EOF )          // as long as there is input
    {
		stack< int > stk;						// stack of numbers

		while( ( c = ifs.get( ) ) != '\n' )     // handle one expression
        {
            if( isdigit( c ) )                  // is it a digit ?
            {
                ifs.putback( c );               // put it back in the input
                int number;                     // an incoming number
                ifs >> number;                  // read the number
                stk.push( number );				// put number on top of stack
                cout << number;			
            }
            else if ( c == ' ')                 // is it a space ?
            {
                cout << c;
            }
            else                                // it must be an operator
            {
				if ( c == '+')
				{
					int second = stk.top( );	// get top number in stack	
					stk.pop( );					// delete top number
					int first  = stk.top( );	// get top number in stack
					stk.pop( );					// delete top number
					stk.push(first + second);	// add the two numbers and push in stack
					cout << c;
				}
				if ( c == '-')
				{
					int second = stk.top( );
					stk.pop( );
					int first  = stk.top( );
					stk.pop( );
					stk.push(first - second);	// subtract the two numbers and push in stack
					cout << c;
				}
				if ( c == '*')
				{
					int second = stk.top( );
					stk.pop( );
					int first  = stk.top( );
					stk.pop( );
					stk.push(first * second);	// multiply the two numbers and push in stack
					cout << c;
				}
				if ( c == '/')
				{
					int second = stk.top( );
					stk.pop( );
					int first  = stk.top( );
					stk.pop( );
					stk.push(first / second);	// divide the two numbers and push in stack
					cout << c;
				}
            }
        }

        cout << "   result is " << stk.top() <<'\n';      // found new line; print value at the top of your stack
    }

    return 0;
}


ifstream get_ifs( )                             // get input file stream
{
    string filename;                            // input file name

    cerr << "name of file to read from? ";
    cin  >> filename;
	experimental::filesystem::path path = experimental::filesystem::current_path();;
	string folder = path.u8string();			// path for folder containing                      
                                                // the .txt test files
    filename = folder + "\\" + filename;

    ifstream ifs( filename, ifstream::in );
    if( ! ifs )                                 // cannot open input file
    {
        cerr << "cannot open input file '" << filename << "'\n";
        exit( 1 );
    }

    return ifs;                                 // return input file stream
}

