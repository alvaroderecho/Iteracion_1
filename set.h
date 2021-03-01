/**
 * @brief Define el Manejo de Conjuntos
 *
 * @author 2111_10
 * @file set.c
 * @version 1.0
 * @date 01-03-2021
 * @copyright GNU Public License
 */

#ifndef SET_H
#define SET_H

#include "types.h"

typedef struct _Set Set;

Set * set_create ();
STATUS set_destroy (Set * set);
STATUS set_add_values (Set* set, Id id);


#endif