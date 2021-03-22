/**
 * @brief Define el Manejo de Conjuntos
 *
 * @author Álvaro Derecho
 * @file set.c
 * @version 1.0
 * @date 01-03-2021
 * @copyright GNU Public License
 */

#ifndef SET_H
#define SET_H

#include "types.h"

typedef struct _Set Set;

/**
 * @brief Crea un set de objetos
 *
 * @file set.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 07/03/2021
 * @return Set*
 */
Set * set_create ();

/**
 * @brief Destruye un set de objetos
 *
 * @file set.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 07/03/2021
 * @param Set set a destruir
 * @return STATUS
 */
STATUS set_destroy (Set * set);

/**
 * @brief Añade un objeto a un set
 *
 * @file set.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 07/03/2021
 * @param Set set a modificar
 * @param id Id del objeto a añadir
 * @return STATUS
 */
STATUS set_add_values (Set* set, Id id);

/**
 * @brief Elimina un objeto a un set
 *
 * @file set.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 07/03/2021
 * @param Set set a modificar
 * @param id Id del objeto a eliminar
 * @return STATUS
 */
STATUS set_del_values (Set* set, Id id);

/**
 * @brief Imprime los datos de un set
 *
 * @file set.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 07/03/2021
 * @param Set set a imprimir
 * @return STATUS
 */
STATUS set_print(Set* set);

/**
 * @brief Devuelve las Ids de los objetos de un set
 *
 * @file set.c
 * @author Joseba Arranz
 * @version 1.0
 * @date 11/03/2021
 * @param Set set a usar
 * @return *Id
 */
Id * set_get_ids(Set* set);

/**
 * @brief Devuelve el número de objetos de un set
 *
 * @file set.c
 * @author Joseba Arranz
 * @version 1.0
 * @date 11/03/2021
 * @param Set set a usar
 * @return int
 */
int set_get_numids(Set* set);

#endif