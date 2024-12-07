#include <stdio.h>
#define SUCESSO 0

int escolha() {
    int choice;
    do {
        printf("Qual questao voce escolhe executar?\n");
        printf("Questao01(1)\nQuestao02(2)\nQuestao03(3)\nQuestao04(4)\nQuestao05(5)\nQuestao06(6)\nQuestao07(7)\nQuestao08(8)\nParar(0)\n");
        printf("Escolha a questao e utilize a tecla 0 (PARAR)\n");
        scanf("%d", &choice);
    } while (choice != 0);
    return choice;

}
int soma(int a, int b) {
    return a + b;
}

int produto(int a, int b) {
    return a * b;
}

float quociente(int a, int b) {
    if (b != 0)
        return (float) a / b;
    else
        return SUCESSO;
}

int main(int argc, char ** argv) {
    int opcao, num1, num2;
    int choice; 
    choice = escolha (1);
    do {
        printf("Escolha uma opcao de calculo para dois numeros:\n");
        printf("1 - Soma\n");
        printf("2 - Produto\n");
        printf("3 - Quociente\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
            printf("Digite dois numeros: ");
            scanf("%d %d", &num1, &num2);
            printf("Resultado: %d\n\n", soma(num1, num2));
            break;
            case 2:
            printf("Digite dois numeros: ");
            scanf("%d %d", &num1, &num2);
            printf("Resultado: %d\n\n", produto(num1, num2));
            break;
            case 3:
            printf("Digite dois numeros: ");
            scanf("%d %d", &num1, &num2);
            printf("Resultado: %.2f\n\n", quociente(num1, num2));
            break;
            case 0:
            printf("Questao01 acabada!!!\n");
            break;
            default:
            printf("Opcao invalida!\n\n");
        }
    } while (opcao != 0);
    return SUCESSO;    

    

}
