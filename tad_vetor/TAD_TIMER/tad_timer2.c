#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "tad_timer.h"

struct timer
{
  clock_t start;
  clock_t end;
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
  t->start = clock();
  return true;
};

bool timer_stop(Timer *t)
{
  if (t == NULL)
    return false;
  t->end = clock();
  return true;
};

bool timer_reset(Timer *t)
{
  if (t == NULL)
    return false;
  t->start = 0;
  t->end = 0;
  return true;
};

double timer_resultado(Timer *t)
{
  if (t == NULL || t->end == 0)
    return -1;
  return ((t->end - t->start) / CLOCKS_PER_SEC);
};
