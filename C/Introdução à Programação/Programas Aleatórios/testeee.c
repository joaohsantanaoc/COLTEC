#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0
#define NUM_MAX_CARACTERES (29 + 1)
#define ERRO -1

typedef struct aluno_s{
    char nome[NUM_MAX_CARACTERES];
    char endereco[NUM_MAX_CARACTERES];
    int matricula;
}aluno_t;

//Função para tirar o '\n' das strings
void util_removeQuebraLinhaFinal(char dados[]) {
    int tamanho;
    tamanho = strlen(dados);
    if ((tamanho > 0) && (dados[tamanho - 1] == '\n')) {
        dados[tamanho - 1] = '\0';
    }
}

void cadastro(aluno_t ** ponteiro_aluno, int * num_alunos){
    aluno_t alunos;

    printf ("CADASTRO:\n");
    printf (".........................................................\n\n");
    printf ("Digite o nome do aluno:\n");
    fgets (alunos.nome, NUM_MAX_CARACTERES, stdin);
    util_removeQuebraLinhaFinal (alunos.nome);
    printf ("Digite o endereco desse aluno:\n");
    fgets (alunos.endereco, NUM_MAX_CARACTERES, stdin);
    util_removeQuebraLinhaFinal (alunos.endereco);
    printf ("Digite a matricula desse aluno:\n");
    scanf ("%d%*c", &alunos.matricula);

    (*num_alunos)++;
    *ponteiro_aluno = realloc (*ponteiro_aluno,*num_alunos * sizeof (aluno_t));
    (*ponteiro_aluno)[*num_alunos - 1] = alunos;
}
int salvar_no_arquivo(aluno_t * ponteiro_aluno,int num_alunos){
    int i;
    FILE * arquivo;

    arquivo = fopen ("alunos.txt","a");
    if (!arquivo){
        printf ("Erro ao abrir o arquivo!\n");
        return ERRO;
    }
    if (num_alunos < 1){
        printf ("Nao ha alunos cadastrados no sistema!\n");
        return ERRO;
    }

    for (i = 0;i < num_alunos;i++){
        fprintf (arquivo,"NOME: %s\n",ponteiro_aluno[i].nome);
        fprintf (arquivo,"ENDERECO: %s\n", ponteiro_aluno[i].endereco);
        fprintf (arquivo,"MATRICULA: %d\n",ponteiro_aluno[i].matricula);
    }

    fclose (arquivo);

    return SUCESSO;
}
int ler_do_arquivo(aluno_t * ponteiro_aluno,int num_alunos){
    int i;
    FILE * arquivo;

    arquivo = fopen("alunos.txt","r");
    if (!arquivo){
        printf ("Erro ao abrir o arquivo!\n");
        return ERRO;
    }

    for (i=0;i<num_alunos;i++){
        fgets (ponteiro_aluno[i].nome, NUM_MAX_CARACTERES ,arquivo);
        util_removeQuebraLinhaFinal(ponteiro_aluno[i].nome);
        fgets (ponteiro_aluno[i].endereco, NUM_MAX_CARACTERES, arquivo);
        util_removeQuebraLinhaFinal(ponteiro_aluno[i].endereco);
        fscanf (arquivo,"%d%*c", &ponteiro_aluno[i].matricula);
    }

    fclose (arquivo);

    return SUCESSO;
}

int listar(aluno_t * ponteiro_aluno,int num_alunos){
    int i;

    if (num_alunos < 1){
        printf ("Nao ha alunos cadastrados no sistema!\n");
        return ERRO;
    }

    printf ("NOME                            ENDERECO                                  MATRICULA\n");
    for (i=0;i<num_alunos;i++){
        printf ("%-30s %-30s %10d\n", ponteiro_aluno[i].nome,ponteiro_aluno[i].endereco,ponteiro_aluno[i].matricula);
    }

    return SUCESSO;
}

int main (int argc,char ** argv){
    aluno_t * ponteiro_aluno = NULL;
    int num_alunos = 0;
    int opcao;

    do{
        printf ("SISTEMA DE CADASTRO E LISTAGEM DE DADOS\n");
        printf ("..................................................\n\n");
        printf ("(1) <CADASTRAR ALUNOS>\n(2) <LISTAR ALUNOS>\n(0) <PARAR>\n");
        printf ("Digite sua opcao:\n");
        scanf ("%d%*c", &opcao);

        switch (opcao){
            case 1:{
                cadastro(&ponteiro_aluno,&num_alunos);
                salvar_no_arquivo(ponteiro_aluno,num_alunos);
                break;
            }
            case 2:{
                ler_do_arquivo(ponteiro_aluno,num_alunos);
                listar(ponteiro_aluno,num_alunos);
                break;
            }
            case 0:{
                printf ("Saindo!!!\n");
                break;
            }
            default:{
                printf ("Opcao invalida!\n");
            }
        }

    }while (opcao != 0);

    return SUCESSO;
}