/**
 * @brief Define Las estructuras y funciones de los objetos
 *
 * @file object.h
 * @author 2111_10
 * @version 1.0
 * @date 15-02-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

struct _Object
{
    Id id;                       //Id del objeto
    char name[WORD_SIZE + 1];    //Nombre del objeto
};

Object *object_create(Id id)
{ //creación de objeto
    Object *new_object = NULL;

    if (id == NO_ID)
        return NULL;

    new_object = (Object *)malloc(sizeof(Object));

    if (new_object == NULL)
    {
        return NULL;
    }

    new_object->id = id;
    new_object->name[0] = '\0';

    return new_object;
}

STATUS object_destroy(Object *object)
{                //eliminar un objeto
    if (!object) // == 0
        return ERROR;

    free(object); //libera memoria
    object = NULL;
    return OK;
}

STATUS object_set_id(Object *object, Id ide)
{
    if (!object || ide == NO_ID)
        return ERROR;
    object->id = ide;
    return OK;
} //Modificar la ID

STATUS object_set_name(Object *object, char *name)
{
    if (!object || !name)
        return ERROR;
    if (!strcpy(object->name, name)) //cambia el nombre
        return ERROR;                //no hay cambia si es el mismo nombre

    return OK; //nombre cambiado
}

Id object_get_id(Object *object)
{
    if (!object)
        return NO_ID;
    return object->id;
} //solicitar ID

const char *object_get_name(Object *object)
{
    if (!object)
        return NULL;
    return object->name;
} //solicitar nombre

STATUS object_print(Object *object)
{
    if (!object)
        return ERROR;
    fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);
    //Muestra Id y nombre
    return OK;
}
