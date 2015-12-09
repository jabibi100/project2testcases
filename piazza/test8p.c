int x;
int y = 2;
int z;

void f1(int *p) {
	*p = z;
}

void f2(int *p) {
	z = 5;
}

int f3() {
	int a = 4;
	int b;
	int c;
	int d;
	f2(&b);
	c = a >> 2 - a * (b - a * (b & 1));
	f1(&d);
	return d;
}

void f4(int m) {
	int r[3];
	int a;
	scanf("%d", &r[m]);
	scanf("%d", &r[a]);
}

void f5(int x) {
    int a = x;
    int b;
    int c = b;
}

main () {
	printf("x=%d, y=%d", x, y);
}