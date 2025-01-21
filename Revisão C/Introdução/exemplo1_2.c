/*
20/01/2025
Revisão Linguagem C: Introdução
Entrada e Saída de um caractere: Stream padrão
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
    char c;

    // Standard input (stdin):
    printf("Digite um caractere:\n");
    c = getc(stdin);

    // Standard Output (stdout):
    printf("Caractere digitado:\n");
    putc(c, stdout);
    putc('\n', stdout);

    // Se deu tudo certo é porque chegou até aqui!!!
    return SUCESSO;
}