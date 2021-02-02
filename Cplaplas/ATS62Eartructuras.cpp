#include<iostream>
using namespace std;
 struct promedio{
   float nota1;
   float nota2;
   float nota3;
 };
 struct Alumno{
   char nombre[20];
   char sexo[10];
   int edad;
   struct promedio prom;
 }alumno[2];

 int main(){
   float promedioAlumno;

   cout<<"Digite su nombre: "; cin.getline(alumno[1].nombre,20,'\n');
   cout<<"Digite su sexo: ";
   cin.getline(alumno[1].sexo,10,'\n');
   cout<<"Digite su edad: ";
   cin>>alumno[1].edad;

   cout<<"\nDigite notas del alumno"<<endl;
   cout<<"Nota1: ";cin>>alumno[1].prom.nota1;
   cout<<"Nota2: ";cin>>alumno[1].prom.nota2;
   cout<<"Nota3: ";cin>>alumno[1].prom.nota3;
   promedioAlumno=(alumno[1].prom.nota1+alumno[1].prom.nota2+alumno[1].prom.nota3)/3;
   cout<<"\nel nombre de alumno es: "<<alumno[1].nombre;
   cout<<"\nEl promedio del alumno es: "<<promedioAlumno;


   int n;
   cout<<"\nHola mundo: ";
   cin>>n;
   cout<<"El numero ingresado es: "<<n<<"\n";
   for(int i=0;i<n;i++){
     cout<<"paso "<<i<<endl;
   }
   return 0;
 }
