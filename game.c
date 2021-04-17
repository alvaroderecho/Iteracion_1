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
  Player *player;                //Puntero al jugador del juego
  Object *objects[OBJECTS];      //Puntero al objeto
  Space *spaces[MAX_SPACES + 1]; //Espacios de un juego
  T_Command last_cmd;            //Último comando escrito por pantalla
  Die *die;                      //Dado usado en el juego
};

/**
   Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game *game, char *arg);

/**
   List of callbacks for each command in the game
*/
void game_callback_unknown(Game *game,char * arg);
void game_callback_exit(Game *game,char * arg);
void game_callback_next(Game *game,char * arg);
void game_callback_back(Game *game,char * arg);
void game_callback_take(Game *game,char * arg);
void game_callback_drop(Game *game,char * arg);
void game_callback_left(Game *game,char * arg);
void game_callback_right(Game *game,char * arg);
void game_callback_roll(Game *game,char * arg);
void game_callback_move (Game *game, char * arg);

static callback_fn game_callback_fn_list[N_CALLBACK] = {
    game_callback_unknown,
    game_callback_exit,
    game_callback_next,
    game_callback_back,
    game_callback_take,
    game_callback_drop,
    game_callback_left,
    game_callback_right,
    game_callback_roll,
    game_callback_move};

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

  game->player = player_create(1);

  game->last_cmd = NO_CMD;

  game->die = die_create(1, 1, 6);

  return OK;
}

STATUS game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++)
  {
    space_destroy(game->spaces[i]);
  }
  for (i = 0; (i < OBJECTS) && (game->spaces[i] != NULL); i++)
  {
    object_destroy(game->objects[i]);
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

STATUS game_update(Game *game, T_Command cmd, char * arg)
{
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game,arg);
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
  return FALSE;
}

/**
   Callbacks implementation for each action
*/

void game_callback_unknown(Game *game,char * arg)
{
}

void game_callback_exit(Game *game,char * arg)
{
}

void game_callback_next(Game *game,char * arg)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_player_get_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = link_get_sp2(space_get_south(game->spaces[i]));
      if (current_id != NO_ID)
      {
        game_player_set_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_back(Game *game,char * arg)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_player_get_location(game);

  if (NO_ID == space_id)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = link_get_sp1(space_get_north(game->spaces[i]));
      if (current_id != NO_ID)
      {
        game_player_set_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_take(Game *game,char * arg)
{
  
  Id space_id = NO_ID;
  int i;
  space_id = game_player_get_location(game);

  

  if (space_id == NO_ID)
    return;

  

for (i=0;i<OBJECTS && game->objects[i] != NULL;i++){
  if (strcmp(object_get_name(game->objects[i]),arg) == 0){
  player_add_object(game_get_player(game), object_get_id(game->objects[i]));
  space_del_object(game_get_space(game, space_id), object_get_id(game->objects[i]));
  return ;
  }

}
  return;
}

void game_callback_drop(Game *game,char * arg)
{
  Id *object_id;
  Id space_id = NO_ID;
  int i;
  space_id = game_player_get_location(game);

  if (space_id == NO_ID)
    return;

  if (inventory_isEmpty(player_get_objects(game_get_player(game))) == TRUE)
  {
    return;
  }

  object_id = inventory_getIds(player_get_objects(game_get_player(game))); //id del objeto del jugador
for (i=0;i < inventory_getNumids(player_get_objects(game_get_player(game)));i++){
  if (strcmp(object_get_name(game_get_object(game,object_id[i])),arg) == 0){
  player_del_object(game_get_player(game), object_id[i]); //poner id del objeto del jugador a NO_ID
  space_add_object(game_get_space(game, space_id), object_id[i]);
  }
}

  return;
}

void game_callback_left(Game *game,char * arg)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_player_get_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      if (link_getId(space_get_west(game->spaces[i])) == 31)
        current_id = link_get_sp2(space_get_west(game->spaces[i]));
      else
        current_id = link_get_sp1(space_get_west(game->spaces[i]));

      if (current_id != NO_ID)
      {
        game_player_set_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_right(Game *game,char * arg)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_player_get_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = link_get_sp2(space_get_east(game->spaces[i]));
      if (current_id != NO_ID)
      {
        game_player_set_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_roll(Game *game,char * arg)
{
  if (die_roll(game_get_die(game)) == ERROR)
  {
    return;
  }
}
Object **game_get_objects(Game *game)
{
  if (game == NULL)
    return NULL;
  return game->objects;
}
STATUS game_add_player(Game *game, Player *player)
{
  if (player == NULL)
    return ERROR;
  game->player = player;
  return OK;
}

void game_callback_move (Game *game, char *arg){
  
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  int i;

  space_id = game_player_get_location(game);
  
  if (strcmp(arg,"north") == 0||strcmp(arg,"n") == 0){
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = link_get_sp1(space_get_north(game->spaces[i]));
      if (current_id != NO_ID)
      {
        game_player_set_location(game, current_id);
      }
      return;
    }
  }
  }
  else if (strcmp(arg,"south") == 0||strcmp(arg,"s") == 0){
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = link_get_sp2(space_get_south(game->spaces[i]));
      if (current_id != NO_ID)
      {
        game_player_set_location(game, current_id);
      }
      return;
    }
  }
  }
  else if (strcmp(arg,"east") == 0||strcmp(arg,"e") == 0){
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = link_get_sp2(space_get_east(game->spaces[i]));
      if (current_id != NO_ID)
      {
        game_player_set_location(game, current_id);
      }
      return;
    }

  }
  }
  else if (strcmp(arg,"west") == 0||strcmp(arg,"w") == 0){
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      if (link_getId(space_get_west(game->spaces[i])) == 31)
        current_id = link_get_sp2(space_get_west(game->spaces[i]));
      else
        current_id = link_get_sp1(space_get_west(game->spaces[i]));

      if (current_id != NO_ID)
      {
        game_player_set_location(game, current_id);
      }
      return;
    }
  }
  }
  
  return;
  
}
