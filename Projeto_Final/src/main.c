/*
 ============================================================================
 Name        : main.c
 Author      : Clovis Kuhn e Matheus Rodrigues da Cunha
 Version     : 1.0
 Copyright   : Your copyright notice
 Description :Programa que exibe na tela o tempo de ordena��o de um arquivo csv:
 	 	 	  Implementa��o de Quicksort e Counting Sort para compara��o.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "dados.h"


int main(){
	struct timespec t_1;
	struct timespec t_2;
	int j, n_linhas;
	long long tempo_nano, tempo_tnano=0;
	long tempo_seg, tempo_tseg=0;
	for (j=0; j < 20; j++){
		n_linhas = 0;
		dado_t **dados = ler_dados("bounding_boxes.csv", &n_linhas);
		clock_gettime(CLOCK_MONOTONIC ,&t_1);
		quick_sort(dados, 0, n_linhas-1);
		clock_gettime(CLOCK_MONOTONIC ,&t_2);
		tempo_nano = ((t_2.tv_nsec) - (t_1.tv_nsec));
		if (tempo_nano < 0 ) {
			t_2.tv_sec = t_2.tv_sec - 1;
			tempo_nano = tempo_nano + 1000000000;
		}
		tempo_seg = (t_2.tv_sec - t_1.tv_sec);
		//printf("Tempo de ordenacao: %lu.%llu segundos\n", tempo_seg, tempo_nano);
		tempo_tseg = tempo_tseg + tempo_seg;
		tempo_tnano = tempo_tnano + tempo_nano;
		liberar_dados(dados, n_linhas); //libera��o do malloc.
	}
	printf("Tempo de ordenacao Quicksort: %lu.%llu segundos\n", (tempo_tseg/20), (tempo_tnano/20));
	tempo_tseg=0;
	tempo_tnano=0;
	for (j=0; j < 20; j++){
			n_linhas = 0;
			dado_t **dados = ler_dados("bounding_boxes.csv", &n_linhas);
			clock_gettime(CLOCK_MONOTONIC ,&t_1);
			counting_sort(dados, n_linhas);
			clock_gettime(CLOCK_MONOTONIC ,&t_2);
			tempo_nano = ((t_2.tv_nsec) - (t_1.tv_nsec));
			if (tempo_nano < 0 ) {
				t_2.tv_sec = t_2.tv_sec - 1;
				tempo_nano = tempo_nano + 1000000000;
			}
			tempo_seg = (t_2.tv_sec - t_1.tv_sec);
			//printf("Tempo de ordenacao: %lu.%llu segundos\n", tempo_seg, tempo_nano);
			tempo_tseg = tempo_tseg + tempo_seg;
			tempo_tnano = tempo_tnano + tempo_nano;
			liberar_dados(dados, n_linhas); //libera��o do malloc.
		}
		printf("Tempo de ordenacao Counting Sort: %lu.%llu segundos", (tempo_tseg/20), (tempo_tnano/20));
	return 0;
}