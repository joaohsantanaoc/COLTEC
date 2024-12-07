// Bibliotecas presentes no código
#include <stdio.h>

//Constantes presentes no código 
#define SUCESSO 0
#define ERRO -1
#define NUM_MAX_ELEMENTOS_VETOR 100

//Funções presentes no código

void questao1(){
    printf ("Questao 1 concluida!\n");
}
void questao2(){
    printf ("Questao 2 concluida!\n");
}
void questao3(){
    printf ("Questao 3 concluida!\n");
}
void questao4(){
    printf ("Questao 4 concluida!\n");
}
void questao5(){
    printf ("Questao 5 concluida!\n");
}
void questao6(){
    printf ("Questao 6 concluida!\n");
}
void questao7(){
    printf ("Questao 7 concluida!\n");
}
/*
void intervalo_fechado_entre_dois_numeros(int a,int b){
    int i;
    
    if (a > b){
        printf ("A nao pode ser maior que b!\n");
        return ERRO;
    }

    for (i = a;i < b;i++){
        printf ("%d \n", i);
    }
}
*/
void mostrar_intervalo_fechado_entre_dois_numeros(int a,int b){
    if (a > b){
        return;
    }

    printf ("%d \n", a);
    mostrar_intervalo_fechado_entre_dois_numeros(a + 1,b);
}
void calcular_vetor(int s[],int num_elementos){
    int i;

    for (i = 0;i< num_elementos;i++){
        printf ("Digite o elementos %d do vetor:\n", i + 1);
        scanf ("%d%*c", &s[i]);
    }
}
/*
int calcular_elemento_maximo_sem_recursividade(int s[],int num_elementos){
    int maximo = s[0];
    int i;

    for (i = 0;i < num_elementos;i++){
        if (s[i] > maximo){
            maximo = s[i];
        }
    }

    return maximo; 
}
*/
int elemento_maximo_do_vetor(int s[],int num_elementos){
    if (num_elementos == 1){
        return s[0];
    }
    int maximo = elemento_maximo_do_vetor(s, num_elementos - 1); 

    return (maximo > s[num_elementos - 1]) ? maximo : s[num_elementos - 1];
}
int main (int argc,char ** argv){
    int opcao; 
    int a, b;
    int s[NUM_MAX_ELEMENTOS_VETOR];
    int num_elementos;

    do {
        printf ("\t\tLISTA 12 DE EXERCICIOS\n");
        printf ("\t\t    RECURSIVIDADE\n");
        printf (".........................................................................\n");
        printf ("QUESTOES:\n");
        printf ("(1) <QUESTAO 1>\n(2) <QUESTAO 2>\n(3) <QUESTAO 3>\n(4) <QUESTAO 4>\n(5) <QUESTAO 5>\n(6) <QUESTAO 6>\n(7) <QUESTAO 7>\n(0) <SAIR>\n");
        printf ("SUA OPCAO: ");
        scanf ("%d%*c", &opcao);

        switch (opcao){
            case 1:{
                printf ("Digite dois valores inteiros (a e b):\n");
                scanf ("%d%*c %d%*c", &a,&b);
                if (a > b){
                    printf ("A nao pode ser maior que b!\n");
                    return ERRO;
                }else{
                    printf ("O intervalo fechado entre %d e %d eh:\n", a, b);
                    mostrar_intervalo_fechado_entre_dois_numeros(a, b);
                }
                questao1();
                break;
            }
            case 2:{
                printf ("Digite quantos elementos voce deseja ter em seu vetor de inteiros:\n");
                scanf ("%d%*c", &num_elementos);
                if (num_elementos <= 0){
                    printf ("O numero de elementos deve ser maior que 1!\n");
                    return ERRO;
                }
                calcular_vetor(s, num_elementos);
                int maximo = elemento_maximo_do_vetor(s,num_elementos);
                printf ("O elemento maximo do vetor eh %d\n", maximo);
                questao2();
                break;
            }
            case 3:{
                
                questao3();
                break;
            }
            case 4:{
                questao4();
                break;
            }
            case 5:{
                questao5();
                break;
            }
            case 6:{
                questao6();
                break;
            }
            case 7:{
                questao7();
                break;
            }
            case 0:{
                printf ("Saindo...\n");
                break;
            }
            default:{
                printf ("Opcao invalida!\n");
            }
        }

    }while (opcao != 0);
    return SUCESSO; 
}