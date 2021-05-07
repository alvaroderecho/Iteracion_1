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
    char description[WORD_SIZE + 1]; //Descripcion del objeto
    BOOL movable;
    Id dependency;
    Id open;
    BOOL illuminate;
    BOOL turnedon;
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
    new_object->description[0] = '\0';
    new_object->movable = FALSE;
    new_object->dependency = NO_ID;
    new_object->open = NO_ID;
    new_object->illuminate = FALSE;
    new_object->turnedon = FALSE;

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

STATUS object_set_description(Object *object, char *dscr)
{
    if (!object || !dscr)
        return ERROR;
    if (!strcpy(object->description, dscr)) //cambia la descripcion
        return ERROR;                //no hay cambia si es el la misma descripcion

    return OK; //descripcion cambiado
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

const char *object_get_description(Object *object)
{
    if (!object)
        return NULL;
    return object->description;
}

STATUS object_print(Object *object)
{
    if (!object)
        return ERROR;
    fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);
    //Muestra Id y nombre
    return OK;
}

STATUS object_set_dependency (Object *object, Id id_dependency){
    if (object == NULL) return ERROR;

    object->dependency = id_dependency;

    return OK;
}
STATUS object_set_open (Object *object, Id link){
    if (object == NULL) return ERROR;

    object->open = link;

    return OK;

}
STATUS object_set_ilumninate(Object *object, BOOL il){
    if (object == NULL) return ERROR;

    object->illuminate = il;

    return OK;

}
STATUS object_set_turnedon (Object *object , BOOL il){
    if (object == NULL) return ERROR;
    if (object->illuminate == FALSE) return ERROR;
    object->turnedon = il;

    return OK;
}
BOOL object_can_iluminate (Object *object){
    if (object == NULL) return FALSE;

    return object->illuminate;
}
BOOL object_is_on(Object *object){
    if (object == NULL) return FALSE;
    return object->turnedon;
}
Id object_get_dependency(Object *object){
    if (object == NULL) return NO_ID;
    return object->dependency;
}
Id object_get_open(Object *object){
    if (object == NULL) return NO_ID;
    return object->open;
}
BOOL object_is_movable(Object *object)
{
    if (object == NULL) return FALSE;

    return object->movable;
}