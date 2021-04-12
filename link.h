/**
 * @brief Define el Manejo de Enlaces
 *
 * @author Álvaro Derecho
 * @file link.c
 * @version 1.0
 * @date 23-03-2021
 * @copyright GNU Public License
 */

#ifndef LINK_H
#define LINK_H

#include "types.h"

typedef struct _Link Link;


/**
 * @brief Crea un enlace
 *
 * @file link.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 23/03/2021
 * @param id Id del enlace
 * @return Link*
 */
Link * link_create(Id id);

/**
 * @brief Destruye un enlace
 *
 * @file link.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 23/03/2021
 * @param link Enlace a destruir
 * @return STATUS
 */
STATUS link_destroy(Link *link);

/**
 * @brief Establece el nombre de un enlace
 *
 * @file link.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 23/03/2021
 * @param link Enlace a modificar
 * @param name Nombre del enlace
 * @return STATUS
 */
STATUS link_set_name (Link *link, char * name);

/**
 * @brief Establece el id del espacio 1 de un enlace
 *
 * @file link.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 23/03/2021
 * @param link Enlace a modificar
 * @param id Id del primer espacio
 * @return STATUS
 */
STATUS link_set_sp1 (Link *link, Id id);

/**
 * @brief Establece el id del espacio 2 de un enlace
 *
 * @file link.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 23/03/2021
 * @param link Enlace a modificar
 * @param id Id del segundo espacio
 * @return STATUS
 */
STATUS link_set_sp2 (Link *link, Id id);

/**
 * @brief Cambia el estado de un enlace
 *
 * @file link.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 23/03/2021
 * @param link Enlace a modificar
 * @return STATUS
 */
STATUS link_change_state(Link *link);


/**
 * @brief Devuelve el Id de un enlace
 *
 * @file link.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 23/03/2021
 * @param link Enlace de interés
 * @return ID
 */
Id link_getId (const Link *link);


/**
 * @brief Devuelve el nombre de un enlace
 *
 * @file link.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 23/03/2021
 * @param link Enlace de interés
 * @return char*
 */
char * link_get_name (Link *link);

/**
 * @brief Devuelve el Id del espacio 1 de un enlace
 *
 * @file link.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 23/03/2021
 * @param link Enlace de interés
 * @return Id
 */
Id link_get_sp1 (const Link *link);

/**
 * @brief Devuelve el Id del espacio 2
 *
 * @file link.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 23/03/2021
 * @param link Enlace de interés
 * @return Id
 */
Id link_get_sp2 (const Link *link);

/**
 * @brief Devuelve el estado de un enlace
 *
 * @file link.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 23/03/2021
 * @param link Enlace de interés
 * @return BOOL
 */
BOOL link_get_state(const Link *link);


/**
 * @brief Imprime los datos de un enlace
 *
 * @file link.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 23/03/2021
 * @param link Enlace de interés
 * @return STATUS
 */
STATUS link_print(const Link *link);

#endif