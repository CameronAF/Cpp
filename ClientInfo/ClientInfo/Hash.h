#include "BST.h"

class Hash
{
	public:
		Hash();
		unsigned int Hash_Function(const string &);
		void Insert(const string &, const int & count);
		void Print();
		void Save();
		void Search(string & name);
		void Del(string & name);
		void Modify(string & name);

	private:
		BST HT[27];
};