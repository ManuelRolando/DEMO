#include<iostream>
using namespace std;
int main()
{
  int num[]={11,-1,3,11,-5};
  int *direccionNum;
  direccionNum = num;//asigna direccion de la primera posicion de num
  for (int i = 0; i < 5; i++) {
    cout<<"Elemento del vector ["<<i<<"]: "<<*direccionNum<<endl;
    cout<<"direccion del vector ["<<i<<"]: "<<direccionNum<<endl;
    direccionNum++;
  }

  direccionNum = num;
  int menor=100;
  int *direcMenor;
  for (int i = 0; i < 5; i++) {
    if(*direccionNum<menor){
      menor=*direccionNum;
      direcMenor=direccionNum;
    }
    direccionNum++;
  }

  cout<<"\nEl menor numero es "<<*direcMenor<<" cuya direccion es: "<<direcMenor;
  //cout<<"\nEl menor numero es "<<menor<<" cuya direccion es: "<<&menor;
  return 0;
}
