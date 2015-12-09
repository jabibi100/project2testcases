int x;
int y = 2;
int z;

void f1() {
	int a = 5;
	int b;
	int c;
	int d;
	if (a + b < 5) {
		c = 5;
		d = 10;
	} else {
		b = 8;
		d = 11;
	}
	a = b + c + d;
}

void f2() {
	int a;
	int b = 4;
	int c = b;
	int d;
	while (c > 0) {
		c--;
		d = 10;
	}
	printf("d=%d", d);
}

void f3() {
	int a;
	int b = a;
	int c;
	int d;
	switch (a) {
		case 1: {
			d = 1;
			c++;
                        break;
		}
		case 2: {
			d = 2;
                        break;
		}
	}
	c = 5 + d;
}

main () {
	f1();
	f3();
	f2();
}