#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0

int main (int argc,char ** argv){
    FILE * dados;

    dados = fopen("dados.txt","w");

    if (!dados){
        printf ("Erro ao abrir o arquivo!!!\n");
        exit(1);
    }else {
        printf ("Arquivo abrido com sucesso!!!\n");
    }

    fclose(dados);
    return SUCESSO;
}
