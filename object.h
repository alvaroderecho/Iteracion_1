#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

//funciones

Object* create_object(Id id);
STATUS destroy_object(Object* object);
STATUS set_object_id(Object* object, Id ide);
STATUS set_object_name(Object* object, char* name);
Id get_object_id(Object* object);
STATUS object_print(Object* object);

#endif
