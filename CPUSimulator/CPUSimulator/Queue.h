#include    "QNode.h"

class Queue
{
	public:
		Queue() { front = 0; size = 0; }
		Queue(const Queue &);
		void Set_Queue();
		void Add(QNode *);
		void Remove(QNode *);
		void Sort();
		bool Empty() { return front == 0; }
		//private:
		QNode *front;
		int size;
};

