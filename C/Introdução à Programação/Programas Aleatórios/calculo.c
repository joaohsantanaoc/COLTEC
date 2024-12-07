#include <stdio.h>
#include <math.h>

#define SUCESSO 0

int main (int argc,char ** argv){
    float a,b,c;
    float r;
    float r0 = 99.994;
    float delta;
    float raiz;
    float solucao;


    printf ("EQUAÇÃO PARA TRANSFORMAR RESISTÊNCIA EM TEMPERATURA\n");
    printf (".............................................................................\n");
    printf ("Digite o coeficiente a:\n");
    scanf ("%f%*c",&a);
    printf ("Agora digite o coeficiente b:\n");
    scanf ("%f%*c", &b);
    printf ("Digite o valor da resistência que esta sendo medida:\n");
    scanf ("%f%*c", &r);
    
    c = -(r/r0) + 1;

    delta = pow(b,2) - (4 * a * c);
    raiz = sqrt(delta);
    solucao = (-b + raiz)/(2 * a);

    printf ("RESULTADO: %2.f\n", solucao);





    return SUCESSO;
}