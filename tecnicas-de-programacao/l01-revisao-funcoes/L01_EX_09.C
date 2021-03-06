/* Fa�a um programa que leia o pre�o de 10 produtos e armazene em um vetor,
   e depois imprima a m�dia de pre�os e o valor do produto mais caro.
   Dever� ser criada uma fun��o para a leitura dos dados, uma que retorne a
   m�dia de pre�os, e uma que retorne o produto mais caro. Todas estas fun��es
   devem receber o vetor como par�metro. A fun��o main dever� apenas declarar
   o vetor e chamar estas fun��es. Utilize constante para controlar o tamanho do vetor. */

#include<stdio.h>

#define TOTAL 5

void leituraPrecos(double precos[], int tamanho){

    int indice;

    printf("\n Entrada de dados");
    printf("\n ================\n\n");

    for (indice = 0; indice < tamanho; indice++){
        printf(" Entre com o preco %d: ", indice + 1);
        scanf("%lf", &precos[indice]);
    }
}

double mediaPrecos(double precos[], int tamanho){

    int  indice; double soma = 0;

    for (indice = 0; indice < tamanho; indice++){
        soma += precos[indice];
    }

    return soma / tamanho;
}

int posProdutoMaisCaro(double precos[], int tamanho){

    int  indice, posCaro = 0;

    for (indice = 1; indice < tamanho; indice++){

        if (precos[indice] > precos[posCaro]){
            posCaro = indice;
        }
    }

    return posCaro;
}

int main(){

    double produtos[TOTAL];
    int    pos;

    leituraPrecos(produtos, TOTAL);

    printf("\n A media dos precos cadastrados eh R$ %.2lf\n", mediaPrecos(produtos, TOTAL));

    pos = posProdutoMaisCaro(produtos, TOTAL);

    printf("\n O produto mais caro eh o %d com o valor de R$ %.2lf\n", pos+1, produtos[pos]);

    return 0;
}
