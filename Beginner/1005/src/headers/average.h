#ifndef _AVERAGE_H
#define _AVERAGE_H

/**
 * @~portuguese
 * @brief Regra para o cálculo da mádia ponderada\n
 *        Onde os valores a e b possuem, respectivamente, 
 *        os pesos 3,5 e 7,5
 *
 * @~english
 * @brief Rule for calculating weighted average\n
 *        Where values a and b have respectively\n
 *        weights 3.5 and 7.5
 */
#define calculate(a, b) ((a * 3.5) + (b * 7.5)) / 11

/**
 * @~portuguese
 * @brief Função responsável por ler os dados de entrada
 *
 * @param[out] a Primeiro número de dupla precisão de entrada
 * @param[out] b Segundo número de dupla precisão de entrada
 *
 * @return void
 *
 * @~english
 * @brief Function responsible for reading input data
 *
 * @param[out] a First number of double entry precision
 * @param[out] b Second number of double entry precision
 *
 * @return void
 */
void input(double *a, double *b);

/**
 * @~portuguese
 * @brief Função responsável por efetuar o cálculo da média
 *
 * @param[out] a Primeiro número de dupla precisão de entrada
 * @param[out] b Segundo número de dupla precisão de entrada
 *
 * @return Resultado do cálculo da média ponderada
 *
 * @~english
 * @brief Function responsible for averaging
 *
 * @param[out] a First number of double entry precision
 * @param[out] b Second number of double entry precision
 *
 * @return Weighted average calculation result
 */
double average(double *a, double *b);

/**
 * @~portuguese
 * @brief Função responsável por gerar a mensagem final de apresentação
 *
 * @param average Resultado do cálculo da média ponderada retornada por ::average
 *
 * @return[out] Ponteiro para a mensagem final de apresentação
 *
 * @~english
 * @brief Function responsible for generating the final presentation message
 *
 * @param average Weighted average calculation result returned by ::average
 *
 * @return[out] Pointer to the final presentation message
 */
char *output(double average);

#endif
