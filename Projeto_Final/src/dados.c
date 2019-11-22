/*
 * dados.c
 *
 *  Created on: 12 de nov de 2019
 *      Author: Matheus e Clovis
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"

struct dados {
	char tempo[64];     /*!< Time stamp */
	float temperatura;  /*!< Valor do dado: temperatura */
	float vento_frio;        /*!< Valor do dado: vento frio*/
	float indice_calor;
	float umidade;
	float pressao;
	float condensacao_agua;
	float visibilidade;
	char vento_direcao[10];
	float vento_velocidade;
	float vento_rajada;
	float precipitacao;
	char clima_evento[10];
	char clima_condicao[15];
};


dado_t * criar_dado (char * tempo, float temperatura,  float vento_frio, float indice_calor, float umidade, float pressao, float condensacao_agua,){

	dado_t * meu_novo_dado = malloc(sizeof(struct dados));
	if (meu_novo_dado == NULL) {
		perror("Criar dado!\n");
		exit(-2);
	}


	meu_novo_dado->pressao = pressao;

	strncpy(meu_novo_dado->tempo, tempo, 64);
	return meu_novo_dado;
}


dado_t **ler_dados(char *dados_METARcsv, int *n_linhas){
	char tempo[64];
	int i=0, linhas=0, amostra;
	float temperatura;

	FILE *fp = fopen(dados_METARcsv,"r");

	if (!fp){
		perror("ler_dados_csv");
		exit(-1);
	}

	/* Ignora primeira linha */
	fgets(tempo,64, fp);

	/* Contar todas as linhas: use while e fgets() */
	while (fgets (tempo,64, fp) != NULL){
		linhas++;
	}

	/* Alocando memória:
	 * Agora é um vetor de ponteiros */
	dado_t **dados = malloc(sizeof(struct dados*) * linhas);
	if (dados == NULL) {
		perror("ler dados!\n");
		exit(-2);
	}
	rewind(fp);
	/* Ignorando a primeira linha */
	fgets(tempo,64, fp);
	while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, tempo) == 3){
		/* Cria um novo dado abstrato e armazena a sua referência */
		dados[i] = criar_dado(amostra, temperatura, tempo);
		i++;
	}
	*n_linhas = linhas;
	return dados;
}

void quick_sort(dado_t **dados, int esq, dir)
{
	dado_t *p;

	if(esq < dir){
		p = particao(dados, esq, dir);
		quick_sort(dados, esq, p);
		quick_sort(dados, p+1, dir);
	}

}
int med_tres(dado_t **dados, int esq, int dir)
{
	int med;

	med = (esq + dir) / 2;

	if(dados[dir]->pressao < dados[esq]->pressao)
		swap(dados, esq, dir);

	if(dados[med]->pressao < dados[esq]->pressao)
		swap(dados, med, esq);

	if(dados[dir]->pressao < dados[med]->pressao)
		swap(dados, dir, med);

	return med;
}

int particao(dado_t **dados, esq, dir)
{

	int med = mediana_tres(dados, esq, dir);
	dado_t *pivot = dados[med];
	int i = esq - 1;
	int j = dir + 1;

	for(;;){
		do{
			i = i + 1;
		}while(dados[i]->pressao < pivot->pressao);
		do{
			j = j - 1;
		}while(dados[j]->pressao > pivot->pressao);

		if(i >= j)
			return j;
		swap(dados, i, j);
	}
	return j;
}
int imprime_amostra(dado_t * dados){
	return (dados->amostra);
}

float imprime_temperatura(dado_t * dados){
	return (dados->temperatura);
}

char * imprime_tempo(dado_t * dados){
	return (dados->tempo);
}

void liberar_dados(dado_t **vetor, int n_linhas){
	int i;
	for(i=0;i<n_linhas;i++)
		free(vetor[i]);
	free(vetor);
}
