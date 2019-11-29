/*
 * dados.h
 *
 *  Created on: 12 de nov de 2019
 *      Author: Matheus e Clovis
 */

#ifndef DADOS_H_
#define DADOS_H_

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;
/**
  * @brief  Cria um novo dado
  * @param  amostra: identificador da amostra
  * @param  temperatura: valor da temperatura
  * @param  timestamp: data e hora da amostra
  *
  * @retval dado_t: ponteiro para uma novo dado
  */
dado_t * criar_dado(dado_t *temp);

dado_t **ler_dados(char *dados_METARcsv, int * n_linhas);

void liberar_dados(dado_t **dados, int n_linhas);

char * imprime_encontro(dado_t *dados);

float imprime_altura_media(dado_t *dados);

float imprime_direcao_pico(dado_t *dados);

float imprime_temperatura_mar(dado_t *dados);

void imprime_dados(dado_t **dados);

float imprime_altura_max(dado_t *dados);

float imprime_onda_zero(dado_t *dados);

float imprime_pico_energia(dado_t *dados);

void imprime_dado(dado_t **dados);

void quick_sort(dado_t **dados, int esq, int dir);

int med_tres(dado_t **dados, int esq, int dir);

int particao(dado_t **dados, int esq, int dir);

void swap(dado_t **dados, int i, int j);
#endif /* DADOS_H_ */
