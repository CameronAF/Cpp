
class Vec
{
  public:
    Vec( );                 // constructor

    void push_back( int );  // similar to vector
    void pop_back( );       // remove last element in Vec

    void erase( int idx );  // erase element at position idx

    // optional:            // erase howmany elements starting at idx
    void erase( int idx, int howmany );

                            // insert a value at position idx
    void insert( int idx, int value );

    int  size( ) const;     // number of elements in array
                            // use operator [ ] as in a vector
    int  operator[ ]( int ) const;

  private:
    int array[ 5 ];         // local attribute
    int loc;                // local index
};