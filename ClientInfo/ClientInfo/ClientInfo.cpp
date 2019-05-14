#include "ClientInfo.h"

ClientInfo::ClientInfo()
{
	front = back = 0;
}

ClientRecord * ClientInfo::Insert(const string & tot_info, const int & count)
{

	ClientRecord *p = new ClientRecord;

	int len;

	p->address = tot_info;
	len=p->address.find(" ");
	p->last=p->address.substr(0,len);
	p->address.erase(0,len+1);
	len=p->address.find(" ");
	p->first=p->address.substr(0,len);
	p->address.erase(0,len+1);
	len=p->address.rfind(" ");
	p->phone_number=p->address.substr(len+1,8);
	p->address.erase(len,9);
	p->next = 0;
	p->line_num=count;

	if (front == 0)
	{
		back = front = p;
	}
	else
	{
	
			back->next = p;
			back = p;
	}

	return p;

}
