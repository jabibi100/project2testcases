void foo()
{
    int x = 2;
    int y;

    if( x > 1 )
    {
        y = 2;
    }
    else
    {
        y = 1;
    }


   // "y" should be OK
   printf( "%d\n", y );
}

void foo2()
{
    int x = 1;
    int y;

    if( x > 1 )
    {
        y = 2;
    }
    else if( x < 1 )
    {
        y = 3;
    }

    // "y" should be printed since there is no ELSE:
    printf( "%d\n", y );
}

void foo3()
{
    float y;
    float z;
    float w = 1;

    // "y" should be printed
    if( y > 2)
    {
        // "w' is OK
        printf( "%f\n", w );
        z = 2.0;
    }

    // "z" should be printed:
    printf( "%f\n", z );
}

void foo4()
{
    int y = 1;
    char z;

    if( y > 0 ){
        z = 'a';
	}
    else if( y == 0 ){
        z = 'b';
	}
    else{
        z = 'c';
	}

    // "z" should NOT be printed:
    printf( "%d\n", z );
}


void foo5()
{
    int x = 2;
    int y;
    int z;

    if( x > 1 )
        y = 2;
    else
    {
        // "z" should be printed
        if( z < 2 )
        {
            y = 3;
        }
    }

    // "y" should be printed:
    printf( "%d\n", y );
}


void foo6()
{
    int x = 2;
    int y;

    if( x < 1 )
    {
        y = 100;
    }
    else
    {
        if( x < 100 ){
            y = 101;
			y = 201;
		}
        else{
            y = 102;
		}
    }
        
    // "y" should be OK
    printf( "%d\n", y );
}


int main(){

foo();
foo1();
foo2();
foo3();
foo4();
foo5();
foo6();

}


