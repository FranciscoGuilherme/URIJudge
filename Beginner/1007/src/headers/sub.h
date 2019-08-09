#ifndef _SUB_H
#define _SUB_H

/**
 * @~portuguese
 * @brief Regra para o cálculo da diferença de produtos
 *
 * @~english
 * @~brief Rule for calculating product difference
 */
#define calculate(a, b, c, d) (a * b) - (c * d)

/**
 * @~portuguese
 * @brief Função responsável por ler os dados de entrada
 *
 * @param[out] a Primeiro valor inteiro na base de cálculo
 * @param[out] b Segundo valor inteiro na base de cálculo
 * @param[out] c Terceiro valor inteiro na base de cálculo
 * @param[out] d Quarto valor inteiro na base de cálculo
 *
 * @return void
 *
 * @~english
 * @~brief Function responsible for reading input data
 *
 * @param [out] a First integer value in calculation base
 * @param [out] b Second integer value in calculation base
 * @param [out] c Third integer value in calculation base
 * @param [out] d Fourth integer value in calculation base
 *
 * @return void
 */
void input(int *a, int *b, int *c, int *d);

/**
 * @~portuguese
 * @brief
 *
 * @param[out] a Primeiro valor inteiro na base de cálculo
 * @param[out] b Segundo valor inteiro na base de cálculo
 * @param[out] c Terceiro valor inteiro na base de cálculo
 * @param[out] d Quarto valor inteiro na base de cálculo
 *
 * @return Resultado do cálculo
 *
 * @~english
 * @~brief
 *
 * @param [out] a First integer value in calculation base
 * @param [out] b Second integer value in calculation base
 * @param [out] c Third integer value in calculation base
 * @param [out] d Fourth integer value in calculation base
 *
 * @return Calculation result
 */
int sub(int *a, int *b, int *c, int *d);

/**
 * @~portuguese
 * @brief Função responsável por gerar a mensagem final de apresentação
 *
 * @param result Resultado do cálculo retornada por ::sub
 *
 * @return[out] Ponteiro para a mensagem final de apresentação
 *
 * @~english
 * @brief Function responsible for generating the final presentation message
 *
 * @param result Calculation result returned by ::sub
 *
 * @return[out] Pointer to the final presentation message
 */
char *output(int result);

#endif
