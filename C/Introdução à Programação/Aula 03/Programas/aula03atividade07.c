#include <stdio.h>
#define SUCESSO 0

int main(int argc,char ** argv) {
    int n;
    int nota;
    int notas_acima_de_60 = 0;
    int i;

    printf("NOTAS DOS ALUNOS:\n");

    printf("Digite o numero total de alunos na turma: ");
    scanf("%d", &n);

    for (i= 1; i <= n; i++) {
        printf("Digite a nota[0 ate 100] do aluno %d: ", i);
        scanf("%d", &nota);

        if (nota >= 60) {
            notas_acima_de_60++;
        }
    }

    double percentual = (double) notas_acima_de_60 / n * 100;

    printf("O percentual de notas acima de 60 foi de %.2f%%.\n", percentual);

    if (percentual >= 60) {
        printf("A sala foi aprovada!\n");
    } else {
        printf("A sala nao foi aprovada.\n");
    }

    return SUCESSO;
}
