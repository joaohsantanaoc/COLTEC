#include <stdio.h>
#define SUCESSO 0 
int main (int argc,char ** argv) {
    int i;
    int contador; 
    int resultado;
    printf (" A tabuada de 1 a 10 eh:");
    for (contador=1;contador<=10; contador++) {
        for (i=1 ; i<=10 ; i++){
            resultado= i*contador;
            printf ("%d x %d= %d\n", i,contador,resultado);
        }
    }
    return SUCESSO;
}