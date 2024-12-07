#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0 
#define TAM_MAX 100
#define TAM_QUALQUER 5
#define N 3
#define M 4

void questao1(){
    printf ("Questao 1 concluida!\n");
}
void questao2(){
    printf ("Questao 2 concluida!\n");
}
void questao3(){
    printf ("Questao 3 concluida!\n");
}
void questao4(){
    printf ("Questao 4 concluida!\n");
}
void questao5(){
    printf ("Questao 5 concluida!\n");
}
void questao6(){
    printf ("Questao 6 concluida!\n");
}
int *alocar_vetor(int tamanho){
    int *vetor = (int *)calloc(tamanho,sizeof(int));
    return vetor;
}
float **alocar_matriz(int tamanho1,int tamanho2){
    float **matriz;
    int i;
    matriz = (float **)calloc(tamanho1,sizeof(float *));
    for (i = 0;i< tamanho1;i++){
        matriz[i] = (float**)calloc(tamanho2,sizeof(float *));
    }
    return matriz;
}
void ler_vetor(int vetor2[TAM_QUALQUER]){
    int i;
    printf ("Digite os elementos do vetor:\n");
    for (i=0;i<TAM_QUALQUER;i++){
        printf ("Elemento %d\n", i+1);
        scanf ("%d", &vetor2[i]);
    }
}
int media_elementos_vetor(int vetor2[]){
    int i;
    int soma = 0;
    int media;
    ler_vetor(vetor2);
    for (i=0;i<TAM_QUALQUER;i++){
        soma += vetor2[i];
    }
    media = soma/TAM_QUALQUER;
    return media;
}
int maior_indice(float *vetor,int tamanho,float *maior){
    int indice_maior = 0;
    *maior = vetor[0];
    int i;
    for (i=1;i<tamanho;i++){
        if (vetor[i] > *maior){
            *maior = vetor[i];
            indice_maior = i;
        }
    }
    return indice_maior;
}
void funcao_questao4(){
    float *vetor;
    int tamanho;
    int i;
    float maior;
    int indice_maior;
    printf ("Digite o tamanho que voce deseja que o vetor tenha:\n");
    scanf ("%d", &tamanho);
    vetor = (float *)calloc(tamanho,sizeof(float));
    printf ("Digite os elementos desse vetor:\n");
    for (i=0;i<tamanho;i++){
        printf ("Elemento %d\n", i+1);
        scanf ("%f", &vetor[i]);
    }
    indice_maior = maior_indice(vetor,tamanho,&maior);
    printf ("O maior valor digitado foi %2.f e seu indice eh %d\n", maior,indice_maior);

    free(vetor);
}
float soma_elementos_matriz(float **matriz2){
    int i,j;
    float soma = 0;
    for (i=0;i<N;i++){
        for (j=0;j<M;j++){
            soma += matriz2[i][j];
        }
    }
    return soma;
}
int main (int argc,char ** argv){
    int opcao;
    int *vetor = alocar_vetor(TAM_MAX);
    float **matriz = alocar_matriz(TAM_MAX,TAM_MAX);
    int vetor2[TAM_QUALQUER];
    float** matriz2;
    int i,j;
    int x,y;
    int produtos[TAM_MAX][TAM_MAX];
    int total;
    int menor_quantidade, menor_loja;

    do{
        printf ("Lista 9 de exercicios!\n");
        printf ("Digite o numero da questao que voce deseja acessar e digite 0 para parar:\n");
        printf ("Questao01 (1)\nQuestao02 (2)\nQuestao03 (3)\nQuestao04 (4)\nQuestao05 (5)\nQuestao06 (6)\nParar (0)\n");
        scanf ("%d", &opcao);
        switch (opcao){
            case 1:
            printf ("O endereco inicial do vetor eh %p\n", (void *)vetor);
            free (vetor);
            questao1();
            break;
            case 2:
            printf ("O endereco inicial da matriz eh %p\n", (void**)matriz);
            free(matriz);
            questao2();
            break;
            case 3:
            printf ("A media dos elementos desse vetor eh %d\n", media_elementos_vetor(vetor2));
            questao3();
            break;
            case 4:
            funcao_questao4();
            questao4();
            break;
            case 5:
            matriz2 = (float**)malloc(N*sizeof(float*));
            for (i=0;i<N;i++){
                matriz2[i] = (float **)malloc(M*sizeof(float));
            }
            printf ("Digite os elementos da matriz de tamanho %dx%d:\n", N,M);
            for (i=0;i<N;i++){
                for (j=0;j<M;j++){
                    scanf ("%f", &matriz2[i][j]);
                }
            }
            printf ("A soma dos elementos dessa matriz eh %2.f\n", soma_elementos_matriz(matriz2));
            free (matriz2);
            questao5();
            break;
            case 6:
            printf ("Digite a quantidade x de produtos e o numero de lojas y:\n");
            scanf ("%d %d", &x,&y);
            for (i=0;i<x;i++){
                for (j=0;j<y;j++){
                    printf ("Digite a quantidade do produto %d na loja %d:\n", i+1,j+1);
                    scanf ("%d", &produtos[i][j]);
                    total += produtos[i][j];
                    if (j == 0 || produtos[i][j] < menor_quantidade){
                        menor_quantidade = produtos[i][j];
                        menor_loja = j+1;
                    }
                }
            }
            printf ("Produtos\t");
            for (i=0;i<y;i++){
                printf ("Loja %d\t",i+1);
            }
            printf ("\n");
            for (i=0;i<x;i++){
                printf ("Produto %d\t",i+1);
                for (j=0;j<y;j++){
                    printf ("%d\t", produtos[i][j]);
                }
                printf ("\n");
            }
            printf ("TOTAL DE PRODUTOS: %d\n", total);
            printf("LOJA COM MENOR QUANTIDADE: %d\n", menor_loja);
            questao6();
            break;
            case 0:
            printf ("Lista 9 de exercicios acabou...\n");
            break;
            default:
            printf ("Opcao invalida!\n");
        }

    }while (opcao != 0);
    return SUCESSO; 
}