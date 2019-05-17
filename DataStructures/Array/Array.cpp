#include     "Array.h"

//////////////////////////////////////////////////////////////////////
//Function Name: Default Constructor
//Precondition: DB, count and capacity have not been initialized
//Postcondition: DB, count and capacity have been initialized.
//               Data in array_strings.txt has been stored in DB.
//Description: The function initializes the state of the class.
//////////////////////////////////////////////////////////////////////
Array::Array()
{
	cout << "Default Constructor Invoked" << endl;
	ifstream in("array_strings.txt");
	// allocate array and variables
	count=0;
	capacity=2;
	DB = new string[ capacity ];
	if (in.fail())
		cout<<"array_strings not opened correctly"<<endl;

	while(!in.eof() && count<capacity)
	{
		in>>DB[count];
		count++;
	}

	in.close();
}

//////////////////////////////////////////////////////////////////////
//Function Name: Explicit-Value Constructor
//Precondition: DB, count and capacity have not been initialized
//Postcondition: DB, count and capacity have been initialized
//				 Data in array_strings.txt has been stored in DB.
//Description: The function initializes the state of the class.
//             the number of cells is explicity passed through the formal parameter
//////////////////////////////////////////////////////////////////////
Array::Array(int cap)
{
	cout << "Explicit-Value Constructor Invoked"<< endl;
	ifstream in;
	in.open("array_strings.txt");
	// allocate array and variables
	count=0;
	capacity=cap;
	DB = new string[ capacity ];
	if (in.fail())
	cout<<"array_strings not opened correctly"<<endl;
	while(!in.eof() && count<capacity)
	{
		in>>DB[count];
		count++;
	}
	in.close();
}

//////////////////////////////////////////////////////////////////////
//Function Name: CopyConstructor
//Precondition: Original contains a valid state, and the current has not
//              been initializes with sorce's state values
//Postcondition: The current object's state has been initialized to sorce's state value
//Description: This does a deep copy of sorce's state.
//             
//////////////////////////////////////////////////////////////////////
Array::Array(const Array &sorce)
{
	cout << "Copy Constructor Invoked" << endl;
	// access if if both ARRAY are not the same
	if (this != &sorce)
	{

		// delete this array
		delete [] DB;
		// restablish new count & capacity from sorce
		count = sorce.count;
		capacity = sorce.capacity;
		// allocate this array 
		DB = new string[capacity];
		// copy sorce to this array
		for (int i=0; i<count; i++)
		{
			DB[i] = sorce.DB[i];
		}
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Destructor
//Precondition: None
//              
//Postcondition: Current Object's dynamic memory returned to heap.
//Description: De-allocates dynamic memory used by object.
//             
/////////////////////////////////////////////////////////////////////
Array::~Array()
{
	cout << "~~~DESTRUCTION~~~" << endl;
	delete [] DB;
}

//////////////////////////////////////////////////////////////////////
//Function Name: Is Empty
//Precondition: DB, count and capacity have been initialized
//Postcondition: true or false
//Description: The function compares count and 0
//			   If count is less then or equal to 0 then 
//             funtion returns true, if not then returns false
//////////////////////////////////////////////////////////////////////
bool Array::IsEmpty()
{
    cout << "Is_Empty Invoked" << endl;
	// if array is empty return true 
	if (count <= 0)
	{
		cout << "  array is empty" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Is Full
//Precondition: DB, count and capacity have been initialized
//Postcondition: true or false
//Description: The function compares count and capacity
//			   If count is equal to or geater then capacity then 
//             funtion returns true, if not then returns false
//////////////////////////////////////////////////////////////////////
bool Array::IsFull()
{
    cout << "Is_Full Invoked" << endl;
	// if array is full return true
	if (count >= capacity)
	{
		cout << "  array is full" << endl;
		return true;
	}
	else
	{
		return false;
	}
}    

//////////////////////////////////////////////////////////////////////
//Function Name: Search
//Precondition: DB, count and capacity have been initialized
//Postcondition: interger index of searched object or -1
//Description: The function calls empty funtion and returns -1 if empty
//			   if not empty the item is searched for using a loop
//			   if the item is found the index is returned, if not -1 is returned
//////////////////////////////////////////////////////////////////////
int Array::Search(const string &find)
{
	cout <<  "Search Invoked" << endl;
	// if array is empty return -1
	if(IsEmpty())
	{
		return -1;
	}
	// if array is not empty search for object
	else
	{
		// loop to look for object in array
		for (int i=0; i<count-1 ; ++i)
		{
			//if object is found return index number 
			if(find == DB[i])
			{
				cout << "  String found" << endl;
				return i;
			}
		}
	}
	// object was not found, return -1
	cout << "  String not found" << endl;
	return -1;
}

//////////////////////////////////////////////////////////////////////
//Function Name: Size Times Two
//Precondition: count is equal to or greater then capacity
//Postcondition: capacity is doubled
//Description: The function makes a temporary string to store the data in DB.
//             DB is then doubled in capacity and the data transfers back to DB from temp
//////////////////////////////////////////////////////////////////////
void Array::Size_Times_Two()
{
	cout <<  "Size_Times_Two Invoked" << endl;
	// double capacity
	capacity = capacity*2;
	// creat variable to temporarily hold values in *DB
	string* temp = new string[capacity];
	// transfer values from DB to temp variable
	for (int i=0; i<count; i++)
	{
		temp[i] = DB[i];
	}
	// delete DB array
	delete [] DB;
	// remake DB with newly doubled capacity
	DB = new string[capacity];
	// transfer values back to DB from temp
	for (int i=0; i<count; i++)
	{
		DB[i] = temp[i];
	}
	delete [] temp;
}

//////////////////////////////////////////////////////////////////////
//Function Name: Sort
//Precondition: DB, count and capacity have been initialized
//Postcondition: array has been alphabatized
//Description: The function alphabatized the array by using two loops 
//////////////////////////////////////////////////////////////////////
void Array::Sort()
{
	cout << "Sort Invoked" << endl;
	// check if array is empty, if empty exit sort function
	if(IsEmpty())
	{
		return;
	}
	// 2 loops to compare two different elements in array
	for (int i=0; i<count-1;i++)
	{
		for(int j=i+1; j<count; j++)
		{
			// call function - if the 1st element value is greater then 2nd elements value swap the 2 elements 
			if(isEqual_CaseInsensitive(DB[i],DB[j]))
			{
				string x=DB[i];
				DB[i]=DB[j];
				DB[j]=x;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Remove
//Precondition: DB, count and capacity have been initialized
//Postcondition: an object was removed in array and cound was decremented by 1
//Description: The function uses search function to find the item index to be removed.
//             the item is then removed in a loop by replacing it with the
//			   following object untill the end of the array
//////////////////////////////////////////////////////////////////////
void Array::Remove(const string &item)		
{
	cout << "Remove invoked" << endl;
	// check if array is empty, if empty exit sort function
	// search for item by calling search and place value in index variable
	int index=Search(item);
	// if index is -1 the item was not found, exit function
	if(index == -1)
	{	
		return;
	}
	// item was found and is being replaced with last element in array
	else
	{
		for (int i=index; i<count-1; i++)
		{
		DB[i]=DB[i+1];
		}
		// decrement count
		--count;
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: operator +
//Precondition: there exist an ARRAY to the left of the operater and a string to the right        
//Postcondition: the string was cancatanated on to DB array
//Description: cancatanated a string to DB array
//			   If DB is full it is called before cancatanating
//////////////////////////////////////////////////////////////////////
Array &Array::operator +(const string &secnd)
{
	cout << "'operator+' invoked" << endl;
	// if array is full call function Size_Times_Two() to increase memory
	if(IsFull())
	{
		Size_Times_Two();
	}
	// put string in array
	DB[count] = secnd;
	// increment count
	++count;
	return *this;
}

//////////////////////////////////////////////////////////////////////
//Function Name: operator =
//Precondition: ARRAY exist to the left and right operator         
//Postcondition: THIS array holds same data as source ARRAY
//Description: deep copy of sorce ARRAY
//////////////////////////////////////////////////////////////////////
Array &Array::operator =(const Array &sorce)			
{
	cout<< "'operator=' invoked" << endl;
	// if both paramaers are not equal enter if staments
	if (this != &sorce)
	{
		// delete this array
		delete [] DB;
		// restablish new count & capacity from sorce
		count = sorce.count;
		capacity = sorce.capacity;
		// allocate this array 
		DB = new string[capacity];
		// copy sorce to this array
		for (int i=0; i<count; i++)
		{
			DB[i] = sorce.DB[i];
		}
	}
	// return this = sorce
	return *this;
}

//////////////////////////////////////////////////////////////////////
//Function Name: operator<<
//Precondition: None         
//Postcondition: DB array has been printed.
//Description: Prints the contains of the DB's array.  
//			   It also includes chaining.        
//////////////////////////////////////////////////////////////////////
ostream &operator <<(ostream &out, Array &ary)
{
	cout <<  "printing array" << endl;
	// loop to display all elements in the array
	for (int i=0; i<ary.count; ++i)
	{
		cout << "  " << ary.DB[i] << endl; 
	}
	// return the output
	return out;
}

//////////////////////////////////////////////////////////////////////
//Function Name: ReadFile
//Precondition: a file exist.        
//Postcondition: the file has been stored in Array.
//Description: Stores contains of the file into Array.
//////////////////////////////////////////////////////////////////////
void Array::ReadFile(string file)	
{
	cout << "Default Constructor Invoked" << endl;
	// file variable
	ifstream in(file);
	// reset count
	count=0;
	// open file 
	if (in.fail())
		cout<<"file not opened correctly"<<endl;
	//store contents of file into DB array
	while(!in.eof() && count<capacity)
	{
		in>>DB[count];
		count++;
		// test if full
		if(IsFull())
		{
			Size_Times_Two();
		}
	}
	//close file
	in.close();                             
}

//////////////////////////////////////////////////////////////////////
//Function Name: is Equal - Case Insensitive
//Precondition: two string exist        
//Postcondition: value of the compared strings
//Description: copies two strings(pass by value) and sets the string all to lower case
//			   compare the two string and return the value
//			   (good for if statments)
//////////////////////////////////////////////////////////////////////
int Array::isEqual_CaseInsensitive(string a, string b)
{
	char c;
	int counter = 0;
	// set first string to all lower case
	while (a[counter]) 
	{
		c = a[counter];
		a[counter] = tolower(c);
		counter++;
	}
	counter = 0;
	// set second string to all lower case
	while (b[counter]) 
	{
		c = b[counter];
		b[counter] = tolower(c);
		counter++;
	}
	// compare the 2 strings and returns the value
	return a.compare(b) > 0;
}