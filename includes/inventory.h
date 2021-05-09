/**
 * @brief Define el inventario del jugador
 *
 * @author Sergio Domínguez
 * @file inventory.c
 * @version 1.0
 * @date 23-03-2021
 * @copyright GNU Public License
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"
#include "set.h"

typedef struct _Inventory Inventory;

/**
 * @brief Crea el inventario
 *
 * @author Sergio Domínguez
 * @file inventory.c
 * @version 1.0
 * @date 23-03-2021
 * @param max Valor máximo del inventario
 * @return puntero al inventario
 */
 Inventory * inventory_create (int max);

 /**
 * @brief Destruye el inventario
 *
 * @author Sergio Domínguez
 * @file inventory.c
 * @version 1.0
 * @date 23-03-2021
 * @param d Inventario a destruir
 * @return OK si no hay fallo y ERROR en caso de fallo.
 */
 STATUS inventory_destroy (Inventory *i);

 /**
 * @brief Devuelve el array de ids del inventario
 *
 * @author Sergio Domínguez
 * @file inventory.c
 * @version 1.0
 * @date 23-03-2021
 * @param d Inventario a usar
 * @return Id
 */
 Id * inventory_getIds (Inventory *i);

 /**
 * @brief Devuelve el tamaño del inventario
 *
 * @author Sergio Domínguez
 * @file inventory.c
 * @version 1.0
 * @date 23-03-2021
 * @param d Inventario a usar
 * @return int
 */
 int inventory_getMaxInv (Inventory *i);

  /**
 * @brief Añade un objeto al inventario
 *
 * @author Sergio Domínguez
 * @file inventory.c
 * @version 1.0
 * @date 23-03-2021
 * @param d Inventario a usar
 * @return STATUS
 */
 STATUS inventory_addId (Inventory *i, Id id);

 /**
 * @brief Elimina un objeto del inventario
 *
 * @author Sergio Domínguez
 * @file inventory.c
 * @version 1.0
 * @date 07-03-2021
 * @param d Inventario a usar
 * @return STATUS
 */
 STATUS inventory_delId (Inventory *i, Id id);

 /**
* @brief Actualiza el tamaño del inventario
*
* @author Sergio Domínguez
* @file inventory.c
* @version 1.0
* @date 23-03-2021
* @param d Inventario a usar
* @return STATUS
*/
STATUS inventory_setMaxInv (Inventory *i, int max);

/**
* @brief Devuelve el numero de ids en el inventario
*
* @author Sergio Domínguez
* @file inventory.c
* @version 1.0
* @date 23-03-2021
* @param d Inventario a usar
* @return int
*/
int inventory_getNumids(Inventory *i);

/**
 * @brief Devuelve True si el inventario contiene el id, en otro caso o caso de error devuelve False
 *
 * @file inventory.c
 * @author Sergio Domínguez
 * @version 1.0
 * @date 17/04/2021
 * @param Inventory Inventario a usar
 * @param Id a buscar
 * @return Bool
 */
BOOL inventory_containsObject(Inventory *i, Id id);

  /**
 * @brief Imprime los datos del inventario
 *
 * @author Sergio Domínguez
 * @file inventory.c
 * @version 1.0
 * @date 23-03-2021
 * @param i Inventario a usar
 * @return STATUS
 */
 STATUS inventory_print (Inventory *i);
/**
 * @brief comprueba si el inventory está vacio
 *
 * @author Sergio Domínguez
 * @file inventory.c
 * @version 1.0
 * @date 23-03-2021
 * @param i Inventario a usar
 * @return STATUS
 */
 BOOL inventory_isEmpty(Inventory *i);

/**
 * @brief Devuelve el Set de Ids
 *
 * @author Álvaro Derecho
 * @file inventory.c
 * @version 1.0
 * @date 09/08/2021
 * @param i Inventario a usar
 * @return Set
 */
Set * inventory_get_Set(Inventory *i);

#endif
