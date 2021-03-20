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

typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1
#define Max_lenght_string 8
#define Num_strings 3

/**
 * @brief Crea un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param id Id del espacio a crear
 * @return Space*
 */
Space *space_create(Id id);

/**
 * @brief Destruye un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio a destruir
 * @return STATUS
 */
STATUS space_destroy(Space *space);

/**
 * @brief Devuelve la Id de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @return Id
 */
Id space_get_id(Space *space);

/**
 * @brief Establece el nombre de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @param name Nombre del espacio
 * @return STATUS
 */
STATUS space_set_name(Space *space, char *name);

/**
 * @brief Establece el nombre de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @return const char *
 */
const char *space_get_name(Space *space);

/**
 * @brief Establece el norte de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @param id Id del norte
 * @return STATUS
 */
STATUS space_set_north(Space *space, Id id);

/**
 * @brief Devuelve el norte de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @return Id
 */
Id space_get_north(Space *space);

/**
 * @brief Establece el sur de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @param id Id del sur
 * @return STATUS
 */
STATUS space_set_south(Space *space, Id id);

/**
 * @brief Devuelve el sur de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @return Id
 */
Id space_get_south(Space *space);

/**
 * @brief Establece el este de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @param id Id del este
 * @return STATUS
 */
STATUS space_set_east(Space *space, Id id);

/**
 * @brief Devuelve el este de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @return Id
 */
Id space_get_east(Space *space);

/**
 * @brief Establece el oeste de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @param id Id del oeste
 * @return STATUS
 */
STATUS space_set_west(Space *space, Id id);

/**
 * @brief Devuelve el oeste de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @return Id
 */
Id space_get_west(Space *space);

/**
 * @brief Establece la id de un objeto
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @param id Id del objeto
 * @return STATUS
 */
STATUS space_set_object(Space *space, Id id);

/**
 * @brief Devuelve la Id del objeto
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @return Id
 */
Id space_get_object(Space *space, int x);

/**
 * @brief Imprime los datos de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param space Espacio usado
 * @return STATUS
 */
STATUS space_print(Space *space);

/**
 * @brief Devuelve el número de objetos de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param s Espacio usado
 * @return int
 */
int space_number_of_objects(Space *s);
/**
 * @brief Devuelve la descripcion del espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param s Espacio usado
 * @return char
 */
char **space_get_gDesc(Space *space);
/**
 * @brief Establece la descripcion de un espacio
 *
 * @file space.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param s Espacio usado
 * @return STATUS
 */
STATUS space_set_gDesc(Space *space, char gDesc[Num_strings][Max_lenght_string]);
#endif
