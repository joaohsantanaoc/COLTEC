#include <stdio.h> 
#define SUCESSO 0
int main (int argc,char ** argv) {
    int i; 
    
    for (i=1 ; i<=100; i++ ){
        if (i %2 ==1) {
            printf ("%d ", i);

        }
        
    }
    
    return SUCESSO; 
}