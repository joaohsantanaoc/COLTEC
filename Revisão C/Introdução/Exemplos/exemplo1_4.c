/*
20/01/2025
Revisão Linguagem C: Introdução
Exemplo com a função getchar() presente no header file stdio.h
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
    // Escopo do programa:

    // Input:
    printf("Entre com um caractere:\n");
    
    // Output:
    printf("Você entrou com o caractere %c\n", getchar());
    
    // Se deu tudo certo é porque chegou até aqui!!!
    return SUCESSO;
}