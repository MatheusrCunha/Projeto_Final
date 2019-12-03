/*
 * dados.c
 *
 *  Created on: 30 de nov de 2019
 *      Author: Matheus e Clovis
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"

struct dados{
	int quadro;
	float coordenadax;
	float coordenaday;
	int comprimento;
	int altura;
};

dado_t * criar_dado (dado_t *temp)
{

	dado_t * meu_novo_dado = malloc(sizeof(struct dados));

	if (meu_novo_dado == NULL){
		perror("Criar dado!\n");
		exit(-2);
	}

	//strncpy(meu_novo_dado->quadro, temp->quadro, 1000);
	meu_novo_dado->quadro = temp->quadro;
	meu_novo_dado->coordenadax = temp->coordenadax;
	meu_novo_dado->coordenaday = temp->coordenaday;
	meu_novo_dado->comprimento = temp->comprimento;
	meu_novo_dado->altura = temp->altura;

	return meu_novo_dado;
}


dado_t **ler_dados(char *bounding_boxes, int *n_linhas){

	char texto[64];

	int i=0, linhas = 0;

	FILE *fp = fopen(bounding_boxes,"r");

	if (!fp){
		perror("ler_dados_csv");
		exit(-1);
	}

	dado_t temp;

	/* Ignora primeira linha */
	fgets(texto, 64, fp);

	/* Contar todas as linhas: use while e fgets() */
	while (fgets (texto, 64, fp) != NULL){
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
	fgets(texto,64, fp);
	//float temperatura;
	//while(fscanf(fp,"%255[^,],

	while(fscanf(fp,"%d, %f, %f, %d, %d\n", &temp.quadro, &temp.coordenadax,
			&temp.coordenaday, &temp.comprimento, &temp.altura) == 5){

		//temp.temperatura_mar = (int)(temperatura*100);
		/* Cria um novo dado abstrato e armazena a sua referência */
		dados[i] = criar_dado(&temp);
		i++;
	}
	*n_linhas = linhas;

	fclose(fp);
	return dados;
}

void quick_sort(dado_t **dados, int esq, int dir)
{
	int p;
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

	if(dados[dir]->altura < dados[esq]->altura)
		swap(dados, esq, dir);

	if(dados[med]->altura < dados[esq]->altura)
		swap(dados, med, esq);

	if(dados[dir]->altura < dados[med]->altura)
		swap(dados, dir, med);

	return med;
}
int particao(dado_t **dados, int esq, int dir)
{

	int med = med_tres(dados, esq, dir);
	dado_t *pivot = dados[med];
	int i = esq - 1;
	int j = dir + 1;

	for(;;){
		do{
			i = i + 1;
		}while(dados[i]->altura < pivot->altura);
		do{
			j = j - 1;
		}while(dados[j]->altura > pivot->altura);

		if(i >= j)
			return j;
		swap(dados, i, j);
	}
	return j;
}
int maximo(dado_t **dados, int n_linhas){

	int i = 0;
	int max = 0;
	for(i = 0; i < n_linhas; i++){
		if(dados[i]->altura > max){
			max = dados[i]->altura;
		}
	}
	return max;
}

void counting_sort(dado_t **dados, int n_linhas)
{
	int i, j, max;
	max = maximo(dados,n_linhas);

	int *count = calloc(max+1, sizeof(int));
	dado_t **output = malloc(sizeof(struct dados*) * n_linhas);

	// Store count of each character
	for(j = 0; j < n_linhas; j++)
		++count[dados[j]->altura];

	for (i = 1; i <= max; i++)
		count[i]= count[i] + count[i-1];

	// Build the output array
	for (j = n_linhas-1; j >= 0; j--)
	{

		printf("%d %d %d\n", j, dados[j]->altura,count[dados[j]->altura]-1 );
		fflush(stdout);


		output[count[dados[j]->altura]-1] = dados[j];
		--count[dados[j]->altura];
	}


		puts("--------------------");

	/*
     For Stable algorithm
     for (i = sizeof(arr)-1; i>=0; --i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }

    For Logic : See implementation
	 */

	// Copy the output array to arr, so that arr now
	// contains sorted characters
	for (i = 0; i < n_linhas; ++i){
		dados[i] = output[i];

		printf("%d %d\n", i, output[i]->altura);
		fflush(stdout);
	}
}

void imprime_dados(dado_t *dados)
{
	printf("%d, %.2f, %.2f, %d, %d\n", imprime_quadro(dados), imprime_coordenadax(dados),
			imprime_coordenaday(dados), imprime_comprimento(dados),imprime_altura(dados));
}
int imprime_quadro(dado_t *dados)
{
	return (dados->quadro);
}

float imprime_coordenadax(dado_t *dados)
{
	return (dados->coordenadax);
}
float imprime_coordenaday(dado_t *dados)
{
	return (dados->coordenaday);
}

int imprime_comprimento(dado_t *dados)
{
	return (dados->comprimento);
}

int imprime_altura(dado_t *dados)
{
	return (dados->altura);
}
void swap(dado_t **dados, int i, int j)
{
	dado_t *temp = dados[i];
	dados[i] = dados[j];
	dados[j] = temp;
}
void liberar_dados(dado_t **dados, int n_linhas)
{
	int i;
	for(i=0;i<n_linhas;i++){
		free(dados[i]);
	}
	free(dados);
}
