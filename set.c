/**
 * @brief Define el Manejo de Conjuntos
 *
 * @author Álvaro Derecho
 * @version 1.0
 * @date 01-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "set.h"

#define MAX_ID 32

struct _Set {
    Id id[MAX_ID];              //Conjunto de Ids de objetos
    int num_id;                 //Número de Ids
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
    return new_set;
}

STATUS set_destroy (Set * set) {
    if (!set) return ERROR;
    free(set);
    set = NULL;
    return OK;
}

STATUS set_add_values (Set* set, Id id) {

    int i;

    if (!set || set->num_id == MAX_ID) return ERROR;

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
    Id flag;

    if (!set || set->num_id == 0) return ERROR;

    for (i=0;i<set->num_id;i++) {
        if (set->id[i] == id) { //i == posición del ID
            
            set->id[i] = NO_ID;
            
        
            flag = set->id[set->num_id -1];
            set->id[i] = flag;
            set->id[set->num_id] = NO_ID;
            set->num_id--;
            return OK;
        }
            
    }
    return ERROR;

}

STATUS set_print(Set* set) {
    int i;
    
    if (!set) return ERROR;

    fprintf(stdout,"Set of %d Id(s): ",set->num_id);
    for (i=0;i<set->num_id;i++) {
        if (set->id[i]!= NO_ID)
        fprintf(stdout,"%ld ",set->id[i]);        
    }

    return OK;
}
Id * set_get_ids(Set* set){
    if (set == NULL) return NULL;
    return set->id;

}
int set_get_numids(Set* set){
    if (set == NULL) return 0;
    return set->num_id;
}
BOOL set_containsId(Set *set, Id id){
  int i = 0;
  if (!set || id == NO_ID){
    return FALSE;
  }
  for (i = 0; i < set->num_id; i++){
    if (set->id[i] == id){
      return TRUE;
    }
  }

  return FALSE;
}