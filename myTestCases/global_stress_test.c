/* 
 * A more complicated example
 *
 */

// main always calls foo2() which calls foo1() which DEFines g0 before USE
// so no need to print
int g0;

// g1 is used in foo1() which is called from main() through foo2()
// main defines g1 AFTER calling foo1()
// Hence g1 needs to be printed
int g1;

//
// g2 is USED in foo1() which is called ALWAYS from main() through foo2()
// main DEFines g2 but does it *conditionally*;  hence needs to be printed
//
int g2;

// g3 is DEFined by foo3() which is ALWAYS called from main()
// g3 is USED by foo1() AFTER main calls foo3()
// hence no need to print g3
int g3;

//
// g4 is DEFined by foo1(), but USED by foo2()
// foo2() is called BEFORE foo1() and hence g4 needs to be be printed:

int g4;

// foo2() DEFines g5 before its USE in main(); 
int g5;

//
// foo4() DEFines g6, but foo4() is called conditionally; 
// main() USEs g6
// hence g6 needs to be printed:
//
int g6;

// g7 is not DEFined anywhere
// USEd by main()
// hence needs to be printed:
int g7;

// foo1 is always called since it is called from 
// foo2 which is always called from main()
int foo1(int y)
{
    int x1, x2;

    // since foo1 is always called g0 is initialized
    g0 = y;

    // g4 is used before initialization in foo2()
    // hence g4 needs to be printed:
    g4 = 22;

    // x1 and x2 are uninitialized
    // g1 needs to be printed;  it is initialized in main() after its use here
    // g2 needs to be printed since it is conditionally initialized in main()
    // g3 is OK;  it is initialized in foo3() BEFORE its use here
    y = x1;
    switch( x2 )
    {
        case 1: x2 = g1; break;
        case 2: x2 = g2; break;
        case 3: x2 = g3; break;
    }
}


// foo2 is always called from main:
void foo2()
{
    int y1, y2;

    // print y1
    int z1 = y1;

    // g5 is initialized
    // g4 needs to be printed -> it is DEFined in foo1() AFTER its USE here:
    g5 = foo1(g4);

    // print y2
    if( y2 > 12 )
    {
        printf( "hey, we should print y2 since it is undefined!\n" );
    }
}


// foo3 is always called from main
void foo3()
{
    int z1;
    int z2;

    // print z1
    while( z1 < 20 )
    {
        printf( "need to exit somehow\n" );
    }

    // print z2
    // g3 is initialized since ALL cases and default initialize it
    switch(z2){
       case 1: g3 = 110; break;
       default: g3 = 120;
    }
}

// foo4 not always called:
void foo4(int x)
{
    int t1, t2;

    // print t1
    x = t1;

    // g6 is not DEFined always since foo4() is not called always!
    g6 = 12;
}


void main()
{
    int r1, r2;
    int r3 = 22;

    if( r3 > 22 )
        g2 = 12;

    // print r1:
    // call foo3() always since it is both THEN and ELSE
    if( r1 > 20 )   
        foo3();
    else 
        foo3();

    // print r2:
    // call foo2() always - fall thru and default present:
    switch(r2) {
        case 1: 
        default: foo2();
    }

    // foo4 *not always* called:
    // g3 is DEFined always in foo3()
    while(r2>100) foo4(g3);

    // g0 is initialized:
    // print g6 since it is not DEFined always (foo4 is called conditionally)
    r1 = g0;
    r2 = g6;

    // g1 was used in foo1() therefore it needs to be printed:
    g1 = 12;

    // g5 was DEFined in foo2()
    printf( "%d %d\n", g5 );

    // need to print g7:
    printf( "g7 is not DEFined so need to print!%d\n", g7 );
}
