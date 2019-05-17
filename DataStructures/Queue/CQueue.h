#include    <iostream>
#include    <iomanip>
#include    <string>
using namespace std;

typedef string stack_element;

#ifndef     QUEUE_h

class QNode
{
    public:
        int time;
        QNode *prev, *next;
		QNode(){prev = next = 0;}
};

class CQueue
{
	public:
        CQueue( );
		CQueue(const CQueue &);
        ~CQueue( );
		bool Empty(){return front == 0;}
        void Enqueue(int);
        void Dequeue( );
        void Print( );
	private:
        QNode *front;
};

#endif