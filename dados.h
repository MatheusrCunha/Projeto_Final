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

dado_t **ler_dados(char *bounding_boxes, int * n_linhas);

void liberar_dados(dado_t **dados, int n_linhas);

void imprime_dados(dado_t *dados);

int imprime_quadro(dado_t *dados);

float imprime_coordenadax(dado_t *dados);

float imprime_coordenaday(dado_t *dados);

int imprime_comprimento(dado_t *dados);

int imprime_altura(dado_t *dados);

void quick_sort(dado_t **dados, int esq, int dir);

int med_tres(dado_t **dados, int esq, int dir);

int particao(dado_t **dados, int esq, int dir);

int maximo(dado_t **dados, int n_linhas);

void counting_sort(dado_t **dados, int n_linhas);

void swap(dado_t **dados, int i, int j);
#endif /* DADOS_H_ */
