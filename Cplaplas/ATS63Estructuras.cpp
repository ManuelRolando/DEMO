#include<iostream>
using namespace std;

struct etapas{
 int hora;
 int minutos;
 int segundo;
}etapa[5];//numero de etapas

int main(){
int n,thora=0,tminutos=0,tsegundos=0;

cout<<"Digite numero de etapas: "; cin>>n;
for(int i=0;i<n;i++){
  cout<<"\nhora: "<<i+1<<": ";cin>>etapa[i].hora;
  cout<<"minutos: "<<i+1<<": ";cin>>etapa[i].minutos;
  cout<<"segundos: "<<(i+1)<<": ";cin>>etapa[i].segundo;
  thora+=etapa[i].hora;
  tminutos+=etapa[i].minutos;
  tsegundos+=etapa[i].segundo;
  if(tsegundos>=60){
    tsegundos=tsegundos%60;
    tminutos++;
  }
  if(tminutos>=60){
    tminutos=tminutos%60;
    thora++;
  }
}

cout<<"\nEl Alumno en sus "<<n<<" etapas acumulo:"<<endl;
cout<<"\t\t"<<thora<<" horas "<<tminutos<<" minutos y "<<tsegundos<<" segundos";

return 0;
}
