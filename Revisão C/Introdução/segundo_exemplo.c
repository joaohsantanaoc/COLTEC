/*
20/01/2025
Revisão Linguagem C: Introdução
Exemplo 2 de um programa básico em C
João Henrique Santana Oliveira Campos
Turma 304 - Automação Industrial
Professor Márcio Fantini
*/

// Header files presentes no código:
#include <stdio.h>

// Constantes presentes no código:
#define SUCESSO 0

// Função principal:
int main(int argc, char ** argv){
    // Declaração explicíta das variáveis:
    int x,y,z;

    // Inicialização das variáveis:
    x = 2;

    // Código:
    // Input:
    printf("Entre com um numero inteiro:\n");
    scanf("%i", &y);

    // Process:
    z = x * y;

    // Output:
    printf("O produto de %i por %i eh igual a %i\n", x, y, z);

    // Se chegou até aqui é porque deu tudo certo!!!
    return SUCESSO;
}