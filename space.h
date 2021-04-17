/**
 * @brief It defines a space
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"
#include "link.h"
#define MAX_LINES 3

typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1


/**
 * @brief Crea un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param id Id del espacio a crear
 * @return Space*
 */
Space *space_create(Id id);

/**
 * @brief Destruye un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio a destruir
 * @return STATUS
 */
STATUS space_destroy(Space *space);

/**
 * @brief Devuelve la Id de un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @return Id
 */
Id space_get_id(Space *space);

/**
 * @brief Establece el nombre de un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @param name Nombre del espacio
 * @return STATUS
 */
STATUS space_set_name(Space *space, char *name);

/**
 * @brief Establece el nombre de un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @return const char *
 */
const char *space_get_name(Space *space);

/**
 * @brief Establece el norte de un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @param id Id del norte
 * @return STATUS
 */
STATUS space_set_north(Space *space, Link * link);

/**
 * @brief Devuelve el norte de un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @return Id
 */
Link * space_get_north(Space *space);

/**
 * @brief Establece el sur de un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @param id Id del sur
 * @return STATUS
 */
STATUS space_set_south(Space *space, Link * link);

/**
 * @brief Devuelve el sur de un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @return Id
 */
Link * space_get_south(Space *space);

/**
 * @brief Establece el este de un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @param id Id del este
 * @return STATUS
 */
STATUS space_set_east(Space *space, Link * link);

/**
 * @brief Devuelve el este de un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @return Id
 */
Link * space_get_east(Space *space);

/**
 * @brief Establece el oeste de un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @param id Id del oeste
 * @return STATUS
 */
STATUS space_set_west(Space *space, Link * link);

/**
 * @brief Devuelve el oeste de un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @return Id
 */
Link * space_get_west(Space *space);

/**
 * @brief Establece la id de un objeto
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @param id Id del objeto
 * @return STATUS
 */
STATUS space_add_object(Space *space, Id id);

/**
 * @brief Devuelve la Id del objeto
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @return Id
 */
Id space_get_object(Space *space, int x);

/**
 * @brief Imprime los datos de un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param space Espacio usado
 * @return STATUS
 */
STATUS space_print(Space *space);

/**
 * @brief Devuelve el número de objetos de un espacio
 *
 * @file space.c
 * @author Joseba Arranz
 * @version 1.0
 * @date 15/03/2021
 * @param s Espacio usado
 * @return int
 */
int space_number_of_objects(Space *s);
/**
 * @brief Devuelve la descripcion del espacio
 *
 * @file space.c
 * @author Joseba Arranz
 * @version 1.0
 * @date 15/03/2021
 * @param s Espacio usado
 * @return char
 */
char **space_get_gDesc(Space *space);
/**
 * @brief Establece la descripcion de un espacio
 *
 * @file space.c
 * @author Joseba Arranz
 * @version 1.0
 * @date 15/03/2021
 * @param space Espacio usado
 * @return STATUS
 */
STATUS space_set_gDesc(Space *space, char **gDesc);
/**
 * @brief Elimina un objeto de un espacio
 *
 * @file space.c
 * @author Joseba Arranz
 * @version 1.0
 * @date 12/04/2021
 * @param space Espacio usado
 * @param id id del objeto
 * @return STATUS
 */
STATUS space_del_object(Space *space, Id id);

/**
 * @brief Comprueba si dos espacios están conectados
 *
 * @file space.c
 * @author Álvaro Derecho y Joseba Arranz
 * @version 1.0
 * @date 16/04/2021
 * @param sp1 Espacio 1
 * @param sp2 Espacio 2
 * @return BOOL
 */
BOOL space_if_connected (Space *sp1, Space *sp2);
Set *space_get_objects(Space *s);
#endif
