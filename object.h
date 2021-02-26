#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

//funciones

Object* object_create(Id id);
STATUS object_destroy(Object* object);
STATUS object_set_id(Object* object, Id ide);
STATUS object_set_name(Object* object, char* name);
Id object_get_id(Object* object);
STATUS object_print(Object* object);
const char * object_get_name (Object * object);

#endif
