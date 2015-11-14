void main()
{
    int z = 12;
    int x;
    int y;
    int w;
    int r = 0, s;

    // "x" should be printed
    printf( "%d\n", x == 1 ? 12 : 13 );

    // "y" should be printed:
    printf( "%d\n", z == 12 ? y : 13 );

    // "w" and "s" should be printed:
    printf( "%d\n", z == 12 ? (w * 12 + 43) : (r + s) );
}


