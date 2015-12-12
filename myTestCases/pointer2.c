foo(int * blah){
	*blah = 10;
}

int main(){
	int a;
	int * b;

	int var = 20;
	int * p1,p2,p3;

	if(var){
		*p1 = 10;
	}
	else{
		p2 = &var;
	}

	printf("%d %d\n", p1,p2);

	foo(&a);
	foo(b);
	printf("%d %d\n" a, b);
}
