int foo()
{
    int x;

    // "x" is uninitialized:
    return x;
}

void foo2()
{
    int y;

    return;
}

float foo3()
{
    int x;
    int y;

    // x and y are uninitialized:
    return x+y;
}

int main(){
	foo();
	foo2();
	foo3();
}
