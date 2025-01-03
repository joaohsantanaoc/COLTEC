/*
02/01/2025
Revisão Linguagem C: Introdução
Exemplo 1.8: Comparando operações lógicas com operações bit-a-bit
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
    // Declaração explicíta das variáveis de entrada:
    int x = 0b1010;
    int y = 0b1101;
    int w, z;

    // Processo:
    z = x && y;
    w = x & y;

    // Output:
    printf("%i && %i = %i \t %i & %i = %i\n", x, y, z, x, y, w);
    printf("%x && %x = %x \t %x & %x = %x\n", x, y, z, x, y, z);

    printf("----------------------------------------------------------------\n");

    // Processo:
    y = 0;
    z = x || y;
    w = x | y;

    // Output:
    printf("%i || %i = %i \t %i | %i = %i\n", x, y, z, x, y, w);
    printf("%x || %x = %x \t %x | %x = %x\n", x, y , z, x, y, w);

    // Se rodou até aqui é porque deu tudo certo!!!
    return SUCESSO;
}