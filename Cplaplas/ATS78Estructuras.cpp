#include<iostream>
using namespace std;
struct persona{
  char nombre[30];
  int edad;
}p1;
struct complejo{
  float real;
  float imaginaria;
}z1,z2;
void pedirComplejos(){
  cout<<"\nDigite datos del primer num: "<<endl;
  cout<<"Parte real: ";cin>>z1.real;
  cout<<"Parte imaginaria: ";cin>>z1.imaginaria;
  cout<<"\nDigite datos del segundo num: "<<endl;
  cout<<"Parte real: ";cin>>z2.real;
  cout<<"Parte imaginaria: ";cin>>z2.imaginaria;
}

void sumaComplejo(complejo z1,complejo z2){
  complejo x;
  x.real=z1.real+z2.real;
  x.imaginaria=z1.imaginaria+z2.imaginaria;
  cout<<"\nLa suma de los numeros complejos es: "<<endl;
  cout<<"\t"<<x.real<<" + "<<x.imaginaria<<"i";
}
void pedirDatos(){
  cout<<"Nombre: ";
  cin.getline(p1.nombre,30,'\n');
  cout<<"Edad: ";cin>>p1.edad;
}
void mostrarDatos(persona p){
  cout<<"\nLos datos ingresados son:\n -------------\n";
  cout<<"Nombre del usuario: "<<p.nombre<<endl;
  cout<<"Edad del usuario: "<<p.edad<<endl;
}


int main(){

  //pedirDatos();
  //mostrarDatos(p1);
  pedirComplejos();
  sumaComplejo(z1,z2);
  return 0;
}
