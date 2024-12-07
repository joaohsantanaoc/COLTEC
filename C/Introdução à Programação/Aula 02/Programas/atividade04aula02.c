#include <stdio.h> 
#define SUCESSO 0 
int main (int argc, char ** argv) {
    int a;
    int b; 
    int resultado;
    char operador;
    printf ("Digite a primeira parcela da operacao");
    scanf ("%d", &a); 
    printf ("Digite a segunda parcela da operacao:");
    scanf ("%d", &b);
    printf ("Digite o operador da operacao: (multiplicacao[*], divisao[/], soma[+], subtracao{-}, potenciacao{**}, radiciacao[sqrt])");
    scanf ("%c", &operador);
    switch (operador) {
        case '+':
        resultado=a+b;
        printf ("A soma de %d com %d é %d\n", a,b,resultado);
        break;
        case '-':
        resultado=a-b;
        printf ("A subtracao de %d com %d eh %d\n", a,b,resultado);
        break;
        case '*':
        resultado=a*b;
        printf ("A multiplicacao de %d com %d eh %d\n", a,b,resultado);
        break;
        case '/':
        resultado=a/b;
        printf ("A divisao de %d com %d eh %d/n", a,b,resultado);
        break;
        case '**':
        resultado=a**b;
        printf ("A potenciacao de %d com %d eh %d", a,b,resultado);
        break;
        case 'sqrt':
        resultado=sqrt(a);
        printf ("A radiciacao de %d eh %d\n", a,resultado);
        break; 
        default:
        printf ("Operacao invalida");
    }
    return SUCESSO;
}