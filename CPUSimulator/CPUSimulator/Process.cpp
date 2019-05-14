#include "Header.h"

// print out queues, uses at context switch
void Print(int *time, QNode *CPU, Queue *ready, Queue *IO, Queue *TRASH, bool swtch)
{
	cout << "Current Time: " << *time << endl << endl;				// Time 
	cout << "Now running:  ";										// on CPU
	if(CPU != 0) cout <<	CPU->process->ID << endl;
	else cout << "[idle]" << endl;
	cout << "..................................................\n\n";
	QNode *p = ready->front;
	if (swtch == false)
	{
		cout << "Ready Queue:  Process    Burst\n";						// ready queue
		if(p==0) cout << "              [empty]\n\n";
		while(p!=0)
		{
			cout << "              " << p->process->ID << "         " << p->process->burst.top() << endl;
			p = p->next;
		}
	}
	else //              P2         10       Q1
	{
		cout << "Ready Queue:  Process    Burst    Queue\n";						// ready queue
		if(p==0) cout << "              [empty]\n\n";
		while(p!=0)
		{
			cout << "              " << p->process->ID << "         " << 
				setw(9) << left << p->process->burst.top() << "Q" << p->process->priority << endl;
			p = p->next;
		}
	}
	cout << "..................................................\n\n";
	cout << "Now in I/O:   Process    Remaining I/O time\n";		// IO queue
    p = IO->front;
	if(p==0) cout << "              [empty]\n\n";
	while(p!=0)
	{
		cout << "              " << p->process->ID << "         " << p->process->IO.top() << endl;
		p = p->next;
	}
	if(!TRASH->Empty())
	{
		p = TRASH->front;
		cout << "..................................................\n\n";
		cout << "Completed:    "<< p->process->ID;					// FINISHED processes
		while (p->next!=0)
		{
			p = p->next;
			cout <<	",  " << 	p->process->ID;
		}
	}
	cout << endl << endl << "::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n";

}

void Printf(int *time, QNode *CPU, Queue *ready, Queue *IO, Queue *TRASH, bool swtch, ofstream *myfile)
{
	*myfile << "Current Time: " << *time << endl << endl;				// Time 
	*myfile << "Now running:  ";										// on CPU
	if(CPU != 0) *myfile <<	CPU->process->ID << endl;
	else *myfile << "[idle]" << endl;
	*myfile << "..................................................\n\n";
	QNode *p = ready->front;
	if (swtch == false)
	{
		*myfile << "Ready Queue:  Process    Burst\n";						// ready queue
		if(p==0) *myfile << "              [empty]\n\n";
		while(p!=0)
		{
			*myfile << "              " << p->process->ID << "         " << p->process->burst.top() << endl;
			p = p->next;
		}
	}
	else //              P2         10       Q1
	{
		*myfile << "Ready Queue:  Process    Burst    Queue\n";						// ready queue
		if(p==0) *myfile << "              [empty]\n\n";
		while(p!=0)
		{
			*myfile << "              " << p->process->ID << "         " << 
				setw(9) << left << p->process->burst.top() << "Q" << p->process->priority << endl;
			p = p->next;
		}
	}
	*myfile << "..................................................\n\n";
	*myfile << "Now in I/O:   Process    Remaining I/O time\n";		// IO queue
    p = IO->front;
	if(p==0) *myfile << "              [empty]\n\n";
	while(p!=0)
	{
		*myfile << "              " << p->process->ID << "         " << p->process->IO.top() << endl;
		p = p->next;
	}
	if(!TRASH->Empty())
	{
		p = TRASH->front;
		*myfile << "..................................................\n\n";
		*myfile << "Completed:    "<< p->process->ID;					// FINISHED processes
		while (p->next!=0)
		{
			p = p->next;
			*myfile <<	",  " << 	p->process->ID;
		}
	}
	*myfile << endl << endl << "::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n";

}

// utilization, RT, WT, TT print out
void Report(int *time, double *idel, Queue *list)
{
	// Time and utilization
	cout << "Finished\n\n";
	cout << "Total Time:         " << *time << endl;
	cout << "CPU Utilization:    " << ((*time-*idel)/ *time) * 100 << "%" << endl << endl;
	// waiting time
	cout << "Waiting Times       P1   P2   P3   P4   P5   P6   P7   P8   P9\n                    ";   
	QNode *p = list->front;
	double avg = 0;
	for (int i = 0; i < 9; i++)
	{ 
		cout << setw(5) << left << p->process->WT;
		avg = avg + p->process->WT;
		p = p->next;
	}       
	cout << "\nAverage Wait:       " << avg/9 << endl << endl;
	// turnaround time
	cout << "Turnaround Times    P1   P2   P3   P4   P5   P6   P7   P8   P9\n                    ";
	p = list->front;
	avg = 0;
	for (int i = 0; i < 9; i++)
	{ 
		cout << setw(5) << left << p->process->TT;
		avg = avg + p->process->TT;
		p = p->next;
	}  
	cout << "\nAverage Turnaround: " << avg/9 << endl << endl;
	// responce time
	cout << "Response Times      P1   P2   P3   P4   P5   P6   P7   P8   P9\n                    ";
	p = list->front;
	avg = 0;
	for (int i = 0; i < 9; i++)
	{ 
		cout << setw(5) << left << p->process->RT;
		avg = avg + p->process->RT;
		p = p->next;
	}  
	cout << "\nAverage Response:   " << avg/9;
}

void Decrement_IO(Queue *IO)
{
	QNode *p = IO->front;
	while(p!=0)
	{
		int temp = p->process->IO.top();
		temp--;
		p->process->IO.pop();
		p->process->IO.push(temp);
		p = p->next;
	}
}

void Reportf(int *time, double *idel, Queue *list, ofstream *myfile)
{
	// Time and utilization
	*myfile << "Finished\n\n";
	*myfile << "Total Time:         " << *time << endl;
	*myfile << "CPU Utilization:    " << ((*time-*idel)/ *time) * 100 << "%" << endl << endl;
	// waiting time
	*myfile << "Waiting Times       P1   P2   P3   P4   P5   P6   P7   P8   P9\n                    ";   
	QNode *p = list->front;
	double avg = 0;
	for (int i = 0; i < 9; i++)
	{ 
		*myfile << setw(5) << left << p->process->WT;
		avg = avg + p->process->WT;
		p = p->next;
	}       
	*myfile << "\nAverage Wait:       " << avg/9 << endl << endl;
	// turnaround time
	*myfile << "Turnaround Times    P1   P2   P3   P4   P5   P6   P7   P8   P9\n                    ";
	p = list->front;
	avg = 0;
	for (int i = 0; i < 9; i++)
	{ 
		*myfile << setw(5) << left << p->process->TT;
		avg = avg + p->process->TT;
		p = p->next;
	}  
	*myfile << "\nAverage Turnaround: " << avg/9 << endl << endl;
	// responce time
	*myfile << "Response Times      P1   P2   P3   P4   P5   P6   P7   P8   P9\n                    ";
	p = list->front;
	avg = 0;
	for (int i = 0; i < 9; i++)
	{ 
		*myfile << setw(5) << left << p->process->RT;
		avg = avg + p->process->RT;
		p = p->next;
	}  
	*myfile << "\nAverage Response:   " << avg/9;
}

void Increment_WT(Queue *ready)
{
	QNode *p = ready->front;
	while(p!=0)
	{
		p->process->WT++;
		p = p->next;
	}
}

void IO_2_ready(Queue *ready, Queue *IO)
{
	QNode *p = IO->front;
	while(p!=0)
	{
		if (p->process->IO.top() == 0)
		{
			p->process->IO.pop();
			IO->Remove(p);
			ready->Add(p);
			IO_2_ready(ready, IO);
		}
		p = p->next;
	}
}

void Next_SJF(QNode **CPU, Queue *ready)
{
	QNode *p = ready->front;
	*CPU = p;
	while (p!=0)
	{
		if (p->process->burst.top() < (*CPU)->process->burst.top())
			*CPU = p;
		p = p->next;
	}
	return;
}

void Next_MLFQ(QNode **CPU, Queue *ready)
{
	for (int i = 1; 1<=3; i++)
	{
		QNode *p = ready->front;
		while (p!=0)
		{
			if (p->process->priority == i)
			{
				*CPU = p;
				return;
			}
			p = p->next;
		}
	}
}

bool Check_If_Kick(QNode *CPU, Queue *ready)
{
	QNode *p = ready->front;
	while (p!=0)
	{
		if (CPU->process->priority > p->process->priority)
			return true;
		p = p->next;
	}
	return false;
}
//Ask the user if they want to Play Again
void Again(char *goagain)
{
	//intruction if user wants to continue with another game
	cout << "\n\nDo you want to do another method?\n";
	cout << "Please ENTER:\n";
	cout << "YES.................Y\n";
	cout << "NO..................N\n";
	//users input
	cin >> goagain;
	*goagain = toupper(*goagain);
	return;
}

void FCFS()
{
	// initialize variables
	Queue ready;
	Queue I_O;
	Queue FINISHED;
	QNode *CPU;
	int time = 0;
	double idel = 0;
	ofstream myfile;
	// prep, at time 0
	ready.Set_Queue();															// set ready queue
	CPU = ready.front;															// put on CPU
	CPU->process->RT = 0;														// 0 RT
	ready.Remove(CPU);															// remove from ready queue
	cout << "\nFCFS schedualor\n";
	Print(&time, CPU, &ready, &I_O, &FINISHED, false);
	myfile.open ("FCFS.txt");
	Printf(&time, CPU, &ready, &I_O, &FINISHED, false, &myfile);
	// loop of full cpu schedual
	while ((I_O.front != 0) || (ready.front!=0) || (CPU !=0))
	{
		time++;																	// increase time
		Decrement_IO(&I_O);														// decrease IO
		Increment_WT(&ready);													// increase WT
		if (CPU != 0)															// if something is on CPU, decrement
		{
			int temp = CPU->process->burst.top();
			temp--;
			CPU->process->burst.pop();
			CPU->process->burst.push(temp);
		}
		IO_2_ready(&ready, &I_O);												// Move done in IO to ready
		if (CPU == 0 || CPU->process->burst.top() == 0)							// when process is done or CPU is idel
		{
			if(CPU != 0)														// when process is done move to queues
			{
				CPU->process->burst.pop();										// remove the 0
				if (!CPU->process->burst.empty() && !CPU->process->IO.empty())	// if both are not empty add to I/O
				{
					I_O.Add(CPU);
					I_O.Sort();
				}
				else															// if process done add to finish
				{
					CPU->process->TT = time;
					FINISHED.Add(CPU);
					FINISHED.Sort();
				}
			}

			if(!ready.Empty())													// pull next process from ready queue if can 
			{
				CPU = ready.front;
				if (CPU->process->RT == -1) CPU->process->RT = time;
				ready.Remove(CPU);
				Print(&time, CPU, &ready, &I_O, &FINISHED, false);
				Printf(&time, CPU, &ready, &I_O, &FINISHED, false, &myfile);
			}
			else if (CPU == 0) {idel++;}										// no change, add to idel time 
			else																// empty ready queue, make CPU 0
			{
				CPU = 0;
				idel++;
				Print(&time, CPU, &ready, &I_O, &FINISHED, false);
				Printf(&time, CPU, &ready, &I_O, &FINISHED, false, &myfile);
			}
		}
	}
	idel--;
	Report(&time, &idel, &FINISHED);											// ending report
	Reportf(&time, &idel, &FINISHED, &myfile);
	myfile.close();
}

void SJF()
{
	// initialize variables
	Queue ready;
	Queue I_O;
	Queue FINISHED;
	QNode *CPU = 0;
	int time = 0;
	double idel = 0;
	ofstream myfile;
	ready.Set_Queue();															// set ready queue
	Next_SJF(&CPU, &ready);
	CPU->process->RT = 0;														// 0 RT
	ready.Remove(CPU);															// remove from ready queue
	cout << "\nMLFQ schedualor\n";
	Print(&time, CPU, &ready, &I_O, &FINISHED, false);
	myfile.open ("SJF.txt");
	Printf(&time, CPU, &ready, &I_O, &FINISHED, false, &myfile);
	// loop of full cpu schedual
	while ((I_O.front != 0) || (ready.front!=0) || (CPU !=0))
	{
		time++;																	// increase time
		Decrement_IO(&I_O);														// decrease IO
		Increment_WT(&ready);													// increase WT
		if (CPU != 0)															// if CPU burst is not done, decrement
		{
			int temp = CPU->process->burst.top();
			temp--;
			CPU->process->burst.pop();
			CPU->process->burst.push(temp);
		}
		IO_2_ready(&ready, &I_O);												// Move done in IO to ready
		if (CPU == 0 || CPU->process->burst.top() == 0)							// when process is done or CPU is idel
		{
			if(CPU != 0)														// when process is done move to queues
			{
				CPU->process->burst.pop();										// remove the 0
				if (!CPU->process->burst.empty() && !CPU->process->IO.empty())	// if both are not empty add to I/O
				{
					I_O.Add(CPU);
					I_O.Sort();
				}
				else															// if process done add to finish
				{
					CPU->process->TT = time;
					FINISHED.Add(CPU);
					FINISHED.Sort();
				}
			}

			if(!ready.Empty())													// pull next process from ready queue if can 
			{
				Next_SJF(&CPU, &ready);
				if (CPU->process->RT == -1) CPU->process->RT = time;
				ready.Remove(CPU);
				Print(&time, CPU, &ready, &I_O, &FINISHED, false);
				Printf(&time, CPU, &ready, &I_O, &FINISHED, false, &myfile);
			}
			else if (CPU == 0) {idel++;}										// no change, add to idel time 
			else																// empty ready queue, make CPU 0
			{
				CPU = 0;
				idel++;
				Print(&time, CPU, &ready, &I_O, &FINISHED, false);
				Printf(&time, CPU, &ready, &I_O, &FINISHED, false, &myfile);
			}
		}
	}
	idel--;
	Report(&time, &idel, &FINISHED);											// ending report
	Reportf(&time, &idel, &FINISHED, &myfile);
	myfile.close();
}

void MLFQ()
{
	// initialize variables
	Queue ready;
	Queue I_O;
	Queue FINISHED;
	QNode *CPU;
	int time = 0;
	int TQ6 = 6;
	int TQ12 = 12;
	int TQ = TQ6;
	double idel = 0;
	ofstream myfile;

	// prep, at time 0
	ready.Set_Queue();															// set ready queue
	CPU = ready.front;															// put on CPU
	CPU->process->RT = 0;														// 0 RT
	ready.Remove(CPU);															// remove from ready queue
	cout << "\nFCFS schedualor\n";
	Print(&time, CPU, &ready, &I_O, &FINISHED, true);
	myfile.open ("MLFQ.txt");
	Printf(&time, CPU, &ready, &I_O, &FINISHED, true, &myfile);

	// loop of full cpu schedual
	while ((I_O.front != 0) || (ready.front!=0) || (CPU !=0))
	{
		bool kick = false;
		time++;																	// increase time
		Decrement_IO(&I_O);														// decrease IO
		Increment_WT(&ready);													// increase WT
		if (CPU != 0)															// if CPU burst is not done, decrement
		{
			int temp = CPU->process->burst.top();
			temp--;
			CPU->process->burst.pop();
			CPU->process->burst.push(temp);
		}
		TQ--;
		IO_2_ready(&ready, &I_O);												// Move done in IO to ready
		if (CPU != 0) kick = Check_If_Kick(CPU, &ready);

		if (CPU == 0 || CPU->process->burst.top() == 0 || TQ == 0 || kick == true)							// when process is done or CPU is idel
		{
			if(CPU == 0)	{}													// when process is done move to queues
			else if (CPU->process->burst.top() == 0)
			{
				CPU->process->burst.pop();										// remove the 0
				if (!CPU->process->burst.empty() && !CPU->process->IO.empty())	// if both are not empty add to I/O
				{
					I_O.Add(CPU);
					I_O.Sort();
				}
				else															// if process done add to finish
				{
					CPU->process->TT = time;
					FINISHED.Add(CPU);
					FINISHED.Sort();
				}
			}
			else if (TQ == 0)
			{
				CPU->process->priority++;
				ready.Add(CPU);
			}
			else if (kick == true)
			{
				ready.Add(CPU);
			}
			else cout << endl << endl << "ERROR 1" << endl << endl;
		

			if(!ready.Empty())													// pull next process from ready queue if can 
			{
				Next_MLFQ(&CPU, &ready);
				if (CPU->process->RT == -1) CPU->process->RT = time;
				ready.Remove(CPU);
				if (CPU->process->priority == 1) TQ = TQ6;
				else if (CPU->process->priority == 2) TQ = TQ12;
				else if (CPU->process->priority == 3) TQ = 0;
				else cout << endl << endl << "ERROR 2" << endl << endl;
				Print(&time, CPU, &ready, &I_O, &FINISHED, true);
				Printf(&time, CPU, &ready, &I_O, &FINISHED, true, &myfile);
			}
			else if (CPU == 0) {idel++;}										// no change, add to idel time 
			else																// empty ready queue, make CPU 0
			{
				CPU = 0;
				idel++;
				Print(&time, CPU, &ready, &I_O, &FINISHED, true);
				Printf(&time, CPU, &ready, &I_O, &FINISHED, true, &myfile);
			}
		}
	}
	idel--;																		
	Report(&time, &idel, &FINISHED);											// ending report
	Reportf(&time, &idel, &FINISHED, &myfile);
	myfile.close();
}