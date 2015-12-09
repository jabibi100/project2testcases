int x;

int f3(int *p, int val) { *p = val; }

main() {
	int a;
	int b = 7;
	int c = 9;
	c = f3(&a, x+c);
	scanf("%d", &b);
}