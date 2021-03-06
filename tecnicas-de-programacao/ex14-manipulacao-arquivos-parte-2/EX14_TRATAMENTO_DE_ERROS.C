
/* Exemplo de manipula��o de Arquivo Texto

   Tratamento de erros

   Uso das fun��es:
   strerror - Pertence a biblioteca <string.h>, e imprime uma mensagem padr�o (normalmente em ingl�s)
              sobre o c�digo de erro passado.

   errno : v�riavel localizada na biblioteca <errno.h> que armazena o c�digo do �ltimo erro
           padr�o identificado. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> // Biblioteca com a v�riavel (errno) e constantes de erro

#define MAXIMO_CARACTERES 255

int main(){

    char  nomeArquivo[MAXIMO_CARACTERES], caracter;
    FILE* arquivo;

    printf("\n Entre com o nome do arquivo para abertura: ");
    fflush(stdin);

    gets(nomeArquivo);

    arquivo = fopen(nomeArquivo, "r+"); // Abre para leitura e escrita (posiciona o curso no in�cio)

    if (arquivo == NULL){
        printf("%\n\a Erro: %s.\n", strerror(errno));
        exit(errno);
    }

    printf("\n Gravando letras...\n\n ");

    for (caracter = 'A'; caracter <= 'Z'; caracter++){

        printf("%c ", caracter);

        if (fputc(caracter, arquivo) == EOF){ // EOF indica erro de escrita
            printf("%\n\a Erro: %s.\n", strerror(errno));
            exit(errno);
        }
    }

    fflush(arquivo); // For�a terminar todas as opera��es pendentes

    rewind(arquivo); // Volta para o in�cio do arquivo

    printf("\n\n Lendo caracteres do arquivo...\n\n ");

    while((caracter = getc(arquivo)) != EOF){
        printf("%c ", caracter);
    }

    fclose(arquivo);

    printf("\n\n Operacao realizada com sucesso!\n");

    return 0;
}
