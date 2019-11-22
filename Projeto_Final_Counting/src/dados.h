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
dado_t * criar_dado (dado_t temp);

dado_t ** ler_dados (char *dados_METARcsv, int * n_linhas);

void liberar_dados (dado_t **meu_novo_dado, int n_linhas);

char * imprime_tempo(dado_t *dados);

float imprime_temperatura(dado_t *dados);

float imprime_vento_frio(dado_t *dados);

float imprime_indice_calor(dado_t *dados);

float imprime_umidade(dado_t *dados);

float imprime_pressao(dado_t *dados);

float imprime_condensacao_agua(dado_t *dados);

float imprime_visibilidade(dado_t *dados);

char * imprime_vento_direcao(dado_t *dados);

float imprime_vento_velocidade(dado_t *dados);

float imprime_vento_rajada(dado_t *dados);

float imprime_precipitacao(dado_t *dados);

char * imprime_clima_evento(dado_t *dados);

char * imprime_clima_condicao(dado_t *dados);

#endif /* DADOS_H_ */
