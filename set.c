/**
 * @brief Define el Manejo de Conjuntos
 *
 * @author 2111_10
 * @version 1.0
 * @date 01-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "set.h"

#define MAX_ID 32

typedef struct _Set {
    Id * id[MAX_ID];
    int num_id;
};

Set * set_create () {
    
}