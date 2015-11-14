void foo()
{
    int x;

    while ( x < 2 )
    {
        int y;
        x = 2;

        // "y" should be printed:
        printf( "%d\n", y );
    }

    // "x" should be printed:
    //printf( "%d\n", x );
}

void foo2()
{
    int x = 2;
    int y;
    int z;

    while ( x < 2 )
    {
        printf( "%d\n", x );
        //
        // "y" should be reported:
        while( y < 3 )
        {
            z = 1;
            printf( "%d\n", y );
        }
        
        // "z" should be reported:
        printf( "%d\n", z );
    }
}


void foo3()
{
    int x;
    int y;

    // "x" should be reported
    while(x > 2)
    {
        int z;

        y = 2;

        // "z" should be reported
        printf( "%d\n", z );
    }

    // "y" should be reported..
    printf( "%d\n", y );

#if 0
    while( x > 2 )
        while( y > 1 )
            printf( "hello\n" );
#endif
}

int main(){
	foo();
	foo2();
	foo3();
}


