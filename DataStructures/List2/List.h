#include    <iostream>
#include    <iomanip>
#include    <string>
using namespace std;


class Node
{
  public:
                                    // constructor
    Node( const string &, Node *, Node * );

    const string &get_word( ) const;// get a const reference to word
    Node   *get_next( ) const;      // get a Node * (value of next)
    Node   *get_prev( ) const;      // get a Node * (value of prev)
    Node   *set_next( Node * );     // set next to a new value
    Node   *set_prev( Node * );     // set prev to a new value

  private:
    string   word;
    Node    *next;
    Node    *prev;
};


class List
{
  public:
    List( );                        // constructor
    List( const List & );           // copy constructor
    ~List( );                       // destructor
                                    // push a node to the back of list
    void push_back( const string & );
                                    // push a node to the front of list
    void push_front( const string & );
                                    // pop  a node from the back  of list
    void pop_back( );
                                    // pop  a node from the front of list
    void pop_front( );
                                    // member function for the optional part
    List &operator =( const List & );
                                    // output a list object
    friend ostream &operator <<( ostream &, const List & );

    Node *begin( ) const;           // pointer to beginning of the list
    Node *end( ) const;             // pointer to end       of the list

    class Iterator
    {
      public:
        Iterator( Node * );
                                    // same as word( )
        const string &operator *( ) const;
        void operator ++( );        // same as next( )
        bool operator !=( Node * ) const;

      private:
        Node *current;
    };

  private:

    Node    *head;
    Node    *tail;

    void copy_list( const List &  );// copy a linked list
    void delete_list( );            // delete a linked list
};

