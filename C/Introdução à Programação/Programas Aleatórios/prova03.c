#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SUCESSO 0
#define TAM_DEFINIDO 10 
#define NUM_ESTADOS 27
#define NUM_CARACTERES (19 + 1)
#define NUM_MAX 8

void questao1(){
    printf ("Questao 1 executada!\n");
}
void questao2(){
    printf ("Questao 2 executada!\n");
}
void questao3(){
    printf ("Questao 3 executada!\n");
}
void questao4(){
    printf ("Questao 4 executada!\n");
}
int encontrar_posicao_numero(int vetor[],int  numero){
    int i;
    int indice = -1;
    for (i=0;i<TAM_DEFINIDO;i++){
        if (vetor[i] == numero){
            indice = i;
            break;
        }
    }
    return indice;
}
void encontrar_posicoes(int primeiro_vetor[],int segundo_vetor[],int terceiro_vetor[]){
    int i,j;
    for (i=0;i<TAM_DEFINIDO;i++){
        for (j=0;j<TAM_DEFINIDO;j++){
            if (primeiro_vetor[i] == segundo_vetor[j]){
                terceiro_vetor[i] = j;
                break;
            }
        }
    }
}
void imprimir_vetor (int terceiro_vetor[]){
    int i;

    for (i=0;i<TAM_DEFINIDO;i++){
        printf ("%d ", terceiro_vetor[i]);
    }
    printf("\n");

}
void imprimir_populacao(int vetor[]){
    int i;
    for (i=0;i<NUM_ESTADOS;i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n");
}
void ordena_vetor(int populacao[],int posicoes_populacao[],int populacao_ordenado [], int posicoes_populacao_ordenado []){
    //Criacao das copias dos vetores
    int * copiapopulacao = (int *)malloc(NUM_ESTADOS * sizeof(int));
    int * copia_posicoes_populacao = (int *)malloc(NUM_ESTADOS * sizeof(int));
    int i,j,temp,tempPosicao;

    memcpy (copiapopulacao,populacao,NUM_ESTADOS * sizeof(int));
    memcpy (copia_posicoes_populacao,posicoes_populacao,NUM_ESTADOS * sizeof(int));

    //Ordenar a copia do vetor
    for (i=0;i<NUM_ESTADOS-1;i++){
        for (j=0;j<NUM_ESTADOS-i-1;j++){
            if (copiapopulacao[j] > copiapopulacao[j+1]){
                //Ordenar o vetor
                temp = copiapopulacao[j];
                copiapopulacao[j] = copiapopulacao[j+1];
                copiapopulacao[j+1] = temp;
                //Ordenar as posicoes
                tempPosicao = copia_posicoes_populacao[j];
                copia_posicoes_populacao[j] = copia_posicoes_populacao[j+1];
                copia_posicoes_populacao[j+1] = tempPosicao;
            }
        }
    }
    //Copiar os vetores ordenados para saida
    memcpy(populacao_ordenado,copiapopulacao,NUM_ESTADOS*sizeof(int));
    memcpy(posicoes_populacao_ordenado,copia_posicoes_populacao,NUM_ESTADOS*sizeof(int));
    //Libera espaco da memoria
    free(copiapopulacao);
    free(copia_posicoes_populacao);
}
void ordenar_tabela(char nome_estados[][NUM_CARACTERES], int populacoes_estado[], int posicoes_populacao[], char nomes_estados_ordenado[][NUM_CARACTERES], int populacao_ordenado[], int posicoes_populacao_ordenado[]) {
    int i, j;
    char temp[NUM_CARACTERES];
    int temp1, tempPosicao;

    int *copia_populacoes_estados = malloc(NUM_ESTADOS * sizeof(int));
    int *copia_posicoes_populacoes_estados = malloc(NUM_ESTADOS * sizeof(int));
    char **copia_nomes_estados = malloc(NUM_ESTADOS * sizeof(char *));
    for (i = 0; i < NUM_ESTADOS; i++) {
        copia_nomes_estados[i] = malloc(NUM_CARACTERES * sizeof(char));
        strncpy(copia_nomes_estados[i], nome_estados[i], NUM_CARACTERES - 1);
        copia_nomes_estados[i][NUM_CARACTERES - 1] = '\0';
    }

    memcpy(copia_populacoes_estados, populacoes_estado, NUM_ESTADOS * sizeof(int));
    memcpy(copia_posicoes_populacoes_estados, posicoes_populacao, NUM_ESTADOS * sizeof(int));

    for (i = 0; i < NUM_ESTADOS - 1; i++) {
        for (j = 0; j < NUM_ESTADOS - i - 1; j++) {
            if (copia_posicoes_populacoes_estados[j] < copia_posicoes_populacoes_estados[j + 1]) {
                strcpy(temp, copia_nomes_estados[j]);
                strcpy(copia_nomes_estados[j], copia_nomes_estados[j + 1]);
                strcpy(copia_nomes_estados[j + 1], temp);

                tempPosicao = copia_posicoes_populacoes_estados[j];
                copia_posicoes_populacoes_estados[j] = copia_posicoes_populacoes_estados[j + 1];
                copia_posicoes_populacoes_estados[j + 1] = tempPosicao;

                temp1 = copia_populacoes_estados[j];
                copia_populacoes_estados[j] = copia_populacoes_estados[j + 1];
                copia_populacoes_estados[j + 1] = temp1;
            }
        }
    }
    for (i = 0; i < NUM_ESTADOS; i++) {
        strcpy(nomes_estados_ordenado[i], copia_nomes_estados[i]);
    }
    memcpy(populacao_ordenado, copia_populacoes_estados, NUM_ESTADOS * sizeof(int));
    memcpy(posicoes_populacao_ordenado, copia_posicoes_populacoes_estados, NUM_ESTADOS * sizeof(int));

    free(copia_populacoes_estados);
    free(copia_posicoes_populacoes_estados);
    for (i = 0; i < NUM_ESTADOS; i++) {
        free(copia_nomes_estados[i]);
    }
    free(copia_nomes_estados);
}

void imprimir_tabela(char nomes_estados_ordenado[][NUM_CARACTERES], int populacao_ordenado[], int posicoes_populacao_ordenado[]) {
    int i;

    for (i = 0; i < NUM_ESTADOS; i++) {
        printf("%02d %-19s %8d\n", posicoes_populacao_ordenado[i], nomes_estados_ordenado[i], populacao_ordenado[i]);
    }
}




int main (int argc,char ** argv){
    int opcao;
    int vetor[TAM_DEFINIDO] = {1,2,3,4,5,6,7,8,9,10};
    int numero;
    int i;
    int primeiro_vetor[TAM_DEFINIDO] = {1,2,3,4,5,6,7,8,9,10};
    int segundo_vetor[TAM_DEFINIDO] = {10,9,8,7,6,5,4,3,2,1};
    int terceiro_vetor[TAM_DEFINIDO];
    char nome_estados[NUM_ESTADOS][NUM_CARACTERES] = {"Minas Gerais","Rio de Janeiro","Sao Paulo","Espirito Santo","Rio Grande do Sul","Santa Catarina","Parana","Goias","Distrito Federal","Mato Grosso do Sul","Mato Grosso","Bahia","Sergipe","Alagoas","Paraiba","Rio Grande do Norte","Maranhao","Piaui","Pernambuco","Ceara","Rondonia","Roraima","Amazonas","Para","Tocantins","Amapa","Acre"};
    int populacoes_estado[NUM_ESTADOS] = {20870000,6748000,44040000,3885000,11290000,7165000,11080000,6523000,2817068,2620000,3224000,15130000,2220000,3322000,3944000,3409000,6851000,3195000,9278000,8843000,1749000,496936,3874000,8074000,1497000,751000,790101};
    int posicoes_populacao[NUM_ESTADOS] = {2,3,1,15,6,10,5,12,20,21,17,4,22,18,14,16,19,7,8,23,27,13,9,24,26,25};
    int populacao[NUM_ESTADOS] = {20870000,6748000,44040000,3885000,11290000,7165000,11080000,6523000,2817068,2620000,3224000,15130000,2220000,3322000,3944000,3409000,6851000,3195000,9278000,8843000,1749000,496936,3874000,8074000,1497000,751000,790101};
    int populacao_ordenado[NUM_ESTADOS];
    int posicoes_populacao_ordenado[NUM_ESTADOS];
    char nomes_estados_ordenado[NUM_ESTADOS][NUM_CARACTERES];
    do{
        printf ("Aqui esta a prova 3!\n");
        printf ("Digite a questao que voce deseja acessar e digite 0 para parar:\n");
        printf ("Questao 1 (1)\nQuestao 2 (2)\nQuestao 3 (3)\nQuestao 4 (4)\nParar (0)\n");
        scanf ("%d%*c", &opcao);
        switch (opcao){
            case 1:
            printf ("Posicao do numero %d: %d\n", 10, encontrar_posicao_numero(vetor,10));
            encontrar_posicoes(primeiro_vetor,segundo_vetor,terceiro_vetor);
            imprimir_vetor(terceiro_vetor);
            questao1();
            break;
            case 2:
            printf ("POPULACAO ORIGINAL:\n");
            imprimir_populacao(populacao);
            ordena_vetor(populacao,posicoes_populacao,populacao_ordenado,posicoes_populacao_ordenado);
            printf ("POPULACAO ORDENADA:\n");
            imprimir_populacao(populacao_ordenado);
            printf ("POPULACAO ORIGINAL:\n");
            imprimir_populacao(populacao);
            questao2();
            break;
            case 3:
            ordenar_tabela(nome_estados,populacoes_estado,posicoes_populacao,nomes_estados_ordenado,populacao_ordenado,posicoes_populacao_ordenado);
            imprimir_tabela (nomes_estados_ordenado,populacao_ordenado,posicoes_populacao_ordenado);
                       
            questao3();
            break;
            case 4:
            questao4();
            break;
            case 0:
            printf ("Prova 3 acabou...\n");
            break;
            default:
            printf ("Opcao invalida!\n");
        }

    }while (opcao != 0);
    return SUCESSO;
}