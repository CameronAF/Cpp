#include "BST.h"

BST::BST()
{
	root = 0;
}


void BST::Insert(const string &key, const int & count)
{
	Insert(root,key,count);
}


void BST::Insert(bnode * & loc_ptr, const string & key, const int & count)
{
	if (loc_ptr== 0)
	{

		loc_ptr = new bnode;
		loc_ptr->lchild = 0;
		loc_ptr->rchild = 0;
		loc_ptr->rest_of_data = CDATA.Insert(key,count);
		loc_ptr->first=loc_ptr->rest_of_data->first;
		loc_ptr->last=loc_ptr->rest_of_data->last;
		loc_ptr->fullname = loc_ptr->last + loc_ptr->first;
	}
	else if (loc_ptr->fullname > key)
	{
		Insert(loc_ptr->lchild,key,count);
	}
	else if (loc_ptr->fullname < key)
	{
		Insert(loc_ptr->rchild,key,count);
	}
	else
	{
		cout<<"Cant Have Duplicate"<<endl;
	}
}

void BST::Search(string &name)
{
	Search(root,name);
}

void BST::Search(bnode * &loc_ptr,string &name)
{
	
	//1st check for an empty tree
	if (loc_ptr==0)
	{
		cout<<"could not find that name"<<endl;	
	}
	//2nd not empty - search left if smaller then current node
	else if (loc_ptr->fullname > name)
	{
		Search(loc_ptr->lchild, name);
	}
	//2.5nd not empty - search right if greater then current node
	else if (loc_ptr->fullname < name)
	{
		Search(loc_ptr->rchild, name);
	}
	//item found
	else if (loc_ptr->fullname == name)
	{
		cout<< setw(loc_ptr->rest_of_data->last.length()) << loc_ptr->rest_of_data->last << ", " << setw(20-loc_ptr->rest_of_data->last.length()) << left << loc_ptr->rest_of_data->first
			<< setw(29)  << loc_ptr->rest_of_data->address
			<< setw(10)  << loc_ptr->rest_of_data->phone_number
			<< loc_ptr->rest_of_data-> line_num << endl;
	}
		//could not find
	else
	{
			cout<<"could not find that name"<<endl;
	}
}

void BST::Mod(string &name)
{
	Mod(root,name);
}

void BST::Mod(bnode * &loc_ptr,string &name)
{
	
	//1st check for an empty tree
	if (loc_ptr==0)
	{
		cout<<"could not find that name"<<endl;	
	}
	//2nd not empty - search left if smaller then current node
	else if (loc_ptr->fullname > name)
	{
		Mod(loc_ptr->lchild, name);
	}
	//2.5nd not empty - search right if greater then current node
	else if (loc_ptr->fullname < name)
	{
		Mod(loc_ptr->rchild, name);
	}
	//item found
	else if (loc_ptr->fullname == name)
	{
		cout << "Names cannot be changed" <<endl;
		cout << "Do you want to change the address?" <<endl;
		cout << "Y.....YES/tor  /tN.....NO" << endl; 
		char reply;
		cin >> reply;
		reply=toupper(reply);
		if (reply == 'Y')
		{
			cout << "Enter the new address" <<endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin,loc_ptr->rest_of_data->address);
		}
		cout << "Do you want to change the phone number?" <<endl;
		cout << "Y..........YES      or      N..........NO" << endl; 
		cin >> reply;
		reply=toupper(reply);
		if (reply == 'Y')
		{
			cout << "Enter the new phone number" <<endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin,loc_ptr->rest_of_data->phone_number);
		}
	}
		//could not find
	else
	{
			cout<<"could not find that name"<<endl;
	}
}

void BST::Dele(string &name)
{
	Dele(root,name);
}

void BST::Dele(bnode * &loc_ptr, string &item)
{
	//1st check for an empty tree
	if (loc_ptr==0)
	{
		cout<<"Tree has as an empty brain"<<endl;
	}
	//2nd not empty - search left if smaller then current node
	else if (loc_ptr->fullname > item)
	{
		Dele(loc_ptr->lchild, item);
	}
	//2.5nd not empty - search right if greater then current node
	else if (loc_ptr->fullname < item)
	{
		Dele(loc_ptr->rchild, item);
	}
	//item found to be deleted
	else
	{
		bnode *ptr;
		//one child
		if (loc_ptr->lchild == 0)
		{
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
			cout << "Deleted item"<<endl;
		}
		//one child
		else if (loc_ptr->rchild == 0 )
		{

			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
			cout << "Deleted item"<<endl;
		}
		//2 children - non-trivial; recursion
		else
		{
			ptr = inorder_succ(loc_ptr);
			loc_ptr->first = ptr->first;
			loc_ptr->last = ptr->last;
			loc_ptr->fullname = ptr->fullname;
			loc_ptr->rest_of_data = ptr->rest_of_data;
			Dele(loc_ptr->rchild, ptr->fullname); //delete successor

		}
	}
}

// successor - left most child of the right most child of the node to-be-deleted
bnode * BST::inorder_succ(bnode * &loc_ptr)
{
	bnode *ptr = loc_ptr->rchild;

	while(ptr->lchild!=0)
	{
		ptr=ptr->lchild;
	}
	return ptr;
}

//void BST::ADD(string &name, string &lname, string &fname, int &count)
//{
//	ADD(root,name, lname, fname, count);
//}
//
//
//void BST::ADD(bnode * &loc_ptr, string &name, string &lname, string &fname, int &count)
//{
//	if (loc_ptr== 0)
//	{
//
//		loc_ptr = new bnode;
//		loc_ptr->lchild = 0;
//		loc_ptr->rchild = 0;
//		loc_ptr->rest_of_data = CDATA.add(name, lname, fname, count);
//		loc_ptr->first=loc_ptr->rest_of_data->first;
//		loc_ptr->last=loc_ptr->rest_of_data->last;
//		loc_ptr->fullname = loc_ptr->last + loc_ptr->first;
//	}
//	else if (loc_ptr->fullname > key)
//	{
//		Insert(loc_ptr->lchild,key,count);
//	}
//	else if (loc_ptr->fullname < key)
//	{
//		Insert(loc_ptr->rchild,key,count);
//	}
//	else
//	{
//		cout<<"Cant Have Duplicate"<<endl;
//	}
//}

void BST::Print_InOrder()
{

	Print_InOrder(root);

}

void BST::Print_InOrder(bnode * &loc_ptr)
{

	if (loc_ptr != 0)
	{
		Print_InOrder(loc_ptr->lchild);
		cout<< setw(loc_ptr->rest_of_data->last.length()) << loc_ptr->rest_of_data->last << ", " << setw(20-loc_ptr->rest_of_data->last.length()) << left << loc_ptr->rest_of_data->first
			<< setw(29)  << loc_ptr->rest_of_data->address
			<< setw(10)  << loc_ptr->rest_of_data->phone_number
			<< loc_ptr->rest_of_data-> line_num << endl;
		Print_InOrder(loc_ptr->rchild);
	}
}

void BST::Save_InOrder(ofstream &out)
{

	Save_InOrder(root,out);

}

void BST::Save_InOrder(bnode * &loc_ptr,ofstream &out)
{

	if (loc_ptr != 0)
	{
		Save_InOrder(loc_ptr->lchild,out);
		out << setw(loc_ptr->rest_of_data->last.length()) << loc_ptr->rest_of_data->last << ", " << setw(20-loc_ptr->rest_of_data->last.length()) << left << loc_ptr->rest_of_data->first
			<< setw(29)  << loc_ptr->rest_of_data->address
			<< setw(10)  << loc_ptr->rest_of_data->phone_number
			<< loc_ptr->rest_of_data-> line_num << endl;
		Save_InOrder(loc_ptr->rchild,out);
	}
}