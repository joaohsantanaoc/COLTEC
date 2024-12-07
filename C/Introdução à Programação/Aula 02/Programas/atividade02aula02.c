#include <stdio.h>
#define SUCESSO 0
int main (int argc, char ** argv) {
    float x,y,z; 
    printf ("Digite o comprimento x:");
    scanf("%f", &x);
    printf ("Digite o comprimento y:");
    scanf ("%f", &y);
    printf ("Digite o comprimento z:");
    scanf ("%f", &z);
    if ( (x< (y+z)) && (y<(x+z)) && (z<(x+y)) ) {
        printf ("Os comprimentos %f, %f e %f formam um triangulo", x,y,z);
       } else {
        printf ("Os valores %f,%f e %f nao formam um triangulo", x,y,z);
       }

    return SUCESSO;
}