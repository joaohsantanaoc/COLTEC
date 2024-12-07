#include <stdio.h>
#define SUCESSO 0
#define termos_maximos 100
int main (int argc,char ** argv){
    int n, i;
    int fib[termos_maximos];
    printf ("Digite um numero N:");
    scanf ("%d", &n);
    if (n>0){
        fib[0]=1;
        fib[1]=0;
        for (i=2;i<n;i++)
            fib[i] = fib[i-1] + fib[i-2];
            printf ("Serie de fibonacci com %d termos", n);
            for (i=0;i<n;i++){
                printf ("%d ", fib[i]);
                printf ("\n");

            }
        
    }
    return SUCESSO;
}