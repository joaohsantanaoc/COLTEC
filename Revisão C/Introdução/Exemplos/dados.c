/*
20/01/2025
Revisão Linguagem C: Introdução
Utilizando o comando sizeof() para ver o tamanho (em bytes) que cada variável ocupa
João Henrique Santana Oliveira Campos
Turma 304 - Automação Industrial
Professor Márcio Fantini
*/

// Header files presentes no código:
#include <stdio.h>

// Constantes presentes no código:
#define SUCESSO 0
#define TAMANHO 7

// Função principal:
int main(int argc, char ** argv){
    // Declaração explicíta de variável:
    char str[TAMANHO] = "String";

    // Output:
    // Tipos numéricos:

    /* int */
    printf("Sizeof de int: %li bytes\n", sizeof(int));
    printf("Sizeof de long int: %li bytes\n", sizeof(long int));

    /* float */
    printf("Sizeof de float: %li bytes\n", sizeof(float));

    /* double */
    printf("Sizeof de double: %li bytes\n", sizeof(double));
    printf("Sizeof de long double: %li bytes\n", sizeof(long double));

    // Tipo caractere:

    /* char */
    printf("Sizeof de char: %li byte\n", sizeof(char));
    printf("String criada: '%s'\n", str);
    printf("Tamanho de bytes que essa string ocupa: %li bytes\n", sizeof(str));

    // Se deu tudo certo é porque chegou até aqui!!!
    return SUCESSO;
}