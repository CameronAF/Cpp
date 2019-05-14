#include    "Thread.h"

class QNode
{
	public:
		Thread *process;
		QNode *prev, *next;
		QNode() { prev = next = 0; process = 0; }
};

