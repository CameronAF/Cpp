#include	"Queue.h"

void Print(int *time, QNode *CPU, Queue *ready, Queue *IO, Queue *TRASH, bool swtch);
void Printf(int *time, QNode *CPU, Queue *ready, Queue *IO, Queue *TRASH, bool swtch, ofstream *myfile);
void Report(int *time, double *idel, Queue *list);
void Reportf(int *time, double *idel, Queue *list, ofstream *myfile);
void Decrement_IO(Queue *IO);
void Increment_WT(Queue *ready);
void IO_2_ready(Queue *ready, Queue *IO);
void Next_SJF(QNode **CPU, Queue *ready);
void Next_MLFQ(QNode **CPU, Queue *ready);
bool Check_If_Kick(QNode *CPU, Queue *ready);
void Again(char *goagain);
void FCFS();
void SJF();
void MLFQ();
