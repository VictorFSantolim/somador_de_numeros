#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Somador de numeros
 *
*/
int fatorial(int fator)
{
    if(fator == 1) return fator;
    return (fatorial(fator - 1) * fator);
}


int main(){

    char palavra[50];
    float soma;
    char temLetra = 0;
    char temFatorial = 0;
    char temPonto = 0;
    char c;

    while(1){

        temLetra = 0;
        temFatorial = 0;
        temPonto = 0;

        c = getchar();
        if(c == '\n' || c == EOF) {break;}
        else if(c == ' ') {continue;}
        else {ungetc(c , stdin);}

        scanf("%s", palavra);
        //printf("A palavra lida foi: [%s]\n" , palavra);

        //Verifica o que tem na string
        for(unsigned int i=0 ; i<strlen(palavra); i++)
        {
            if(palavra[i] > 65) temLetra = 1;
            if(palavra[i] == 33) temFatorial = 1;
            if(palavra[i] == 46) temPonto = 1;
        }

        //Se tem letra, ignora, vai para proximo
        if(temLetra == 1) continue;

        //Se tem fatorial, nao tem ponto e nao eh fatorial sozinho
        if(temFatorial == 1 && temPonto == 0 && strlen(palavra) > 1)
        {
            palavra[strlen(palavra) - 1] = '\0';
            int fator = atoi(palavra);
            fator = fatorial(fator);
            soma += fator;
        }
        else if(temFatorial == 0)
        {
            soma += strtof(palavra , NULL);
        }
    }

    printf("%.2f\n" , soma);
    return 0;
}
