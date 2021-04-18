/**
 * @brief Define un Objeto
 *
 * @file game.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"
#define Max_Objects 100
typedef struct _Object Object;

//funciones

/**
 * @brief Crea un objeto
 *
 * @file object.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param id Id del objeto
 * @return Object*
 */
Object *object_create(Id id);

/**
 * @brief Destruye un objeto
 *
 * @file object.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param object Objeto a destruir
 * @return STATUS
 */
STATUS object_destroy(Object *object);

/**
 * @brief Establece una Id a un objeto
 *
 * @file object.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param object Objecto usado
 * @param ide Id del objeto
 * @return STATUS
 */
STATUS object_set_id(Object *object, Id ide);

/**
 * @brief Establece el nombre de un objeto
 *
 * @file object.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param object Objeto usado
 * @param name Nombre del objeto
 * @return STATUS
 */
STATUS object_set_name(Object *object, char *name);

/**
 * @brief Establece la descripcion de un objeto
 *
 * @file object.c
 * @author Sergio Dominguez
 * @version 1.0
 * @date 17/04/2021
 * @param object Objeto usado
 * @param dscr Descripción del objeto
 * @return STATUS
 */
STATUS object_set_description(Object *object, char *dscr);
/**
 * @brief Devuelve la id de un objeto
 *
 * @file object.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param object Objecto usado
 * @return Id
 */
Id object_get_id(Object *object);

/**
 * @brief Devuelve la descripción de un objeto
 *
 * @file object.c
 * @author Sergio Dominguez
 * @version 1.0
 * @date 15/02/2021
 * @param object Objeto usado
 * @return const char *
 */
const char *object_get_description(Object *object);

/**
 * @brief Imprime los datos de un objeto
 *
 * @file object.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param object Objeto usado
 * @return STATUS
 */
STATUS object_print(Object *object);

/**
 * @brief Devuelve el nombre de un objeto
 *
 * @file object.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param object Objeto usado
 * @return const char *
 */
const char *object_get_name(Object *object);

#endif
