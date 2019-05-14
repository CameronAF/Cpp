#include "Hash.h"

Hash::Hash()
{
}

void Hash::Insert(const string & info, const int & count)
{
	HT[Hash_Function(info)].Insert(info,count);
}

unsigned int Hash::Hash_Function(const string & info)
{

	return int(info[0]) - 64;
}

void Hash::Search(string &name)
{
	HT[Hash_Function(name)].Search(name);
}

void Hash::Del(string &name)
{
	HT[Hash_Function(name)].Dele(name);
}

void Hash::Modify(string &name)
{
	HT[Hash_Function(name)].Mod(name);
}

void Hash::Print()
{
	for(unsigned int i = 1; i<27; i++)
	{
		HT[i].Print_InOrder();
	}
}

void Hash::Save()
{
	ofstream out("sorted_clients_address_bk.txt");
	for(unsigned int i = 1; i<27; i++)
	{
		HT[i].Save_InOrder(out);
	}
	out.close();
	cout << "FILE SAVED" <<endl;
}
