#include <stdlib.h>
#include <stdio.h>
#include "graphic_engine.h"
#include "space.h"
#include <string.h>

struct _Graphic_engine
{
  Area *map, *descript, *banner, *help, *feedback; //Interfaz del juego
};

Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init();
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL)
    return NULL;

  ge->map = screen_area_init(1, 1, 48, /*13*/21);
  ge->descript = screen_area_init(50, 1, 29, /*13*/21);
  ge->banner = screen_area_init(28, /*15*/23, 23, 1);
  ge->help = screen_area_init(1, /*16*/24, 78, 2);
  ge->feedback = screen_area_init(1, /*19*/27, 78, 3);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge)
{
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID;
  Space *space_act = NULL, *space_next = NULL, *space_back = NULL;
  char obj = '\0';
  char str[255];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  int i,num_o;
  Object **objects=NULL;

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_player_get_location(game)) != NO_ID)
  {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);
    space_next = game_get_space(game, id_next);
    space_back = game_get_space(game, id_back);

    if (id_back != NO_ID)
    {
      sprintf(str, "  |         %2d|", (int)id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", space_get_gDesc(space_back)[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |",space_get_gDesc(space_back)[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", space_get_gDesc(space_back)[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }
    
    if (id_act != NO_ID)
    {
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  | 8D      %2d|", (int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", space_get_gDesc(space_act)[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |",space_get_gDesc(space_act)[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", space_get_gDesc(space_act)[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }

    if (id_next != NO_ID)
    {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |         %2d|", (int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", space_get_gDesc(space_next)[0]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |",space_get_gDesc(space_next)[1]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |  %s  |", space_get_gDesc(space_next)[2]);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);
  num_o = game_num_o(game);
  sprintf(str, "  Objects locations:");
  screen_area_puts(ge->descript, str);

  for (i=0;i<num_o;i++)  {
    objects=game_get_objects(game);
      if ((obj_loc = game_get_object_location(game,object_get_id(objects[i]))) != NO_ID) {
          sprintf(str,"O%d:%d ",(int)object_get_id(objects[i]), (int)obj_loc);
      } 
      screen_area_puts(ge->descript,str);
  }

  sprintf(str," ");
  screen_area_puts(ge->descript, str);
  
  sprintf(str, "Player object:");
  screen_area_puts(ge->descript, str);

  if (player_get_object(game_get_player(game)) != NO_ID) {
  sprintf(str, "O%d",(int)player_get_object(game_get_player(game)));
  screen_area_puts(ge->descript, str);
  }

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  sprintf(str, "Last die value: %d",die_getLastThrow(game_get_die(game)));
  screen_area_puts(ge->descript, str);

  /* Paint in the banner area */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, exit or e, take or t, drop or d, left or l, right or r");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s (%s)", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
