#include <stdio.h>
#define SUCESSO 0 
int main(int argc,char ** argv){
    int num;
    int contador;
    int resultado;
    printf ("Digite um numero:"); 
    scanf ("%d", &num);
    for(contador=0;contador<=9;contador++){
        resultado=num*contador;
        printf ("%d x %d= %d\n", num, contador,resultado);

    }
    return SUCESSO; 
}