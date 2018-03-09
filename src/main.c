//Victor Ferrão Santolim
//RA 187888

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Somador de numeros
 *
*/

//Funcao recursiva que calcula o fatorial de um número
int fatorial(int fator)
{
    if(fator == 1) return fator;
    return (fatorial(fator - 1) * fator);
}

int main(){

    char palavra[50];       //Cadeia de caracteres separados por espaco
    float soma;             //Acumulado da soma dos numeros ate entao
    char temLetra = 0;      //Flags de existencia de letra, fatorial e ponto
    char temFatorial = 0;
    char temPonto = 0;
    char c;                 //Letra lida no momento

    while(1){

        //Zera as flags
        temLetra = 0;
        temFatorial = 0;
        temPonto = 0;

        //Pega um caractere da entrada padrao, verifica se acabou a linha
        //ou o imput. Se for espaco, loop novamente. Se for alfanumerico ou
        //simbolo, devolve o char a entrada padrao
        c = getchar();
        if(c == '\n' || c == EOF) {break;}
        else if(c == ' ') {continue;}
        else {ungetc(c , stdin);}

        //Realiza a leitura da palavra ate o espaco ou fim de linha
        scanf("%s", palavra);

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

        //Se eh um numero sem fatorial, pega seu valor e acumula na soma
        else if(temFatorial == 0)
        {
            soma += strtof(palavra , NULL);
        }
    }

    //Printa o resultado final
    printf("%.2f\n" , soma);
    return 0;
}
