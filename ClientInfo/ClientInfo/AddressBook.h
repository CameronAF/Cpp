#include "Hash.h"

class AddressBook
{
	public:
		AddressBook();		//initialize open data file
		void Add(string &);
		void Del(string &);
		void Print();
		void Modify(string &);
		void Search(string &);
		void Save_Exit();
		int Get_count();

	private:
		int count;
		Hash book;
};