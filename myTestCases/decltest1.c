void function_a(int arg1, int arg2)
{
    // single variable uninitialized
    int f2;

    // single variable initialized with constant
    int f1 = 1;

    // single variable, initialized with another variable
    // "f2" should be flagged here:
    int f3=f2;

    // multiple variables;  one initialized with variable and another not:
    int f4,f5=1;

    // multiple variables: uninitialized/constant/variable:
    // "f6" should be reported below
    int f6,f7=1,f8=f6;

    int f9;

    // modify with another variable
    // "f4" should be flagged.  
    f6 = f4;

    // modify with constant:
    f2 = 2;

#ifdef OUT_OF_SCOPE
    // fun with post and pre:
    // "f9" should be reported.
    f9++;
    ++f9;
#endif
}

// function with no parameters:
void function_b()
{
    int x;

    // call with variable and constant:
    // "x" should be reported
    function_a(x,1);
}

// function with one parameter:
// nothing reported here
void function_c(int x)
{
    // call with no parameters:
    function_b();
    printf( "%d\n", x );
}

int main(){

function_c(10);

}

