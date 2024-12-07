#include <stdio.h>
#include <stdbool.h>
#define SUCESSO 0
int main (int argc, char ** argv) {
    char opcao;
    bool executar;
    char operador; 
    float a,b,resultado = 0; 
    printf ("Voce deseja executar o programa?[s ou n]");
    scanf ("%c", &opcao);
    if (opcao == 's') {
        printf ("Digite a primeira e segunda parcela da operacao, alem do operador (+,-,*,/)");
        scanf ("%f,%f,%c", &a,&b,&operador);
        switch (operador) {
            case '+': 
            resultado= a+b; 
            printf ("A soma de %f com %f eh %f\n", a,b,resultado);
            break;
            case '-':
            resultado= a-b;
            printf ("A subtracao entre %f e %f eh %f\n", a,b,resultado);
            break;
            case '*':
            resultado= a*b;
            printf ("A multiplicacao de %f com %f eh %f\n", a,b,resultado);
            break;
            case '/':
            if (b !=0) {
                resultado= a/b; 
                printf ("A divisao entre %f e %f eh %f\n", a,b,resultado);
            } else {
                printf ("Erro divisao por zero\n");
            }
            break; 
            
    }
    return SUCESSO;
}