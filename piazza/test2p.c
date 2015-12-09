/*
main:m
*/

int fa(int a, int b, int c, int d, int e, int f, int g, int *h) {
	return a+b+c+d;
}

main() {
	int m;
	int n;
	n = fa(1,2,3,4,5,6,7,&m);
	n++;
	switch (n) {
		case 1: 
			n--;
			m--;
			n--;
			break;
		case 2: 
		case 3: 
			n++;
			m++;
			n++;
			break;
		default:
			++n;
			++m;
	}
}