#include<iostream>
using namespace std;

void secuencia(int n){
   if(n=1){
       cout<<1<<" ";
   }else{
     secuencia(n-1);
   }
   cout<<n<<" ";
}

int main()
{

  secuencia(5);
  return 0;
}
