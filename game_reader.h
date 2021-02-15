#ifndef __GAME_READER__
#define __GAME_READER__

#include "game.h"

STATUS game_load_spaces(Game* game, char* filename);
STATUS game_create_from_file(Game* game, char* filename);
#endif
