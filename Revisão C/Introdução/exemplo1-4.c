/*
02/01/2025
Revisão Linguagem C: Introdução
Exemplo 1.4: Utilização da função de entrada getchar()
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

    // Entrada padrão:
    printf("Entre com um caractere:\n");
    c = getchar();

    // Saída padrão:
    printf("Caractere digitado:\n");
    putc(c, stdout);
    putc('\n', stdout);

    // Se rodou até aqui é porque deu tudo certo!!!
    return SUCESSO;
}