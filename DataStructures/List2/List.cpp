#include    "List.h"


// methods for Node

                            // constructor: init. a Node
Node::Node( const string &s, Node *n, Node *p )
{
    word = s;               // init. word with a copy of s
    next = n;               // next points to n
    prev = p;               // prev points to p
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

                            // return a pointer to prev node
Node *Node::get_prev( ) const
{
    return prev;
}

                            // sets next to pointer n and return next
Node *Node::set_next( Node *n )
{
    next = n;               // next now points to n
    return next;
}

                            // sets prev to pointer p and return prev
Node *Node::set_prev( Node *p )
{
    prev = p;               // prev now points to p
    return prev;
}





// methods for List

List::List( )               // constructor: init. head and tail
{
    cout << "List::List( )\n";

    head = tail = 0;
}


List::List( const List &rhs )
{
    copy_list( rhs );
}


List::~List( )              // destructor: delete the list
{
    cout << "List::~List( )\n";
    for( Node *p = head; p; )
    {
        Node *tmp = p;			// remember current pointer

        p = p->get_next();      // advance p to the next node
       
		delete tmp;             // deallocate tmp
    }
}


void List::copy_list( const List &rhs )
{
    head = tail = 0;
                            // copy rhs' list into this
    for( Node *p = rhs.head; p; p = p->get_next( ) )
    {
        push_back( p->get_word( ) );
    }
}


void List::push_back( const string &s )
{
                            // p points to a new node
    Node *p = new Node( s, 0, tail );

    if( tail == 0 )         // tail not pointing to a node yet?
    {
        head = tail = p;    // head & tail point to new node in the list
    }
    else
    {                       // tail->next points to new node
        tail->set_next( p );
        tail = p;           // tail points to last node in the list
    }
}


void List::pop_back( )
{
    if( tail )              // tail points to a node?
    {
        Node *tmp = tail;
        tail      = tail->get_prev( );

        delete tmp;         // delete node to be removed

        if( tail == 0 )     // no more elements in the list?
        {
            head = 0;
        }
        else
        {
            tail->set_next( 0 );
        }
    }
}

// remaining methods for List


void List::delete_list( )   // delete a linked list
{
    head = tail = 0;
}


void List::push_front( const string &s )
{
                            // p points to a new node
    Node *p = new Node( s, head, 0 );

    if( tail == 0 )         // tail not pointing to a node yet?
    {
        head = tail = p;    // head & tail point to new node in the list
    }
    else
    {                       
		p -> set_next(head);// set added Node's p.next to head of list
        head -> set_prev(p);
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
		if (head == tail)
		{
			head = tail = 0;
		}
		else
		{
			head = head -> get_next(); 
			head -> set_prev(0);
		}
    }
}

                            // method for the optional part of lab-07
List &List::operator =( const List &rhs )
{
    head=rhs.head;
	tail=rhs.tail;
	return *this;
}


ostream &operator <<( ostream &out, const List &list )
{
    for( Node *p = list.head; p; p = p->get_next( ) )
    {
        cout << p << '\t' << p->get_prev( ) << '\t' << p->get_word( ) << '\t'
             << p->get_next( ) << '\n';
    }

    return out;
}


Node *List::begin( ) const  // beginning of a linked list
{
    return head;
}


Node *List::end( ) const    // end of a linked list
{
    return 0;
}




// methods for Iterator
                            // constructor: init. an Iterator
List::Iterator::Iterator( Node * p )
{
    current = p;            // current points to p
}

                            // get a const ref to word
const string &List::Iterator::operator *( ) const
{
    return current->get_word( );
}

                            // get a const ref to word
void List::Iterator::operator ++( )
{
    if( current )
    {
        current = current->get_next( );
    }
}

                            // current != p
bool List::Iterator::operator !=( Node * p ) const
{
    return current != p;
}

