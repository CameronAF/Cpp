#include	"Stack.h"

// function prototypes
char KeepGoing();
string RemoveSpaces(string &);
void ValidExp(string &);

int main( )
{
	//counter for loop
	char repeat='n';
	do{
		//input posfix expresion
		cout << "Input a postfix expression\n";
		string postfix;
		if(repeat=='Y')		//clear stream if repeating
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		getline(cin,postfix);
		//remove spaces from expresiion
		postfix=RemoveSpaces(postfix);
		ValidExp(postfix);
		Stack  stk;	// stack of numbers
		string c;
		string infix;
		// handle one expression
		for (int i=0; i<postfix.length(); ++i)    
		{
			c = postfix[i];
			// is it a operator ?
			if((c=="+")||(c=="-")||(c=="*")||(c=="/"))             
			{
				string second = stk.top( );	// get top number in stack	
				stk.pop( );					// delete top number
				string first  = stk.top( );	// get top number in stack
				stk.pop( );					// delete top number
				string expres = "(" + first + " " + c + " " + second + ")";
				stk.push(expres);			// place operator between two numbers and push in stack
			}
			// it must be a variable
			else                                
			{
				stk.push( c );				// put variable on top of stack	
			}
		}
		//print postfix and inflix
		cout << "RESULT" << endl;
		cout << "\tpostfix:\t" << postfix << endl; 
		cout << "\tinfix:\t\t"; 
		stk.print();   
		//do you have another postfix expresion to input?
		repeat=KeepGoing();
	}while(repeat=='Y');
	cout << "\nThank you for using my program. :)\n";
	return 0;
}

//////////////////////////////////////////////////////////////////////
//Function Name: KeepGoing
//Precondition: None
//Postcondition: send users responce as char
//Description: ask user if they want to continue the program
//////////////////////////////////////////////////////////////////////
char KeepGoing()
{
	//intruction if user wants to continue with another expression
	cout << "\nDo you want to input another postfix expression?\n";
	cout << "Please ENTER:\n";
	cout << "YES.................Y\n";
	cout << "NO..................N\n";
	//users input
	char answer;
	cin >> answer;
	answer = toupper(answer);
	return answer;
}

//////////////////////////////////////////////////////////////////////
//Function Name: RemoveSpaces
//Precondition: a string has been initalized
//Postcondition: string has no spaces
//Description: remove all spaces from the string
//////////////////////////////////////////////////////////////////////
string RemoveSpaces(string &org)
{
	string spaceless = "";
	for (int i=0; i<org.length(); ++i)
	{
		if ( org[i] != ' ') 
		{
			spaceless = spaceless + org[i];
		}
	} 
	cout << spaceless << endl;
	return spaceless;
}

//////////////////////////////////////////////////////////////////////
//Function Name: ValidExpresion
//Precondition: a string has been initalized & has no spaces
//Postcondition: exit program if postfix is not valid
//Description: check to see if the expresion is a valid posfix expression
//////////////////////////////////////////////////////////////////////
void ValidExp(string &exp)
{
	int oper =0;
	int var =0;
	for (int i=0; i<exp.length(); ++i)    
		{
			char c = exp[i];
			// is it a operator ?
			if((c=='+')||(c=='-')||(c=='*')||(c=='/'))             
			{
				oper++;	// place operator between two numbers and push in stack
			}
			// it must be a variable
			else                                
			{
				var++;				// put variable on top of stack	
			}
		}
	if (var-oper != 1)
	{
		cout << "this is not a proper postfix exprestion\n";
		exit(1);
	}
}
