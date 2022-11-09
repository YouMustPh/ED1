#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "tad_timer.h"

struct timer
{
  time_t start;
  time_t end;
};

Timer *timer_criar()
{
  Timer *timer = calloc(1, sizeof(Timer));
  timer->end = 0;
  timer->start = 0;
  return timer;
};

void timer_desalocar(Timer **t)
{
  free(*t);
  *t = NULL;
};

bool timer_start(Timer *t)
{
  if (t == NULL)
    return false;
  time(&t->start);
  return true;
};

bool timer_stop(Timer* t){
  if (t == NULL)
    return false;
  time(&t->end);
  return true;
};

bool timer_reset(Timer* t){
  if (t == NULL ) return false; 
  t->start = 0;
  t->end = 0;
  return true;
};

double timer_resultado(Timer* t){
  if (t == NULL || t->end == 0) return -1;
  return (t->end - t->start);
};
