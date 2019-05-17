#include    "List.h"


int main( )
{
    List la;                    // create list la

    la.push_front( "mom" );
    la.push_back( "please" );
    la.push_back( "send" );
    la.push_back( "money" );
    la.push_front( "hi" );

    cout << "\nla contains:\n" << la << '\n';

    List lb( la );              // copy list la to lb

    cout << "lb contains:\n" << lb << '\n';

    lb.pop_front( );
    lb.pop_front( );
    lb.push_front( "mother" );
    lb.push_front( "dear" );
    lb.push_back( "Bubba" );

    cout << "lb contains:\n" << lb << '\n';


    cout << "\n\nOPTIONAL PART\n";

    List lc;                    // create list lc
    lc.push_back( "money" );
    lc.push_front( "send" );

    cout << "\nlc contains:\n" << lc << '\n';

    List ld;                    // create list ld
    cout << "\nld contains nothing:\n" << ld << '\n';

    ld.push_front( "hi" );
    cout << "ld contains:\n" << ld << '\n';

    ld.pop_front( );
    cout << "ld contains nothing:\n" << ld << '\n';

    ld.push_back( "hello" );
    ld.push_back( "Bubba" );
    cout << "ld contains:\n" << ld << '\n';

    ld.pop_front( );
    cout << "ld contains:\n" << ld << '\n';

    ld.pop_front( );
    cout << "ld contains nothing:\n" << ld << '\n';

    List le( ld );
    cout << "le contains nothing:\n" << le << '\n';

    le.push_back( "last" );
    cout << "le contains:\n" << le << '\n';

    cout << "END OPTIONAL PART\n\n";

    return 0;
}

