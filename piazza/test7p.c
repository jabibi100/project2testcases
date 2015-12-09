int x;
int y = 2;
int z;

int f1(int m, int n) {
	int a = m;
	int b = n;
	int c;
	int d;
	if (a + b < 5) {
		if (b > 10)
			d = 10;
		else
			c = 5;
	} else {
		c = m;
		d = 11;
	}
	return b + c + d;
}

int f2() {
	int a;
	int b = 4;
	int c = b;
	int d;
	while (1) {
		c--;
		d = 10;
		if (c == 0) {
			break;
		}
	}
	scanf("%d", &a);
	printf("d=%d, a=%d", d, a);
	return y;
}

int f3() {
	int a = 2;
	int b = a;
	int c;
	int d;
	switch (a) {
		case 1: {
			d = a;
			break;
		}
		case 2: {
			c = b;
		}
		default: {
			d = 2;
		}
	}
	return f1(c, d);
}

main () {
	int c;
	int a;
	f2();
	c = f3();
	z = c;
	printf("c=%d, a=%d, x=%d, z=%d", c, a, x, z);
}