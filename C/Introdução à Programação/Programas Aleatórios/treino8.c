#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0
#define CARACTERES_MAX (30+1)
#define MAX_INGREDIENTES 10

typedef struct ingredientes_s {
    char nome[CARACTERES_MAX];
    int quantidade;
    char unidade[CARACTERES_MAX];
} ingredientes_t;

typedef struct receitas_s {
    int codigo;
    char nome_receita[CARACTERES_MAX];
    char categoria[CARACTERES_MAX];
    ingredientes_t ingredientes[MAX_INGREDIENTES]; 
    int num_ingredientes; 
} receitas_t;

void util_removeQuebraLinhaFinal(char dados[]) {
    int tamanho;
    tamanho = strlen(dados);
    if ((tamanho > 0) && (dados[tamanho - 1] == '\n')) {
        dados[tamanho - 1] = '\0';
    }
}

void cadastro_receita(receitas_t **ponteiro_receita, int *num_receitas) {
    receitas_t receitas;

    printf("Digite o codigo da sua receita primeiramente:\n");
    scanf("%d", &receitas.codigo);
    getchar();
    printf("Agora digite o nome da receita:\n");
    fgets(receitas.nome_receita, CARACTERES_MAX, stdin);
    util_removeQuebraLinhaFinal(receitas.nome_receita);
    printf("Digite a categoria dessa receita:\n");
    fgets(receitas.categoria, CARACTERES_MAX, stdin);
    util_removeQuebraLinhaFinal(receitas.categoria);

    (*num_receitas)++;
    *ponteiro_receita = realloc(*ponteiro_receita, (*num_receitas) * sizeof(receitas_t));
    (*ponteiro_receita)[*num_receitas - 1] = receitas;
    printf("Cadastro concluido com sucesso!\n");
}

int procura_receita(receitas_t *ponteiro_receita, int num_receitas) {
    int i;
    int codigo_procurado;

    printf ("CODIGO  NOME RECEITA\n");
    for (i=0;i<num_receitas;i++){
        printf ("%-2d %-31s\n", ponteiro_receita[i].codigo,ponteiro_receita[i].nome_receita);
    }
    printf("Informe o codigo da receita:\n");
    scanf("%d", &codigo_procurado);

    for (i = 0; i < num_receitas; i++) {
        if (codigo_procurado == ponteiro_receita[i].codigo) {
            return i;
        }
    }

    return -1;
}

void cadastro_ingredientes(receitas_t *receita) {
    int i = receita->num_ingredientes;

    if (i >= MAX_INGREDIENTES) {
        printf("Limite máximo de ingredientes atingido!\n");
        return;
    }
    getchar();

    printf("Digite o nome do ingrediente:\n");
    fgets(receita->ingredientes[i].nome, CARACTERES_MAX, stdin);
    util_removeQuebraLinhaFinal(receita->ingredientes[i].nome);

    printf("Digite a quantidade do ingrediente:\n");
    scanf("%d", &receita->ingredientes[i].quantidade);
    getchar();

    printf("Digite a unidade do ingrediente:\n");
    fgets(receita->ingredientes[i].unidade, CARACTERES_MAX, stdin);
    util_removeQuebraLinhaFinal(receita->ingredientes[i].unidade);

    receita->num_ingredientes++;
}

void listagem_tabela(receitas_t *ponteiro_receita, int num_receitas) {
    int i;

    printf("CODIGO                          NOME RECEITA               CATEGORIA                               NUMERO INGREDIENTES\n");
    for (i = 0; i < num_receitas; i++) {
        printf("%-31d %-31s %-31s %-2d\n", ponteiro_receita[i].codigo, ponteiro_receita[i].nome_receita, ponteiro_receita[i].categoria, ponteiro_receita[i].ingredientes->quantidade);
    }
}

void listagem_normal(receitas_t * ponteiro_receita, int num_receitas) {
    int i,j;
    int codigo_procurado;

    for (i=0;i<num_receitas;i++){
        printf ("%-4d %-31s\n", ponteiro_receita[i].codigo,ponteiro_receita[i].nome_receita);
    }
    printf ("Digite o codigo da receita:\n");
    scanf ("%d", &codigo_procurado);
    printf ("DADOS DA RECEITA:\n");
    for (i=0;i<num_receitas;i++){
        if (codigo_procurado == ponteiro_receita[i].codigo){
            printf ("CODIGO: %-4d\n", ponteiro_receita[i].codigo);
            printf ("NOME: %-31s\n", ponteiro_receita[i].nome_receita);
            printf ("CATEGORIA: %-31s\n", ponteiro_receita[i].categoria);

            printf ("Ingredientes:\n");
            printf ("NOME                           QUANTIDADE     UNIDADE\n");
            for (j=0;j<ponteiro_receita[i].num_ingredientes;j++){
                printf ("%-31s %-4d %-31s\n", ponteiro_receita[i].ingredientes->nome,ponteiro_receita[i].ingredientes->quantidade,ponteiro_receita[i].ingredientes->unidade);
            }
            return;
        }
    }
    printf ("Codigo nao encontrado!\n");
}

int main(int argc, char **argv) {
    receitas_t *ponteiro_receita = NULL;
    int num_receitas = 0;
    int opcao;
    int i;

    do {
        printf("Bem vindo ao nosso sistema de listagem e busca de receitas!!!\n");
        printf("Temos opcoes de cadastro e listagem de receitas e ingredientes\n");
        printf("Para prosseguir, digite sua opcao:\n");
        printf("<CADASTRO RECEITA> (1)\n<CADASTRO INGREDIENTE> (2)\n<LISTAGEM RECEITA EM TABELA> (3)\n<LISTAGEM RECEITA NORMAL> (4)\n<PARAR> (0)\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastro_receita(&ponteiro_receita, &num_receitas);
                break;
            case 2:
                if (num_receitas > 0) {
                    int index = procura_receita(ponteiro_receita, num_receitas);
                    if (index != -1) {
                        cadastro_ingredientes(&ponteiro_receita[index]);
                    } else {
                        printf("Receita não encontrada!\n");
                    }
                } else {
                    printf("Não há receitas cadastradas ainda. Cadastre uma receita primeiro.\n");
                }
                break;
            case 3:
                listagem_tabela(ponteiro_receita, num_receitas);
                break;
            case 4:
                listagem_normal(ponteiro_receita,num_receitas);
                break;
            case 0:
                printf("Programa acabou!\n");
                break;
            default:
                printf("Opcao invalida!!!\n");
        }
    } while (opcao != 0);

    // Liberar a memória alocada antes de sair do programa
    for (i = 0; i < num_receitas; i++) {
        free(ponteiro_receita[i].ingredientes);
    }
    free(ponteiro_receita);

    return SUCESSO;
}
