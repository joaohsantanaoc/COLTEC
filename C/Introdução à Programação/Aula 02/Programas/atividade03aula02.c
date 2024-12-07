#include <stdio.h>
#define SUCESSO 0
int main (int argc, char ** argv) {
int dia;
printf ("Digite um numero de [1:7]:");
scanf ("&d", &dia); 
switch (dia) {
    case '1':
    printf ("O primeiro dia da semana eh domingo");
    break;
    case '2':
    printf ("O segundo dia da semana eh segunda feira");
    break;
    case '3':
    printf ("O terceiro dia da semana eh terca feira");
    break; 
    case '4':
    printf ("O quarto dia da semana eh quarta feira");
    break; 
    case '5':
    printf ("O quinto dia da semana eh quinta feira");
    break;
    case '6':
    printf ("O sexto dia da semana eh sexta feira");
    break; 
    case '7':
    printf ("O setimo dia da semana eh sabado");
    break;
    default:
    printf ("Dia da semana invalido");
}
return SUCESSO;
}
