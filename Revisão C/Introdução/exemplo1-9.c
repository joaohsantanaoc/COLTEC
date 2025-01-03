/*
02/01/2025
Revisão Linguagem C: Introdução
Exemplo 1.9: Comparando operações lógicas com operações bit-a-bit
João Henrique Santana Oliveira Campos
Turma 304 - Automação Industrial
Professor Márcio Fantini
 */

// Header files usados no código:
#include <stdio.h>

// Constantes usadas no código:
#define SUCESSO 0

// Função principal:
int main(int argc, char ** argv){
    // Declaração explicíta das variáveis de entrada:
    int a = 0b00111100;
    int b = 0b00001101;

    int x;
    int y;
    int z;
    int w;

    // Processo:
    x = a & b;
    y = a | b;
    z = a ^ b;
    w = ~ a;

    // Output:
    printf("%x & %x = %x\n", a, b, x);
    printf("%x | %x = %x\n", a, b, y);
    printf("%x ^ %x = %x\n", a, b, z);
    printf("~%x = %x\n", a, w);

    // Se rodou até aqui é porque deu tudo certo!!!
    return SUCESSO;
}