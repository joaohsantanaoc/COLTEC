#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0
#define CARACTERES_MAX 51
#define CARACTERES_TELEFONE 31

typedef struct agenda_s{
    char nome[CARACTERES_MAX];
    char telefone[CARACTERES_TELEFONE];
    char email[CARACTERES_MAX];


}agenda_t;

void util_removeQuebraLinhaFinal(char dados[]) {
    int tamanho;
    tamanho = strlen(dados);
    if ((tamanho > 0) && (dados[tamanho - 1] == '\n')) {
        dados[tamanho - 1] = '\0';
    }
}

void cadastrar_contatos(agenda_t **ponteiro_agenda,int* num_contatos){
    agenda_t nova_agenda; 

    printf ("Digite o nome do contato:\n");
    fgets (nova_agenda.nome, CARACTERES_MAX,stdin);
    util_removeQuebraLinhaFinal(nova_agenda.nome);
    printf ("Digite o telefone:\n");
    fgets (nova_agenda.telefone, CARACTERES_TELEFONE,stdin);
    util_removeQuebraLinhaFinal(nova_agenda.telefone);
    printf ("Agora digite o email:\n");
    fgets (nova_agenda.email,CARACTERES_MAX,stdin);
    util_removeQuebraLinhaFinal(nova_agenda.email);

    (*num_contatos)++;
    *ponteiro_agenda = realloc (*ponteiro_agenda,(*num_contatos) * sizeof(agenda_t));
    (*ponteiro_agenda)[*num_contatos -1] = nova_agenda;
    printf ("Cadastro concluido!\n");




}
void listar_unico_contato(agenda_t * ponteiro_agenda, int num_contatos,int index){
    if (index >= 0 && index < num_contatos){
        printf ("NOME:                                              TELEFONE:                      EMAIL:\n");
        printf ("%-51s %-31s %-51s\n", ponteiro_agenda[index].nome,ponteiro_agenda[index].telefone,ponteiro_agenda[index].email);
        printf("...................................................................................................\n");

    }


}
void listar_contatos(agenda_t * ponteiro_agenda, int num_contatos){
    int i; 
    if (num_contatos == 0){
        printf ("Agenda vazia!\n");
        return;
    }
    printf ("NOME:                                              TELEFONE:                      EMAIL:\n");
    for (i=0;i<num_contatos;i++){
        printf ("%-51s %-31s %-51s\n", ponteiro_agenda[i].nome,ponteiro_agenda[i].telefone,ponteiro_agenda[i].email);
        printf("...................................................................................................\n");
    }

    


}


int main (int argc,char ** argv){
    int opcao;
    int num_contatos = 0;
    agenda_t *ponteiro_agenda = NULL;
    int index;


    do {
        printf ("Aqui esta a nossa agenda!\n");
        printf ("Digite o numero correspondente a cada funcao e digite 0 para sair:\n");
        printf ("<CADASTRAR> (1)\n<LISTAR REGISTROS> (2)\n<IMPRIMIR TABELA> (3)\n<PARAR> (0)\n");
        scanf ("%d", &opcao);
        getchar();

        switch (opcao){
            case 1:
            cadastrar_contatos(&ponteiro_agenda, &num_contatos);
            break;
            case 2:
            if (num_contatos > 0){
                printf ("Digite o indice do contato:\n");
                scanf ("%d", &index);
                listar_unico_contato(ponteiro_agenda,num_contatos,index);
            } else {
                printf ("Agenda vazia!\n");
            }
            
            break;
            case 3:
            listar_contatos(ponteiro_agenda,num_contatos);
            break;
            case 0:
            printf ("Agenda concluida!\n");
            break;
            default:
            printf ("Opcao Invalida!\n");
        }

    }while(opcao != 0);

    free (ponteiro_agenda);



    return SUCESSO;
}