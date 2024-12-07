#include <stdio.h>
#define SUCESSO 0
int main (int argc,char ** argv){
    int n;
    int numero_atual;
    float fatorial, e=1.0;
    int i;
    printf ("Digite um valor inteiro e positivo para n:");
    scanf ("%d", &n);
    for (i=1;i<=n;i++){
        fatorial=1.0;
        for (numero_atual=i; numero_atual>0;numero_atual++){
            fatorial*=numero_atual;
            e+= 1.0/fatorial;
            printf ("O valor de E para N=%d eh: %f\n", n,e);
        }
    }
    return SUCESSO;

}
