#include "Thread.h"

// initialize - name proccess and fill IO and Burst stacks 
void Thread::Fill_Thread(string name, int count, ...)
{
	ID = name;
	arrival = 0;
	va_list num;							// list of many IO and Burst
	va_start(num, count);
	burst.push(va_arg(num, int));			// put last burst in stack
	for (int i = 1; i < count; i += 2)		// loop to put IO and Burst in stack
	{
		IO.push(va_arg(num, int));
		burst.push(va_arg(num, int));
	}
	va_end(num);
	return;
};
