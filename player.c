#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"


struct _Player {
    Id id;
    char name[WORD_SIZE +1];
    Id location;
    Id object;
};

Player* create_player(Id id) {
    Player *new_player = NULL;

    if (id == NO_ID) //==-1
        return NULL;
    
    new_player = (Player *)malloc(sizeof(Player));
    if (new_player == NULL)
        return NULL; //error en la reserva de memoria
    
    new_player->id = id;
    new_player->name[0] = '\0';

    return new_player;
}

STATUS destroy_player(Player* player) {
    if (!player) // == 0
        return ERROR;
    free(player);
    player = NULL;
    return OK; //destruido
}

STATUS set_player_id(Player* player, Id ide) {
    if (!player || ide == NO_ID)
        return ERROR;
    player->id = ide;
    return OK;
} //Modificar la ID

STATUS set_player_name(Player* player, char* name) {
    if (!player || !name)
        return ERROR;
    if (!strcpy(player->name, name)) //cambia el nombre
        return ERROR; //no hay cambia si es el mismo nombre

    return OK; //nombre cambiado
}

STATUS set_player_location(Player* player, Id id) {
    if (!player || id == NO_ID)
        return ERROR;
    
    player->location = id;
    return OK;    
}

STATUS set_player_object(Player* player, Id id) {
    if (!player || id == NO_ID)
        return ERROR;
    player->object = id;
    return OK;
}

Id get_player_id(Player* player) {
    if (!player)
        return NO_ID;
    return player->id;
}

const char * get_player_name(Player* player) {
    if (!player)
        return NULL;
    return player->name;
}


Id get_player_location(Player* player) {
    if (!player)
        return NO_ID;
    return player->location;
}

Id get_player_object(Player* player) {
    if (!player)
        return NO_ID;
    return player->object;
}

STATUS player_print(Player* player) {
    if (!player)
        return ERROR;
    fprintf(stdout,"Player (Id: %ld; Name: %s)\n",player->id,player->name);
    fprintf(stdout,"Location Id: %ld, Object Id: %ld",player->location,player->object);
    return OK;
}