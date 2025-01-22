/*
22/01/2025
Revisão Linguagem C: Introdução
Exercícios de Fixação 1.14.2: Exercício 3
João Henrique Santana Oliveira Campos
Turma 304 - Automação Industrial
Professor Márcio Fantini
*/

// Header files presentes no código:
#include <stdio.h>
#include <stdlib.h>
// Constantes presentes no código:
#define SUCESSO 0
#define TAMANHO 200

// Função principal:
int main(int argc, char ** argv){
    // Declaração explicíta das variáveis:
    int i, n = 200;
    int vetor[TAMANHO];

    // Inicialização do vetor:
    for(i = 0; i < n; i++){
        vetor[i] = 0;
    }

    // Preenchimento dos elementos do vetor com o resto da divisão por 30:
    for(i = 0; i < n; i++){
        vetor[i] = i % 30;
    }

    // Apresentação dos elementos das posições 0 até 35:
    n = 36;

    printf("Posicoes do vetor variando de 0 ate 35\n");
    for(i = 0; i < n; i++){
        printf("%d\n", vetor[i]);
    }

    // Apresentação dos elementos das posições 0 até 60:
    n = 61;

    printf("Posicoes do vetor variando de 0 ate 60\n");
    for(i = 0; i < n; i++){
        printf("%d\n", vetor[i]);
    }

    // Se rodou até aqui é porque deu tudo certo!!!
    return SUCESSO;
}