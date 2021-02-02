#include <iostream>
using namespace std;
//x tamaño del vecto a    y tamaño de b
void vector(int a[],int x,int b[], int y){
  for(int i=0;i<x;i++){
    a[i]+=b[i];
  }
}
void mostrar(int v[],int n){
  cout<<"[ ";
  for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
  }
  cout<<"]\n";
}
void cambiarSigno(int v[],int n){
  cout<<"[ ";
  for(int i=0;i<n;i++){
    v[i]*=-1;
  }
  cout<<"]\n";
}

float SumaElementos(int vector[],int n){
  float suma=0;
  for(int i=0;i<n;i++){
    suma+=vector[i];
  }
  return suma;
}

void VectorOrdenado(int vector[], int n){
  bool orden=true;
  for(int i=0;i<n;i++){
    if(i!=0){
      if(vector[i-1]>=vector[i]){
        orden=false;
      }
    }
  }
  if(orden==true){cout<<"\nEl vector es creciente\n";
  }else{cout<<"\nEl vector no es creciente\n";}
}

int main(){
  int n=3;
  int a[]={1,2,3},b[]={30,200,10};
  mostrar(a,n);
    VectorOrdenado(a,n);
  mostrar(b,n);
  vector(a,n,b,n);
  mostrar(a,n);
  mostrar(b,n);
  cambiarSigno(b,n);
  mostrar(b,n);
  cout<<SumaElementos(b,n);
  cout<<"\n"<<a;

  return 0;
}
