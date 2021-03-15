/**
 * @brief Define el dado del juego
 *
 * @author 2111_10
 * @file die.c
 * @version 1.0
 * @date 07-03-2021
 * @copyright GNU Public License
 */

#ifndef DIE_H
#define DIE_H

#include "types.h"

typedef struct _Die Die;


 Die * die_create (Id id, int min, int max);
 STATUS die_destroy (Die *d);
 Id die_getId (Die *d);
 int die_getLastThrow (Die *d);
 STATUS die_roll (Die *d);
 STATUS die_print (Die *d);
#endif
