int g1, g2, g3, g4, g5, g6, g7, g8, g9;
int nathan = 76;

int loops(){
	int a, b, c, d;
	while (a < 10) { 
		int e = 2;
		b = 1;
		while(1){
			c = 1;
			while (d < 1){
				d = d + 1;
			}
		}
	}
	return a + b + c + d + e; //should not report e here it should actually be a compiler error
}

int switches(){
	int f, g, h, i, j;
	switch(f){
		case 1: g = 2; h = g;  
		default: break;
	}
	switch(f){
		case 1: i = 2; break;
		default: i = 2; break;
	}
	switch(f){
		case 1: j = 2;
	}
	return f + g + h + i + j;
}

int cond(){
	int k, l, m, n, o;
	if(1){
		k = 2;
	}

	if(1){
		l = 2;
		m = 1;
	}
	else{
		l = 2;
		n = 1;
	}          

	if(1){
		m = 1;
		o = 2;
	}
	else if(1){
		n = 1;
		o = 3;
	}
	else {
		m = 1;
		o = 4;
	}          

	return k + l + m + n + o;
}

int parameters(int x, int y){
	int p, q;
	p = x;
	q = y;
	printf("mind your %d's and %d's\n", p, q);
}

int nested(){
	int r,s,t,u,v,w;
	switch(r){
		case 1:
		{
			while(2){
			 	if(s) t = 3;
				s = 0;
				break;
			}
			break;
		}
	}

	while (u < 10){
		if(v){
			switch(r){
				default: w = 2; break;
			}
		}
		continue;
	}
	return r+s+t+u+v+w;  //nobody gets initialized in that mess
}

int foo(){
	g1 = 2;
	if(2) g2 = 3;
	else g3 = 2;
	return g2 + g3;
}

int bar(){
	g4 = 2;
	return g4;
}

int goo(){
	scanf("%d", &g5);
	return 1;
}

int blah() {
	g6 = 3;
	if(g6){
		g7 = g8;
	}
	else
		g9 = 10;

	return 2;
}

//test c-graph
int main(){
	int z;
	scanf("%d", &z);
	parameters(1,2);
	loops();
	nested();
	switches();
	cond();

	foo();

	if(1) bar();
	else bar();

	if(2) goo();

	while(z) blah();
	return g1+g2+g3+g4+g5+g6+g7+g8+g9;
}