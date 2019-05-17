#include    "List.h"

// methods for Node
                            // constructor: init. a Node
Node::Node( const string &s, Node * p )
{
    word = s;               // init. word with a copy of s
    next = p;               // next points to p
}

                            // return a const ref to word
const string &Node::get_word( ) const
{
    return word;
}

                            // return a pointer to next node
Node *Node::get_next( ) const
{
    return next;
}

                            // sets next to pointer p and return next
Node *Node::set_next( Node * p )
{
    next = p;               // next now points to p
    return next;
}



// methods for List

List::List( )               // constructor: init. head and tail
{
    cout << "List::List( )\n";

    head = tail = 0;
}


List::List( const List &s )	// copy constructor
{
	head = s.head;
	tail = s.tail;
}


List::~List( )              // destructor: deallocate the list
{
    cout << "List::~List( )\n";

    for( Node *p = head; p; )
    {
        Node *tmp = p;      // remember current pointer
        p = p->get_next( ); // advance p to the next Node, p will Not deallocate
        delete tmp;         // deallocate tmp which deallocats list
        cout << "deallocated\t" << tmp << "\tnext is\t" << p << '\n';
    }
}


void List::push_back( const string &s )
{
                            // p points to a new node
    Node *p = new Node( s, 0 );

    if( head == 0 )         // list is empty?
    {
        head = tail = p;    // head & tail point to new node in the list
    }
    else
    {                       
        tail->set_next( p );// tail->next points to new node
        tail = p;           // tail points to last node in the list
    }
}


void List::push_front( const string &s )
{
	                        // p points to a new node
    Node *p = new Node( s, 0 );

    if( tail == 0 )         // tail not pointing to a node yet?
    {
        head = tail = p;    // head & tail point to new node in the list
    }
    else
    {                       
		p -> set_next(head);// set added Node's p.next to head of list
        head = p;           // head points to added node in the list
    }
}


void List::pop_front( )
{
	if( head == 0 )			// list is empty; error
    {
        cerr << "list is empty\n\n";
		return;          
    }
    else                    // set head to head -> next
    {
		head = head -> get_next(); 
    }
}


ostream &operator <<( ostream &out, const List &list )  //cout
{
    for( Node *p = list.head; p != 0; p = p->get_next( ) )
    {
        cout << p << '\t' << setw( 8 ) << p->get_word( )
             << '\t' << "next:" << '\t' << p->get_next( ) << '\n';
    }

    return out;
}