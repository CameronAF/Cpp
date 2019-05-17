#include "CQueue.h"

//////////////////////////////////////////////////////////////////////
//Function Name: Default Constructor
//Precondition: front have not been initialized
//Postcondition: front is set to 0
//Description: The function initializes the state of the class.
//////////////////////////////////////////////////////////////////////
CQueue::CQueue()
{
	front=0;
}

//////////////////////////////////////////////////////////////////////
//Function Name: Copy Constructor
//Precondition: a QUEUE has been initialized
//Postcondition: a new QUEUE was made with the same state as the origin QUEUE
//Description: The function initializes the state of the class.
//////////////////////////////////////////////////////////////////////
CQueue::CQueue(const CQueue & Org)
{
	QNode *neww, *p=Org.front;

	(*this).front = 0;
	//if original queue isnt empty
	if (p != 0)
	{
		(*this).front = new QNode;			//new node in front
		(*this).front ->time = p->time;		//copy time from original queue
		neww = front;						
		p = p->next;						//got to original next

		while(p!=0)
		{
			neww->next = new QNode;			//make new node at newest-made-node next 
			QNode *last=neww;				//point to new node
			neww = neww->next;				//infrement new node
			neww->time = p->time;			//copy time
			neww->prev = last;				//set prev
			neww->next = 0;					//set next
			p = p->next;
		}
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Destructor
//Precondition: A QUEUE exist
//Postcondition: Delete elements in the QUEUE
//Description: dealocate memory
//////////////////////////////////////////////////////////////////////
CQueue::~CQueue()
{
	while (!Empty())
	{
		Dequeue();		//delete front node till empty
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Enqueue
//Precondition: a queue was constructed
//Postcondition: queue has 1 more element
//Description: adds int to end of queue
//////////////////////////////////////////////////////////////////////
void CQueue::Enqueue(int x)		//add element at end
{
	if (Empty())	//if empty
	{
		front = new QNode;		//front is new node
		front->time = x;		
	}
	else			//if not empty
	{
		QNode *p = front;		//point to front
		while (p->next != 0)	//go to last element
		{ 
			p = p->next;
		}
		p->next = new QNode;	//make new node at last-node next
		QNode *f = p;			//save old last node
		p = p->next;			//go to new node
		p->time = x;			//set time
		p->prev = f;			//set prev
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Dequeue
//Precondition: a queue was constructed
//Postcondition: if not empty, queue has 1 less element
//Description: deletes int in front of queue
//////////////////////////////////////////////////////////////////////
void CQueue::Dequeue( )			//delete front element
{ 
	if (Empty())				//empty
	{
		cout<<"Cannot deQueue because queue is empty\n";
	}
	else if (front->next == 0)	//one element
	{
		delete front;			//delete element
		front = 0;
	}
	else						//more then 1 element
	{
		QNode *p = front;		//point to front
		front = front->next;	//make front next
		delete p;				//delete old front
		front->prev=0;
	}
}

//////////////////////////////////////////////////////////////////////
//Function Name: Print
//Precondition: a queue was constructed
//Postcondition: if not empty, contents is displayed
//Description: displays content of queue
//////////////////////////////////////////////////////////////////////
void CQueue::Print( )
{
	if (Empty())				//empty
	{
		cout<<"QUEUE is empty\n";
		return;
	}
	QNode *p = front;
	cout << "QUEUE contains:\n";
	while (p != 0)				//display content
	{ 
		cout << p->time << endl;
		p = p->next;
	}
	cout<<endl;
}