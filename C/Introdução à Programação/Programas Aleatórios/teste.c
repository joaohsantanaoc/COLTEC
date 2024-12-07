#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define TAM_MAX 100

int *alocar_vetor(int tamanho){
    int *vetor = (int *)calloc(tamanho,sizeof(int));
    return vetor; 
}

int main (int argc,char ** argv){
    int *vetor= alocar_vetor(TAM_MAX);
    printf ("O endereco inicial do vetor eh %p\n", (void *)vetor);
    free (vetor);
    return SUCESSO; 
}