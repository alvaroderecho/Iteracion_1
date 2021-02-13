#ifndef __GAME_READER__
#define __GAME_READER__

typedef struct _Game{
  Id player_location;
  Id object_location;
  Space* spaces[MAX_SPACES + 1];
  T_Command last_cmd;
} Game;

STATUS game_load_spaces(Game* game, char* filename);
#endif
