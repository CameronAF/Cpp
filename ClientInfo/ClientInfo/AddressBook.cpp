#include "AddressBook.h"

AddressBook::AddressBook()
{
	string info;
	count = 0;
	string str;
	cout<<"Name the address_book file you would like to open."<<endl
		<<"Please include '.txt' at the end of the file name"<<endl;
	cin>>str;
	ifstream in(str);
	if (in.fail())
	{
		cout<<"FILE NOT FOUND"<<endl;
		count = -1;
	}
	cout<<"FILE OPENED"<<endl;
	while(!in.eof())
	{
		getline(in,info);
		count++;
		book.Insert(info, count);
	}

	in.close();
}

void AddressBook::Add(string &info)
{
	book.Insert(info, 0);
}

void AddressBook::Del(string &name)
{
	book.Del(name);
}

void AddressBook::Search(string &name)
{
	book.Search(name);
}

void AddressBook::Print()
{
	book.Print();
}

void AddressBook::Save_Exit()
{
	book.Save();
}

int AddressBook::Get_count()
{
	return count;
}

void AddressBook::Modify(string & name)
{
	book.Modify(name);
}