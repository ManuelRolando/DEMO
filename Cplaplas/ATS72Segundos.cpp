#include<iostream>
using namespace std;

void tiempo(int x,int &hora,int &minuto,int &segundos){

hora=x/3600;
x=x%3600;
minuto=x/60;
segundos=x%60;
}

int main(){
  int x,hora=0, minuto=0,segundos=0;
  cout<<"Ingrese el total de segundos: ";cin>>x;
  tiempo(x, hora, minuto,segundos);
  cout<<"\nLa cantidad de horas es: "<<hora<<endl;
  cout<<"La cantidad de minutos es: "<<minuto<<endl;
  cout<<"La cantidad de segundos es: "<<segundos<<endl;

  return 0;
}
