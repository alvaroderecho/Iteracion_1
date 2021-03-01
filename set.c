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

Set * set_create () { //creación de set
    int i;
    Set *new_set = NULL;

    new_set = (Set * )malloc(sizeof(Set));

    if (new_set == NULL) return NULL;

    for (i=0;i<MAX_ID;i++) {
        new_set->id[i] = NO_ID;
    }
    new_set->num_id = 0;
}

STATUS set_destroy (Set * set) {
    if (!set) return ERROR;
    free(set);
    set = NULL;
    return OK;
}

STATUS set_add_values (Set* set, Id id) {

    int i;

    if (!set || set->num_id == MAX_ID || id == NULL) return ERROR;

    for (i=0;i<set->num_id;i++) { //comprobación el valor no se repite
        if (set->id[i] == id)
            return ERROR;
    }

    set->id[set->num_id] = id;
    set->num_id++;
    return OK;

}

STATUS set_del_values (Set* set, Id id) {
    int i;

    if (!set || set->num_id == 0) return ERROR;

    for (i=0;i<set->num_id;i++) {
        if (set->id[i] == id) { //i == posición del ID
            
            set->id[i] = NO_ID;
            if (i = set->num_id - 1) return OK;
        
            set->id[i] = set->id[set->num_id];
            set->id[set->num_id] = NO_ID;

            return OK;
        }
            
    }
    return ERROR;

}