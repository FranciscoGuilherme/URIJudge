#ifndef _SUM_H
#define _SUM_H

/**
 * @~portuguese
 * @brief Função responsável por ler os dados de entrada
 *
 * @param[out] a Primeiro número inteiro de entrada
 * @param[out] b Segundo número inteiro de entrada
 *
 * @return void
 *
 * @~english
 * @brief Function responsible for reading input data
 *
 * @param[out] a First Entry Integer
 * @param[out] b Second Integer Input
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
 * @return Soma de a e b
 *
 * @~english
 * @brief Function responsible for summing the two integers a and b
 *
 * @param[out] a First Entry Integer
 * @param[out] b Second Integer Input
 *
 * @return Sum of a and b
 */
int sum(int *a, int *b);

/**
 * @~portuguese
 * @brief Função responsável por gerar a mensagem final de apresentação
 *
 * @param total Resultado da soma retornada por ::sum
 *
 * @return[out] Ponteiro para a mensagem final de apresentação
 *
 * @~english
 * @brief Role responsible for generating the final presentation message
 *
 * @param total Sum result returned by ::sum
 *
 * @return[out] Pointer to the final presentation message
 */
char *output(int total);

#endif
