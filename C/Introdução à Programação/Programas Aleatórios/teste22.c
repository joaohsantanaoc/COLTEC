#include <stdio.h>

#define SUCESSO 0 

int fatorial (int n){
    int a;
    int fatorial = 0; 
    for (a=1;a<=n;a++){
        fatorial = fatorial * a;
    }
    return fatorial;

}
int calculo(int N){
    int resultado=0;
    int linha,coluna; 
    for (linha=0; linha<=N;linha++){
        for (coluna=0;coluna<=linha;coluna++){
            if (coluna == 0 && linha == 0){
                resultado = 1;
            }
        }
    }

    
}
int main (int argc,char**argv){
    return SUCESSO;
}