#include<iostream>
#include <stdlib.h>
#include<string.h>
using namespace std;
void pedirDimension();
void mostrarMatriz(string **,int);
bool evitarRepetido(int *, int , int );
string verificarGanador(string **,int );
void jugar();
string **matriz;
int n,*seleccionador,tecla=1;
int main()
{
  while(tecla==1){
    pedirDimension();
    mostrarMatriz(matriz,n);
    cout<<"\n Jugador 1 (O) - Jugador 2 (X)\n";
    cout<<"\t---Iniciar---\n";
    jugar();
    cout<<"\n DIGITE 1 SI DESEA JUGAR DE NUEVO\n";
    cout<<" DIGITE OTRA TECLA SI DESEA SALIR--->";
    cin>>tecla;
  }
  for(int i=0;i<n;i++)
  delete[] matriz[i];//liberando bytes de n
  delete[] matriz;
  delete seleccionador;
  return 0;
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

void mostrarMatriz(string **matriz,int n){
  system("cls");
  cout<<"\n\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(j==n-1){
        cout<<"   "<<*(*(matriz+i)+j)<<"\t";
      }else{cout<<"   "<<*(*(matriz+i)+j)<<"\t|";}//matriz[i][j];}
    }
    cout<<endl;
    if(i!=(n-1)){
      for(int k=0;k<4*n;k++){
        cout<<" _";
      }
    }cout<<"\n\n";
  }
}

void pedirDimension(){
  system("cls");
  cout<<"  UTEC: PROGRAMACION ORIENTADA A OBJETOS I\n";
  cout<<"  Juego: TIC-TAC-TOE\n";
  cout<<"\n Digite orden de la matriz juego: ";cin>>n;cout<<"\n\n";
  matriz = new string*[n];
  for(int i=0;i<n;i++){
    matriz[i] = new string[n];
  }
  int contador=1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      *(*(matriz+i)+j)=std::to_string(contador++);
    }
  }
}

bool evitarRepetido(int *vector, int m, int jugador){
  bool indica=true;
  for(int i=0;i<m;i++){
    if(vector[i]==jugador){
      indica=false;
      break;
    }
  }
  return indica;
}

void jugar(){
  int jugador1,jugador2;
  seleccionador = new int[n*n];
  for( int k=0;k<n*n;k++){
   if(k%2==0){
     do{
       cout<<"\n (O) Jugador 1 digite el numero que quiere marcar: ";cin>>jugador1;
       cout<<endl;
       if(jugador1 < 1 || jugador1 > n*n){
         cout<<" Jugador 1, Elija un numero correcto!!"<<endl;
         system("pause");mostrarMatriz(matriz, n);
       };
       if(evitarRepetido(seleccionador,n*n,jugador1)==false && k!=0){
         cout<<" Jugador 1, Elegir numero que falta, no repetir!!"<<endl;system("pause");
         mostrarMatriz(matriz, n);
       };
     }while(jugador1 < 1 || jugador1 > n*n||evitarRepetido(seleccionador,n*n,jugador1)==false);
     seleccionador[k]=jugador1;
     matriz[(jugador1-1)/n][(jugador1-1)%n]="O";
     mostrarMatriz(matriz, n);
   }else{
     do{
       cout<<"\n (X) Jugador 2 digite el numero que quiere marcar: ";cin>>jugador2;
       cout<<endl;
       if(jugador2 < 1 || jugador2 > n*n){
         cout<<" Jugador2 Elija un numero correcto!!"<<endl;
         system("pause");mostrarMatriz(matriz, n);
       };
       if(evitarRepetido(seleccionador,n*n,jugador2)==false){
         cout<<" Jugador 2,  Elegir numero que falta, no repetir!!"<<endl;system("pause");
         mostrarMatriz(matriz, n);
       };
     }while(jugador2 < 1 || jugador2 > n*n||evitarRepetido(seleccionador,n*n,jugador2)==false);
     seleccionador[k]=jugador2;
     matriz[(jugador2-1)/n][(jugador2-1)%n]="X";
     mostrarMatriz(matriz, n);
   }
   if(verificarGanador(matriz,n) == "O" || verificarGanador(matriz,n) == "X"){
     cout<<"\n  HAY UN GANADOR!!!!"<<", es el Jugador"<<k%2+1<<" FELICITACIONES\n";break;};
   if(k>=n*n-1){
     cout<<"\n Quedaron empates!!!\n";
   }
  }
}
