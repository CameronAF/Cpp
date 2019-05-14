#include "ClientInfo.h"

#ifndef BN
#define BN

class bnode
{
	public:

		string last, first, fullname;
		bnode *lchild, *rchild;
		ClientRecord *rest_of_data;
};


class BST
{
	public:
		BST();
		bool Empty(){return root ==0;};
		void Insert(const string &key, const int & count);
		void Insert(bnode * &, const string &, const int & count);
		void Del(bnode * & loc_ptr, const string & item);
		void Print_InOrder();
		void Print_InOrder(bnode *&);
		void Save_InOrder(ofstream &out);
		void Save_InOrder(bnode *&, ofstream &out);
		void Search(string &name);
		void Search(bnode * &loc_ptr,string &name);
		void Dele(string &name);
		void Dele(bnode * &loc_ptr,string &item);
		void Mod(string &name);
		void Mod(bnode * &loc_ptr,string &item);
		bnode * inorder_succ(bnode * &loc_ptr);

	private:

		ClientInfo CDATA;
		bnode *root;
};

#endif