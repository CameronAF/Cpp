#include "Queue.h"

// copy constructor
Queue::Queue(const Queue & Org)
{
	QNode *neww, *p = Org.front;

	(*this).front = 0;
	//if original queue isnt empty
	if (p != 0)
	{
		(*this).front = new QNode;			//new node in front
		neww = front;
		p = p->next;						//got to original next

		while (p != 0)
		{
			neww->next = new QNode;			//make new node at newest-made-node next 
			QNode *last = neww;				//point to new node
			neww = neww->next;				//infrement new node
			neww->prev = last;				//set prev
			neww->next = 0;					//set next
			p = p->next;
		}
	}
}

// set ready queue, hard code fill with processes
void Queue::Set_Queue()
{
	QNode *neww;
	Thread *P[9];
	(*this).size = 9;
	(*this).front = new QNode;			//new node in front
	neww = (*this).front;				//set front to neww node
	neww->process = new Thread;			//new procces on node 
	P[0] = neww->process;				//set to first in array
	for (int i = 1; i < 9; ++i)
	{
		QNode *last = neww;				//save current node
		neww->next = new QNode;			//make new node at newest-made-node next 
		neww = neww->next;				//increment to new node
		neww->process = new Thread;		//new procces on node
		P[i] = neww->process;			//put in array
		neww->prev = last;				//set prev
		neww->next = 0;					//set next
	}
	// set up all processes, hard coded
	P[0]->Fill_Thread("P1", 17, 15, 19, 15, 64, 14, 43, 16, 33, 14, 27, 16, 31, 17, 73, 18, 24, 17);
	P[1]->Fill_Thread("P2", 15, 19, 51, 15, 43, 12, 47, 9, 43, 7, 42, 8, 35, 9, 31, 10);
	P[2]->Fill_Thread("P3", 13, 12, 31, 20, 43, 21, 31, 22, 61, 24, 53, 23, 51, 18);
	P[3]->Fill_Thread("P4", 15, 14, 66, 15, 72, 12, 67, 15, 52, 17, 54, 20, 55, 19, 42, 17);
	P[4]->Fill_Thread("P5", 19, 5, 42, 3, 61, 4, 77, 3, 51, 4, 62, 5, 61, 3, 71, 5, 82, 6, 61, 5);
	P[5]->Fill_Thread("P6", 13, 11, 29, 13, 41, 15, 32, 11, 33, 14, 41, 12, 35, 10);
	P[6]->Fill_Thread("P7", 17, 5, 24, 6, 22, 8, 21, 7, 29, 5, 16, 4, 19, 5, 21, 7, 18, 6);
	P[7]->Fill_Thread("P8", 15, 15, 32, 13, 31, 14, 43, 16, 21, 14, 31, 14, 42, 12, 52, 9);
	P[8]->Fill_Thread("P9", 17, 4, 22, 5, 16, 5, 29, 4, 41, 7, 32, 6, 33, 6, 41, 4, 35, 6);
}

// add a process to a Queue
void Queue::Add(QNode *added)
{
	if ((*this).front == 0)				// if queue is empty
	{
		(*this).front = added;
		(*this).front->next = (*this).front->prev = 0;
	}
	else								// not empty
	{
		QNode *p = (*this).front;			// pomt to front
		while (p->next != 0)				// got to end 
			p = p->next;
		p->next = new QNode;			// make new node
		p->next = added;				// add process to node
		added->next = 0;
		added->prev = p;
	}
}

// remove process form queue
void Queue::Remove(QNode *trash)
{
	if ((*this).front == trash)							// if node to be removed is in the front
	{
		(*this).front = (*this).front->next;			// advance to next 
		if (!(*this).Empty()) (*this).front->prev = 0;	// if not empty, set front prev to 0 					
	}
	else
	{
		QNode *p = (*this).front;							// point to front
		while (p->next->process != trash->process)			// find process to be removed
			p = p->next;
		p->next = p->next->next;							// set next to skip over removed node
		if (p->next != 0)								// if next is not 0, set its prev
			p->next->prev = p;
	}
	trash->next = trash->prev = 0;							// remove prev and next from trash 
}

// sort queue by ID 
void Queue::Sort()
{
	QNode *p = (*this).front;
	QNode *part[9];
	int i = 0;
	while (p != 0)									// put all of queue in an array
	{
		part[i] = p;
		p = p->next;
		i++;
	}
	int k = i;
	int num = i;								// number of processes
	for (i = 0; i < (num - 1); i++)					// bibble sort
	{
		for (k = 0; k < (num - i - 1); k++)
		{
			if (part[k]->process->ID > part[k + 1]->process->ID)
			{
				p = part[k];
				part[k] = part[k + 1];
				part[k + 1] = p;
			}
		}
	}
	(*this).size = num;						// set size
	(*this).front = part[0];				// set front
	p = (*this).front;						// point to front
	p->prev = 0;
	for (int i = 1; i < num; ++i)				// put array (ordered processes) back in queue
	{
		p->next = part[i];					// put process in 
		p = p->next;						// infrement next node
		p->prev = part[i - 1];				// set prev
		p->next = 0;						// set next
	}
}