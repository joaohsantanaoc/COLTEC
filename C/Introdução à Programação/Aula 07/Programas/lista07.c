#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SUCESSO 0
#define TAM_MAX 100
void questao01(){
    printf ("Questao 1 executada!\n");
}
void questao02(){
    printf ("Questao 2 executada!\n");
}
void questao03(){
    printf ("Questao 3 executada!\n");
}
void questao04(){
    printf ("Questao 4 executada!\n");
}
void questao05(){
    printf ("Questao 5 executada!\n");
}
void questao06(){
    printf ("Questao 6 executada!\n");
}
void removedor_espacos(char string[]) {
    int i, j;
    for (i = 0, j = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ') {
            string[j] = string[i];
            j++;
        }
    }
    string[j] = '\0';
}

int main (int argc,char ** argv){
    int opcao; 
    char string [TAM_MAX];
    int contador,contador2=0, contador_espaco=0,contador_vogais=0; 
    char palavra[TAM_MAX];
    int caracteres; 
    int palindromo = 1;
    char frase[TAM_MAX];
    char copia_frase[TAM_MAX];
    int tam_frase; 
    int diferentes = 0; 
    do {
        printf ("Digite qual questao voce deseja executar e digite 0 para parar\n"); 
        printf ("Questao01 (1)\nQuestao02 (2)\nQuestao03 (3)\nQuestao04 (4)\nQuestao05 (5)\nQuestao06 (6)\nParar (0)\n");
        scanf ("%d", &opcao);
        getchar(); 
        switch (opcao){
            case 1:
            printf ("Digite uma string:\n");
            fgets (string, TAM_MAX,stdin);
            for (contador = 0; string[contador] != '\0'; contador++){
                if (string[contador] == ' '){
                    contador_espaco++;
                }
            }
            printf ("O numero de espacos em branco eh %d\n", contador_espaco);
            questao01();
            break;
            case 2:
            printf ("Digite uma string:\n");
            fgets (string,TAM_MAX,stdin);
            removedor_espacos(string);
            printf ("%s\n", string);
            questao02();
            break;
            case 3:
            printf ("Digite uma string:\n");
            fgets (string,TAM_MAX,stdin);
            for (contador=0;string[contador] != '\0';contador++){
                if (string[contador] == 'a' || string[contador] == 'e' || string[contador] == 'i' || string[contador] == 'o' || string[contador] == 'u'){
                    contador_vogais++;
                }
            }
            printf ("O numero de vogais eh %d\n", contador_vogais);
            questao03();
            break; 
            case 4:
            printf ("Digite uma string com mais de uma palavra:\n");
            fgets (string,TAM_MAX,stdin);
            for (contador = 0;string[contador] != '\0';contador++){
                if (contador == 0 || string[contador-1] == ' '){
                    string[contador] = toupper(string[contador]);
                }
            }
            printf ("String com todos os primeiros caracteres em maiusculo:\n%s\n", string);
            questao04();
            break; 
            case 5:
            printf ("Digite uma palavra:\n");
            fgets(palavra,TAM_MAX,stdin);
            palavra[strcspn(palavra, "\n")] = '\0';
            caracteres = strlen(palavra); 
            for (contador = 0;contador < caracteres/2;contador++){
                if (tolower(palavra[contador]) != tolower(palavra[caracteres - 1 - contador ])){
                    palindromo = 0;
                    break; 
                }
            } 
            if (palindromo){
                printf ("A palavra eh um palindromo\n");
            }else{
                printf ("A palavra nao eh um palindromo\n"); 
            }
            questao05();
            break; 
            case 6:
            printf ("Digite uma frase:\n");
            fgets (frase,TAM_MAX,stdin);
            tam_frase = strlen (frase) -1; 
            for (contador = 0; contador < tam_frase;contador++){
                if (isalpha(frase[contador])){
                    copia_frase[contador2++] = tolower(frase[contador]);
                }
            }
            copia_frase[contador2] = '\0';
            tam_frase = contador2;
            for (contador = 0;contador < tam_frase/2;contador++){
                if (copia_frase[contador] != copia_frase[tam_frase - 1 - contador]){
                    diferentes = 1;
                    break; 
                }
                
            } 
            if (diferentes == 0){
                printf ("A frase eh um palindromo\n");
            }else {
                printf ("A frase nao eh um palindromo\n"); 
            }

            questao06();
            break;
            case 0:
            printf ("Lista acabou...\n");
            break; 
            default:
            printf ("Opcao invalida!\n"); 
        } 
    }while (opcao != 0);
    return SUCESSO;  
}