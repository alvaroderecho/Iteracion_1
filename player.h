#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

//funciones
Player* create_player(Id id);
STATUS destroy_player(Player* player);
STATUS set_player_id(Player* player, Id ide);
STATUS set_player_name(Player* player, char* name);
STATUS set_player_location(Player* player, Id id);
STATUS set_player_object(Player* player, Id id);
Id get_player_id(Player* player);
const char * get_player_name(Player* player);
Id get_player_location(Player* player);
Id get_player_object(Player* player);
STATUS player_print(Player* player);

#endif