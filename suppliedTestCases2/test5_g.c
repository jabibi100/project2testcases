/*test call graph*/
int g1;
int g2;
int g3;

void init1( int i1)
{
   int b;
   g1 = i1 + b;
}

void init2( int i2){
  g2 = i2;
}

void init3( int i3){
  g3 = i3;
}

int add(){
  init1(1);
  init2(1);
  return g1+g2;
}

int sub(){
  return g1-g3;
}
 
void main(){
  int i,j;
  scanf("%d", &i);

  if (i<10){
  init1(1);
  init2(1);
  printf("%d\n", g1+g2+j);
  }
  
  
 init3(1);
 i = sub();
 i = add();
}

