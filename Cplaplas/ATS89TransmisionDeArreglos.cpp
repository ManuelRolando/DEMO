#include<iostream>
#include <stdlib.h>
using namespace std;

void pedirNum();
int maxim(int *,int);
int n,*vector;
void ordenarVector(int *,int);
int main()
{

 pedirNum();
 cout<<"El mayor elemento es: "<<maxim(vector,n);
 cout<<"\n";
 ordenarVector(vector,n);
cout<<"\nEl vector ordenado es: "<<endl;
 for(int i=0;i<n;i++)cout<<*(vector+i)<<" ";//for(int i=0;i<n;i++)cout<<vector[i]<<" "
 delete[] vector;
  return 0;
}

void pedirNum(){
  cout<<"Ingrese numero de datos: ";cin>>n;
  vector = new int[n];
  for(int i=0;i<n;i++){
    cout<<"Ingrese numero "<<i<<": ";cin>>vector[i];
  }
}
int maxim(int *dirvector,int n){
  int max=0;
  for(int i=0;i<n;i++){
    if(*(dirvector+i)>max){
      max=*(dirvector+i);
    }
  }
  return max;
}
void ordenarVector(int *dirVector,int n){
  int aux;
  for(int i=0;i<n;i++){
    //aux=*(dirVector+i);
    for(int j=i+1;j<n;j++){
      if(*(dirVector+j)<*(dirVector+i)){
        aux=*(dirVector+j);
        *(dirVector+j)=*(dirVector+i);
        *(dirVector+i)=aux;
      }
    }
  }
}
