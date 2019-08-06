#ifdef _EN_US

/**
 * @~portuguese
 * @file sun.h
 * @author Francisco Guilherme A. S. Bessa
 * @date 2019/08/05
 * @brief
 *      - Contém a lógica de soma de dois inteiros
 */

/**
 * @~portuguese
 * @brief Função responsável por ler os dados de entrada
 *
 * @param[out] int a Primeiro número inteiro de entrada
 * @param[out] int b Segundo número inteiro de entrada
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
 */
int sum(int *a, int *b);

/**
 * @~portuguese
 * @brief Função responsável por gerar a mensagem final de apresentação
 *
 * @param int total Resultado da soma returnada por ::sum
 *
 * @return[out] char Ponteiro para a mensagem final de apresentação
 */
char *output(int total);

#endif
