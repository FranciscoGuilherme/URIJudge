/**
 * @~portuguese
 * @file salary.h
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/07/27
 * @brief
 *      - Contém a lógica de cálculo do salário de um funcionário
 *      - Manipulando os dados através de funções por responsabilidades
 */
#ifndef _SALARY_H
#define _SALARY_H

/**
 * @~portuguese
 * @brief Estrutura para armazenamento dos dados de um funcionário.
 */
struct employee
{
    int number;  /**< Número do funcionário#number. */
    int hours;   /**< Número de horas trabalhadas#hours. */
    float value; /**< Valor recebido por hora trabalhada#value */
};

/**
 * @~portuguese
 * @brief Define regra para cálculo do salário de um funcionário
 */
#define calculate(hours, value) hours * value

/**
 * @~portuguese
 * @brief Função responsável por ler os dados de um funcionário
 *
 * @param[out] number Número do funcionário
 * @param[out] hours  Número de horas trabalhadas
 * @param[out] value  Valor recebido por hora trabalhada
 *
 * @return void
 */
void input(int *number, int *hours, float *value);

/**
 * @~portuguese
 * @brief Função responsável por fazer o cálculo do salário de um funcionário\n
 *        Faz uso de uma macro para encapsular a lógica de cálculo do salário
 *        de um funcionário
 *
 * @param[out] hours Número de horas trabalhadas
 * @param[out] value Valor recebido por hora trabalhada
 *
 * @code
 * calculate(hours, value);
 * @endcode
 *
 * @note
 *     - <b>hours</b> é um ponteiro para um inteiro identificador do funcionário
 *     - <b>value</b> é o valor recebido por hora trabalhada
 *
 * @return float
 */
float salary(int *hours, float *value);

/**
 * @~portuguese
 * @brief Função responsável por geral a mensagem final de apresentação
 *
 * @param[out] number Número identificador de um funcionário
 * @param      salary Valor recebido por hora trabalhada
 *
 * @return char **
 */
char **output(int *number, float salary);

/**
 * @~portuguese
 * @brief Função responsável por liberar memória alocada dinamicamente
 *
 * @param[out] employee Estrutura que representa um funcionário
 * @param[out] buffer   Lista de mensagens de apresentação (saída)
 *
 * @return void
 */
void destroy(struct employee *employee, char **buffer);

#endif
