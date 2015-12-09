void foo()
{
    int x = 1;
    int z = 1;

    {
        int y;

        printf( "%d\n", y ); // "y" is uninitialized
    }
}

void foo1()
{
    int var1;
    int var2 = 2;
    int var3 = 1;
    int var4;
	int var5;

    {
        int var10 = 2;
        printf( "%d\n", var1 ); 

        var5  = 2;

        printf( "%d\n", var4 ); 
    }

    {
        printf( "%d\n", var2 ); 
        printf( "%d\n", var3 ); 
    }

    printf("%d\n", var5 ); // "var5" is OK

}

// example I gave in the tip in the piazza
void foo2()
{
   int x;
   int z;
   int w;

    {
        int y;
        z = 2;

        printf( "%d\n", x, y );  // "y" is uninitialized
    }

    printf( "%d\n", z, w ); // "w" is uninitialized
}

void main(){

foo();
foo1();
foo2();

}