/**
 * @~portuguese
 * @file salary.h
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/11/21
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
    char *name;    /**< Nome do funcionário#name. */
    double number; /**< Salario do funcionário#number. */
    double sales;  /**< Valor das vendas feitas#sales. */
};

/**
 * @~portuguese
 * @brief Define regra para cálculo do salário de um funcionário
 */
#define calculate(number, sales) number + (0.15 * sales)

/**
 * @~portuguese
 * @brief Função responsável por ler os dados de um funcionário
 *
 * @param[out] name   Nome do funcionário
 * @param[out] number Salario fixo do funcionário
 * @param[out] sales  Valor das vendas realizadas
 *
 * @return void
 */
void input(char **name, double *number, double *sales);

/**
 * @~portuguese
 * @brief Função responsável por fazer o cálculo do salário de um funcionário\n
 *        Faz uso de uma macro para encapsular a lógica de cálculo do salário
 *        de um funcionário
 *
 * @param[out] number Salario fixo do funcionário
 * @param[out] sales  Valor das vendas realizadas
 *
 * @code
 * calculate(number, sales);
 * @endcode
 *
 * @note
 *     - <b>number</b> é um ponteiro para um inteiro que representa o salario fixo do funcionário
 *     - <b>sales</b> é o valor das vendas realizadas
 *
 * @return double
 */
double salary(double *number, double *sales);

/**
 * @~portuguese
 * @brief Função responsável por geral a mensagem final de apresentação
 *
 * @param salary Valor recebido baseado no calculo do salarios
 *
 * @return char *
 */
char *output(double salary);

/**
 * @~portuguese
 * @brief Função responsável por liberar memória alocada dinamicamente
 *
 * @param[out] employee Estrutura que representa um funcionário
 * @param[out] buffer   Lista de mensagens de apresentação (saída)
 *
 * @return void
 */
void destroy(struct employee *employee, char *buffer);

#endif
