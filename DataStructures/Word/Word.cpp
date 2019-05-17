#include "Word.h"

//////////////////////////////////////////////////////////////////////
//Function Name: Default Constructor
//Precondition: DB, count and capacity have not been initialized
//Postcondition: DB, count and capacity have been initialized.
//               Data in array_strings.txt has been stored in DB.
//Description: The function initializes the state of the class.
//////////////////////////////////////////////////////////////////////
Word::Word()
{
	front = 0;
	length = 0;
}

//////////////////////////////////////////////////////////////////////
//Function Name: Explicit-Value Constructor
//Precondition: DB, count and capacity have not been initialized
//Postcondition: DB, count and capacity have been initialized
//				 Data in array_strings.txt has been stored in DB.
//Description: The function initializes the state of the class.
//             the number of cells is explicity passed through the formal parameter
//////////////////////////////////////////////////////////////////////
Word::Word(string source)
{
	length = 0;
	for (int i=0; i<source.length(); ++i)
	{
		Add(source[i]);
	}
	return;
}

//////////////////////////////////////////////////////////////////////
//Function Name: CopyConstructor - same as operater '='
//Precondition: Original contains a valid state, and the current has not
//              been initializes with sorce's state values
//Postcondition: The current object's state has been initialized to sorce's state value
//Description:  same as operator '='
//				This does a deep copy of sorce's state.             
//////////////////////////////////////////////////////////////////////
Word::Word(const Word &sorce)
{
	length =0;
	*this = sorce;
}

//////////////////////////////////////////////////////////////////////
//Function Name: Destructor
//Precondition: None
//              
//Postcondition: Current Object's dynamic memory returned to heap.
//Description: De-allocates dynamic memory used by object.
//             
/////////////////////////////////////////////////////////////////////
Word::~Word()
{
	cout << "~~~DESTRUCTION~~~" << endl;
	alpha_numeric *p;
	// loop[ to delete each node
	while (front != 0)
	{
		p = front;
		front = front -> next;
		delete p;
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Is Empty
//Precondition: WORD have been initialized
//Postcondition: true or false
//Description: If front is less then or equal to 0 then 
//             funtion returns true, if not then returns false
//////////////////////////////////////////////////////////////////////
bool Word::IsEmpty()
{
	// if WORD is empty return true 
	if (front == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Length
//Precondition: WORD have been initialized
//Postcondition: int length of list
//Description: returns length of list
//////////////////////////////////////////////////////////////////////
int Word::Length()
{
	return length;
}

//////////////////////////////////////////////////////////////////////
//Function Name: Add
//Precondition: WORD have been initialized and char is declared 
//Postcondition: the list is increased by one alpha_numeric
//Description: Used for constructors and operator '='
//             adds a new alpha_numeric with char at the end of this WORD 
//////////////////////////////////////////////////////////////////////
void Word::Add(char new_data)
{ 
	// make a node with new symbol
	alpha_numeric *new_ptr = new alpha_numeric;
	new_ptr -> symbol = new_data;
	new_ptr -> next = 0; 
	// if this is empty make node the front of list
	if ((*this).IsEmpty())
	{
		front = new_ptr;
	}
	else
	{
		// got to last node
		alpha_numeric *fwd_ptr= front, *pre_ptr=front;
		while(fwd_ptr!=0)
		{
			pre_ptr = fwd_ptr;
			fwd_ptr = fwd_ptr->next;
		}
		// input new symbol at end of list
		pre_ptr->next = new_ptr;
	}
	length++;
}

//////////////////////////////////////////////////////////////////////
//Function Name: Insert
//Precondition: two WORDs have been initialized 
//Postcondition: WORD2 is in this WORD at index 
//Description: insert a WORD into this WORD ar index
//             is this WORD empty? is the inserter WORD empty?
//			   makes deep copy of alpha_numeric from inserter WORD
//////////////////////////////////////////////////////////////////////
void Word::Insert(const Word &word, int idx)
{
	// if this is empty
	if ((*this).IsEmpty())
	{
		*this=word;
	}
	// there is nothing to insert
	else if (word.length==0)
	{
	}
	// there exist 2 WORDS with elements
	else
	{
		// if index exeads length idx is length
		if (idx>length)
		{
			idx=length;
		}
		// go to index
		alpha_numeric *now_ptr=front, *next_ptr= front, *wordS=word.front;
		for(int i = 0; i != idx; i++)
		{
			now_ptr = next_ptr;
			next_ptr = next_ptr->next;
		}
		// insert WORD word into WORD this
		for (int i=0; i<word.length; ++i)
		{
			// make a node with new symbol
			alpha_numeric *new_ptr = new alpha_numeric;
			new_ptr -> symbol = wordS -> symbol;
			new_ptr -> next = wordS -> next;
			wordS = wordS->next;
			// insert at front of WORD
			if(idx==0)
			{
				front=new_ptr;
				now_ptr=front;
				idx++;
			}
			// insert in middle or end
			else
			{
				now_ptr->next = new_ptr;
				now_ptr=now_ptr->next;
			}
			// increment & prep for next loop
			length++;
		}
		//reconnect WORD
		now_ptr->next=next_ptr;
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Search
//Precondition: address of front from this WORD & address of WORD to search for 
//Postcondition: true or false if item was found
//				 address of WORD in this WORD (&fin_front)
//Description: loop through both words looking for WORD find in this WORD
//             if found return true if nor found or empty return false
//////////////////////////////////////////////////////////////////////
bool Word::Search(alpha_numeric *&fin_front, const Word &find)
{
	// WORD is empty
	if (IsEmpty())
	{
		return false;
	}
	alpha_numeric *current=front;
	// loop through destination WORD 
	for(int i=0; i<=length-find.length; i++)
	{
		// current WORD pointer equals front of find WORD
		alpha_numeric *search=find.front;
		if(current->symbol == search->symbol)
		{
			// loop through the source WORD
			for(int i=0; i<=find.length; i++)
			{
				// full WORD found
				if(i == find.length)
				{
					return true;
				}
				// current WORD pointer equals search WORD pointer
				else if(current->symbol == search->symbol)
				{
					current=current->next;
					search=search->next;
				}
				// current WORD pointer DOES NOT equals search WORD pointer - exit loop
				else
				{
					current=fin_front;
					i=find.length+1;
				}
			}
		}
		// the two symbles didnt equal -  got to next node
		fin_front=current;
		current=current->next;
	}
	// loops finished - could not find WORD to remove
	return false;
}

//////////////////////////////////////////////////////////////////////
//Function Name: Remove
//Precondition: 2 WORDs initialized
//Postcondition: this WORD is smaller becouse WORD trash was removed
//			     or WORD trash was not found in this word
//Description: use search funstion to find WORD trash in this word
//             loop to delete trash from this Word
//////////////////////////////////////////////////////////////////////
void Word::Remove(const Word &trash)
{
	alpha_numeric *fp=front;
	// is WORD trash in *this?
	if (Search(*&fp, trash))
	{
		alpha_numeric *temp;
		// delete WORD trash in *this
		for(int i=0; i<trash.length; i++)
		{
			temp = fp->next;
			fp->next=temp->next;
			delete temp;
			length--;
		}
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Remove
//Precondition: 2 WORDs initialized
//Postcondition: this WORD is smaller becouse WORD trash was removed
//			     or WORD trash was not found in this word
//Description: loop to keep calling search function 
//			   to find WORD trash in this word multiple times.
//             loop to delete trash from this Word
//////////////////////////////////////////////////////////////////////
void Word::RemoveAll(const Word &trash)
{
	int i=0;
	while(i == 0)
	{
		alpha_numeric *fp=front;
		// is WORD trash in *this?
		if (Search(*&fp, trash))
		{
			alpha_numeric *temp;
			// delete WORD trash in *this
			for(int i=0; i<trash.length; i++)
			{
				temp = fp->next;
				fp->next=temp->next;
				delete temp;
				length--;
			}
		}
		// stop loop
		else
		{
			i=1;
		}
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: IsEqual
//Precondition: 2 WORDs initialized
//Postcondition: true or false
//Description: are the 2 WORDs equal?
//////////////////////////////////////////////////////////////////////
bool Word::IsEqual(const Word &w2)
{
	int i=0;
	alpha_numeric *word1=front, *word2=w2.front;
	// if the lengths arent equal then the WORDs arent equal
	if (this->length == w2.length)
	{
		// loop though WORDs
		while(i<=length || i<=w2.length)
		{
			// if i is length then at empty node and WORDs are equal
			if (i == length || i == w2.length)
			{
				return true;
			}
			// if the symbols equal then go to next
			else if(word1->symbol == word2->symbol)
			{
				word1=word1->next;
				word2=word2->next;
				i++;
			}
			// the symbles arent equal so make i big and exit loop
			else
			{
				i=length+w2.length;
			}
		}
	}
	return false;
}

//////////////////////////////////////////////////////////////////////
//Function Name: SetEqual - same as operater '='
//Precondition: 2 WORDs initialized
//Postcondition: this WORD is equal to WORD w2
//Description: same as opperator '='
//			   This does a deep copy of sorce's state.
//////////////////////////////////////////////////////////////////////
void Word::SetEqual(const Word &w2)
{
	*this = w2;
}

//////////////////////////////////////////////////////////////////////
//Function Name: CatWord 
//Precondition: 2 WORDs initialized
//Postcondition: this WORD is longer becouse w2 was added to the end of this WORD
//Description: w2 is inserted at the end of this WORD
//////////////////////////////////////////////////////////////////////
void Word::CatWords(const Word &w2)
{
	// if this is empty make this equal w2
	if (IsEmpty())
	{
		*this=w2;
	}
	// insert w2 at end of this
	else 
	{
		Insert(w2,length);
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: operater '='
//Precondition: WORD has been declared and a string has been declared
//Postcondition: The current object's state has been initialized to the characters in str
//Description: This does a deep copy of strings chars             
//////////////////////////////////////////////////////////////////////
Word &Word::operator =(const string &str)			
{
	// delete this
	alpha_numeric *p;
	while (front != 0)
	{
		p = front;
		front = front -> next;
		delete p;
	}
	// copy str to this class
	length = 0;
	for (int i=0; i<str.length(); ++i)
	{
		Add(str[i]);
	}
	return *this;
}

//////////////////////////////////////////////////////////////////////
//Function Name: operater '='
//Precondition: 2 WORDs have been declared
//Postcondition: The current object's state has been initialized to copy's state value
//Description: This does a deep copy of copy's state.             
//////////////////////////////////////////////////////////////////////
Word &Word::operator =(const Word &copy)
{
	// if both paramaers are not equal enter if staments
	if (this != &copy)
	{
		// delete this 
		alpha_numeric *p;
		while (front != 0)
		{
			p = front;
			front = front -> next;
			delete p;
		}
		// copy sorce to this class
		length = 0;
		for (alpha_numeric *p=copy.front; p!=0; p=p->next)
		{
			Add(p->symbol);
		}
	}
	return *this;
}

//////////////////////////////////////////////////////////////////////
//Function Name: operater '<<'
//Precondition: a WORD has been declared
//Postcondition: cout of WORDs state
//Description: allows cout to word with class WORD to display WORDs state           
//////////////////////////////////////////////////////////////////////
ostream &operator <<(ostream &out, Word &word)
{
	// if WORD is empty
	if (word.length == 0)
	{
		cout << "WORD is empty";
	}
	// display elements in WORD
	else for (alpha_numeric *p=word.front; p!=0; p=p->next)
		{
			cout << p->symbol;
		}
	return out;
}
