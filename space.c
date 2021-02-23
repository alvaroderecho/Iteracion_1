#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"

struct _Space {
  Id id;
  char name[WORD_SIZE + 1];
  Id north;
  Id south;
  Id east;
  Id west;
  Id object;
};

Space* space_create(Id id) {

  Space *newSpace = NULL; //puntero tipo Space a newSpace

  if (id == NO_ID) // == -1
    return NULL;

  newSpace = (Space *) malloc(sizeof (Space));

  if (newSpace == NULL) {
    return NULL; //Comprobación reserva memoria dinámica
  }
  newSpace->id = id; //ID del nuevo espacio

  newSpace->name[0] = '\0';

  newSpace->north = NO_ID; // == -1
  newSpace->south = NO_ID; // == -1
  newSpace->east = NO_ID; // == -1
  newSpace->west = NO_ID; // == -1

  newSpace->object = FALSE; // == 0

  return newSpace;
}

STATUS space_destroy(Space* space) {
  if (!space) { // == 0
    return ERROR; //no se puede eliminar
  }

  free(space); //libera memoria
  space = NULL;

  return OK; //eliminado correctamente
}

STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) { //si el nombre es 0, o el espacio
    return ERROR; //error
  }

  if (!strcpy(space->name, name)) { //cambia el nombre
    return ERROR; //no hay cambio si se llaman igual
  }

  return OK; //completado
}

STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
} //norte del espacio

STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}//sur del espacio

STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}//este del espacio

STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}//oeste del espacio

STATUS space_set_object(Space* space, Id id) {
  if (!space) {
    return ERROR;
  }
  space->object = id;
  return OK;
} //establecer un objeto

const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
} //solicitar nombre

Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}//solicitar ID

Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}//solicitar norte

Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}//solicitar sur

Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}//solicitar este

Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}//solicitar oeste

Id space_get_object(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->object;
}//solicitar objeto

STATUS space_print(Space* space) {
  Id idaux = NO_ID;

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
  //Muestra ID y nombre del espacio

  idaux = space_get_north(space);
  if (NO_ID != idaux) { //implica norte diferente a -1
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);
  if (NO_ID != idaux) {//implica sur diferente a -1
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);
  if (NO_ID != idaux) {//implica este diferente a -1
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);
  if (NO_ID != idaux) {//implica oeste diferente a -1
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  if (space_get_object(space)) { //objeto diferente a 0
    fprintf(stdout, "---> Object in the space.\n");
  } else {
    fprintf(stdout, "---> No object in the space.\n");
  }

  return OK;
} //Pasar todo por pantalla
