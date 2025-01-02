/*
01/01/2025
Revisão linguagem C: Introdução
Tipos de dados na linguagem C
João Henrique Santana Oliveira Campos
Turma 304 - Automação Industrial
Professor Márcio Fantini
*/

// Bibliotecas presentes no código:
#include <stdio.h>

// Constantes presentes no código:
#define SUCESSO 0

// Função principal:
int main(int argc, char ** argv){
    // Output:

    // Tipos númericos:
    printf("-------------------------------------------------------------\n");
    printf("\t\tTIPOS NÚMERICOS DE DADOS\n");
    printf("-------------------------------------------------------------\n");
    printf("Sizeof de int: %lu bytes\n", sizeof(int));
    printf("Sizeof de long int: %lu bytes\n", sizeof(long int));
    printf("Sizeof de float: %lu bytes\n", sizeof(float));
    printf("Sizeof de double: %lu bytes\n", sizeof(double));
    printf("Sizeof de long double: %lu bytes\n", sizeof(long double));

    printf("-------------------------------------------------------------\n");
    // Tipos de caractere:

    printf("\t\tTIPOS DE CARACTERE\n");
    printf("-------------------------------------------------------------\n");
    printf("Sizeof de char: %lu bytes\n", sizeof(char));
    return SUCESSO;
}