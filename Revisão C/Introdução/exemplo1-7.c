/*
02/01/2025
Revisão Linguagem C: Introdução
Exemplo 1.7: Usando a função srand() do header file stdlib
João Henrique Santana Oliveira Campos
Turma 304 - Automação Industrial
Professor Márcio Fantini
*/

// Header files presentes no nosso código:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Constantes presentes no código:
#define SUCESSO 0

// Função principal:
int main(int argc, char ** argv){
    // Declaração explicíta das variáveis de entrada:
    int i, n;
    time_t t;

    n = 5;

    // Inicia o gerador de números aleatórios:
    srand((unsigned) time(&t));
    printf("Inicio\n");

    sleep(4);
    system("clear");

    // Imprime 5 números aleatórios entre 0 e 50:
    for (i = 0;i < n;i++){
        sleep(3);
        printf("%d\n", rand() % 49);
    }
    // Se rodou até aqui é porque deu tudo certo!!!
    return SUCESSO;
}