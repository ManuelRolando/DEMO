#include<iostream>
#include <stdlib.h>
using namespace std;
void pedirMatriz();
void mostrarMatriz(string **,int , int);
string verificarGanador(string **,int );
string **matriz;
int fila,columna;
int main()
{
 pedirMatriz();
 mostrarMatriz(matriz,fila,columna);
 cout<<verificarGanador(matriz,fila);

for(int i=0;i<fila;i++)
 delete[] matriz[i];//liberando bytes de fila
 delete[] matriz;
return 0;

}

void mostrarMatriz(string **matriz,int fila, int columna){
  cout<<"\n\nImprimiendo Matriz\n"<<endl;
  for (int i = 0; i < fila; i++) {
    for (int j = 0; j < columna; j++) {
      if(j==columna-1){
        cout<<"   "<<*(*(matriz+i)+j)<<"\t";
      }else{cout<<"   "<<*(*(matriz+i)+j)<<"\t|";}//matriz[i][j];}
    }
    cout<<endl;
    if(i!=(fila-1)){
    for(int k=0;k<4*fila;k++){
      cout<<"_ ";
    }}cout<<"\n\n";
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


string verificarGanador(string **matriz,int n){
  bool ganador;
  string aux;
  for(int i=0;i<n;i++){
    ganador=true;
    aux=matriz[i][0];
    for(int j=1;j<n;j++){
      if(matriz[i][j]!=aux){
        ganador=false;break;
      }
    }
    if(ganador)break;
  }
  if(ganador)return aux;
  else{// return "NO";
    bool ganador;
    string aux;
    for(int j=0;j<n;j++){
      ganador=true;
      aux=matriz[0][j];
      for(int i=1;i<n;i++){
        if(matriz[i][j]!=aux){
          ganador=false;break;
        }
      }
      if(ganador)break;
    }
    if(ganador){return aux;}
    else{
      bool ganador=true;
      string aux;
        aux=matriz[0][0];
        for(int i=1;i<n;i++){
          if(matriz[i][i]!=aux){
            ganador=false;break;
          }
        }
        if(ganador){
          return aux;
        }
        else{
          bool ganador=true;
          string aux;
            aux=matriz[0][n-1];
            for(int i=1;i<n;i++){
              if(matriz[i][n-1-i]!=aux){
                ganador=false;break;
              }
            }
          if(ganador){
            return aux;
          }else{return "No";}
        }

     }
  }

}
