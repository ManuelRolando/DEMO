#include<iostream>
using namespace std;

void tiempo(int x,int &anhos,int &meses,int &dias){

anhos=x/365;
x=x%365;
meses=x/30;
dias=x%30;
}

int main(){
  int x,anhos=0, meses=0,dias=0;
  cout<<"Ingrese el total de dias: ";cin>>x;
  tiempo(x, anhos, meses,dias);
  cout<<"\nLa cantidad de anhoss es: "<<anhos<<endl;
  cout<<"La cantidad de meses es: "<<meses<<endl;
  cout<<"La cantidad de dias es: "<<dias<<endl;

  return 0;
}
