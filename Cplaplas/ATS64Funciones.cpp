#include<iostream>
#include<string.h>
using namespace std;
void maximo(int x,int y){
  int mayor;
  if(x>y)mayor=x;
  else mayor=y;
  cout<<mayor;
}
int main() {
  maximo(50,6);
  return 0;
}


//punteros
/*
void multiplicar(int *x){//(int &x)
  *x=*x*2;//c=x*2;
}
int main() {
  int x=3;
  multiplicar(&x);//multiplicar(x);
  cout<<x;
  return 0;
}*/
