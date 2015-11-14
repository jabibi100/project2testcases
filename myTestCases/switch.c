void foo()
{
    int x ;
    int y;

    // "y" should be printed
    switch( y )
    {
        case 1:
        {
            x = 2;
            printf( "%d\n", x );
            break;
        }

        case 2:
            x = 3;
            printf( "%d\n", x );
            break;

        default:
            x = 4;
            printf( "%d\n", x );
            break;
    }

    // "x" should NOT be printed since it is defined in ALL blocks above:
    printf( "%d\n", x );
}

void foo2()
{
    int x;
    int y = 2;

    // y is OK here:
    switch(y)
    {
        // fall through example:
        case 1:
        case 2:
        {
            int z;

            // should print "z"
            printf( "%d\n", z );
            break;
        }

        case 3:
        default:
            // should print "x"
            printf( "%d\n", x );
    }
}

void foo3()
{
    int y;
    int x;

    switch(y)
    {
        case 0:
            y = 1;
            // y is OK here:
            printf( "%d\n", y );

            // fall through
        case 1:
            // should print "y" (not defined in the Case 1 block!)
            printf( "%d\n", y ); break;

        case 2:
            x = 3; break;

        default:
            x = 4; break;
    }

    // should print "x" since it is not initialized in the first block:
    printf( "%d\n", x );
}




void foo4()
{
    int y = 1;
    int x;

    // "y" is OK
    switch(y*2)
    {
        case 1:
        case 2:
        default:
            x = 1;
            break;
    }

    // should NOT print "x"
    printf( "x is %d\n", x );
}

void foo5()
{
    float a;
    float c;
    int b = 2;

    switch( b )
    {
        case 1:
            a = 1.0; break;
        case 2:
            a = 2.0; break;
    }

    // "a" is uninitialized since there is not DEFAULT block above.
    c = a;
}

int main(){

	void foo();
	void foo2();
	void foo3();
	void foo4();
	void foo5();
}

