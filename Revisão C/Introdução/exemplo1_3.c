/*
20/01/2025
Revisão Linguagem C: Introdução
Entrada e saída de um caractere: arquivo
João Henrique Santana Oliveira Campos
Turma 304 - Automação Industrial
Professor Márcio Fantini
*/

// Header files presentes no código:
#include <stdio.h>

// Constantes presentes no código:
#define SUCESSO 0
#define ERRO 1

// Função principal:
int main(int argc, char ** argv){
    // Declaração explicíta das variáveis:
    char c;
    int input_char;
    FILE * my_stream;
    char file_name[] = "teste.txt";

    // Input:
    printf("Digite um caractere:\n");
    c = getc(stdin);
    // Output:
    printf("Caractere digitado:\n");
    putc(c, stdout);
    putc('\n', stdout);

    // Abrindo e escrevendo no arquivo:
    my_stream = fopen(file_name, "w");
    if(!my_stream){
        printf("Arquivo não existe ou com problema!!!\n");
        printf("Abortando...\n");
        return ERRO;
    }else{
        fprintf(my_stream, "%c", c);
    }

    // Fechando o arquivo:
    fclose(my_stream);

    // Abrindo o arquivo para leitura:
    my_stream = fopen(file_name, "r");
    if(!my_stream){
        printf("Erro ao abrir o arquivo!!!\n");
        printf("Abortando!!!\n");
        return ERRO;
    }else{
        input_char = getc(my_stream);
        printf("Caractere lido do arquivo: %c\n", input_char);
    }

    // Fechando o arquivo:
    fclose(my_stream);


    // Se chegou até aqui é porque deu tudo certo!!!
    return SUCESSO;
}