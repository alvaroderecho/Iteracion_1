#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "die.h"


struct _Die
{
  Id id;
  int min;
  int max;
  int last_throw;

};

Die *die_create(Id id, int min, int max){
  Die *d = NULL;

  if (id < 0 || min < 0 || max < 0){
    return NULL;
  }

  d = (Die*)malloc(sizeof(Die));
  if (d == NULL){
    return NULL;
  }
  d->id = id;
  d->min = min;
  d->max = max;
  d->last_throw = -1;

  return d;
}

STATUS die_destroy(Die *d){
  if (d == NULL){
    return ERROR;
  }
  free(d);
  return OK;
}

Id die_getId (Die *d){
  if (d == NULL){
    return -1;
  }
  return d->id;
}

int die_getLastThrow (Die *d){
  if (d == NULL){
    return -1;
  }
  return d->last_throw;
}

STATUS die_roll (Die *d){
  if (d == NULL){
    return ERROR;
  }
  srand (time(NULL));
  d->last_throw = (rand() % ((d->max - d->min) + 1)) + 1;

  return OK;
}

STATUS die_print (Die *d){
  if (d == NULL){
    fprintf(stdout, "Error en el argumento. \n");
    return ERROR;
  }

  fprintf(stdout, "--> Dado (Id: %ld; Min: %d; Max: %d; Última tirada: %d \n", d->id, d->min, d->max, d->last_throw);
  return OK;
}
