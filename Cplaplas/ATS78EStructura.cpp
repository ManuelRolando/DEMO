#include<iostream>
using namespace std;
struct fecha{
  int dia;
  int mes;
  int anho;
}fechaz[2];
void ingresarFecha(){
  for(int i=0;i<2;i++){
    cout<<"\nDatos de la fecha "<<i<<": "<<endl;
    cout<<"Dia: ";cin>>fechaz[i].dia;
    cout<<"Mes: ";cin>>fechaz[i].mes;
    cout<<"Anho: ";cin>>fechaz[i].anho;
  }
}
void mostrar(fecha f){
  cout<<"\nLa mayor fecha es: ";
  cout<<"\nDia: "<<f.dia;
  cout<<" Mes: "<<f.mes;
  cout<<" Anho: "<<f.anho;
}
void fechaMayor(fecha f1,fecha f2){
  if(f1.anho>f2.anho){
    mostrar(f1);
  }else if(f1.anho<f2.anho){
    mostrar(f2);
  }else{
    if(f1.mes>f2.mes){
      mostrar(f1);
    }else if(f1.mes<f2.mes){
      mostrar(f2);
    }else{
      if(f1.anho>f2.anho){
        mostrar(f1);
      }else if(f1.anho<f2.anho){
        mostrar(f2);
      }else{
        cout<<"\nLas fechas son iguales";
      }
    }
  }
}
int main()
{
  ingresarFecha();
  fechaMayor(fechaz[0],fechaz[1]);
  return 0;
}
