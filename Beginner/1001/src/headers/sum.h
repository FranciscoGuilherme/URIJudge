/**
 * @~portuguese
 * @file sun.h
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/08/05
 * @brief
 *      - Contém a lógica de soma de dois inteiros
 */

#ifndef _sum_h_
#define _sum_h_

/**
 * @~portuguese
 * @brief Função responsável por ler os dados de entrada
 *
 * @param[out] a Primeiro número inteiro de entrada
 * @param[out] b Segundo número inteiro de entrada
 *
 * @return void
 */
void input(int *a, int *b);

/**
 * @~portuguese
 * @brief Função responsável por efetuar a soma dos dois valores inteiros a e b
 *
 * @param[out] a Primeiro número inteiro
 * @param[out] b Segundo número inteiro
 *
 * @return int Soma de a e b
 */
int sum(int *a, int *b);

/**
 * @~portuguese
 * @brief Função responsável por gerar a mensagem final de apresentação
 *
 * @param total Resultado da soma returnada por ref:sum
 *
 * @return char* Ponteiro para a mensagem final de apresentação
 */
char *output(int total);

#endif
