#include<iostream>
#include<string.h>
using namespace std;

void opcion(int x[],int n){
  x[0]=x[0]*x[0];
  cout<<x[0];
}
int x[1];
int main() {
  cin>>x[0];
  opcion(x,1);
  cout<<"\n"<<x[0];//solo cambia cuando es vector
  return 0; //              |
}           //              |
//                          |
//                          |
/*                          |
void opcion(int x){//       |
  x=x*x;//                  |
  cout<<x;//                |
}//                         |
int x;//                    |
int main() {//              |
  cin>>x;//                 |
  //int x=3;//              |
  //cuadrado(x,1);// <------| No cambia cuandoi sales de una funcion

  opcion(x);
  cout<<"\n"<<x;
  return 0;
}

*/
