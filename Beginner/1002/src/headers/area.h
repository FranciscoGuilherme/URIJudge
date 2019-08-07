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
 * @param[out] double pradius Raio de uma circunferência
 *
 * @return void
 *
 * @~english
 * @brief Function responsible for reading input data
 *
 * @param[out] double pradius Radius of a circumference
 *
 * @return void
 */
void input(double *pradius);

/**
 * @~portuguese
 * @brief Function responsible for calculating area
 *
 * @param[out] double pradius Raio de uma circunferência
 *
 * @return double Área calculada
 *
 * @~english
 * @brief Function responsible for summing the two integers a and b
 *
 * @param[out] double pradius Raio de uma circunferência
 *
 * @return double Calculated area
 */
double area(double *pradius);

/**
 * @~portuguese
 * @brief Função responsável por gerar a mensagem final de apresentação
 *
 * @param double area Área calculada retornada por ::area
 *
 * @return[out] char Ponteiro para a mensagem final de apresentação
 *
 * @~english
 * @brief Role responsible for generating the final presentation message
 *
 * @param double area Calculated area returned by ::area
 *
 * @return[out] char Pointer to the final presentation message
 */
char *output(double area);

#endif
