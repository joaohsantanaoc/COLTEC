#include <stdio.h>
#define SUCESSO 0 
#define termos_maximos 100
void questao1(){
    printf ("Questao 1 executada!\n"); 
}
void questao2(){
    printf ("Questao2 executada!\n"); 

}
void questao3(){
    printf ("Questao 3 executada!\n"); 
}
void questao4(){
    printf ("Questao4 executada!\n"); 
}
void questao5(){
    printf ("Questao5 executada!\n"); 

}
void questao6(){
    printf ("Questao6 executada!\n"); 
}
void questao7(){
    printf ("Questao7 executada!\n"); 
}
void questao8(){
    printf ("Questao8 executada!\n"); 
}
void questao0(){
    printf ("Lista acabou...\n"); 
} 
float  soma (float a, float b){
    return a+b; 
}
float produto(float a,float b){
    return a*b; 
}
float quociente(float a,float b){
    if (b!=0){
        return (float)a/b;
    }else{
        return SUCESSO; 
    }
}
int conversor(int anos,int meses, int dias){
    int resultado;
    resultado= anos*365 + meses * 30 + dias; 
    return resultado;    
}
void duracao(int segundos){
    int horas;
    int minutos;
    int segundos_resto;
    horas= segundos/3600;
    minutos= (segundos % 3600)/60; 
    segundos_resto = (segundos %3600)%60;
    printf ("A duracao do experimento eh %d horas,%d minutos e %d segundos\n", horas,minutos,segundos_resto);
}
int primo (int num){
    int divisor;
    if (num <=1){
        return 0;
    }
    for (divisor =2; divisor * divisor <= num; divisor++){
        if (num % divisor == 0){
            return 0;
        }
    }
    return 1; 
}
void verificador_primo(int num){
    if (primo(num)){
        printf ("O numero eh primo\n");
    }else {
        printf ("O numero nao eh primo\n");
    }
}
int fatorando(int n){
    int a;
    int fatorial=1; 
    for (a=1;a<=n;a++){
        fatorial = fatorial * a;
    }
    return fatorial; 
}
void imprimir_fatorial(int n){
    int fatorial = fatorando (n);
    printf ("O fatorial eh %d\n", fatorial);
}
int calculo(int linha, int coluna) {
    if (coluna == 0 || coluna == linha) {
        return 1;
    } else {
        return calculo(linha - 1, coluna - 1) + calculo(linha - 1, coluna);
    }
}
void imprimir_triangulo_pascal(int h) {
    int linha, coluna;
    for (linha = 0; linha <= h; linha++) {
        for (coluna = 0; coluna <= linha; coluna++) {
            int elemento = calculo(linha, coluna);
            printf("%d ", elemento);
        }
        printf("\n");
    }
}
float  calculo_media(float nota1,float nota2,float nota3){
    return (nota1 + nota2 + nota3)/3.0 ; 
}
float aprovado_ou_reprovado(float media){
    if (media >=60){
        return 1;
    }else {
        return 0; 
    }
}
void calculo_fib(int fib[termos_maximos], int y) {
    int v;
    if (y > 0) {
        fib[0] = 0;
        fib[1] = 1;
        for (v = 2; v < y; v++) {
            fib[v] = fib[v - 1] + fib[v - 2];
        }
    }
}

void impressao_numeros(int fib[termos_maximos], int y) {
    int v;
    for (v = 0; v < y; v++) {
        printf("%d ", fib[v]);
    }
    printf("\n");
}



int main (int argc,char ** argv){
    int escolha; 
    float a,b;  
    int choice; 
    int anos; 
    int meses; 
    int dias; 
    int segundos; 
    int num;
    int n;
    int h;
    float media;
    float nota1,nota2,nota3; 
    int N; 
    int i;
    int alunos_reprovados; 
    int aprovados;
    float percentual;
    int y;
    int fib[termos_maximos];
    do{printf ("Vamos comecar a nossa lista de exercicios!!!\n");
    printf ("Questao01 (1)\nQuestao02 (2)\nQuestao03 (3)\nQuestao04 (4)\nQuestao05 (5)\nQuestao06 (6)\nQuestao07 (7)\nQuestao08 (8)\nParar (0)\n"); 
    printf ("Digite a questao que desejar e digite 0 para sair.\n"); 
    printf ("Qual questao voce deseja?\n"); 
    scanf ("%d", &escolha); 
    switch (escolha){
        case 1:
        do{
            printf ("Escolha a operacao que deseja realizar e digite o numero correspondente a cada uma:\nPara parar digite 0\n1-Soma (1)\n2-Produto (2)\n3-Quociente (3)\n0-Parar (0)\n");
            scanf("%d", &choice); 
            switch (choice){
                case 0:
                printf ("Programa terminado!\n"); 
                break; 
                case 1:
                printf ("Digite os numeros da soma:\n"); 
                scanf ("%f %f", &a, &b); 
                printf ("O resultado eh %f\n", soma(a,b)); 
                break; 
                case 2: 
                printf ("Digite os numeros da multiplicacao:\n"); 
                scanf ("%f %f", &a, &b); 
                printf ("O resultado eh %f\n", produto(a,b));
                break; 
                case 3:
                printf ("Digite os numeros da divisao:\n");
                scanf ("%f %f", &a,&b); 
                printf ("O resultado eh %f\n", quociente (a,b)); 
                break; 
                default:
                printf ("Opcao invalida!\n"); 
            }
        }while (choice!=0);
        questao1();
        break; 
        case 2:
        printf ("Qual a sua idade expressa em anos,meses e dias?\n"); 
        scanf ("%d %d %d", &anos, &meses, &dias);
        printf ("A sua idade em dias eh %d\n", conversor(anos,meses,dias));
        questao2(); 
        break; 
        case 3:
        printf ("Digite a duracao do seu experimento em segundos:\n");
        scanf("%d", &segundos);
        duracao(segundos);
        questao3();
        break; 
        case 4:
        printf ("Digite um numero para verificarmos se ele eh primo ou nao:\n");
        scanf ("%d", &num);
        verificador_primo(num);
        questao4(); 
        break; 
        case 5:
        printf ("Digite um numero que voce deseja calcular o fatorial:\n");
        scanf ("%d", &n);
        imprimir_fatorial(n);
        questao5();
        break; 
        case 6:
        printf("Digite a altura do triangulo de Pascal (0 a 10): ");
        scanf("%d", &h);
        imprimir_triangulo_pascal(h);
        questao6();
        break; 
        case 7:
        printf ("Digite quantos alunos tem na sala:\n");
        scanf ("%d", &N); 
        for (i=0; i < N; i++){
            printf ("Digite as notas do aluno %2d:\n",(i + 1));
            printf ("Nota 1:\n");
            scanf ("%f", &nota1);
            printf ("Nota 2:\n");
            scanf ("%f", &nota2);
            printf ("Nota 3:\n");
            scanf ("%f", &nota3);
            media = calculo_media(nota1,nota2,nota3); 
            aprovados= aprovado_ou_reprovado(media);
            if (aprovados){
                aprovados++; 
            }
        }
        alunos_reprovados = N - aprovados; 
        percentual = (float) aprovados/N * 100;
        printf ("Total de alunos: %d\n", N);
        printf ("Alunos aprovados: %d\n", aprovados);
        printf ("Alunos reprovados: %d\n", alunos_reprovados);
        printf ("Percentual de Aprovacao: %2f\n", percentual);
        questao7();
        break; 
        case 8:
        printf("Digite um numero N: ");
        scanf("%d", &y);
        calculo_fib(fib, y);
        printf("Serie de Fibonacci com %d termos\n", y);
        impressao_numeros(fib, y);
        questao8();
        break; 
        case 0:
        questao0();
        break; 
        default: 
        printf ("Opcao invalida!\n"); 

    }
    }while (escolha !=0);
    return SUCESSO; 

}