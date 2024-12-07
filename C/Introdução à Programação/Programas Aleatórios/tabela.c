#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0
#define NUM_ESTADOS 27
#define NUM_CARACTERES (19 + 1)


void imprimir_tabela_original(char nomes_estados[][NUM_CARACTERES],int populacoes_estados[],int posicoes_populacao[]){
    int i;
    printf ("Tabela com dados originais:\n");
    for (i=0;i<NUM_ESTADOS;i++){
        printf ("%02d %-16s %8d\n",posicoes_populacao[i],nomes_estados[i],populacoes_estados[i]);
    }
}

void ordenar_tabela(char nomes_estados[][NUM_CARACTERES], int populacoes_estados[], int posicoes_populacao[], char nomes_estados_ordenado[][NUM_CARACTERES], int populacoes_estados_ordenado[], int posicoes_populacao_ordenado[]) {
    int i, j;
    char temp[NUM_CARACTERES];
    int temp1, tempPosicao;

    int *copia_populacoes_estados = malloc(NUM_ESTADOS * sizeof(int));
    int *copia_posicoes_populacoes_estados = malloc(NUM_ESTADOS * sizeof(int));
    char **copia_nomes_estados = malloc(NUM_ESTADOS * sizeof(char *));
    for (i = 0; i < NUM_ESTADOS; i++) {
        copia_nomes_estados[i] = malloc(NUM_CARACTERES * sizeof(char));
        strncpy(copia_nomes_estados[i], nomes_estados[i], NUM_CARACTERES - 1);
        copia_nomes_estados[i][NUM_CARACTERES - 1] = '\0';
    }

    memcpy(copia_populacoes_estados, populacoes_estados, NUM_ESTADOS * sizeof(int));
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
    memcpy(populacoes_estados_ordenado, copia_populacoes_estados, NUM_ESTADOS * sizeof(int));
    memcpy(posicoes_populacao_ordenado, copia_posicoes_populacoes_estados, NUM_ESTADOS * sizeof(int));

    free(copia_populacoes_estados);
    free(copia_posicoes_populacoes_estados);
    for (i = 0; i < NUM_ESTADOS; i++) {
        free(copia_nomes_estados[i]);
    }
    free(copia_nomes_estados);
}

void imprimir_tabela(char nomes_estados_ordenado[][NUM_CARACTERES], int populacoes_estados_ordenado[], int posicoes_populacao_ordenado[]) {
    int i;

    printf ("Tabela com dados ordenados\n");
    for (i = 0; i < NUM_ESTADOS; i++) {
        printf("%02d %-19s %8d\n", posicoes_populacao_ordenado[i], nomes_estados_ordenado[i], populacoes_estados_ordenado[i]);
    }
}

void ordenar_ordenado(char nomes_estados[][NUM_CARACTERES], int populacoes_estados[], int posicoes_populacao[], char nomes_estados_ordenado1[][NUM_CARACTERES], int populacoes_estados_ordenado1[], int posicoes_populacao_ordenado[]) {
    int i, j;
    char temp[NUM_CARACTERES];
    int temp1, tempPosicao;

    char **copia_nomes_estados = malloc(NUM_ESTADOS * sizeof(char *));
    for (i = 0; i < NUM_ESTADOS; i++) {
        copia_nomes_estados[i] = malloc(NUM_CARACTERES * sizeof(char));
        strncpy(copia_nomes_estados[i], nomes_estados[i], NUM_CARACTERES - 1);
        copia_nomes_estados[i][NUM_CARACTERES - 1] = '\0';
    }

    int *copia_populacoes_estados = malloc(NUM_ESTADOS * sizeof(int));
    int *copia_posicoes_populacoes_estados = malloc(NUM_ESTADOS * sizeof(int));

    memcpy(copia_populacoes_estados, populacoes_estados, NUM_ESTADOS * sizeof(int));
    memcpy(copia_posicoes_populacoes_estados, posicoes_populacao, NUM_ESTADOS * sizeof(int));

    for (i = 0; i < NUM_ESTADOS - 1; i++) {
        for (j = 0; j < NUM_ESTADOS - i - 1; j++) {
            if (copia_populacoes_estados[j] < copia_populacoes_estados[j + 1]) {
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
        strcpy(nomes_estados_ordenado1[i], copia_nomes_estados[i]);
    }
    memcpy(populacoes_estados_ordenado1, copia_populacoes_estados, NUM_ESTADOS * sizeof(int));
    memcpy(posicoes_populacao_ordenado, copia_posicoes_populacoes_estados, NUM_ESTADOS * sizeof(int));

    for (i = 0; i < NUM_ESTADOS; i++) {
        free(copia_nomes_estados[i]);
    }
    free(copia_nomes_estados);
    free(copia_populacoes_estados);
    free(copia_posicoes_populacoes_estados);
}

void imprimir_tabela_ordenada(char nomes_estados_ordenado1[][NUM_CARACTERES],int populacoes_estados_ordenado1[],int posicoes_populacao_ordenado1[]){
    int i;

    printf ("Tabela do maior para o menor:\n");
    for (i=0;i<NUM_ESTADOS;i++){
        printf ("%02d %-16s %8d\n", i+1,nomes_estados_ordenado1[i],populacoes_estados_ordenado1[i]);
    }

}




int main(int argc,char ** argv) {
    char nomes_estados[NUM_ESTADOS][NUM_CARACTERES] = {
        "Roraima", "Amapa", "Tocantins", "Alagoas", "Paraiba", "Mato Grosso", "Piaui",
        "Bahia", "Acre", "Goias", "Sao Paulo", "Pernambuco", "Santa Catarina",
        "Espirito Santo", "Rio Grande do Sul", "Rondonia", "Mato Grosso do Sul", "Maranhao",
        "Para", "Minas Gerais", "Parana", "Distrito Federal", "Rio Grande do Norte",
        "Ceara", "Rio de Janeiro", "Sergipe", "Amazonas"
    };
    int populacoes_estados[NUM_ESTADOS] = {
        576568, 829494, 1555229, 3322820, 3996496, 3441998, 3264531,
        14812617, 869265, 6921161, 45538936, 9496294, 7075494,
        3972388, 11329605, 1757589, 2748023, 7035055,
        8513497, 21040662, 11348937, 2974703, 3479010,
        9075649, 17159960, 2278308, 4080611
    };
    int posicoes_populacao[NUM_ESTADOS] = {
        27, 26, 24, 18, 14, 17, 19,
        4, 25, 12, 1, 7, 10,
        15, 6, 23, 21, 11,
        9, 2, 5, 20, 16,
        8, 3, 22, 13
    };
    char nomes_estados_ordenado[NUM_ESTADOS][NUM_CARACTERES];
    int populacoes_estados_ordenado[NUM_ESTADOS];
    int posicoes_populacao_ordenado[NUM_ESTADOS];

    char nomes_estados_ordenado1[NUM_ESTADOS][NUM_CARACTERES];
    int populacoes_estados_ordenado1[NUM_ESTADOS];
    int posicoes_populacao_ordenado1[NUM_ESTADOS];

    ordenar_tabela(nomes_estados, populacoes_estados, posicoes_populacao, nomes_estados_ordenado, populacoes_estados_ordenado, posicoes_populacao_ordenado);
    imprimir_tabela(nomes_estados_ordenado, populacoes_estados_ordenado, posicoes_populacao_ordenado);
    

    imprimir_tabela_original(nomes_estados,populacoes_estados,posicoes_populacao);
    imprimir_tabela(nomes_estados_ordenado,populacoes_estados_ordenado,posicoes_populacao_ordenado);
    imprimir_tabela_original(nomes_estados,populacoes_estados,posicoes_populacao);

    ordenar_ordenado(nomes_estados,populacoes_estados,posicoes_populacao,nomes_estados_ordenado1,populacoes_estados_ordenado1,posicoes_populacao_ordenado1);
    imprimir_tabela_ordenada(nomes_estados_ordenado1,populacoes_estados_ordenado1,populacoes_estados_ordenado1);

    return SUCESSO;
}

