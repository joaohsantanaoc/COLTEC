#include <stdio.h>
#define SUCESSO 0 
int main (int argc,char ** argv){
    int numero, i, resto; 
    printf ("Digite um numero:");
    scanf ("%d", &numero); 
    for (i=0; i<numero+1; i++){
        resto= numero % i; 
        if (resto=0) {
            printf ("%d ",i);
        }
    }
    return SUCESSO;
    
}