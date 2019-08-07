#ifndef _AREA_H
#define _AREA_H

/**
 * @~portuguese
 * @brief Valor assumido para PI
 *
 * @~english
 * @brief Default value for PI
 */
#define N 3.14159

/**
 * @~portuguese
 * @brief Função responsável por ler os dados de entrada
 *
 * @param[out] pradius Raio de uma circunferência
 *
 * @return void
 *
 * @~english
 * @brief Function responsible for reading input data
 *
 * @param[out] pradius Radius of a circumference
 *
 * @return void
 */
void input(double *pradius);

/**
 * @~portuguese
 * @brief Function responsible for calculating area
 *
 * @param[out] pradius Raio de uma circunferência
 *
 * @return Área calculada
 *
 * @~english
 * @brief Function responsible for summing the two integers a and b
 *
 * @param[out] pradius Raio de uma circunferência
 *
 * @return Calculated area
 */
double area(double *pradius);

/**
 * @~portuguese
 * @brief Função responsável por gerar a mensagem final de apresentação
 *
 * @param area Área calculada retornada por ::area
 *
 * @return[out] Ponteiro para a mensagem final de apresentação
 *
 * @~english
 * @brief Role responsible for generating the final presentation message
 *
 * @param area Calculated area returned by ::area
 *
 * @return[out] Pointer to the final presentation message
 */
char *output(double area);

#endif
