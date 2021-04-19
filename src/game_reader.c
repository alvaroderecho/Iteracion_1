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
#include "link.h"

STATUS game_reader_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char desc[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID;
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
      strcpy(desc, toks);
      toks = strtok(NULL, "|");
      toks = strtok(NULL, "|");
      toks = strtok(NULL, "|");
      toks = strtok(NULL, "|");
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
        space_set_description(space,desc);
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

  if (game_reader_load_links(game,filename) == ERROR) 
    return ERROR;

    //FALTA game_reader_load_players

  return OK;
}

STATUS game_reader_load_objects(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char desc[WORD_SIZE] = "";
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
      strcpy(desc,toks);
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
        object_set_description(object,desc);
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
        player_add_object(player,object);
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

STATUS game_reader_load_links(Game *game, char *filename)
{
  FILE *file = NULL;
  BOOL l_st;
  Id id, sp1, sp2;
  char name[WORD_SIZE+1] = "";
  char line[WORD_SIZE] = "";
  char *toks = NULL;
  Link *link;
  STATUS status = OK;

  if (!filename) return ERROR;

  file = fopen(filename,"r");
  if (file == NULL) return ERROR;

  while (fgets(line,WORD_SIZE,file)) {

    if (strncmp("#l:", line, 3) == 0) {
        toks = strtok(line+3,"|");
        id = atol(toks);
        toks = strtok(NULL,"|");
        strcpy(name,toks);
        toks = strtok(NULL,"|");
        sp1 = atol(toks);
        toks= strtok(NULL,"|");
        sp2 = atol(toks);
        toks= strtok(NULL,"|");
        l_st = atoi(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|", id, name, sp1, sp2, l_st);
#endif

    link = link_create(id);    
    if (link!= NULL) {
      link_set_name(link,name);
      link_set_sp1(link,sp1);
      link_set_sp2(link,sp2);
      link_set_state(link,l_st);

      if (sp2 == sp1 + 1) { //casillas contiguas
        space_set_north(game_get_space(game,sp2),link);
        space_set_south(game_get_space(game,sp1),link);
       
        //space_print(game_get_space(game,sp2));

      }
      else if (sp2 == sp1 + 4) { //ocas
        space_set_east(game_get_space(game,sp1),link); //oca, solo ida
      }
      else if (sp2 == sp1 + 8) { //puente ida y vuelta
        space_set_east(game_get_space(game,sp1),link);
        space_set_west(game_get_space(game,sp2),link);
      }
      else {//muerte
        space_set_west(game_get_space(game,sp1),link);
      }
      game_add_link(game,link);
    }

  }
  }

  
  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);
  return status;

}