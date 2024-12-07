#include <stdio.h> 
#define SUCESSO 0
int main (int argc, char ** argv) {
    int valor01;
    int valor02;
    int maior;
    printf ("Digite um numero:");
    scanf ("%d", &valor01);
    printf ("Digite outro numero:");
    scanf ("%d", &valor02);
    if (valor01 > valor02) {
        maior= valor01;
    } else {
        maior= valor02;
    }
    printf ("O maior numero eh: %d\n", maior);
    return SUCESSO;
}
