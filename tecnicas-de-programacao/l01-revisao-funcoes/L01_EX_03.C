/* Fa�a a leitura dos seguintes dados no formato real: Velocidade,
   Tempo e Litros Gastos. Depois chame uma fun��o para calcular e
   retornar o deslocamento do veiculo passando como par�metros
   Velocidade e Tempo. Chame outra fun��o para calcular e retornar
   o consumo de combust�vel, passando como par�metros Velocidade,
   Tempo e Litros Gastos. Esta segunda fun��o dever� utilizar a
   fun��o anterior para chegar ao consumo m�dio do veiculo.
   Imprima os resultados achados na fun��o principal. As fun��es
   criadas dever�o estar em um arquivo diferente do arquivo da fun��o
   principal, este arquivo externo dever� chamar veiculo.c */

#include <stdio.h>
#include "VEICULOC.C"

int main() {

    double velocidade, tempo, litrosGastos;

    velocidade = tempo = litrosGastos = 0;

    printf("\n\n Calcula o Deslocamento e a Taxa de Consumo de um Veiculo");
    printf("\n\n ========================================================");

    printf("\n\n Entre com a Velocidade (Km/h) .............: ");
    scanf("%lf",&velocidade);

    printf("\n Entre com o Tempo em Movimento (horas).....: ");
    scanf("%lf",&tempo);

    printf("\n Entre com o Total de Litros Gastos (litros): ");
    scanf("%lf",&litrosGastos);

    printf("\n\n O veiculo percorreu a distancia total de %.2lf Km", deslocamento(velocidade, tempo));
    printf("\n\n O veiculo andou %.2lf kilometros com cada litro de combustivel\n", consumo(velocidade, tempo, litrosGastos));

    return 0;
}
