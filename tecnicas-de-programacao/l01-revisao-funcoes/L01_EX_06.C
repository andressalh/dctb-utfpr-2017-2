/* Fa�a um programa que apresente o seguinte menu para o usu�rio:

   Controle de Produtos
   ====================
   <1> - Adicionar dados de um produto
   <2> - Remover um produto
   <3> - Listar todos os produtos
   <4> - Listas apenas produtos com estoque zerado
   <5> - Valor total em estoque
   <6> - Sair

   Qual op��o escolhida?

   O usu�rio poder� entrar no m�ximo com 30 produtos. Para cada produto armazene o
   c�digo (int), a quantidade em estoque (int), e o valor unit�rio (float). Para isto
   utilize tr�s vetores. Na op��o 1 o usu�rio entrar� com os dados de apenas um
   produto. Caso o usu�rio tente executar as op��es 2, 3, 4, ou 5 e n�o exista nenhum
   produto cadastrado mostre uma mensagem de alerta. Caso o usu�rio tente cadastrar os
   dados de um novo produto e n�o exista mais espa�o nos vetores de uma mensagem de
   erro. Na op��o 2 o usu�rio dever� entrar com o c�digo do produto que ser� removido,
   caso o produto n�o seja encontrado de uma mensagem de alerta, e caso o produto seja
   apagado corretamente de uma mensagem de sucesso. Na op��o 5 dever� ser impresso o
   valor total em estoque, o valor em estoque de cada produto � o eu valor unit�rio
   vezes a quantidade que existe daquele produto em estoque. O valor total em estoque
   � a soma dos valores em estoque de todos os produtos. Caso o usu�rio escolha a
   op��o 6 use a fun��o exit(int) para encerrar o programa. Caso escolha uma op��o
   inv�lida de uma mensagem de erro e retorne ao menu. As op��es de 1 a 5 devem chamar
   fun��es especificas para realizar as atividades propostas. Utilize a estrutura switch
   com break, e a do/while para fazer o menu.
*/

#include<stdio.h>
#include<stdlib.h>

#define TOTAL_PRODUTOS    5

int    codigos[TOTAL_PRODUTOS], quantidades[TOTAL_PRODUTOS];
double precos[TOTAL_PRODUTOS];

int pos = 0;

void adicionar(){

   if (pos < TOTAL_PRODUTOS){

      printf("\n Entre com os dados do produto %d",pos+1);
      printf("\n ================================");

      printf("\n Entre com o codigo: ");
      scanf("%d",&codigos[pos]);

      printf(" Entre com o preco.: ");
      scanf("%lf",&precos[pos]);

      printf(" Entre com a quantidade em estoque: ");
      scanf("%d",&quantidades[pos]);

      pos++;

   }else{
      printf("\n\a Nao existe espaco no vetor!\n");
   }
}

/*- Caso nao tenha nenhum produto cadastrado a funcao retorna -2
  - Caso nao seja localizado nenhum produto com o codigo procurado a
    funcao retorna -1
  - Mas caso a funcao localize o produto com o codigo procurado ela
    devolve a posicao do codigo no vetor                         */

int busca(int cod){

   int cont;

   if (pos == 0){
      return -2;// nenhum produto cadastrado
   }else{

      for(cont = 0; cont < pos; cont++){

          if (cod == codigos[cont]){
             return cont;
          }
      }
      return -1;// nao localizou o codigo
   }
}

/* Remove e mantem o vetor na mesma ordem de inser��o */

int removeMantendoOrdem(int posRemove){

   int cont;

   if (posRemove >= 0){

      pos--;

      for(cont = posRemove; cont < pos; cont++){
         codigos[cont]     = codigos[cont+1];
         precos[cont]      = precos[cont+1];
         quantidades[cont] = quantidades[cont+1];
      }
      return 1;
   }else
      return 0;
}

/* Remove e muda a ordem dos elementos no vetor */

int removeTrocandoOrdem(int posRemove){

   if (posRemove >= 0){

       pos--;

       if (pos > 0){
           codigos[posRemove]     = codigos[pos];
           precos[posRemove]      = precos[pos];
           quantidades[posRemove] = quantidades[pos];
       }
       return 1;
   }else
       return 0;
}

void remover(){

   int  cont, posRemove, codRemove;
   char opcao, teste;

   if (pos == 0){
      printf("\n\a Nenhum produto foi cadastrado!\n");
   }else{

      printf("\n Remocao de Produto Mantendo Ordem");
      printf("\n =================================\n");

      printf("\n Entre com o codigo do produto: ");
      scanf("%d",&codRemove);

      posRemove = busca(codRemove);

      if (posRemove == -1){
          printf("\n\a Codigo de produto nao localizado!\n");
      }else{

          printf("\n Desejar remover mantendo a ordem de cadastro (S/N)? ");
          fflush(stdin);
          opcao = getchar();

          if (opcao == 's' || opcao == 'S'){
             teste = removeMantendoOrdem(posRemove);
          }else{
             teste = removeTrocandoOrdem(posRemove);
          }

          if (teste){
             printf("\n Remocao realizada com sucesso!\n");
          }else{
             printf("\n\a Ocorreu um erro durante a remo��o!\n");
          }
      }
   }
}

void listarTodos(){

   int cont;

   if (pos == 0){
      printf("\n\a Nenhum produto foi cadastrado!\n");
   }else{

      printf("\n Listagem dos produtos");
      printf("\n =====================");
      printf("\n Nr. Codigo  Preco   Quantidade\n");

      for(cont = 0; cont < pos; cont++){
         printf(" %3d %5d   %6.2lf  %6d\n", cont+1, codigos[cont], precos[cont], quantidades[cont]);
      }
   }
}

void listarZerados(){

   int cont, aux;

   if (pos == 0){
      printf("\n\a Nenhum produto foi cadastrado!\n");
   }else{
      printf("\n Listagem dos produtos com estoque zerado");
      printf("\n ========================================");
      printf("\n Nr. Codigo  Preco   Quantidade\n");

      aux = 1;

      for(cont = 0; cont < pos; cont++){

        if (quantidades[cont] <= 0){
           printf(" %3d %5d   %6.2lf  %6d\n", aux, codigos[cont], precos[cont], quantidades[cont]);
           aux++;
        }
      }
   }
}

void valorTotalEmEstoque(){

   int    cont;
   double soma = 0;

   if (pos == 0){
      printf("\n\a Nenhum produto foi cadastrado!\n");
   }else{

      for(cont = 0; cont < pos; cont++){
         soma += precos[cont] * quantidades[cont];
      }

      printf("\n O valor total em estoque eh R$ %.2lf\n", soma);
   }
}

int main(){

  char opcao;

  do{
    printf("\n Controle de Produtos");
    printf("\n ====================");
    printf("\n <1> - Adicionar dados de um Produto");
    printf("\n <2> - Remover um Produto");
    printf("\n <3> - Listar todos os Produtos");
    printf("\n <4> - Listas apenas produtos com estoque zerado");
    printf("\n <5> - Valor total em estoque");
    printf("\n <6> - Sair");

    printf("\n\n Qual opcao escolhida? ");
    fflush(stdin);
    scanf("%d", &opcao);

    switch(opcao){

       case  1:adicionar();
               break;

       case  2:remover();
               break;

       case  3:listarTodos();
               break;

       case  4:listarZerados();
               break;

       case  5:valorTotalEmEstoque();
               break;

       case  6:exit(0);

       default:printf("\n\a Opcao invalida!\n");
    }
  }while(1);
}
