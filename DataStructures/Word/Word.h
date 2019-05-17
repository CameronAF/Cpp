#include    <iostream>
#include	<fstream>
#include    <iomanip>
#include    <string>

using namespace std;

#ifndef     WORD_h

// Node of linked-list
class alpha_numeric
{
	public:
		char symbol;
		alpha_numeric *next;
};

// linked-list
class Word
{
	public:
		Word();
		Word(string);
		Word( const Word &);
		~Word();
		bool IsEmpty();
		int Length();
		void Add(char);
		void Insert(const Word &, int);
		bool Search(alpha_numeric *&, const Word &);
		void Remove(const Word &);
		void RemoveAll(const Word &);
		bool IsEqual(const Word &);
		void SetEqual(const Word &);
		void CatWords(const Word &);
		Word &operator =(const string &);			
		Word &operator =(const Word &);			
		friend ostream &operator <<(ostream &, Word &);	

	private:
		alpha_numeric *front;
		int length;
};

#endif
