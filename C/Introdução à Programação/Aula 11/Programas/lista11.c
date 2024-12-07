//Bibliotecas presentes no código
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Constantes presentes no código
#define SUCESSO 0
#define ERRO -1
#define NUM_MAX_CARACTERES_STRING (29 + 1)
#define NUM_CARACTERES_STRING (29 + 1)
#define NUM_CARACTERES_ENDERECO (49 + 1)
#define NUM_CARACTERES_NOME (49 + 1)
#define NUM_MAX_CARACTERES (29 + 1)
#define MAX_USUARIOS 100

//Estrutura presente no código
typedef struct agenda_s{
    int matricula;
    char endereco[NUM_CARACTERES_ENDERECO];
    char nome[NUM_CARACTERES_NOME];
}agenda_t;
typedef struct aluno_s{
    char nome[NUM_MAX_CARACTERES];
    char endereco[NUM_MAX_CARACTERES];
    int matricula;
}aluno_t;
//Função para verificar se as questões foram feitas
void questao1(){
    printf ("Questao 1 concluida!!!\n");
}
void questao2(){
    printf ("Questao 2 concluida!!!\n");
}
void questao3(){
    printf ("Questao 3 concluida!!!\n");
}
void questao4(){
    printf ("Questao 4 concluida!!!\n");
}
void questao5(){
    printf ("Questao 5 concluida!!!\n");
}
void questao6(){
    printf ("Questao 6 concluida!!!\n");
}
void questao7(){
    printf ("Questao 7 concluida!!!\n");
}
void questao8(){
    printf ("Questao 8 concluida!!!\n");
}

//Funções utilizadas para o código

//Função para tirar o '\n' das strings
void util_removeQuebraLinhaFinal(char dados[]) {
    int tamanho;
    tamanho = strlen(dados);
    if ((tamanho > 0) && (dados[tamanho - 1] == '\n')) {
        dados[tamanho - 1] = '\0';
    }
}
int salvar_info_em_arquivo(char string[], int caracteres){
    int i;
    FILE * arquivo;

    arquivo = fopen("texto.txt", "w");
    if (!arquivo){
        printf ("Erro ao abrir o arquivo!\n");
        return ERRO;
    }
    for (i=0;i<caracteres;i++){
        fputc (string[i], arquivo);
    }

    fclose(arquivo);
    return SUCESSO;

}
int ler_caracteres_do_arquivo(){
    FILE * arquivo;
    int num_caracteres = 0;
    

    arquivo = fopen("texto.txt","r");
    if (!arquivo){
        printf ("Erro ao abrir o arquivo!\n");
        return ERRO;
    }
    char c = fgetc(arquivo);
    while (c != EOF){
        if (c != ' ' && c != '\n'){
            num_caracteres++;
            printf ("%c\n", c);
        }
        printf ("NUM DE CARACTERES: %d\n", num_caracteres);
        c = fgetc(arquivo);
        
    }

    fclose (arquivo);
    return SUCESSO; 
}
int ler_linhas_de_um_arquivo(){
    FILE * arquivo;
    int num_de_linhas = 0;

    arquivo = fopen("texto.txt","r");
    if (!arquivo){
        printf ("Erro ao abrir o arquivo!\n");
        return ERRO;
    }
    char c = fgetc(arquivo);
    if (c != EOF){
        num_de_linhas++;
        printf ("NUM DE LINHAS: %d\n", num_de_linhas);
    }
    while(c != EOF){
        if (c == '\n'){
            num_de_linhas++;
            printf ("NUM DE LINHAS: %d\n", num_de_linhas);
        }
        
        c = fgetc(arquivo);
    }

    fclose(arquivo);
    return SUCESSO;
}
int ler_numeros_em_arquivo(){
    FILE * arquivo;
    int contandor_de_numeros = 0;

    arquivo = fopen("texto.txt","r");
    if (!arquivo){
        printf ("Erro ao abrir o arquivo!\n");
        return ERRO;
    }
    char c = fgetc(arquivo);
    while(c != EOF){
        if (c == '0' || c == '1'|| c == '2'|| c == '3'|| c == '4'|| c == '5'|| c == '6'|| c == '7'|| c == '8'|| c == '9'){
            contandor_de_numeros++;
            printf ("%c", c);
            printf(" ");
            printf ("\n");
        }
        c = fgetc(arquivo);
    }
    printf ("NUM DE NUMEROS: %d\n", contandor_de_numeros);

    fclose(arquivo);
    return SUCESSO;
}
void ler_dados_agenda(agenda_t * ponteiro_agenda){

    printf ("\t\tDADOS DO USUARIO:\n");
    printf ("Digite o numero de sua matricula:\n");
    scanf("%d", &ponteiro_agenda->matricula);
    getchar();
    printf ("Digite seu nome:\n");
    fgets(ponteiro_agenda->nome, NUM_CARACTERES_NOME, stdin);
    util_removeQuebraLinhaFinal(ponteiro_agenda->nome);
    printf ("Digite o seu endereco:\n");
    fgets(ponteiro_agenda->endereco, NUM_CARACTERES_ENDERECO, stdin);
    util_removeQuebraLinhaFinal(ponteiro_agenda->endereco);

}
int salvar_dados_agenda(agenda_t * ponteiro_agenda){
    FILE * arquivo;

    arquivo = fopen("agenda.txt", "w");
    if (!arquivo){
        printf ("Erro ao abrir o arquivo!\n");
        return ERRO;
    }
    fprintf (arquivo,"NUM DE MATRICULA: %d\n", ponteiro_agenda->matricula);
    fprintf (arquivo,"NOME: %-50s\n", ponteiro_agenda->nome);
    fprintf (arquivo,"ENDERECO: %-50s\n", ponteiro_agenda->endereco);

    printf ("Dados salvos com sucesso!!!\n");

    fclose(arquivo);

    return SUCESSO;
}
int cadastrar_e_salvar_unico_numero_em_binario(){
    FILE * arquivo;
    int numero;

    arquivo = fopen("numero.bin","wb");
    if (!arquivo){
        printf ("Erro ao abrir o arquivo!\n");
        return ERRO;
    }
    while (numero >= 0){
        printf ("Digite um numero sem ser negativo:\n");
        scanf("%d",&numero);
        fwrite(&numero,sizeof(int),1,arquivo);
    }

    fclose(arquivo);
    return SUCESSO;
}
int ler_numeros_inteiros(int ** numeros,int *contador_de_digitos){
    *numeros = NULL;
    *contador_de_digitos = 0;

    int numero;
    
    do{
        printf ("Digite quaisquer numeros sem ser negativo:\n");
        scanf ("%d", &numero);

        (*contador_de_digitos)++;
        *numeros =(int *) realloc(*numeros,*contador_de_digitos * sizeof(int));
        if (*numeros == NULL){
            printf ("Erro ao salvar as informacoes!!!\n");
            return ERRO;
        }
        (*numeros)[*contador_de_digitos - 1] = numero;
    }while(numero >= 0);

    return SUCESSO; 
}
int salvar_em_binario(int * numeros,int contador_de_digitos){
    FILE * arquivo;
    
    arquivo = fopen("numeros.bin","wb");
    if (!arquivo){
        printf ("Erro ao abrir o arquivo!\n");
        return ERRO;
    }
    fwrite(numeros,sizeof(int),contador_de_digitos,arquivo);

    fclose(arquivo);

    return SUCESSO; 
}
void ler_dados_agenda_array(agenda_t ** ponteiro_agenda,int * num_usuarios){
    agenda_t usuarios; 

    printf ("\t\tDADOS DO USUARIO:\n");
    printf ("Digite o numero de sua matricula:\n");
    scanf("%d", &usuarios.matricula);
    getchar();
    printf ("Digite seu nome:\n");
    fgets(usuarios.nome, NUM_CARACTERES_NOME, stdin);
    util_removeQuebraLinhaFinal(usuarios.nome);
    printf ("Digite o seu endereco:\n");
    fgets(usuarios.endereco, NUM_CARACTERES_ENDERECO, stdin);
    util_removeQuebraLinhaFinal(usuarios.endereco);

    (*num_usuarios)++;
    *ponteiro_agenda =realloc(*ponteiro_agenda,*num_usuarios * sizeof(agenda_t));
    (*ponteiro_agenda)[*num_usuarios - 1] = usuarios; 
}
int salvar_dados_agenda_em_binario(agenda_t * ponteiro_agenda,int num_usuarios){
    FILE * arquivo;

    arquivo = fopen("agenda.bin","wb");
    if (!arquivo){
        printf ("Erro ao abrir o arquivo!\n");
        return ERRO;
    }
    fwrite(ponteiro_agenda,sizeof(agenda_t),num_usuarios,arquivo);

    fclose(arquivo);

    return SUCESSO;
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


//Função principal
int main (int argc,char ** argv){
    int opcao;
    char string[NUM_MAX_CARACTERES_STRING] = "Meu programa em c\n12345";
    int caracteres = strlen(string);
    agenda_t usuario;
    agenda_t * ponteiro_agenda = NULL;
    int num_usuarios = 0;
    int * numeros; 
    int contador_de_digitos = 0;
    aluno_t * ponteiro_aluno = NULL;
    int num_alunos = 0;
    int escolha;


    do {
        printf ("Bem vindo a lista 11 de exercicios!!!\n");
        printf ("QUESTOES:\n(1) <QUESTAO 1>\n(2) <QUESTAO 2>\n(3) <QUESTAO 3>\n(4) <QUESTAO 4>\n(5) <QUESTAO 5>\n(6) <QUESTAO 6>\n(7) <QUESTAO 7>\n(8) <QUESTAO 8>\n(0) <PARAR>\n");
        printf ("Qual questao voce deseja fazer:\n");
        scanf ("%d", &opcao);
        getchar();

        switch (opcao){
            case 1:{
                salvar_info_em_arquivo(string,caracteres);
                ler_caracteres_do_arquivo();
                questao1();
                break;
            }
            case 2:{
                ler_linhas_de_um_arquivo();
                questao2();
                break;
            }
            case 3:{
                ler_numeros_em_arquivo();
                questao3();
                break;
            }
            case 4:{
                ler_dados_agenda(&usuario);
                questao4();
                break;
            }
            case 5:{
                cadastrar_e_salvar_unico_numero_em_binario();
                questao5();
                break;
            }
            case 6:{
                ler_dados_agenda_array(&ponteiro_agenda,&num_usuarios);
                salvar_dados_agenda_em_binario(ponteiro_agenda,num_usuarios);
                questao6();
                break;
            }
            case 7:{
                ler_numeros_inteiros(&numeros,&contador_de_digitos);
                salvar_em_binario(numeros,contador_de_digitos);
                questao7();
                break;
            }
            case 8:{
                do{
                    printf ("SISTEMA DE CADASTRO E LISTAGEM DE DADOS\n");
                    printf ("..................................................\n\n");
                    printf ("(1) <CADASTRAR ALUNOS>\n(2) <LISTAR ALUNOS>\n(3) <SALVAR NO ARQUIVO>\n(4) <LER DO ARQUIVO>\n(0) <PARAR>\n");
                    printf ("Digite sua opcao:\n");
                    scanf ("%d%*c", &escolha);

                    switch (escolha){
                        case 1:{
                            cadastro(&ponteiro_aluno,&num_alunos);
                            break;
                        }
                        case 2:{
                            listar(ponteiro_aluno,num_alunos);
                            break;
                        }
                        case 3:{
                            salvar_no_arquivo(ponteiro_aluno,num_alunos);
                            break;
                        }
                        case 4:{
                            ler_do_arquivo(ponteiro_aluno,num_alunos);
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

                }while (escolha != 0);
                questao8();
                break;
            }
            case 0:{
                printf ("Lista 11 de exercicios acabou!!!\n");
                break;
            }
            default:{
                printf ("Opcao invalida!!!\n");
            }
        }

    }while (opcao != 0);

    //Se tudo correu bem é porque chegou até aqui
    return SUCESSO;
}