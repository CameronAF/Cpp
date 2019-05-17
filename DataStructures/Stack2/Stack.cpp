#include	"Stack.h"

//////////////////////////////////////////////////////////////////////
//Function Name: Default Constructor
//Precondition: DB, count and capacity have not been initialized
//Postcondition: s_top is set to 0
//Description: The function initializes the state of the class.
//////////////////////////////////////////////////////////////////////
Stack::Stack()
{
	s_top=0;
}

//////////////////////////////////////////////////////////////////////
//Function Name: Copy Constructor
//Precondition: a Stack has been initialized
//Postcondition: a new Stack was made with the same state as the origin Stack
//Description: The function initializes the state of the class.
//////////////////////////////////////////////////////////////////////
Stack::Stack(const Stack & Org)
{
	SNode *back, *p=Org.s_top;

	(*this).s_top = 0;

	if (p != 0)
	{
		(*this).s_top = new SNode;
		(*this).s_top ->data = p->data; 
		back = s_top;
		p = p->next;

		while(p!=0)
		{
			back->next = new SNode;
			back = back->next;
			back->data = p->data;
			back->next = 0;
			p = p->next;
		}
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Destructor
//Precondition: A Stack exist
//Postcondition: Delete elements in the stack
//Description: dealocate memory
//////////////////////////////////////////////////////////////////////
Stack::~Stack()
{
	while(s_top!=0)
	{
		pop();
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: top
//Precondition: A Stack exist
//Postcondition: None
//Description: Returns the top of the stack
//////////////////////////////////////////////////////////////////////
stack_element & Stack::top()
{
	if (s_top == 0)
	{
		exit(1);
	}
	else
	{
		return s_top->data;
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Pop
//Precondition: A Stack exist
//Postcondition: delete top of stack 
//			     makes top, top next
//Description: Delete the top elemebt of the stack
//////////////////////////////////////////////////////////////////////
void Stack::pop()
{
	SNode *p;
	
	if (s_top != 0)
	{
		p = s_top;
		s_top = s_top->next;
		delete p;
	}
	
}

 //////////////////////////////////////////////////////////////////////
//Function Name: Push
//Precondition: A Stack exist
//Postcondition: add item to top of stack
//			     pushes all other elements back 
//Description: stack gets bigger
//////////////////////////////////////////////////////////////////////
void Stack::push(const stack_element & item)
{
	SNode *p = new SNode;

	p->data = item;
	p->next = 0;

	if (s_top == 0)
	{
		s_top = p;
	}
	else
	{
		p->next = s_top;
		s_top = p;
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Print
//Precondition: A Stack exist
//Postcondition: dall elements in stack are displayed
//Description: display all elements in stack
//////////////////////////////////////////////////////////////////////
void Stack::print()
{
	for(SNode *p = s_top; p!=0; p=p->next)
	{
		cout<<p->data<<endl;
	}
}

