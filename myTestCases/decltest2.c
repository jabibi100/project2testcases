void foo_1()
{
    float x;

    {
        float y;
    }
}

void foo_2()
{
    // various forms of declarations:
    // all are uninitialized except for var1 and var6
    int var1=1, var2, var3;
    int var4, var5, var6 = 10, var7;

    // All possible operators that are part of the project:
    //  || && ! == != < > <= >=
    if( var1 == 1 && var2 <= 2 || var3 != 3 && !var4 || var5 < 3 && 4 > var6  && 5 >= var7 )
    {
        // variables inside the loop come later
        char y = 3;
    }
}

char foo_3()
{
    char x;

    // "x" is uninitialized:
    if( x == '9')
    {
        printf("%d\n", x );
    }
}

void foo_4()
{
    // various definitions:
    float var1, var2=2;
    float var3, var4;
    float var5;
    float var6;

    // arithmetic operators:
    // all variables except var2 are uninitialized:
    var6  = var1 + var2 * 2 / var3 - var4 + var5;

    // it is OK not to print var6 for project1 (technically it is undefined)
    printf( "%d\n", var6 );
}

int main(){
	foo_1();
	foo_2();
	foo_3();
	foo_4();
}