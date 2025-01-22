/*
22/01/2025
Revisão Linguagem C: Introdução
Usando o gerador de números aleatórios (função rand() da biblioteca <stdlib.h>)
João Henrique Santana Oliveira Campos
Turma 304 - Automação Industrial
Professor Márcio Fantini
*/

// Header files presente no código:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constantes presentes no código:
#define SUCESSO 0

// Função principal:
int main(int argc, char ** argv){
    // Declaração explicíta das variáveis:
    int i, n = 5;

    // Processo:
    for (i = 0; i < n; i++){
        printf("%d\n", rand() % 50);
    }
    // Se rodou até aqui é porque deu tudo certo!!!
    return SUCESSO;
}