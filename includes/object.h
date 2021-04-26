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
/**
 * @brief Establece la dependencia del objeto
 *
 * @file object.c
 * @author Joseba Arranz 
 * @version 1.0
 * @date 26/04/2021
 * @param object Objeto usado
 * @param id_dependency id del objecto que depende
 * @return STATUS
 */
STATUS object_set_dependency (Object *object, Id id_dependency);
/**
 * @brief Establece la id del link que puede abrir un objeto
 *
 * @file object.c
 * @author Joseba Arranz 
 * @version 1.0
 * @date 26/04/2021
 * @param object Objeto usado
 * @param link id del objecto que puede abrir
 * @return STATUS
 */
STATUS object_set_open (Object *object, Id link);
/**
 * @brief Establece si un objecto puede iluminar un espacio
 *
 * @file object.c
 * @author Joseba Arranz 
 * @version 1.0
 * @date 26/04/2021
 * @param object Objeto usado
 * @param il indica si puede iluminar o no
 * @return STATUS
 */
STATUS object_set_ilumninate(Object *object, BOOL il);
/**
 * @brief Establece si un objecto que puede ilumiar esta encendido o no
 *
 * @file object.c
 * @author Joseba Arranz 
 * @version 1.0
 * @date 26/04/2021
 * @param object Objeto usado
 * @param il indica si está encendido o no
 * @return STATUS
 */
STATUS object_set_turnedon (Object *object , BOOL il);
/**
 * @brief Establece si un objecto que puede ilumiar esta encendido o no
 *
 * @file object.c
 * @author Joseba Arranz 
 * @version 1.0
 * @date 26/04/2021
 * @param object Objeto usado
 * @return BOOL
 */
BOOL object_can_iluminate (Object *object);
/**
 * @brief devuelve si un objecto esta encendido o no 
 *
 * @file object.c
 * @author Joseba Arranz 
 * @version 1.0
 * @date 26/04/2021
 * @param object Objeto usado
 * @return BOOL
 */
BOOL object_is_on(Object *object);
/**
 * @brief devuelve el id del objeto del que depende
 *
 * @file object.c
 * @author Joseba Arranz 
 * @version 1.0
 * @date 26/04/2021
 * @param object Objeto usado
 * @return Id  
 */
Id object_get_dependency(Object *object);
/**
 * @brief devuelve el id del link que puede abrir
 *
 * @file object.c
 * @author Joseba Arranz 
 * @version 1.0
 * @date 26/04/2021
 * @param object Objeto usado
 * @return Id 
 */
Id object_get_open(Object *object);


#endif
