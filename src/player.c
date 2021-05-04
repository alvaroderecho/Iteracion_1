/**
 * @brief Define Las estructuras y funciones de los jugadores
 *
 * @file player.h
 * @author 2111_10
 * @version 1.0
 * @date 15-02-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

struct _Player
{
    Id id;                              //Id del jugador
    char name[WORD_SIZE + 1];           //Nombre del jugador
    Id location;                        //Localización del jugador (su espacio)
    Inventory *inventory;               //Inventario de objetos que lleva el jugador
};

Player *player_create(Id id)
{
    Player *new_player = NULL;

    if (id == NO_ID) //==-1
        return NULL;

    new_player = (Player *)malloc(sizeof(Player));
    if (new_player == NULL)
        return NULL; //error en la reserva de memoria

    new_player->id = id;
    new_player->name[0] = '\0';
    new_player->location = NO_ID;
    new_player->inventory = NULL;

    return new_player;
}

STATUS player_create_inventory(Player *player, int max) {
    if (!player || max <= 0) return ERROR;

    player->inventory = inventory_create(max);

    if (player->inventory == NULL) return ERROR;

    return OK;
}

STATUS player_destroy(Player *player)
{
    if (!player) // == 0
        return ERROR;
    inventory_destroy(player->inventory);
    free(player);
    player = NULL;
    return OK; //destruido
}

STATUS player_set_id(Player *player, Id ide)
{
    if (!player || ide == NO_ID)
        return ERROR;
    player->id = ide;
    return OK;
} //Modificar la ID

STATUS player_set_name(Player *player, char *name)
{
    if (!player || !name)
        return ERROR;
    if (!strcpy(player->name, name)) //cambia el nombre
        return ERROR;                //no hay cambia si es el mismo nombre

    return OK; //nombre cambiado
}

STATUS player_set_location(Player *player, Id id)
{
    if (!player || id == NO_ID)
    {
        return ERROR;
    }

    player->location = id;
    return OK;
}

STATUS player_add_object(Player *player, Id id)
{
    if (!player)
    {
        return ERROR;
    }
    if (inventory_addId(player->inventory, id) == ERROR){
      return ERROR;
    }
    return OK;
}

STATUS player_del_object(Player *player, Id id)
{
  if (!player)
  {
    return ERROR;
  }
  if (inventory_delId(player->inventory, id) == ERROR){
    return ERROR;
  }
  return OK;
}

Id player_get_id(Player *player)
{
    if (!player)
        return NO_ID;
    return player->id;
}

const char *player_get_name(Player *player)
{
    if (!player)
        return NULL;
    return player->name;
}

Id player_get_location(Player *player)
{
    if (!player)
        return NO_ID;
    return player->location;
}

Inventory* player_get_objects(Player *player)
{
    if (!player)
        return NULL;
    return player->inventory;
}

BOOL player_containsObject (Player *player, Id id){
  if (!player || id == NO_ID){
    return FALSE;
  }
  return inventory_containsObject(player->inventory, id);
}

STATUS player_print(Player *player)
{
    if (!player)
        return ERROR;
    fprintf(stdout, "Player (Id: %ld; Name: %s)\n", player->id, player->name);
    fprintf(stdout, "Location Id: %ld, ", player->location);
    inventory_print(player->inventory);
    return OK;
}