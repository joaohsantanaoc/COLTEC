/*
02/01/2024
Revisão Linguagem C: Introdução
Exemplo 2 do uso da função rand()
João Henrique Santana Oliveira Campos
Turma 304 - Automação Industrial
Professor Márcio Fantini
*/

// Header files presentes no código:
#include <stdio.h>
#include <stdlib.h>

// Constantes presentes no código:
#define SUCESSO 0

// Função principal:
int main(int argc, char ** argv){
    // Declaração explicíta das variáveis:
    int i, j, k, p;

    // Entrada (Input):
    printf("Olá! Sou um sorteador de números aleatórios!!! Quantos números você deseja escolher?\n");
    scanf("%i", &p);
    printf("E quantos conjuntos de números aleatórios serão necessários?\n");
    scanf("%i", &k);

    // Processo:
    for (i = 0;i < k;i++){
        printf("-------------------------------------------\n");
        printf("Conjunto númerico %i\n", i + 1);
        for (j = 0;j < p;j++){
            printf("%i\n", rand() % 3 + 1);
        }
    }
    // Se rodou tudo até aqui é porque deu tudo certo!!!
    return SUCESSO;
}