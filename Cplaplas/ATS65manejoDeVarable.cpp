#include<iostream>
#include<string.h>
using namespace std;

//cuando no sabes el tipo de variable
template <class NoSeTipoDeVariable>
NoSeTipoDeVariable absoluto(NoSeTipoDeVariable x){//FUNCION ABSOLUTO
  /*if(x<=0)x=x*(-1);
  cout<<x;*/
  return x;
}
int main() {
  cout<<absoluto("sdvdfbvdfbvdf")<<endl;
  cout<<absoluto(-10000)<<endl;
  cout<<absoluto(12.2)<<endl;
  cout<<absoluto(1/3)<<endl;
  return 0;
}
//PARA CREAR UNA FUNCION EL PROTOTIPO(Void funcion(variable);) VA ANTES DE Int main(){} Y DESPUES DE return 0;} va la estructura de la funcion
