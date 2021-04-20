#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"

struct _Space
{
  Id id;                    //Id del espacio
  char name[WORD_SIZE + 1]; //nombre del espacio
  Link *north;              //link norte
  Link *south;              //link sur
  Link *east;               //link este
  Link *west;               //link oeste
  Set *objects;             //puntero a conjunto de objetos
  char **gDesc;             //doble puntero a descripción gráfica del espacio
  char description[WORD_SIZE + 1]; //descripción del espacio
  BOOL illuminated; //espacio iluminado
};

Space *space_create(Id id)
{
  Space *newSpace = NULL; //puntero tipo Space a newSpace

  if (id == NO_ID) // == -1
    return NULL;

  newSpace = (Space *)malloc(sizeof(Space));

  if (newSpace == NULL)
  {
    return NULL; //Comprobación reserva memoria dinámica
  }
  newSpace->id = id; //ID del nuevo espacio

  newSpace->name[0] = '\0';

  newSpace->north = NULL;
  newSpace->south = NULL;
  newSpace->east = NULL;
  newSpace->west = NULL;

  newSpace->illuminated = TRUE;

  newSpace->objects = set_create();

  newSpace->description[0] = '\0';

  if ((newSpace->gDesc = (char **)malloc(3 * sizeof(char *))) == NULL)
    return NULL; //tres filas
  if ((newSpace->gDesc[0] = (char *)malloc(9 * sizeof(char))) == NULL)
    return NULL; //primera fila
  if ((newSpace->gDesc[1] = (char *)malloc(9 * sizeof(char))) == NULL)
    return NULL; //segunda fila
  if ((newSpace->gDesc[2] = (char *)malloc(9 * sizeof(char))) == NULL)
    return NULL; //tercera fila

  return newSpace;
}

STATUS space_destroy(Space *space)
{
  int i;
  if (!space)
  {               // == 0
    return ERROR; //no se puede eliminar
  }
  for (i = 0; i < MAX_LINES; i++)
  {
    free(space->gDesc[i]);
  }
  free(space->gDesc);

  set_destroy(space->objects);

  free(space); //libera memoria
  space = NULL;

  return OK; //eliminado correctamente
}

STATUS space_set_name(Space *space, char *name)
{
  if (!space || !name)
  {               //si el nombre es 0, o el espacio
    return ERROR; //error
  }

  if (!strcpy(space->name, name))
  {               //cambia el nombre
    return ERROR; //no hay cambio si se llaman igual
  }

  return OK; //completado
}

STATUS space_set_description(Space *space, char *dscr)
{
  if (!space || !dscr)
  {               //si la descripcion es 0, o el espacio
    return ERROR; //error
  }

  if (!strcpy(space->description, dscr))
  {               //cambia la descripcion
    return ERROR; //no hay cambio si se llaman igual
  }

  return OK; //completado
}

STATUS space_set_north(Space *space, Link *link)
{
  if (!space || !link)
  {
    return ERROR;
  }
  space->north = link;
  return OK;
} //norte del espacio

STATUS space_set_south(Space *space, Link *link)
{
  if (!space || !link)
  {
    return ERROR;
  }
  space->south = link;
  return OK;
} //sur del espacio

STATUS space_set_east(Space *space, Link *link)
{
  if (!space || !link)
  {
    return ERROR;
  }
  space->east = link;
  return OK;
} //este del espacio

STATUS space_set_west(Space *space, Link *link)
{
  if (!space || !link)
  {
    return ERROR;
  }
  space->west = link;
  return OK;
} //oeste del espacio

STATUS space_add_object(Space *space, Id id)
{
  if (!space)
  {
    return ERROR;
  }

  if (set_add_values(space->objects, id) == ERROR)
    return ERROR;
  return OK;
} //establecer un objeto

STATUS space_del_object(Space *space, Id id)
{
  if (!space)
  {
    return ERROR;
  }

  if (set_del_values(space->objects, id) == ERROR)
    return ERROR;
  return OK;
}

const char *space_get_name(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->name;
} //solicitar nombre

const char *space_get_description(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->description;
} //solicitar nombre

Id space_get_id(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->id;
} //solicitar ID

Link *space_get_north(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->north;
} //solicitar norte

Link *space_get_south(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->south;
} //solicitar sur

Link *space_get_east(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->east;
} //solicitar este

Link *space_get_west(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->west;
} //solicitar oeste

Id space_get_object(Space *space, int x)
{
  Id *ids;
  if (!space)
  {
    return NO_ID;
  }
  ids = set_get_ids(space->objects);

  return ids[x];
} //solicitar objeto

char **space_get_gDesc(Space *space)
{
  if (space == NULL)
    return NULL;
  return space->gDesc;
}

STATUS space_set_gDesc(Space *space, char **desc)
{
  int i;
  if (space == NULL)
    return ERROR;
  for (i = 0; i < MAX_LINES; i++)
    strcpy(space->gDesc[i], desc[i]);

  return OK;
}

STATUS space_print(Space *space)
{
  Link *link = NULL;
  int i;
  if (!space)
  {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);
  //Muestra ID y nombre del espacio

  link = space_get_north(space);
  if (NULL != link)
  { //implica norte diferente a -1
    fprintf(stdout, "---> North link: %ld.\n", link_getId(link));
  }
  else
  {
    fprintf(stdout, "---> No north link.\n");
  }

  link = space_get_south(space);
  if (NULL != link)
  { //implica sur diferente a -1
    fprintf(stdout, "---> South link: %ld.\n", link_getId(link));
  }
  else
  {
    fprintf(stdout, "---> No south link.\n");
  }

  link = space_get_east(space);
  if (NULL != link)
  { //implica este diferente a -1
    fprintf(stdout, "---> East link: %ld.\n", link_getId(link));
  }
  else
  {
    fprintf(stdout, "---> No east link.\n");
  }

  link = space_get_west(space);
  if (NULL != link)
  { //implica oeste diferente a -1
    fprintf(stdout, "---> West link: %ld.\n", link_getId(link));
  }
  else
  {
    fprintf(stdout, "---> No west link.\n");
  }

  if (space_number_of_objects(space) > 0)
  { //objeto diferente a 0
    fprintf(stdout, "---> %d object(s) in the space.\n", space_number_of_objects(space));
  }
  else
  {
    fprintf(stdout, "---> No object in the space.\n");
  }
  for (i = 0; i < MAX_LINES; i++)
    fprintf(stdout, "%s\n", space->gDesc[i]);

  fprintf(stdout, "Iluminado(1) / Apagado(0): %d\n", space->illuminated);
  return OK;
} //Pasar todo por pantalla
int space_number_of_objects(Space *s)
{
  int i;

  if (s == NULL)
    return 0;

  if ((i = set_get_numids(s->objects)) > 0)
    return i;

  return 0;
}

BOOL space_if_connected(Space *sp1, Space *sp2)
{

  if (link_getId(space_get_north(sp2)) == link_getId(space_get_south(sp1)))
    return TRUE;

  else if (link_getId(space_get_east(sp1)) == link_getId(space_get_west(sp2)))
    return TRUE;

  return FALSE;
}
Set *space_get_objects(Space *s){
  if (s == NULL) return NULL;
  return s->objects;
}


BOOL space_get_illuminate (Space *s) {
  if (!s) return FALSE;

  return s->illuminated;
}

STATUS space_set_illuminate (Space *s, BOOL st) {
  if (!s) return ERROR;

  s->illuminated = st;

  return OK;
}