#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0
#define ERRO -1
#define NUM_CARACTERES_STRING (29 + 1)
#define NUM_CARACTERES_ENDERECO (49 + 1)
#define NUM_CARACTERES_NOME (49 + 1)

typedef struct agenda_s{
    int matricula;
    char endereco[NUM_CARACTERES_ENDERECO];
    char nome[NUM_CARACTERES_NOME];
}agenda_t;
typedef struct perfil_s{
    char nome[NUM_CARACTERES_NOME];
    int idade;
    int cpf;
}perfil_t;

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
void cadastro_dados(perfil_t ** ponteiro_perfil,int * num_perfis){
    perfil_t perfis;

    printf ("\t\tCADASTRO DE DADOS\n");
    printf ("Digite seu nome:\n");
    fgets(perfis.nome, NUM_CARACTERES_NOME, stdin);
    util_removeQuebraLinhaFinal(perfis.nome);
    printf ("Digite sua idade:\n");
    scanf ("%d", &perfis.idade);
    printf ("Digite seu CPF:\n");
    scanf ("%d", &perfis.cpf);

    (*num_perfis)++;
    *ponteiro_perfil = realloc(*ponteiro_perfil,*num_perfis * sizeof(perfil_t));
    (*ponteiro_perfil)[*num_perfis - 1] = perfis;

}
int salvar_dados(perfil_t * ponteiro_perfil,int num_perfis){
    int i;
    FILE * arquivo;
    if (num_perfis < 1){
        printf ("Nao existem perfis cadastrados!\n");
        return ERRO;
    }
    arquivo = fopen("perfis.txt","wo");
    if (!arquivo){
        printf ("Erro ao abrir o arquivo!\n");
        return ERRO;
    }
    for (i=0;i<num_perfis;i++){
        fprintf(arquivo,"NOME: %s\n", ponteiro_perfil[i].nome);
        fprintf(arquivo,"IDADE: %d\n",ponteiro_perfil[i].idade);
        fprintf(arquivo,"CPF: %d\n",ponteiro_perfil[i].cpf);
    }

    fclose(arquivo);
    return SUCESSO;
}
int ler_dados(perfil_t * ponteiro_perfil,int num_perfis){
    FILE * arquivo;
    int i;

    if (num_perfis < 1){
        printf ("Nao existem perfis cadastrados!\n");
        return ERRO;
    }

    arquivo = fopen("perfis.txt","r");
    if (!arquivo){
        printf ("Erro ao abrir o arquivo!\n");
        return ERRO;
    }
    for (i=0;i<num_perfis;i++){
        fgets(ponteiro_perfil[i].nome,NUM_CARACTERES_NOME,arquivo);
        fscanf(arquivo,"%d",&ponteiro_perfil[i].idade);
        fscanf(arquivo,"%d",&ponteiro_perfil[i].cpf);
    }

    fclose(arquivo);
    return SUCESSO;
}
int listar_dados(perfil_t * ponteiro_perfil,int num_perfis){
    int i;
    if (num_perfis < 1){
        printf ("Nao existem perfis cadastrados!\n");
        return ERRO;
    }
    printf ("\t\tDADOS\n");
    for (i=0;i<num_perfis;i++){
        printf ("%-50s %3d %11d\n", ponteiro_perfil[i].nome,ponteiro_perfil[i].idade,ponteiro_perfil[i].cpf);
    }

    return SUCESSO;


}


int main (int argc,char ** argv){
    char string[NUM_CARACTERES_STRING] = "Meu programa em c\n12345";
    int caracteres = strlen(string);
    int opcao,opcao2;
    agenda_t usuario;
    agenda_t * ponteiro_agenda = NULL;
    int num_usuarios = 0;
    int * numeros; 
    int contador_de_digitos = 0;
    perfil_t * ponteiro_perfil = NULL;
    int num_perfis = 0;


    do{
        printf ("Bem vindo ao sistema de arquivos!!!\n");
        printf ("O que voce deseja fazer?\n");
        printf ("(1) <SALVAR INFORMACOES NO ARQUIVO>\n(2) <LER CARACTERES DE UM ARQUIVO>\n(3) <LER LINHAS DE UM ARQUIVO>\n(4) <LER NUMEROS DE UM ARQUIVO>\n(5) <CADASTRO DAS INFORMACOES>\n(6) <SALVAR INFORMACOES>\n(7) <LER NUMEROS>\n(8) <SALVAR INFORMACOES EM BINARIO>\n(9) <CADASTRAR DADOS DE VARIOS USUARIOS>\n(10) <SALVAR DADOS EM BINARIO>\n(11) <SALVAR UNICO NUMERO EM BINARIO>\n(12) <PERFIS>\n(0) <PARAR>\n");
        printf ("SUA OPCAO: ");
        scanf ("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:{
                salvar_info_em_arquivo(string,caracteres);
                break;
            }
            case 2:{
                ler_caracteres_do_arquivo();
                break;
            }
            case 3:{
                ler_linhas_de_um_arquivo();
                break;
            }
            case 4:{
                ler_numeros_em_arquivo();
                break;
            }
            case 5:{
                ler_dados_agenda(&usuario);
                break;
            }
            case 6:{
                salvar_dados_agenda(&usuario);
                break;
            }
            case 7:{
                ler_numeros_inteiros(&numeros,&contador_de_digitos);
                break;
            }
            case 8:{
                salvar_em_binario(numeros,contador_de_digitos);
                break;
            }
            case 9:{
                ler_dados_agenda_array(&ponteiro_agenda,&num_usuarios);
                break;
            }
            case 10:{
                salvar_dados_agenda_em_binario(ponteiro_agenda,num_usuarios);
                break;
            }
            case 11:{
                cadastrar_e_salvar_unico_numero_em_binario();
                break;
            }
            case 12:{
                printf ("\t\tBem vindo ao cadastro de informacoes!!!\n");
                do{ 
                    printf ("(1) <CADASTRAR DADOS>\n(2) <LISTAR DADOS>\n");
                    printf ("Digite sua opcao:\n");
                    scanf ("%d", &opcao2);
                    getchar();

                    switch (opcao2){
                        case 1:{
                            cadastro_dados(&ponteiro_perfil,&num_perfis);
                            salvar_dados(ponteiro_perfil,num_perfis);
                            break;
                        }
                        case 2:{
                            ler_dados(ponteiro_perfil,num_perfis);
                            listar_dados(ponteiro_perfil,num_perfis);
                            break;
                        }
                        case 0:{
                            printf ("Saindo!\n");
                            break;
                        }
                        default:{
                            printf ("Opcao invalida!\n");
                        }

                    }
                    

                }while(opcao2 != 0);
                break;
            }
            case 0:{
                printf ("Saindo!\n");
                break;
            }
            default:{
                printf ("Opcao invalida!\n");
            }
        }

    }while(opcao != 0);

    free(numeros);
    free(ponteiro_agenda);
    free(ponteiro_perfil);
    return SUCESSO;
}