/*
02/01/2025
Revisão Linguagem C: Introdução
Exercícios de fixação 1.14.2: Exercício 3
João Henrique Santana Oliveira Campos
Turma 304 - Automação Industrial
Professor Márcio Fantini
*/

// Headers files presentes no código:
#include <stdio.h>

// Constantes presentes no código:
#define SUCESSO 0
#define TAMANHO 200
#define CONSTANTE 30

// Função principal:
int main(int argc, char ** argv){
    // Declaração explicíta das variáveis:
    int i, j, k, n = 200;
    int vetor[TAMANHO];

    // Processo:
    for (i = 0; i < n;i++){
        vetor[i] = i % CONSTANTE;
    }

    // Output:
    printf("Valores da posição do vetor de 0 até 35:\n");
    for (j = 0;j < 36;j++){
        printf("v[%i] = %i\n", j, vetor[j]);
    }

    printf("Valores da posição do vetor de 0 até 60:\n");
    for (k = 0;k < 61;k++){
        printf("v[%i] = %i\n", k, vetor[k]);
    }

    // Se rodou até aqui é porque deu tudo certo!!!
    return SUCESSO;
}