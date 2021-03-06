/**
 * @brief It implements the game interface and all the associated callbacks
 * for each command
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

#define N_CALLBACK 10

struct _Game
{
  Player *player;             //Puntero al jugador del juego
  Object *objects[OBJECTS];   //Puntero al objeto
  Link *links[LINKS];         //Puntero a los enlaces
  Space *spaces[MAX_SPACES];  //Espacios de un juego
  T_Command last_cmd;         //Último comando escrito por pantalla
  Die *die;                   //Dado usado en el juego
  char last_detail_descr[WORD_SIZE]; //Última descripción detallada

  BOOL game_over;             //Final de partida
};

/**
   Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game *game, char *arg);

/**
   List of callbacks for each command in the game
*/
void game_callback_unknown(Game *game, char *arg);
void game_callback_exit(Game *game, char *arg);
void game_callback_take(Game *game, char *arg);
void game_callback_drop(Game *game, char *arg);
void game_callback_roll(Game *game, char *arg);
void game_callback_move(Game *game, char *arg);
void game_callback_inspect(Game *game, char *arg);
void game_callback_open(Game *game, char *arg);
void game_callback_turnon(Game *game, char *arg);
void game_callback_turnoff(Game *game, char *arg);

static callback_fn game_callback_fn_list[N_CALLBACK] = {
    game_callback_unknown,
    game_callback_exit,
    game_callback_take,
    game_callback_drop,
    game_callback_roll,
    game_callback_move,
    game_callback_inspect,
    game_callback_open,
    game_callback_turnon,
    game_callback_turnoff};

/**
   Private functions
*/

STATUS game_add_space(Game *game, Space *space);
Id game_get_space_id_at(Game *game, int position);
STATUS game_player_set_location(Game *game, Id id);
STATUS game_set_object_location(Game *game, Id id, Id id2);

/**
   Game interface implementation
*/

STATUS game_player_set_location(Game *game, Id id)
{

  if (!game || id == NO_ID)
  {
    return ERROR;
  }

  return player_set_location(game_get_player(game), id);
}

Game *game_init()
{
  Game *game = NULL;

  if ((game = (Game *)malloc(sizeof(Game))) == NULL)
    return NULL;
  return game;
}

STATUS game_set_object_location(Game *game, Id id, Id id2)
{

  //int i = 0;
  if (game == NULL)
  {
    return ERROR;
  }
  if (id == NO_ID)
  {
    return ERROR;
  }

  if (space_add_object(game_get_space(game, id), object_get_id(game_get_object(game, id2))) == ERROR)
    return ERROR;

  return OK;
}

int game_num_o(Game *game)
{
  int i = 0;
  while (game->objects[i] != NULL)
    i++;
  return i;
}

STATUS game_create(Game *game)
{

  int i;
  for (i = 0; i <= MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }

  for (i = 0; i < OBJECTS; i++)
  {
    game->objects[i] = NULL;
  }

  for (i = 0; i < LINKS; i++)
  {
    game->links[i] = NULL;
  }

  game->player = NULL;

  game->last_cmd = NO_CMD;

  game->die = die_create(1, 1, 6);
  
  game->last_detail_descr[0] = '\0';

  game->game_over = FALSE;

  return OK;
}

STATUS game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++)
  {
    space_destroy(game->spaces[i]);
  }
  for (i = 0; (i < OBJECTS) && (game->objects[i] != NULL); i++)
  {
    object_destroy(game->objects[i]);
  }

  for (i = 0; (i < LINKS) && (game->links[i] != NULL); i++)
  {
    link_destroy(game->links[i]);
  }

  player_destroy(game_get_player(game));
  die_destroy(game_get_die(game));
  free(game);
  return OK;
}

STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;

  if (space == NULL)
  {
    return ERROR;
  }

  while ((i < MAX_SPACES) && (game->spaces[i] != NULL))
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

STATUS game_add_object(Game *game, Object *object)
{
  int i = 0;

  if (object == NULL)
    return ERROR;

  while ((i < OBJECTS) && (game->objects[i] != NULL))
  {
    i++;
  }
  if (i >= OBJECTS)
  {
    return ERROR;
  }

  game->objects[i] = object;
  return OK;
}

STATUS game_add_link(Game *game, Link *link)
{
  int i = 0;

  if (link == NULL)
    return ERROR;

  while ((i < LINKS) && (game->links[i] != NULL))
  {
    i++;
  }
  if (i >= LINKS)
  {
    return ERROR;
  }

  game->links[i] = link;
  return OK;
}

Id game_get_space_id_at(Game *game, int position)
{

  if (position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  if (id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}

Player *game_get_player(Game *game)
{
  if (game == NULL)
  {
    return NULL;
  }
  return game->player;
}

Die *game_get_die(Game *game)
{
  if (game == NULL)
  {
    return NULL;
  }
  return game->die;
}

Object *game_get_object(Game *game, Id id)
{
  int i;

  if (game == NULL)
  {
    return NULL;
  }

  for (i = 0; i < OBJECTS; i++)
  {
    if (object_get_id(game->objects[i]) == id)
      return game->objects[i];
  }
  return NULL;
}

Id game_player_get_location(Game *game)
{
  if (game == NULL)
  {
    return NO_ID;
  }

  return player_get_location(game_get_player(game));
}

Id game_get_object_location(Game *game, Id id)
{
  Id object_id;
  int i, j;

  object_id = object_get_id(game_get_object(game, id));

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    for (j = 0; j < space_number_of_objects(game->spaces[i]); j++)
    {
      if (space_get_object(game->spaces[i], j) == object_id)
      {
        return space_get_id(game->spaces[i]);
      }
    }
  }

  return NO_ID;
}

STATUS game_update(Game *game, T_Command cmd, char *arg)
{
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game, arg);
  return OK;
}

T_Command game_get_last_command(Game *game)
{
  return game->last_cmd;
}

void game_print_data(Game *game)
{
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: %d\n", (int)game_get_object_location(game, 1));
  printf("=> Player location: %d\n", (int)game_player_get_location(game));
  printf("prompt:> ");
}

BOOL game_is_over(Game *game)
{
  return game->game_over;
}

/**
   Callbacks implementation for each action
*/

void game_callback_unknown(Game *game, char *arg)
{
}

void game_callback_exit(Game *game, char *arg)
{
}

void game_callback_take(Game *game, char *arg)
{

  Id space_id = NO_ID, object_id = NO_ID, *ids;
  int i, player_obj = 0, max_inv = 0;
  space_id = game_player_get_location(game);
  BOOL b, flag = FALSE;
  Object *o_aux;
  if (space_id == NO_ID)
    return;

  player_obj = set_get_numids(inventory_get_Set(player_get_objects(game_get_player(game)))); //nḿero de objetos del jugador
  max_inv = inventory_getMaxInv(player_get_objects(game_get_player(game)));

  if (player_obj >= max_inv) //si tiene el inventario lleno
    return;
  for (i = 0; i < OBJECTS; i++)
  {
    if (game->objects[i] != NULL)
    {
      if (strcmp(arg, object_get_name(game->objects[i])) == 0)
      {
        o_aux = game->objects[i];
        object_id = object_get_id(game->objects[i]);
        break;
      }
    }
  }

  if (object_is_movable(o_aux) == FALSE) //no se puede coger
    return;

  ids = inventory_getIds(player_get_objects(game_get_player(game)));
  for (i = 0; i < inventory_getNumids(player_get_objects(game_get_player(game))) && flag == FALSE; i++)
  {
    if (ids[i] == object_get_dependency(o_aux))
      flag = TRUE;
  }

  b = set_containsId(space_get_objects(game_get_space(game, space_id)), object_id);
  if (b == TRUE && flag == TRUE)
  {

    player_add_object(game_get_player(game), object_id);
    space_del_object(game_get_space(game, space_id), object_id);
    return;
  }
  else if (object_get_dependency(o_aux) == NO_ID && b == TRUE)
  {
    player_add_object(game_get_player(game), object_id);
    space_del_object(game_get_space(game, space_id), object_id);
    return;
  }
  return;
}

void game_callback_drop(Game *game, char *arg)
{
  Id *object_id, *ids;
  Id space_id = NO_ID, dependency_id = NO_ID;
  int i, j;
  space_id = game_player_get_location(game);
  Object *o_aux;
  if (space_id == NO_ID)
    return;

  if (inventory_isEmpty(player_get_objects(game_get_player(game))) == TRUE)
  {
    return;
  }
  inventory_print(player_get_objects(game_get_player(game)));
  object_id = inventory_getIds(player_get_objects(game_get_player(game))); //id del objeto del jugador
  for (i = 0; i < inventory_getNumids(player_get_objects(game_get_player(game))); i++)
  {
    if (strcmp(object_get_name(game_get_object(game, object_id[i])), arg) == 0)
    {
      o_aux = game_get_object(game, object_id[i]);
      dependency_id = object_get_dependency(o_aux);
      ids = inventory_getIds(player_get_objects(game_get_player(game)));
      for (j = 0; j < inventory_getNumids(player_get_objects(game_get_player(game))); j++)
      {
        if (dependency_id == ids[j])
        {
          space_add_object(game_get_space(game, space_id), ids[j]);
          player_del_object(game_get_player(game), ids[j]);
        }
      }
      space_add_object(game_get_space(game, space_id), object_id[i]);
      player_del_object(game_get_player(game), object_id[i]); //poner id del objeto del jugador a NO_ID
    }
  }
  inventory_print(player_get_objects(game_get_player(game)));
  return;
}

void game_callback_roll(Game *game, char *arg)
{
  if (die_roll(game_get_die(game)) == ERROR)
  {
    return;
  }
}

void game_callback_inspect(Game *game, char *arg)
{
  int i = 0;
  Id space_id;
  Id object_id;

  space_id = game_player_get_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  if (strcmp(arg, "space") == 0 || strcmp(arg, "s") == 0)
  {
    if (game_get_space_illuminate(game, space_id) == FALSE)
      return;

    strcpy(game->last_detail_descr, space_get_descr_detail(game_get_space(game, space_id)));
    return;
  }

  //MIRAMOS SI EL ARGUMENTO ES UN OBJETO
  for (i = 0; i < OBJECTS; i++)
  {
    if (strcmp(arg, object_get_name(game->objects[i])) == 0)
    {
      object_id = object_get_id(game->objects[i]);
      if (game_get_space_illuminate(game, space_id) == FALSE)
      { //si no está iluminado el espacio
        return;
      }
      if (set_containsId(space_get_objects(game_get_space(game, space_id)), object_id) == TRUE)
      {

        strcpy(game->last_detail_descr, object_get_description(game->objects[i]));
        return;
      }
      else if (inventory_containsObject(player_get_objects(game_get_player(game)), object_id) == TRUE)
      {
        strcpy(game->last_detail_descr, object_get_description(game->objects[i]));
        return;
      }
      else
      {
        return;
      }
    }
  }
}

char *game_get_last_detailed_description(Game *game)
{
  if (!game)
    return NULL;

  return game->last_detail_descr;
}

Object **game_get_objects(Game *game)
{
  if (game == NULL)
    return NULL;
  return game->objects;
}

STATUS game_add_player(Game *game, Player *player)
{
  if (player == NULL || game == NULL)
    return ERROR;
  game->player = player;
  return OK;
}

void game_callback_move(Game *game, char *arg)
{

  Id current_id = NO_ID;
  Id space_id = NO_ID;
  int i;

  space_id = game_player_get_location(game);

  if (strcmp(arg, "north") == 0 || strcmp(arg, "n") == 0)
  {
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id)
      {
        current_id = link_get_sp1(space_get_north(game->spaces[i]));
        if (current_id != NO_ID && link_get_state(space_get_north(game->spaces[i])) == FALSE)
        {
          game_player_set_location(game, current_id);
        }
        return;
      }
    }
  }
  else if (strcmp(arg, "south") == 0 || strcmp(arg, "s") == 0)
  {
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id)
      {
        current_id = link_get_sp2(space_get_south(game->spaces[i]));
        if (current_id != NO_ID && link_get_state(space_get_south(game->spaces[i])) == FALSE)
        {
          game_player_set_location(game, current_id);
        }
        return;
      }
    }
  }
  else if (strcmp(arg, "east") == 0 || strcmp(arg, "e") == 0)
  {
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id)
      {
        current_id = link_get_sp2(space_get_east(game->spaces[i]));
        if (current_id != NO_ID && link_get_state(space_get_east(game->spaces[i])) == FALSE)
        {
          game_player_set_location(game, current_id);
        }
        return;
      }
    }
  }
  else if (strcmp(arg, "west") == 0 || strcmp(arg, "w") == 0)
  {
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id)
      {
        if (link_getId(space_get_west(game->spaces[i])) == 31)
          current_id = link_get_sp2(space_get_west(game->spaces[i]));
        else
          current_id = link_get_sp1(space_get_west(game->spaces[i]));

        if (current_id != NO_ID && link_get_state(space_get_west(game->spaces[i])) == FALSE)
        {
          game_player_set_location(game, current_id);
        }
        return;
      }
    }
  }

  else if (strcmp(arg, "down") == 0 || strcmp(arg, "d") == 0)
  {
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id)
      {
        current_id = link_get_sp1(space_get_down(game->spaces[i]));
        if (current_id != NO_ID && link_get_state(space_get_down(game->spaces[i])) == FALSE)
        {
          game_player_set_location(game, current_id);
        }
        return;
      }
    }
  }

  else if (strcmp(arg, "up") == 0 || strcmp(arg, "u") == 0)
  {
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
    {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id)
      {
        current_id = link_get_sp2(space_get_up(game->spaces[i]));
        if (current_id != NO_ID && link_get_state(space_get_up(game->spaces[i])) == FALSE)
        {
          game_player_set_location(game, current_id);
        }
        return;
      }
    }
  }

  return;
}

BOOL game_get_space_illuminate(Game *game, Id id)
{
  int i;

  if (!game)
    return FALSE;

  for (i = 0; i < MAX_SPACES; i++)
  {
    if (game_get_space_id_at(game, i) == id)
    {
      return space_get_illuminate(game->spaces[i]);
    }
  }
  return FALSE;
}

void game_callback_open(Game *game, char *arg)
{
  char link_name[WORD_SIZE] = "";
  char obj_name[WORD_SIZE] = "";
  char *toks = NULL;
  int i;
  Link *link = NULL;
  Object *object = NULL;

  BOOL link_st = FALSE;
  BOOL obj_st = FALSE;

  if (!game || !arg)
    return;

  toks = strtok(arg, " \t\r\n"); // open link with obj
  strcpy(link_name, toks);
  toks = strtok(NULL, " \t\r\n");
  toks = strtok(NULL, " \t\r\n");
  strcpy(obj_name, toks);

  for (i = 0; i < LINKS; i++)
  {
    if (link_get_name(game->links[i]) != NULL)
    {
      if (strcmp(link_name, link_get_name(game->links[i])) == 0)
      { //link existe
        link_st = TRUE;
        link = game->links[i];
        break;
      }
    }
  }

  if (link_st == FALSE)
    return;

  for (i = 0; i < OBJECTS; i++)
  {
    if (object_get_name(game->objects[i]) != NULL)
    {
      if (strcmp(obj_name, object_get_name(game->objects[i])) == 0)
      { //obj existe
        if (inventory_containsObject(player_get_objects(game_get_player(game)), object_get_id(game->objects[i])) == TRUE)
        { //obj en el inventario
          obj_st = TRUE;
          object = game->objects[i];
          break;
        }
      }
    }
  }

  if (obj_st == FALSE)
    return;

  //si link existe, y obj en el inventario, hay que comprobar la dependencia

  
  if (link_st == TRUE && obj_st == TRUE)
  {
    if (link_get_sp1(link) == game_player_get_location(game))
    {

      //Caso de muerte del jugador

      if (link_getId(link) == 10 && object_get_id(object) == 20)
      {
        game->game_over = TRUE;
        return;
      }

      //si el link entre espacios depende del objeto, se abrirá el link

      if (link_get_sp2(link) == object_get_open(object) || link_get_sp1(link) == object_get_open(object))
      {
        link_set_state(link, FALSE); //abres el enlace
      }
    }
  }

  return;
}

void game_callback_turnon(Game *game, char *arg)
{

  Id space_id = NO_ID;
  Id *ids;
  int i;
  Space *space;
  BOOL b = FALSE;
  if (!game || !arg)
    return;
  space_id = game_player_get_location(game);
  space = game_get_space(game, space_id);
  ids = set_get_ids(space_get_objects(space));

  for (i = 0; i < OBJECTS && b == FALSE; i++)
  {
    if (strcmp(arg, object_get_name(game_get_objects(game)[i])) == 0)
      b = TRUE;
  }
  for (i = 0; i < space_number_of_objects(game_get_space(game, space_id)) && b == TRUE; i++)
  {
    if (strcmp(arg, object_get_name(game_get_object(game, ids[i]))) == 0 && object_can_iluminate(game_get_object(game, ids[i])) == TRUE)
    {
      if (object_is_on(game_get_object(game, ids[i])) == FALSE)
      {
        object_set_turnedon(game_get_object(game, ids[i]), TRUE);
      }
      return;
    }
  }
  ids = inventory_getIds(player_get_objects(game_get_player(game)));
  for (i = 0; i < inventory_getNumids(player_get_objects(game_get_player(game))) && b == TRUE; i++)
  {
    if (strcmp(arg, object_get_name(game_get_object(game, ids[i]))) == 0 && object_can_iluminate(game_get_object(game, ids[i])) == TRUE)
    {
      if (object_is_on(game_get_object(game, ids[i])) == FALSE)
      {
        object_set_turnedon(game_get_object(game, ids[i]), TRUE);
        space_set_illuminate(space, TRUE);
      }
      return;
    }
  }
}

void game_callback_turnoff(Game *game, char *arg)
{
  Id space_id = NO_ID;
  Id *ids;
  int i;
  Space *space;
  BOOL b = FALSE;
  if (!game || !arg)
    return;
  space_id = game_player_get_location(game);
  space = game_get_space(game, space_id);
  ids = set_get_ids(space_get_objects(space));
  for (i = 0; i < game_num_o(game) && b == FALSE; i++)
  {
    if (strcmp(arg, object_get_name(game_get_objects(game)[i])) == 0)
      b = TRUE;
  }
  for (i = 0; i < space_number_of_objects(game_get_space(game, space_id)) && b == TRUE; i++)
  {
    if (strcmp(arg, object_get_name(game_get_object(game, ids[i]))) == 0 && object_can_iluminate(game_get_object(game, ids[i])) == TRUE)
    {
      if (object_is_on(game_get_object(game, ids[i])) == TRUE)
      {
        object_set_turnedon(game_get_object(game, ids[i]), FALSE);
      }
      return;
    }
  }
  ids = inventory_getIds(player_get_objects(game_get_player(game)));
  for (i = 0; i < inventory_getNumids(player_get_objects(game_get_player(game))) && b == TRUE; i++)
  {
    if (strcmp(arg, object_get_name(game_get_object(game, ids[i]))) == 0 && object_can_iluminate(game_get_object(game, ids[i])) == TRUE)
    {
      if (object_is_on(game_get_object(game, ids[i])) == TRUE)
      {
        object_set_turnedon(game_get_object(game, ids[i]), FALSE);
      }
      return;
    }
  }
}

Link * game_find_link_by_sp1 (Game *game, Id sp1) {
  int i;

  if (!game || sp1 == NO_ID) return NULL;

  for (i=0;i<LINKS;i++) {
    if (link_get_sp1(game->links[i]) == sp1)
      return game->links[i];
  }

  return NULL;
}