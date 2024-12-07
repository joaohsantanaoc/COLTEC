#include <stdio.h>
#define SUCESSO 0 
int main (int argc,char ** argv) {
    float altura,massaideal; 
    char sexo; 
    printf ("Digite sua altura (em metros):");
    scanf ("%f", &altura); 
    printf ("Digite seu genero: (masculino ou feminino)");
    scanf ("%c" &sexo); 
    if (sexo=masculino) {
        massaideal= (72,7 * altura) - 44,7;
    } else {
        massaideal=(62.1 * altura) - 44.7;
    }
    printf ("Seu peso ideal eh %.2f", massaideal);
    return SUCESSO;
}