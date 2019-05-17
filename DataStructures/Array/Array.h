#include    <iostream>
#include	<fstream>
#include    <iomanip>
#include    <string>

using namespace std;

#ifndef     array_h

class Array
{
	public:
		Array();									//default contsuctor
		Array(int );								//explicite value constructor
		Array(const Array &);						//copy constructor
		~Array();							
		bool IsEmpty();								// is array empty?
		bool IsFull();								// is array full?
		int Search(const string &);					//search for item and return index or -1
		void Size_Times_Two();					    //double size if array is full
		void Sort();								//sort from a-z
		void Remove(const string &);				//remove item from list
		Array &operator +(const string &);			//+ member chain
		Array &operator =(const Array &);			//= member chain
		friend ostream &operator <<(ostream &, Array &);	//cout
		void ReadFile(string);							//get from file
		int isEqual_CaseInsensitive(string, string);
		//other functions you may want to implement

	private:
		string *DB;									//dynamic array
		int count;
		int capacity;
		//additonal state variables you may wish add
};

#endif
