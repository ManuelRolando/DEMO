#include<iostream>
#include<string.h>
using namespace std;
//template <class nose>
void imprime(int &x, string &y){
  cout<<x<<endl;
  cout<<y<<endl;
  x=125;
  y="cambio porque soy parametro por referncia";
}

int main()
{
  int x=5;
  string y="hola";
  imprime(x,y);
  cout<<x<<endl;
  cout<<y<<endl;

  return 0;
}
