#include "Header.h"

int main()
{
	int method = 0;
	char repeat;
	cout << "Welcome to Camerons' CPU scheduling simulator\n";
	do{	
		cout << "enter the number of what schedualing method you would like to use\n";
		cout << "FCFS - First Come First Serve....................... 1\n";
		cout << "SJF  - Shortest Job First........................... 2\n";
		cout << "MLFQ - Multi-Level Feedback Queue................... 3\n";
		cin >> method;
		switch (method)
		{
		case 1:	FCFS();
			break;
		case 2:	SJF();
			break;
		case 3:	MLFQ();
			break;
		default:
			break;
		}
		Again(&repeat);
	}while(repeat=='Y');
	return 0;
}