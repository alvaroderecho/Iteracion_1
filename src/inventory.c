/**
 * @brief Define el inventario del jugador
 *
 * @author Sergio Domínguez
 * @version 1.0
 * @date 23-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"

struct _Inventory{
  Set *ids;          //Conjunto de ids
  int max_inv;      //Tamaño maximo del inventario
};

 Inventory * inventory_create (int max){
   Inventory *i;
   if (max <= 0){
     return NULL;
   }
   i = (Inventory*)malloc(sizeof(Inventory));
   if (i == NULL){
     return NULL;
   }
   i->ids = set_create();
   i->max_inv = max;
   return i;
 }

 STATUS inventory_destroy (Inventory *i){
   if (i == NULL){
     return ERROR;
   }
   if (set_destroy(i->ids) == ERROR){
     return ERROR;
   }
   free(i);
   return OK;
 }

  Id * inventory_getIds (Inventory *i){
    if (i == NULL){
      return NULL;
    }
    return set_get_ids(i->ids);
  }

  int inventory_getMaxInv (Inventory *i){
    if (i == NULL){
      return 0;
    }
    return i->max_inv;
  }

  STATUS inventory_addId (Inventory *i, Id id){
    if (i == NULL || id == NO_ID){
      return ERROR;
    }
    if (inventory_getMaxInv(i) == set_get_numids(i->ids)){
      return ERROR;
    }
    if (set_add_values(i->ids, id) == ERROR){
      return ERROR;
    }
    return OK;
  }

  STATUS inventory_delId (Inventory *i, Id id){
    if (i == NULL || id == NO_ID){
      return ERROR;
    }
    if (set_del_values(i->ids, id) == ERROR){
      return ERROR;
    }
    return OK;
  }

  STATUS inventory_setMaxInv (Inventory *i, int max){
    if (i == NULL || max < 0){
      return ERROR;
    }
    i->max_inv = max;
    return OK;
  }

  int inventory_getNumids(Inventory *i){
    if (!i){
      return -1;
    }
    return set_get_numids(i->ids);
  }

  BOOL inventory_containsObject(Inventory *i, Id id){
    if (!i || id == NO_ID){
      return FALSE;
    }
    return set_containsId(i->ids, id);
  }

  STATUS inventory_print (Inventory *i){
    if (i == NULL){
      return ERROR;
    }
    fprintf(stdout, "Objetos en la mochila del jugador: \t");
    set_print(i->ids);
    fprintf(stdout, "\n");
    fprintf(stdout, "Tamaño máximo del inventario: %d \n", i->max_inv);
    return OK;
  }
    BOOL inventory_isEmpty(Inventory *i){
    if (!i){
      return TRUE;
    }
    if (inventory_getNumids(i) == 0){
      return TRUE;
    }

    return FALSE;
  }

  Set * inventory_get_Set(Inventory *i) {
    if (!i) return NULL;

    if (!i->ids) return NULL;

    return i->ids;
  }
