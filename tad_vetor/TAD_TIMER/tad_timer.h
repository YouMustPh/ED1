#ifndef TAD_TIMER
#define TAD_TIMER

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

/*******************************************************************
*  DADOS
*******************************************************************/
typedef struct timer Timer;

/*******************************************************************
*  OPERACOES
*******************************************************************/

/**
 * Cria um timer
 */
Timer* timer_criar();

/**
 * Destroi um timer
 */
void timer_desalocar(Timer** t);

/**
 * Inicia o timer
 */
bool timer_start(Timer* t);

/**
 * Para o timer
 */
bool timer_stop(Timer* t);

/**
 * Reinicia o timer
 */
bool timer_reset(Timer* t);

/**
 * Devolve o resultado.
 * Caso o timer ainda não tenha finalizado devolve -1
 */
double timer_resultado(Timer* t);

#endif