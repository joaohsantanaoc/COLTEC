/*
02/01/2025
Revisão Linguagem C: Introdução
Exemplo 1.5: Utilização da função gets()
João Henrique Santana Oliveira Campos
Turma 304 - Automação Industrial
Professor Márcio Fantini
*/

// Header files presentes no código:
#include <stdio.h>

// Constantes presentes no código:
#define SUCESSO 0
#define TAMANHO_MAX 100

// Função principal:
int main(int argc, char ** argv){
    // Declaração explicíta das variáveis:
    char str1[TAMANHO_MAX];

    // Entrada padrão:
    printf("Digite seu nome completo:\n");
    gets(str1);

    // Saída padrão:
    printf("Olá %s! Bom dia!!!\n", str1);

    // Se rodou até aqui é porque deu tudo certo!!!
    return SUCESSO;
}