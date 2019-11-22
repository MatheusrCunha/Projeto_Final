/*
 ============================================================================
 Name        : main.c
 Author      : Clovis Kuhn e Matheus Cunha
 Version     : 1.0
 Copyright   : Your copyright notice
 Description :Programa que verifica o tempo de ordenação de um arquivo CSV conforme o algoritmo de counting sort:
  	  	  	  Time,Temp.,Windchill,Heat Index,Humidity,Pressure,Dew Point,Visibility,Wind Dir,Wind Speed,Gust Speed,Precip,Events,Conditions
  	  	  	  <string>;<float>;<float>;<float>;<float>;<float>;<float>;<float>;<string>;<float>;<float>;<float>;<string>;<string>;
   	  	  	  <string>;<float>;<float>;<float>;<float>;<float>;<float>;<float>;<string>;<float>;<float>;<float>;<string>;<string>;
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "dados.h"


int main(){
    int i;
    int n_linhas = 0;
    dado_t **dados = ler_dados("dados_METAR.csv", &n_linhas);

    // Imprima os dados:
    for (i=0; i < n_linhas; i++){
        printf( "%s, %.2f, %.2f, %.f, %.2f, %.2f, %.2f, %.2f, %s, %.2f, %.2f, %.2f, %s, %s\n", imprime_tempo(dados[i]),imprime_temperatura(dados[i]),imprime_vento_frio(dados[i]),imprime_indice_calor(dados[i]),imprime_umidade(dados[i]),imprime_pressao(dados[i]),imprime_condensacao_agua(dados[i]),imprime_visibilidade(dados[i]),imprime_vento_direcao(dados[i]),imprime_vento_velocidade(dados[i]),imprime_vento_rajada(dados[i]),imprime_precipitacao(dados[i]),imprime_clima_evento(dados[i]),imprime_clima_condicao(dados[i]));
    }

    liberar_dados(dados, n_linhas); //liberação do malloc.

    return 0;
}
