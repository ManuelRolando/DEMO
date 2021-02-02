#include<iostream>
#include <stdlib.h>
using namespace std;
void pedirMatriz();
void mostrarMatriz(string **,int , int);
string **matriz;
int fila,columna;
int main()
{
 pedirMatriz();
 mostrarMatriz(matriz,fila,columna);


for(int i=0;i<fila;i++)
 delete[] matriz[i];//liberando bytes de fila
 delete[] matriz;
return 0;

}

void mostrarMatriz(string **matriz,int fila, int columna){
  cout<<"\n\nImprimiendo Matriz\n"<<endl;
  for (int i = 0; i < fila; i++) {
    for (int j = 0; j < columna; j++)
      cout<<"   "<<*(*(matriz+i)+j);
    cout<<endl;
  }
}

void pedirMatriz(){
  cout<<"Filas: ";cin>>fila;
  cout<<"columna: ";cin>>columna;

  matriz = new string*[fila];

  for(int i=0;i<fila;i++){
    matriz[i] = new string[columna];
  }
  cout<<"\nDigitando elementos de la matriz\n";
  for (int i = 0; i < fila; i++) {
    for (int j = 0; j < columna; j++) {
      cout<<"Digite un numero ["<<i<<"]["<<j<<"]:  ";
      cin>>*(*(matriz+i)+j);//matriz[i][j];

    }
  }
}
