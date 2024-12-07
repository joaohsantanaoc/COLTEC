#include <stdio.h>

#define SUCESSO 0
#define DIMENSAO1 5
#define DIMENSAO2 5
#define CONSTANTE1 100
#define CONSTANTE2 100
#define TAM_MAX 100
#define QUANTIDADE_DE_PRODUTOS 5
#define NUMERO_DE_LOJAS 7

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
int soma_elementos_matriz(int matriz2[][CONSTANTE2],int tamanho,int tamanho2){
    int a,b;
    int soma; 
    for (a=0;a<tamanho;a++){
        for (b=0;b<tamanho2;b++){
            soma += matriz2[a][b];
        }
    }
    return soma; 
}
void ler_vetor(int vetor[TAM_MAX],int N){
    int i;
    for (i=0;i<N;i++){
        scanf ("%d", &vetor[i]);
    }
}
void ler_matriz(int matriz3[][TAM_MAX],int N){
    int i,j;
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            scanf ("%d", &matriz3[i][j]);
        }
    }
}
void produto_vetor_matriz(int matriz3[][TAM_MAX],int vetor[TAM_MAX],int produto[TAM_MAX],int N){
    int i,j;
    for (i=0;i<N;i++){
        produto[i]=0;
        for (j=0;j<N;j++){
            produto[i] += vetor[j]*matriz3[i][j];
        }
    }
}

int main (int argc,char ** argv){
    int opcao;
    int matriz[DIMENSAO1][DIMENSAO2];
    int i,j;
    int matriz2[CONSTANTE1][CONSTANTE2];
    int a,b;
    int tamanho,tamanho2;
    int N;
    int vetor[TAM_MAX];
    int matriz3[TAM_MAX][TAM_MAX];
    int produto[TAM_MAX];
    int produtos[QUANTIDADE_DE_PRODUTOS][NUMERO_DE_LOJAS];
    int menor_quantidade=0;
    int total_produtos = 0;
    int loja_menor_quantidade=0;

    do{
        printf ("Lista 8 de exercicios!\n");
        printf ("Digite o numero da questao que voce deseja e digite 0 para parar:\n");
        printf ("Questao 1 (1)\nQuestao 2 (2)\nQuestao 3 (3)\nQuestao 4 (4)\nParar (0)\n");
        scanf ("%d", &opcao);
        switch (opcao){
            case 1:
            printf ("Digite os elementos de uma matriz 5x5:\n");
            for (i=0;i<DIMENSAO1;i++){
                for (j=0;j<DIMENSAO2;j++){
                    scanf ("%d", &matriz[i][j]);
                }
            }
            printf ("Imprimindo a matriz com todos os seus elementos:\n");
            for (i=0;i<DIMENSAO1;i++){
                for (j=0;j<DIMENSAO2;j++){
                    printf ("%d ", matriz[i][j]);
                }
                printf ("\n");
            }
            questao1();
            break;
            case 2:
            printf ("Digite o tamanho da primeira e segunda dimensao da matriz:\n");
            scanf ("%d %d", &tamanho,&tamanho2);
            printf ("Agora digite os elementos da matriz de dimensao %dx%d:\n", tamanho,tamanho2);
            for (a=0;a<tamanho;a++){
                for (b=0;b<tamanho2;b++){
                    scanf ("%d", &matriz2[a][b]);
                }
            }
            printf ("A soma dos elementos dessa matriz eh: %d\n", soma_elementos_matriz(matriz2,tamanho,tamanho2));
            questao2();
            break;
            case 3:
            printf ("Digite o tamanho N do vetor:\n");
            scanf ("%d", &N);
            printf ("Agora digite os elementos desse vetor:\n");
            ler_vetor(vetor,N);
            printf ("Agora o numero N sera a dimensao NxN para a matriz\n");
            printf ("Agora digite os elementos da matriz com dimensoes %dx%d\n", N,N);
            ler_matriz(matriz3,N);
            produto_vetor_matriz(matriz3,vetor,produto,N);
            for (i=0;i<N;i++){
                printf ("%d ", produto[i]);
            }
            printf ("\n"); 
            questao3();
            break;
            case 4:
            for (i=0;i<QUANTIDADE_DE_PRODUTOS;i++){
                for (j=0;j<NUMERO_DE_LOJAS;j++){
                    printf ("Digite a quantidade total do produto %d na loja %d:\n", i+1,j+1);
                    scanf ("%d", &produtos[i][j]);
                    total_produtos += produtos[i][j];
                    if ( j == 0  || produtos[i][j] < menor_quantidade){
                        menor_quantidade = produtos[i][j];
                        loja_menor_quantidade = j+1; 
                    }
                }
            }
            printf ("Produtos\t");
            for (i=0;i<NUMERO_DE_LOJAS;i++){
                printf ("Loja %d\t", i+1);
            }
            printf ("\n");
            for (i=0;i<QUANTIDADE_DE_PRODUTOS;i++){
                printf ("Produto %d\t",i+1);
                for (j=0;j<NUMERO_DE_LOJAS;j++){
                    printf ("%d\t", produtos[i][j]);
                }
                printf ("\n");
            }
            
            printf ("TOTAL DE PRODUTOS: %d\n", total_produtos);
            printf ("LOJA COM MENOR QUANTIDADE: %d\n", loja_menor_quantidade);
            questao4();
            break;
            case 0:
            printf ("Lista acabou...\n"); 
            break;
            default:
            printf ("Opcao invalida!!!\n");
        }


    }while (opcao != 0);
    return SUCESSO; 
}