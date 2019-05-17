#include     "Array.h"

int main()
{
	cout<<"invoking the default constructor (11)"<<endl;
	Array myArray;
	cout<<"Output after default constructor called\n";
	cout<<myArray<<endl<<endl;

	cout<<"invoking the explicit-value constructor (12)"<<endl;
	Array yourArray(5);
	cout<<"Output after explicit-value constructor called\n";
	cout<<yourArray<<endl<<endl;


	cout<<"invoking the copy constructor (3)"<<endl;
	Array ourArray = myArray;
	cout<<"Output after copyconstructor called\n";
	cout<<ourArray<<endl<<endl;
	

	cout<<"testing overloaded operator= with chaining as a member (1)"<<endl;
	Array X, Y, Z;

	X = Y = ourArray;
	cout<<"Output after operator= called\n";
	cout<<X<<endl<<endl;
	

	cout<<"testing overloaded operator<< overloaded as a friend with chaining (4)"<<endl;
	cout<<"the test also allows us to check how well operator= performed (4 & 1)"<<endl;
	cout<<X<<Y<<Z;
	cout<<endl<<endl;

	cout<<"testing overlaoded operator+ as a member function with chaining, Size_Times_Two "
		<<" and Is_Full. (2, 7 and 8)"<<endl;
	Array theirArray(1);
	theirArray + "Overload the +" + " operator as a member function " + "with chaining to add a string " + "to an Arrary object.";
	cout<<"Output after operator+, Size_Times_Two and Is_Full called\n";
	cout<<theirArray<<endl<<endl;
	

	cout<<"testing Remove and Search.  Assuming Remove uses Search (5 & 6)"<<endl;
	
	theirArray.Remove("XXXXXX");
	theirArray.Remove("Overload the +");
	cout<<"Output after Remove and Search called\n";
	cout<<theirArray<<endl<<endl;
	

	cout<<"testing ReadFile (13) "<<endl;
	myArray.ReadFile("array_strings.txt");
	cout<<"ReadFile called\n";
	cout<<myArray<<endl<<endl;

	cout<<"testing Sort  (10)"<<endl;
	myArray.Sort();
	cout<<"Output after Sort called\n";
	cout<<myArray<<endl<<endl;
	
	return 0;
}