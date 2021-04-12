/**
 * @brief Desine la carga de espacios y la creación de un juego
 *
 * @file game_reader.h
 * @author 2111_10
 * @version 1.0
 * @date 15-02-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"
#include "space.h"

STATUS game_reader_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  STATUS status = OK;
  char **spgdesc;
  int i,j;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  if ((spgdesc = (char**)malloc(3*sizeof(char*))) == NULL) return ERROR; //tres filas
  for (i=0;i<MAX_LINES;i++) {
    if ((spgdesc[i] = (char*)malloc(9*sizeof(char))) == NULL) {
      for (j=0;j<i;j++) free(spgdesc[j]);      
      free(spgdesc);
      
      return ERROR;
    } 
  }



  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      for (i=0;i<MAX_LINES;i++) {
      toks = strtok(NULL, "|");
      strcpy(spgdesc[i], toks);          
      }
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        space_set_gDesc(space,spgdesc);
        game_add_space(game, space);
      }
    }
  }

  for (i=0;i<MAX_LINES;i++) {
    free(spgdesc[i]);
  }
  free(spgdesc);


  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

STATUS game_reader_create_from_file(Game *game, char *filename)
{

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_reader_load_spaces(game, filename) == ERROR)
    return ERROR;

  if (game_player_set_location(game, game_get_space_id_at(game, 0)) == ERROR)
    return ERROR;

  if (game_reader_load_objects(game, filename) == ERROR)
    return ERROR;


  return OK;
}

STATUS game_reader_load_objects(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id, obj_location;
  Object *object;
  STATUS status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {

    if (strncmp("#o:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      obj_location = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|", id, name, location,object);
#endif
      object = object_create(id);
      if (object != NULL)
      {
        object_set_name(object, name);
        object_set_id(object,id);
        space_add_object(game_get_space(game, obj_location), id);
        game_add_object(game,object);
      }
    }
  }
  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);
  return status;

}
STATUS game_reader_load_player(Game *game, char *filename){
    FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id, location,object;
  Player *player;
  STATUS status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {

    if (strncmp("#o:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      object = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld", id, name, obj_location);
#endif
      player = player_create(id);
      if (player != NULL)
      {
        player_set_name(player, name);
        player_set_id(player,id);
        player_set_location(player,location);
        player_set_object(player,object);
        game_add_player(game,player);
      }
    }
  }
  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);
  return status;
}