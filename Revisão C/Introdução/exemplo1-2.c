/*
02/01/2025
Revisão Linguagem C: Introdução
Exemplo 1.2: Entrada e Saída de Caractere: Stream padrão
João Henrique Santana Oliveira Campos
Turma 304 - Automação Industrial
Professor Márcio Fantini
*/

// Header Files presentes no código:
#include <stdio.h>

// Constantes presentes no código:
#define SUCESSO 0

// Função principal:
int main(int argc, char ** argv){
    // Declaração explicíta das variáveis:
    char c;

    // Obtenção da entrada por meio de entrada padrão: teclado
    printf("Digite um caractere:\n");
    c = getc(stdin);

    // Apresentação da entrada por meio da saída padrão: monitor
    printf("Caractere digitado:\n");
    putc(c, stdout);
    putc('\n', stdout);

    return SUCESSO;
}