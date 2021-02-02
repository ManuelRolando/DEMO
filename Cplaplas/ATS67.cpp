#include<iostream>
using namespace std;
template <class Nose>
void decimal(Nose x){
int y;
y=x;
cout<<x-y;
}
int main()
{
  double d;
  cout<<"Ingrese numeo: ";
  cin>>d;
  cout<<"La parte decimal es: ";
  decimal(d);
  return 0;
}
