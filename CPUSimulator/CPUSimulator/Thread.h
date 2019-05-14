#include    <iostream>
#include	<fstream>
#include    <iomanip>
#include	<stack>
#include	<list>
#include	<vector>
#include	<string>
#include    <stdarg.h>
using namespace std;

class Thread
{
	public:
		string ID;
		int arrival;
		int RT;
		int WT;
		int TT;
		stack<int> burst;
		stack<int> IO;
		int priority;
		Thread() { arrival = WT = TT = 0; priority = 1; RT = -1; }
		void Fill_Thread(string name, int count, ...);
};

