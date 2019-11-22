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
dado_t * criar_dado (int amostra, float temperatura, char * tempo);

dado_t ** ler_dados (char *camera_tempcsv, int * n_linhas);

void liberar_dados (dado_t **meu_novo_dado, int n_linhas);

int imprime_amostra(dado_t *dados);

float imprime_temperatura(dado_t *dados);

char * imprime_tempo(dado_t *dados);

void quick_sort(dado_t **dados, int n_linhas);

int med_tres(dado_t **dados, int esq, int dir);

int particao(dado_t **dados, int esq, int dir);

#endif /* DADOS_H_ */
