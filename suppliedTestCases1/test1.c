void foo(int i)
{
   int a;
   if (i) a = 1;
   printf("a = %d", a);
   a = 3;
   if (i) a = 1;
   else a = 2;
}
main()
{
   foo(0);
}

