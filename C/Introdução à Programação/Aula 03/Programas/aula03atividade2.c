#include <stdio.h>
#define SUCESSO 0
int main(int argc,char ** argv) {
    int numero; 
    int numero2;
    int resultado;
    printf ("Digite um numero:");
    scanf ("%d", &numero); 
    printf ("Digite outro numero:");
    scanf ("%d", &numero2);
    for (numero=1;numero<=10;numero++){
        for (numero2=1;numero2<=10;numero2++){
            resultado=numero*numero2;
            printf ("O resultado da multiplicacao de %d com %d eh %d\n", numero,numero2,resultado);
        }
    }
    return SUCESSO;
}