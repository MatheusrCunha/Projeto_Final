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
    char tempo[255];     /*!< Time stamp */
    float temperatura;  /*!< Valor do dado: temperatura */
    float vento_frio;        /*!< Valor do dado: vento frio*/
    float indice_calor;
    float umidade;
    float pressao;
    float condensacao_agua;
    float visibilidade;
    char vento_direcao[15];
    float vento_velocidade;
    float vento_rajada;
    float precipitacao;
    char clima_evento[20];
    char clima_condicao[20];
};


dado_t * criar_dado (dado_t temp){

    dado_t * meu_novo_dado = malloc(sizeof(struct dados));
    if (meu_novo_dado == NULL) {
        perror("Criar dado!\n");
        exit(-2);
    }
    strncpy(meu_novo_dado->tempo, temp.tempo, 255);
    meu_novo_dado->temperatura = temp.temperatura;
    meu_novo_dado->vento_frio = temp.vento_frio;
    meu_novo_dado->indice_calor = temp.indice_calor;
    meu_novo_dado->umidade = temp.umidade;
    meu_novo_dado->pressao = temp.pressao;
    meu_novo_dado->condensacao_agua = temp.condensacao_agua;
    meu_novo_dado->visibilidade = temp.visibilidade;
    strncpy(meu_novo_dado->vento_direcao, temp.vento_direcao, 15);
    meu_novo_dado->vento_velocidade = temp.vento_velocidade;
    meu_novo_dado->vento_rajada = temp.vento_rajada;
    meu_novo_dado->precipitacao = temp.precipitacao;
    strncpy(meu_novo_dado->clima_evento, temp.clima_evento, 20);
    strncpy(meu_novo_dado->clima_condicao, temp.clima_condicao, 20);
    return meu_novo_dado;
}


dado_t **ler_dados(char *dados_METARcsv, int *n_linhas){
    int i=0, linhas=0;

    FILE *fp = fopen(dados_METARcsv,"r");

    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }

    /*Estrutura temporária para criar cada dado*/
    dado_t temp;

    /* Ignora primeira linha */
    fgets(temp.tempo,255, fp);

    /* Contar todas as linhas: use while e fgets() */
    while (fgets (temp.tempo,255, fp) != NULL){
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
    fgets(temp.tempo,255, fp);
    while (fscanf (fp,"%254,%f,%f,%f,%f,%f,%f,%f,%14,%f,%f,%f,%19,%19[^\n]", temp.tempo, &temp.temperatura, &temp.vento_frio, &temp.indice_calor, &temp.umidade, &temp.pressao, &temp.condensacao_agua, &temp.visibilidade, temp.vento_direcao, &temp.vento_velocidade, &temp.vento_rajada, &temp.precipitacao, temp.clima_evento, temp.clima_condicao) == 14){
        /* Cria um novo dado abstrato e armazena a sua referência */
        dados[i] = criar_dado(temp);
        i++;
    }
    *n_linhas = linhas;
    return dados;
}

char * imprime_tempo(dado_t *dados){
	return (dados->tempo);
}

float imprime_temperatura(dado_t *dados){
	return (dados->temperatura);
}

float imprime_vento_frio(dado_t *dados){
	return (dados->vento_frio);
}

float imprime_indice_calor(dado_t *dados){
	return (dados->indice_calor);
}

float imprime_umidade(dado_t *dados){
	return (dados->umidade);
}

float imprime_pressao(dado_t *dados){
	return (dados->pressao);
}

float imprime_condensacao_agua(dado_t *dados){
	return (dados->condensacao_agua);
}

float imprime_visibilidade(dado_t *dados){
	return (dados->visibilidade);
}

char * imprime_vento_direcao(dado_t *dados){
	return (dados->vento_direcao);
}

float imprime_vento_velocidade(dado_t *dados){
	return (dados->vento_velocidade);
}

float imprime_vento_rajada(dado_t *dados){
	return (dados->vento_rajada);
}

float imprime_precipitacao(dado_t *dados){
	return (dados->precipitacao);
}

char * imprime_clima_evento(dado_t *dados){
	return (dados->clima_evento);
}

char * imprime_clima_condicao(dado_t *dados){
	return (dados->clima_condicao);
}

void liberar_dados(dado_t **vetor, int n_linhas){
	int i;
	for(i=0;i<n_linhas;i++)
		free(vetor[i]);
	free(vetor);
}
