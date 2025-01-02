/*
01/01/2025
Revisão da Linguagem C: Introdução
Exemplo 2 de programa básico em C
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
    // Declaração explicítas das variáveis utilizadas:
    int x,y,z;

    // Inicialização das variáveis (input):
    x = 2;

    // Processo utilizado:
    printf("Entre com um numero inteiro:\n");
    scanf("%i", &y);

    z = x * y;

    // Output:
    printf("O produto de %i por %i é igual a %i\n", x, y, z);

    // Se rodou até aqui é porque deu tudo certo
    return SUCESSO;
}