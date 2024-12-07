#include <stdio.h>
#define SUCESSO 0 
int main (int argc, char ** argv) {
    float aluno1nota1,aluno1nota2,aluno1nota3;
    float aluno2nota1,aluno2nota2,aluno2nota3;
    float aluno3nota1,aluno3nota2,aluno3nota3;
    float mediaaluno1,mediaaluno2,mediaaluno3;
    char aluno1conceito,aluno2conceito,aluno3conceito;
    printf ("aluno01\n");
    printf ("Digite a primeira nota do aluno 1:");
    scanf ("%f", &aluno1nota1);
    printf ("Digite a segunda nota:");
    scanf ("%f", &aluno1nota2);
    printf ("Digite a terceira nota:");
    scanf ("%f", &aluno1nota3);
    printf ("aluno02\n");
    printf ("Digite a primeira nota do aluno 2:");
    scanf ("%f", &aluno2nota1);
    printf ("Digite a segunda nota:");
    scanf ("%f", &aluno2nota2);
    printf ("Digite a terceira nota:");
    scanf ("%f", &aluno2nota3);
    printf ("aluno03\n");
    printf ("Digite a primeira nota do aluno 3:");
    scanf ("%f", &aluno3nota1);
    printf ("Digite a segunda nota:");
    scanf ("%f", &aluno3nota2);
    printf ("Digite a terceira nota:");
    scanf ("%f", &aluno3nota3);

    mediaaluno1=(aluno1nota1+aluno1nota2+aluno1nota3)/3;
    mediaaluno2=(aluno2nota1+aluno2nota2+aluno2nota3)/3;
    mediaaluno3=(aluno3nota1+aluno3nota2+aluno3nota3)/3;
    if (mediaaluno1>=90) {aluno1conceito='A';} 
    else if (mediaaluno1=80) {aluno1conceito='B';}
    else if (mediaaluno1=70) {aluno1conceito='C';}
    else if (mediaaluno1=60) {aluno1conceito='D';}
    else {aluno1conceito='R';}
    if (mediaaluno2>=90) {aluno2conceito='A';}
    else if (mediaaluno2=80) {aluno2conceito='B';}
    else if (mediaaluno2=70) {aluno2conceito='C';}
    else if (mediaaluno2=60) {aluno2conceito='D';}
    else {aluno2conceito='R';}
    if (mediaaluno3>=90) {aluno3conceito='A';}
    else if (mediaaluno3=80) {aluno3conceito='B';}
    else if (mediaaluno3=70) {aluno3conceito='C';}
    else if (mediaaluno3=60) {aluno3conceito='D';}
    else {aluno3conceito='R';}
    printf ("Tabela com notas:");
    printf ("Aluno %d\t%.2f\t%.2f\t%.2f",1, aluno1nota1,aluno1nota2,aluno1nota3, aluno1conceito);
    printf ("Aluno %d\t%.2f\t%.2f\t%.2f",2, aluno2nota1,aluno2nota2,aluno2nota3,aluno2conceito);
    printf ("Aluno %d\t%.2f\t%.2f\t%.2f",3,aluno3nota1,aluno3nota2,aluno3nota3,aluno3conceito);


    return SUCESSO;
}