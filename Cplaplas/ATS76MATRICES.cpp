#include<iostream>
using namespace std;

void mostrarMatriz(int m[][3],int nfilas, int ncolum){
  for(int i=0;i<nfilas;i++){
    for(int j=0;j<ncolum;j++){
      cout<<m[i][j]<<" ";
    }
    cout<<endl;
  }
}

void cuadradomatriz(int m[][3],int nfilas, int ncolum){
  for(int i=0;i<nfilas;i++){
    for(int j=0;j<ncolum;j++){
      m[i][j]*=m[i][j];
    }
  }
}

int main(){
  int fila=2;
  const int col=3;
  int m[fila][col]={{1,2,3},{4,5,6}};
  mostrarMatriz(m,fila,col);
  cuadradomatriz(m,fila,col);
  cout<<"\nEl cuadrado de los elementos de la matriz: \n";
  mostrarMatriz(m,fila,col);
  return 0;
}








/*#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void generarArreglo(int **matriz, int rows, int cols){
    int contador=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            matriz[i][j]=contador++;
        }

    }
}

void imprimirArreglo(int **matriz, int rows, int cols){
    for(int i=0;i< rows;i++){
        for(int j=0;j< cols;j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin >> n;
    int rows , cols;
    rows = cols = n;
    int** matriz = new int*[rows];
    for (int i = 0; i < rows; ++i)
        matriz[i] = new int[cols];
    generarArreglo(matriz, rows, cols);
    imprimirArreglo(matriz, rows, cols);

    matriz[1][1]=0;
    imprimirArreglo(matriz, rows, cols);

    return 0;
}*/
