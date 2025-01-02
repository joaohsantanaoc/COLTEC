/*
01/01/2025
Revisão Linguagem C: Introdução
Trabalhando com diferentes bases numéricas
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
    // Declaração explicíta das variáveis (Input):
    int a = 0xAA;
    int b = 052;
    int c = 52;
    int d = 0b10101010;

    // Output:
    printf("BASE 10: a = %i, b = %i, c = %i, d = %i\n", a,b,c,d);
    printf("BASE 10: a = %d, b = %d, c = %d, d = %d\n", a,b,c,d);
    printf("BASE 16: a = %x, b = %x, c = %x, d = %x\n", a,b,c,d);
    printf("BASE 8: a = %o, b = %o, c = %o, d = %o\n", a,b,c,d);

    // Se rodou até aqui é porque deu tudo certo!!!
    return SUCESSO;
}