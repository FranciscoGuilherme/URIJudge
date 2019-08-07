#ifndef _SIMPLE_MULT_H
#define _SIMPLE_MULT_H

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
 * @brief Função responsável por efetuar a multiplicação dos dois valores inteiros a e b
 *
 * @param[out] a Primeiro número inteiro
 * @param[out] b Segundo número inteiro
 *
 * @return Multiplicação de a e b
 *
 * @~english
 * @brief Function responsible for multiplying the two integers a and b
 *
 * @param[out] a First Entry Integer
 * @param[out] b Second Integer Input
 *
 * @return Multiplication of a and b
 */
int mult(int *a, int *b);

/**
 * @~portuguese
 * @brief Função responsável por gerar a mensagem final de apresentação
 *
 * @param mult Resultado da multiplicação retornada por ::mult
 *
 * @return[out] Ponteiro para a mensagem final de apresentação
 *
 * @~english
 * @brief Function responsible for generating the final presentation message
 *
 * @param mult Multiplication result returned by ::mult
 *
 * @return[out] Pointer to the final presentation message
 */
char *output(int mult);

#endif
