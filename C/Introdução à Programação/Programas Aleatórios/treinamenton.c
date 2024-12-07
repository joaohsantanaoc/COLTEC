#include <stdio.h>
#include <stdbool.h>
#define SUCESSO 0
int main (int argc,char ** argv) {
    bool executar;
    char opcao; 
    char operador; 
    float a,b,resultado;
        printf ("Voce deseja executar o programa?(s ou n)");
        scanf ("%c", &opcao);
        if (opcao='s') {
           printf ("Digite o operador, a primeira e segunda parcela da operacao:\n"); 
           scanf(" %c %f %f", &operador, &a, &b); 
           switch (operador) {
            case '+':
            resultado= a+b;
            printf ("A soma de %.2f com %.2f eh %.2f", a,b,resultado);
            break; 
            case '-':
            resultado= a-b; 
            printf ("A subtracao entre %.2f e %.2f eh %.2f", a,b,resultado); 
            break; 
            case '*':
            resultado= a*b; 
            printf ("A multiplicacao de %.2f com %.2f eh %.2f", a,b,resultado);
            break; 
            case '/':
            if (b) {
                resultado= a/b; 
                printf ("A divisao entre %.2f e %.2f eh %.2f", a,b,resultado); 
            } else {
                printf ("Divisao por zero nao existe!");
            } break;
        } 
        }  
        
    return SUCESSO; 
}