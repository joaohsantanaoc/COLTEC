#include <stdio.h>
#define SUCESSO 0
int main (int argc,char ** argv){
    int N;
    int a; 
    int fatorial=1; 
    printf ("Digite o valor de N:");
    scanf ("%d", &N);
    for (a=1;a<=N;a++) {
        fatorial=fatorial*a;
    }
    printf ("O fatorial de %d eh %d",N,fatorial);

    
    return SUCESSO;

}