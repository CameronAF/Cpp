#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#ifndef CID
#define CID

class ClientRecord
{
	public:
		int line_num;
		string last, first, address, phone_number;
		ClientRecord *next;
		friend class BST;
};

class ClientInfo
{
	public:
		ClientInfo();
		ClientRecord * Insert(const string &, const int & count);

	private:
		ClientRecord *front, *back;
};

#endif