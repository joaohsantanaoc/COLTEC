#include <stdio.h>
#define SUCESSO 0
#define TAM_MAXIMO 20
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
void questao5(){
    printf ("Questao 5 executada!\n");
}
void questao6(){
    printf ("Questao 6 executada!\n");
}
void questao7(){
    printf ("Questao 7 executada!\n");
}
void questao8(){
    printf ("Questao 8 executada!\n");
}
void imprimirquestao1(){
    int numeros[TAM_MAXIMO]; 
    int i; 
    int menor,maior; 
    int indice_maior, indice_menor; 
    for (i=0;i<20;i++){
        printf ("Insira numeros diferentes:\n"); 
        scanf ("%d", &numeros[i]);
    }
    menor=maior=numeros[0];
    indice_menor= 0;
    for (i=1;i<20;i++){
        if (numeros[i]>maior){
            maior = numeros[i];
            indice_maior= i;
        }
        if (numeros[i]<menor){
            menor = numeros[i];
            indice_menor = i; 
        }
    }
    printf ("O maior valor digitado foi %d e seu indice eh %d\n", maior, indice_maior); 
    printf ("O menor valor digitado foi %d e seu indice eh %d\n", menor, indice_menor); 
}
void imprimirquestao03(){
    float vetor01[10];
    float vetor02[10];
    int a;
    float produto_escalar = 0;
    printf("Digite os numeros do vetor 1:\n");
    for (a = 0; a < 10; a++) {
        scanf("%f", &vetor01[a]);
    }
    printf("Digite os numeros do vetor 2:\n");
    for (a = 0; a < 10; a++) {
        scanf("%f", &vetor02[a]);
    }
    for (a = 0; a < 10; a++) {
        produto_escalar += vetor01[a] * vetor02[a];
    }
    printf("O produto escalar entre os vetores eh %f\n", produto_escalar);
}
void imprimirquestao02(){
    int i; 
    float vetor[100]; 
    int tamanho; 
    float escalar; 
    printf ("Digite o tamanho do vetor:\n");
    scanf ("%d", &tamanho); 
    printf ("Digite os elementos do vetor:\n");
    for (i=0;i<tamanho;i++){
        scanf ("%f", &vetor[i]);
    }
    printf ("Digite o valor do escalar:\n");
    scanf ("%f", &escalar);
    for (i=0;i<tamanho;i++){
        vetor[i]=vetor[i]*escalar;
    }
    printf ("Resultado da multiplicacao:\n");
    for (i=0;i<tamanho;i++){
        printf ("%.2f ", vetor[i]);
    }
    printf ("\n");
}
void imprimirquestao04(){
    int tamanho;
    float vetor[100];
    int x; 
    float media;
    float soma; 
    printf ("Digite o tamanho do vetor:\n");
    scanf ("%d", &tamanho);
    if ((tamanho <= 0 | tamanho >100)){
        printf ("Tamanho invalido! Digite um valor ate 100:\n"); 
        printf ("Digite o tamanho do vetor:\n");
        scanf ("%d", &tamanho);
    }
    printf ("Digite os elementos do vetor:\n");
    for (x=0;x<tamanho;x++){
        scanf ("%f", &vetor[x]);
    }
    for (x=0;x<tamanho;x++){
        soma += vetor[x];
    }
    media = soma/tamanho;
    printf ("A media aritmetica dos elementos do vetor eh %2.f\n", media);
}
float menor_valor(float vetor[], int tamanho) {
    int i;
    float menor = vetor[0];
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    return menor;
}

float maior_valor(float vetor[], int tamanho) {
    int i;
    float maior = vetor[0];
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

int encontrar_indice(float vetor[], int tamanho, float valor) {
    int i;
    int indice = -1;
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            indice = i;
            break;
        }
    }
    return indice;
}

void imprimirquestao05() {
    int i;
    int tamanho;
    float vetor[100];
    float menor, maior;
    int indice;
    float valor;
    printf("Qual o tamanho do vetor?\n");
    scanf("%d", &tamanho);
    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < tamanho; i++) {
        scanf("%f", &vetor[i]);
    }
    menor = menor_valor(vetor, tamanho);
    maior = maior_valor(vetor, tamanho);
    printf("O menor valor eh %.2f\n", menor);
    printf("O maior valor eh %.2f\n", maior);
    printf("Digite um valor que voce digitou no vetor e apresentarei o indice:\n");
    scanf("%f", &valor);
    indice = encontrar_indice(vetor, tamanho, valor);
    if (indice != -1) {
        printf("O indice desse valor eh %d\n", indice);
    } else {
        printf("O valor nao foi encontrado no vetor.\n");
    }
}
void multiplicacao_vetor_por_escalar(float vetor[],int tamanho,float escalar){
    int i; 
    for (i=0;i<tamanho;i++){
        vetor[i] = vetor[i] * escalar; 
    } 
}
void imprimirquestao06(){
    int i;
    float vetor[100];
    float escalar;
    int tamanho;
    printf ("Digite o tamanho do vetor:\n");
    scanf ("%d", &tamanho);
    printf ("Digite os elementos do vetor:\n");
    for (i=0;i<tamanho;i++){
        scanf ("%f", &vetor[i]);
    }
    printf ("Digite o valor do escalar:\n");
    scanf ("%f", &escalar); 
     multiplicacao_vetor_por_escalar(vetor,escalar,tamanho); 
    for (i=0;i<tamanho;i++){
        printf ("O produto da multiplicacao do vetor pelo escalar eh %2.f\n", vetor[i]);
    }
}
float produto_escalarv(float vetor1[],float vetor02[],int tamanho,float produto_escalar){
    int a; 
    for (a=0;a<tamanho;a++){
        produto_escalar += vetor1[a] * vetor02[a]; 
    }
    return produto_escalar; 
}
void imprimirquestao07(){
    int a;
    int tamanho; 
    float vetor1[100];
    float vetor02[100];
    float produto_escalar;
    printf ("Digite o tamanho para os dois vetores:\n"); 
    scanf ("%d", &tamanho);
    printf ("Digite os elementos do vetor 1:\n");
    for (a=0;a<tamanho;a++){
        scanf ("%f", &vetor1[a]);
    } 
    printf ("Agora digite os elementos do vetor 2:\n");
    for (a=0;a<tamanho;a++){
        scanf ("%f", &vetor02[a]);
    }
    produto_escalar = produto_escalarv(vetor1,vetor02,tamanho,produto_escalar);
    printf ("O produto escalar entre os dois vetores eh %.2f\n", produto_escalar);

}
void fib(int vetor_fib[],int tamanho){
    int v; 
    if (tamanho >= 1){
        vetor_fib[0]=1;
    }
    if (tamanho >=2){
        vetor_fib[1]=1;
    }
    for (v=2;v<tamanho;v++){
        vetor_fib[v] = vetor_fib[v-1] + vetor_fib[v-2];
    }

}
void imprimirquestao08(){
    int v; 
    int vetor_fib [100]; 
    int tamanho; 
    printf ("Digite o tamanho do vetor:\n");
    scanf ("%d", &tamanho); 
    fib (vetor_fib,tamanho);
    printf ("Os %d primeiros termos com a serie de Fibonacci sao:\n", tamanho); 
    for (v=0;v<tamanho;v++){
        printf ("%d ", vetor_fib[v]);
    }
    printf ("\n");
}


     
int main (int argc,char ** argv){
    int opcao;
    do{
        printf ("Lista 06\nEscolha a questao que voce deseja e digite 0 para parar:\nQuestao 1 (1)\nQuestao 2 (2)\nQuestao 3 (3)\nQuestao 4 (4)\nQuestao 5 (5)\nQuestao 6 (6)\nQuestao 7 (7)\nQuestao 8 (8)\nParar (0)\n");
        scanf ("%d", &opcao); 
        switch (opcao){
            case 1:
            imprimirquestao1(); 
            questao1(); 
            break;
            case 2:
            imprimirquestao02();
            questao2();
            break;
            case 3:
            imprimirquestao03();
            questao3();
            break;
            case 4:
            imprimirquestao04();
            questao4();
            break;
            case 5:
            imprimirquestao05();
            questao5();
            break;
            case 6:
            imprimirquestao06();
            questao6();
            break; 
            case 7:
            imprimirquestao07();
            questao7();
            break; 
            case 8:
            imprimirquestao08();
            questao8();
            break; 
            case 0:
            printf ("Lista acabou...\n");
            break; 
            default:
            printf ("Opcao invalida!\n");
        }      

    }while (opcao!=0);
    return SUCESSO; 
}