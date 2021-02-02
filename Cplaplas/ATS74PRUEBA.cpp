
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i=0; int mostrar=1;
    while (i<5) { if(i>3) { break; }
                        printf("i vale %d\n", i);
                       i++; }
    i=0; // Ejemplos aprendereaprogramar.com
    while (i<10) { if(i%3==0) {mostrar=0;}
                         if (mostrar)  { printf("Ahora i vale %d\n", i); }
                           i++; mostrar = 1;  }
    return 0;
}
