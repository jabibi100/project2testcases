/*test call graph*/
int g1;
int g2;
int g3;

void init1( int i1)
{
   g1 = i1;
}

void init2( int i2){
  g2 = i2;
}

int sub(){
  return g1-g3;
}
 
void main(){
  int i;
  scanf("%d", &i);

  if (i<10){
  init1(1);
  init2(1);
  printf("%d\n", g1+g2);
  }
  
 i = sub();
}

