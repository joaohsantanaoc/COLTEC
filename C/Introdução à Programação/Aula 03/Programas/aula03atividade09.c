#include <stdio.h>
#define SUCESSO 0
int main (int argc,char ** argv){
    int valor,menor,maior;
    printf ("Digite uma sequencia de numeros(0 para terminar a sequencia):");
    scanf ("%d", &valor);
    if (valor == 0){
        printf("nenhum valor foi digitado\n");
        return SUCESSO;
    }
        menor = valor;
        maior = valor;
        while (valor!=0){
            menor = valor;
        }
        if (valor>maior){
            maior=valor; 
        }
        printf ("O menor valor digitado foi %d\n", menor);
        printf ("O maior valor digitado foi %d\n", maior);
    
    return SUCESSO;
}