
void f1(int *b) {
	int c;
	*b = c;
}

main () {
	int a;
        int b;
	f1(&a);
	switch (a) {
		case 4:
                        a = 5;
		default:
                        b = 5 + a;
	}
        printf("%d - %d", a, b);
}