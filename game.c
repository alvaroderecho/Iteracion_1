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

#define N_CALLBACK 8

/**
   Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game *game);

/**
   List of callbacks for each command in the game
*/
void game_callback_unknown(Game *game);
void game_callback_exit(Game *game);
void game_callback_next(Game *game);
void game_callback_back(Game *game);
void game_callback_take(Game *game);
void game_callback_drop(Game *game);
void game_callback_left(Game *game);
void game_callback_right(Game *game)
;

static callback_fn game_callback_fn_list[N_CALLBACK] = {
    game_callback_unknown,
    game_callback_exit,
    game_callback_next,
    game_callback_back,
    game_callback_take,
    game_callback_drop,
    game_callback_left,
    game_callback_right};

/**
   Private functions
*/

STATUS game_add_space(Game *game, Space *space);
Id game_get_space_id_at(Game *game, int position);
STATUS game_player_set_location(Game *game, Id id);
STATUS game_set_object_location(Game *game, Id id);

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

STATUS game_set_object_location(Game *game, Id id)
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

  if (space_set_object(game_get_space(game, id), object_get_id(game_get_object(game))) == ERROR)
    return ERROR;

  return OK;
}

STATUS game_create(Game *game)
{
  int i;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }

  game->player = player_create(1);
  game->object = object_create(1);
  game->last_cmd = NO_CMD;

  return OK;
}

STATUS game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++)
  {
    space_destroy(game->spaces[i]);
  }
  player_destroy(game_get_player(game));
  object_destroy(game_get_object(game));

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

Object *game_get_object(Game *game)
{
  if (game == NULL)
  {
    return NULL;
  }
  return game->object;
}

Id game_player_get_location(Game *game)
{
  if (game == NULL)
  {
    return NO_ID;
  }

  return player_get_location(game_get_player(game));
}

Id game_get_object_location(Game *game)
{
  Id object_id;
  int i,j;

  object_id = object_get_id(game_get_object(game));

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    for (j=0;j<space_number_of_objects(game->spaces[i]);j++){
    if (space_get_object(game->spaces[i],j) == object_id)
    {
      return space_get_id(game->spaces[i]);
    }
    }
  }

  return NO_ID;
}

STATUS game_update(Game *game, T_Command cmd)
{
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
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

  printf("=> Object location: %d\n", (int)game_get_object_location(game));
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

void game_callback_unknown(Game *game)
{
}

void game_callback_exit(Game *game)
{
}

void game_callback_next(Game *game)
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
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_player_set_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_back(Game *game)
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
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_player_set_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_take(Game *game)
{
  Id object_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_player_get_location(game);
  space_print(game_get_space(game,space_id));

  if (space_id == NO_ID)
    return;

  if (player_get_object(game_get_player(game)) != NO_ID)
  {
    return;
  }
  space_print(game_get_space(game,space_id));

  object_id = space_get_object(game_get_space(game,space_id));

  player_set_object(game_get_player(game), object_id);
  space_set_object(game_get_space(game,space_id), NO_ID);

  return;
}

void game_callback_drop(Game *game)
{
  Id object_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_player_get_location(game);

  if (space_id == NO_ID)
    return;

  if (player_get_object(game_get_player(game)) == NO_ID)
  {
    return;
  }
  
  object_id = player_get_object(game_get_player(game)); //id del objeto del jugador
  
  player_set_object(game_get_player(game), NO_ID);  //poner id del objeto del jugador a NO_ID
  space_set_object(game_get_space(game,space_id), object_id);

  return;
}

void game_callback_left(Game *game)
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
      current_id = space_get_west(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_player_set_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_right(Game *game)
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
      current_id = space_get_east(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_player_set_location(game, current_id);
      }
      return;
    }
  }
}