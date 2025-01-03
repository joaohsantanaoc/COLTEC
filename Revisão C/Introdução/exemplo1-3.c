/*
02/01/2025
Revisão Linguagem C: Introdução
Exemplo 1.3: Entrada e Saída de Caracteres: Stream padrão
João Henrique Santana Oliveira Campos
Turma 304 - Automação Industrial
Professor Márcio Fantini
*/

// Header Files presentes no código:
#include <stdio.h>

// Constantes presentes no código:
#define SUCESSO 0
#define ERRO 1

// Função principal:
int main(int argc, char ** argv){
    // Declaração explicíta das variáveis:
    char c;
    int input_char;
    FILE* my_stream;
    char my_file_name[] = "teste.txt";

    // Entrada padrão: Teclado
    printf("Digite um caractere:\n");
    c = getc(stdin);

    // Saída padrão: Monitor:
    printf("Caractere digitado:\n");
    putc(c, stdout);
    putc('\n', stdout);

    // Criação e leitura de arquivo texto:
    my_stream = fopen(my_file_name, "w");
    putc(c, my_stream);
    fclose(my_stream);
    // Leitura de arquivo texto:
    my_stream = fopen(my_file_name, "r");

    // Verificação:
    if (!my_stream){
        printf("O arquivo não existe!!!\n");
        return ERRO;
    }
    else{
        printf("Caractere lido de stream não padrão:\n");
        input_char = getc(my_stream);
        putc(input_char, stdout);
        putc('\n', stdout);

        fclose(my_stream);
    }

    // Se rodou até aqui é porque deu tudo certo!!!
    return SUCESSO;
}