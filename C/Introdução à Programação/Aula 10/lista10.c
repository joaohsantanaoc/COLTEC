#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0 
#define NUM_CARACTERES 50
#define NUM_ALUNOS 4
#define NUM_NOTAS 3 

void util_removeQuebraLinhaFinal(char dados[]) {
    int tamanho;
    tamanho = strlen(dados);
    if ((tamanho > 0) && (dados[tamanho - 1] == '\n')) {
        dados[tamanho - 1] = '\0';
    }
}
void questao1(){
    printf ("Questao 1 executada!\n");
}
void questao2(){
    printf ("Questao 2 executada!\n");
}
void questao3(){
    printf ("Questao 3 executada!\n");
}
typedef struct alunos_s{
    int matricula;
    char nome[NUM_CARACTERES];
    char curso[NUM_CARACTERES];
    float altura;

}alunos_t;

typedef struct novo_alunos_s{
    int matricula;
    char nome[NUM_CARACTERES];
    char curso[NUM_CARACTERES];
    float altura;
    float notas[NUM_NOTAS];
    float media;

}novo_alunos_t;

void unico_aluno(){
    alunos_t a1; 

    printf ("Digite o numero de matricula desse aluno:\n");
    scanf ("%d", &a1.matricula);
    printf ("Digite a altura desse aluno:\n");
    scanf ("%f", &a1.altura);
    getchar();
    printf ("Digite o nome desse aluno:\n");
    fgets (a1.nome, NUM_CARACTERES,stdin);
    util_removeQuebraLinhaFinal(a1.nome);
    printf ("Digite o curso desse aluno:\n");
    fgets (a1.curso,NUM_CARACTERES,stdin);
    util_removeQuebraLinhaFinal(a1.curso);

    printf ("\tDADOS:\n");
    printf ("NOME: %s\n", a1.nome);
    printf ("NUM DE MATRICULA: %d\n", a1.matricula);
    printf ("CURSO: %s\n", a1.curso);
    printf ("ALTURA: %.2f\n", a1.altura);
    printf ("...........................................................\n");

}
void alunos(){
    alunos_t a1[NUM_ALUNOS];
    int i; 

    for (i=0;i<NUM_ALUNOS;i++){
        printf ("Digite o numero de matricula do aluno %d:\n", i+1);
        scanf ("%d", &a1[i].matricula);
        getchar();
        printf ("Digite o nome do aluno %d:\n",i+1);
        fgets (a1[i].nome,NUM_CARACTERES,stdin);
        util_removeQuebraLinhaFinal(a1[i].nome);
        printf ("Digite o curso do aluno %d:\n", i+1);
        fgets (a1[i].curso,NUM_CARACTERES,stdin);
        util_removeQuebraLinhaFinal(a1[i].curso);
        printf ("Digite a altura do  aluno %d:\n", i+1);
        scanf ("%f", &a1[i].altura);
    }

    for (i=0;i<NUM_ALUNOS;i++){
        printf ("\tALUNO %d\n", i+1);
        printf ("NOME: %s\n", a1[i].nome);
        printf ("NUM DE MATRICULA: %d\n", a1[i].matricula);
        printf ("CURSO: %s\n", a1[i].curso);
        printf ("ALTURA: %.2f\n", a1[i].altura);
        printf ("...........................................................\n");
    }
}
float media_notas(novo_alunos_t a2){
    int i;
    float soma=0;
    float media;
    for (i=0;i<NUM_NOTAS;i++){
        soma += a2.notas[i];
    }
    media = soma/NUM_NOTAS;

    return media; 

}

void novo_unico_aluno(){
    novo_alunos_t a2;
    int i;

    printf ("Digite o numero de matricula do aluno:\n");
    scanf ("%d", &a2.matricula);
    printf ("Digite a altura do aluno:\n");
    scanf ("%f", &a2.altura);
    getchar();
    printf ("Digite o nome do aluno:\n");
    fgets (a2.nome, NUM_CARACTERES,stdin);
    util_removeQuebraLinhaFinal(a2.nome);
    printf ("Digite o curso do aluno:\n");
    fgets (a2.curso,NUM_CARACTERES,stdin);
    util_removeQuebraLinhaFinal(a2.curso);

    for (i=0;i<NUM_NOTAS;i++){
        printf ("NOTA %d:\n", i+1);
        scanf ("%f", &a2.notas[i]);
    }

    printf ("\tDADOS:\n");
    printf ("NOME: %s\n", a2.nome);
    printf ("NUM DE MATRICULA: %d\n", a2.matricula);
    printf ("CURSO: %s\n", a2.curso);
    printf ("ALTURA: %.2f\n", a2.altura);

    a2.media = media_notas(a2);


    for (i=0;i<NUM_NOTAS;i++){
        printf ("NOTA %d:\n", i+1);
        printf ("%.2f\n", a2.notas[i]);
    }
    printf ("MEDIA: %.2f\n", a2.media);
    printf ("...........................................................\n");


}
void novo_alunos(){
    novo_alunos_t a2[NUM_ALUNOS];
    int i,j; 

    

    for (i=0;i<NUM_ALUNOS;i++){
        printf ("Digite o numero de matricula do aluno %d:\n", i+1);
        scanf ("%d", &a2[i].matricula);
        getchar();
        printf ("Digite o nome do aluno %d:\n",i+1);
        fgets (a2[i].nome,NUM_CARACTERES,stdin);
        util_removeQuebraLinhaFinal(a2[i].nome);
        printf ("Digite o curso do aluno %d:\n", i+1);
        fgets (a2[i].curso,NUM_CARACTERES,stdin);
        util_removeQuebraLinhaFinal(a2[i].curso);
        printf ("Digite a altura do  aluno %d:\n", i+1);
        scanf ("%f", &a2[i].altura);
    }
    for (i=0;i<NUM_ALUNOS;i++){
        for (j=0;j<NUM_NOTAS;j++){
        printf ("Digite as 3 notas do aluno %d\n",i+1);
        scanf ("%f", &a2[i].notas[j]);
        }
    }
    

    for (i=0;i<NUM_ALUNOS;i++){
        printf ("\tALUNO %d\n", i+1);
        printf ("NOME: %s\n", a2[i].nome);
        printf ("NUM DE MATRICULA: %d\n", a2[i].matricula);
        printf ("CURSO: %s\n", a2[i].curso);
        printf ("ALTURA: %.2f\n", a2[i].altura);
    }
    for (i=0;i<NUM_ALUNOS;i++){
        printf ("Notas do aluno %d:\n", i+1);
        for (j=0;j<NUM_NOTAS;j++){
            printf ("%.2f\n", a2[i].notas[j]);
        }
    }
    
    printf ("................................................\n");
      
    }




int main (int argc,char ** argv){
    int opcao;
    novo_alunos_t * ponteiro_alunos= NULL;
    char opcao2; 
    int i,j;
    int num_alunos = 0;


    
    
    do {
        printf ("Lista 10 de exercicios!\n");
        printf ("Digite o numero que voce desejar para acessar as questões e digite 0 para parar:\n");
        printf ("QUESTAO 1 (1)\nQUESTAO 2 (2)\nQUESTAO 3 (3)\nPARAR (0)\n");
        scanf ("%d", &opcao);
        getchar();
        switch (opcao){
            case 1:
            unico_aluno();
            alunos();
            questao1();
            break;
            case 2:
            novo_unico_aluno();
            novo_alunos();
            questao2();
            break;
            case 3:
            printf ("CADASTRAMENTO DE ALUNOS:\n");
            do{
                novo_alunos_t novo_alunos;
                printf ("Voce deseja executar o programa?\n");
                printf ("SIM (s ou S):\nNAO (n ou N):\n");
                scanf (" %c", &opcao2);
                if (opcao2 == 's' || opcao2 == 'S'){
                    printf ("Vamos realizar o cadastramento entao!\n");
                    printf ("Primeiramente digite o numero de matricula do aluno:\n");
                    scanf ("%d", &novo_alunos.matricula);
                    getchar();
                    printf ("Agora digite o nome do aluno:\n");
                    fgets (novo_alunos.nome, NUM_CARACTERES,stdin);
                    util_removeQuebraLinhaFinal(novo_alunos.nome);
                    printf ("Digite o curso:\n");
                    fgets (novo_alunos.curso, NUM_CARACTERES,stdin);
                    util_removeQuebraLinhaFinal(novo_alunos.curso);
                    printf ("Digite a altura desse aluno:\n");
                    scanf ("%f", &novo_alunos.altura);
                    for (i=0;i<NUM_NOTAS;i++){
                        printf ("Digite a nota %d do aluno:\n", i+1);    
                        scanf ("%f", &novo_alunos.notas[i]); 
                    }
                    novo_alunos.media = media_notas(novo_alunos);
                    num_alunos++;
                    ponteiro_alunos = realloc (ponteiro_alunos, num_alunos * sizeof(novo_alunos_t));
                    ponteiro_alunos[num_alunos - 1] = novo_alunos;
                    printf ("Cadastro do aluno concluido!\n");
                    }
            }while (opcao2 == 's'|| opcao2 == 'S');
            if (opcao2 == 'n'||opcao2 == 'N'){
                for (i=0;i<num_alunos;i++){
                    printf ("\tDADOS INSERIDOS:\n");
                    printf ("NOME: %s\n", ponteiro_alunos[i].nome);
                    printf ("NUM DE MATRICULA: %d\n", ponteiro_alunos[i].matricula);
                    printf ("CURSO: %s\n", ponteiro_alunos[i].curso);
                    printf ("ALTURA: %.2f\n", ponteiro_alunos[i].altura);
                    for (j=0;j<NUM_NOTAS;j++){
                        printf ("NOTA %d do aluno:\n", j+1);
                        printf ("%.2f\n", ponteiro_alunos[i].notas[j]);
                    }
                    printf ("MEDIA: %.2f\n", ponteiro_alunos[i].media);
                    printf ("................................................\n");
                }
            }

            free (ponteiro_alunos);



            questao3();
            break;
            case 0:
            printf ("Lista 10 de exercicios acabou...\n");
            break;
            default: 
            printf ("Opcao invalida!\n");
        }
    }while (opcao != 0);
    return SUCESSO;
}