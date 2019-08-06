#ifndef _SUM_H
#define _SUM_H

/**
 * @~portuguese
 * @brief Função responsável por ler os dados de entrada
 *
 * @param[out] int a Primeiro número inteiro de entrada
 * @param[out] int b Segundo número inteiro de entrada
 *
 * @return void
 *
 * @~english
 * @brief Function responsible for reading input data
 *
 * @param[out] int a First Entry Integer
 * @param[out] int b Second Integer Input
 *
 * @return void
 */
void input(int *a, int *b);

/**
 * @~portuguese
 * @brief Função responsável por efetuar a soma dos dois valores inteiros a e b
 *
 * @param[out] int a Primeiro número inteiro
 * @param[out] int b Segundo número inteiro
 *
 * @return int Soma de a e b
 *
 * @~english
 * @brief Function responsible for summing the two integers a and b
 *
 * @param[out] int a First Entry Integer
 * @param[out] int b Second Integer Input
 *
 * @return int Sum of a and b
 */
int sum(int *a, int *b);

/**
 * @~portuguese
 * @brief Função responsável por gerar a mensagem final de apresentação
 *
 * @param int total Resultado da soma retornada por ::sum
 *
 * @return[out] char Ponteiro para a mensagem final de apresentação
 *
 * @~english
 * @brief Role responsible for generating the final presentation message
 *
 * @param int total Sum result returned by ::sum
 *
 * @return[out] char Pointer to the final presentation message
 */
char *output(int total);

#endif
