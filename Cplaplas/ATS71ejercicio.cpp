#include<iostream>
using namespace std;

void cambio(int x,int &cien,int &cincuenta,int &veinte,int &diez, int &cinco,int &uno){

int aux;
cien=x/100;
x=x%100;
cincuenta=x/50;
x=x%50;
veinte=x/20;
x=x%20;
diez=x/10;
x=x%10;
cinco=x/5;
uno=x%5;
}

int main(){
  int x,cien=0, cincuenta=0,veinte=0,diez=0,cinco=0,uno=0;
  cout<<"Ingrese monto en dolares: $";cin>>x;
  cambio(x, cien, cincuenta,veinte,diez,cinco,uno);
  cout<<"\nLa cantidad de billetes de 100$ es: "<<cien<<endl;
  cout<<"La cantidad de billetes de 50$ es: "<<cincuenta<<endl;
  cout<<"La cantidad de billetes de 20$ es: "<<veinte<<endl;
  cout<<"La cantidad de billetes de 10$ es: "<<diez<<endl;
  cout<<"La cantidad de billetes de 5$ es: "<<cinco<<endl;
  cout<<"La cantidad de billetes de 1$ es: "<<uno<<endl;
  return 0;
}
