/* Fa�a um programa que apresente o seguinte menu para o usu�rio.

   Manipula��o de N�meros
   ====================
   <1> - Verificar se um n�mero � par ou �mpar
   <2> - Verificar se um n�mero � primo
   <3> - Calcular o fatorial de um n�mero
   <4> - Calcular a raiz quadrada de um n�mero
   <5> - Sair
   Qual op��o escolhida?

   Nas op��es de 1 a 4 deve-se primeiro ler o n�mero que ser� usado e depois chamar
   uma fun��o espec�fica para fazer cada a��o pedida. Uma fun��o para calcular
   fatorial, se o n�mero � primo, e se � par ou �mpar. Para o calculo da raiz quadrada
   utilizar a fun��o sqrt da biblioteca math.h. Caso o usu�rio escolha a op��o 5 use a
   fun��o exit(int) para encerrar o programa. Caso o usu�rio entre com uma op��o
   inv�lida apresente uma mensagem de erro e retorne ao menu. Utilize a estrutura switch
   com break, e a do/while para fazer o menu */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "MATLIB.C"

int main() {

    int    numero;
    double fat, numeroRaiz;
    char   opcao;

    do {
        printf("\n Manipulacao de Numeros");
        printf("\n ======================");
        printf("\n <1> - Verificar se um numero eh par ou impar");
        printf("\n <2> - Verificar se um numero eh primo");
        printf("\n <3> - Calcular o fatorial de um numero");
        printf("\n <4> - Calcular a raiz quadrada de um numero");
        printf("\n <5> - Sair");

        printf("\n\n Qual opcao escolhida? ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao) {

           case  1:printf("\n Entre com o numero: ");
                   fflush(stdin);
                   scanf("%d",&numero);
                   if (ehImpar(numero)) {
                       printf("\n O numero eh impar\n");
                   }else {
                       printf("\n O numero eh par\n");
                   }
                   break;

           case  2:printf("\n Entre com o numero: ");
                   fflush(stdin);
                   scanf("%d",&numero);
                   if (ehPrimo(numero)) {
                       printf("\n O numero eh primo\n");
                   }else{
                       printf("\n O numero nao eh primo\n");
                   }
                   break;

           case  3:printf("\n Entre com o numero: ");
                   fflush(stdin);
                   scanf("%d",&numero);
                   fat = fatorial(numero);
                   if (fat == VALOR_INVALIDO) {
                       printf("\n\a Nao existe fatorial de numero negativo!\n");
                   }else{
                       printf("\n O fatorial de %d eh %.0lf\n",numero,fat);
                   }
                   break;

           case  4:printf("\n Entre com o numero: ");
                   fflush(stdin);
                   scanf("%lf",&numeroRaiz);
                   printf("\n A raiz quadrada de %.2lf eh %.2lf\n",numeroRaiz,sqrt(numeroRaiz));
                   break;

           case  5:exit(0);

           default:printf("\n\a Opcao invalida!\n");
        }
    }while(1);
}
