#include<iostream>
#include<stdlib.h>//Funciona new y delete
using namespace std;

void pedirnotas();
void mostrarNotas();

int numCalif,*calif;
int fila,columna;
int main()
{
  pedirnotas();
  mostrarNotas();
  delete[] calif;//Liberando bytesarreglo creado
  return 0;
}

void pedirnotas(){
  cout<<"Digite el numero de calificacion: ";
  cin>>numCalif;
  calif = new int[numCalif];//crear el arreglo dinámico REservar memoria

  for(auto i=0;i<numCalif;i++){
    cout<<"Ingrese nota: ";cin>>calif[i];
  }
}
void mostrarNotas(){
  cout<<"\nNotas del usuario:\n";
  for(auto i=0;i<numCalif;i++){
    cout<<calif[i]<<endl;
  }
}
