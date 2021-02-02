#include <iostream>
using namespace std;

void operacion(int x,int y,int &suma,int &multi){//X Y por valor
  suma=x+y;
  multi=x*y;
}
void intercambiar(int &x,int &y){//VARIABKLE POR REFERENCIA
  int aux;
  aux=x;
  x=y;
  y=aux;
}

int main(){
  int x,y,sumar=0,multip=1;
  cout<<"Ingrese primer numero: ";cin>>x;
  cout<<"Ingrese segundo numero; ";cin>>y;

  intercambiar(x,y);
  cout<<x<<" y "<<y<<endl;

  operacion(x,y,sumar,multip);
  cout<<"El producto es: "<<multip<<endl;
  cout<<"La suma es: "<<sumar;

  return 0;
}
