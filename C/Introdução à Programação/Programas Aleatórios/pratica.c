#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define NUM_NOTAS 3

typedef struct aluno_s{
    float *notas;
}aluno_t;
float calcula_media (float* notas,int n){
    int i;
    float  media= 0;
    for (i=0;i<n;i++){
        media += notas[i];
    } 
    return media/(float)n;
}

int main (int argc,char ** argv){
    int i;
    aluno_t *ponteiro_alunos;
    ponteiro_alunos = (aluno_t*) malloc (4 *sizeof (aluno_t));
    for (i=0;i<4;i++){
        ponteiro_alunos[i].notas = (float *)malloc (3 * sizeof (float));
    }
    for (i=0;i<4;i++){
        ponteiro_alunos[i].notas[0] = i;
        ponteiro_alunos[i].notas[1] = 2*i;
        ponteiro_alunos[i].notas[2] = 3*i;
    }
    for (i=0;i<NUM_NOTAS;i++){
        printf ("Digite a nota %d do aluno:\n", i+1);
        scanf ("%f", &ponteiro_alunos->notas[i]);
    }
    printf ("\tDADOS INSERIDOS\n");
    for (i=0;i<NUM_NOTAS;i++){
        printf ("NOTA %d: %.2f\n", i+1, ponteiro_alunos->notas[i]);
    }
    printf ("MEDIA: %.2f\n", calcula_media(ponteiro_alunos->notas, 3));
    for (i=0;i<4;i++){
        free (ponteiro_alunos[i].notas);
    }
    free (ponteiro_alunos);
    
    return SUCESSO; 
}