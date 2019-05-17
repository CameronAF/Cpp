#include    <iostream>
#include    <iomanip>
#include    <string>
using namespace std;


class Node
{
  public:
                                    // constructor
    Node( const string &, Node * );

    const string &get_word( ) const;// get a const reference to word
    Node   *get_next( ) const;      // get a Node * (value of next)
    Node   *set_next( Node * );     // set next to a new value

  private:
    string   word;
    Node    *next;
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

    void pop_front( );              // pop first element of list
                                    // output a list object
    friend ostream &operator <<( ostream &, const List & );

  private:
    Node    *head;
    Node    *tail;
};

