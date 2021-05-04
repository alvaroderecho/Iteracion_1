/**
 * @brief Define un jugador
 *
 * @file player.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "inventory.h"

typedef struct _Player Player;

//funciones

/**
 * @brief Crea un jugador
 *
 * @file player.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param id Id del objeto
 * @return Player*
 */
Player *player_create(Id id);

/**
 * @brief Destruye un objeto
 *
 * @file player.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param player Jugador a destruir
 * @return STATUS
 */
STATUS player_destroy(Player *player);

/**
 * @brief Establece una Id al jugador
 *
 * @file player.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param id Id del objeto
 * @return STATUS
 */
STATUS player_set_id(Player *player, Id ide);

/**
 * @brief Establece el nombre a un jugador
 *
 * @file player.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param player Jugador a usar
 * @param name Nombre a establecer
 * @return STATUS
 */
STATUS player_set_name(Player *player, char *name);

/**
 * @brief Establece la localización a un jugador
 *
 * @file player.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param player Jugador usado
 * @param id Id a establecer
 * @return STATUS
 */
STATUS player_set_location(Player *player, Id id);

/**
 * @brief Añade un objeto al inventario del jugador
 *
 * @file player.c
 * @author Álvaro Derecho && Sergio Domínguez
 * @version 2.0
 * @date 17/04/2021
 * @param player Jugador a usar
 * @param id Id a establecer
 * @return STATUS
 */
STATUS player_add_object(Player *player, Id id);


/**
 * @brief Quita un objeto del inventario del jugador
 *
 * @file player.c
 * @author Álvaro Derecho && Sergio Domínguez
 * @version 2.0
 * @date 17/04/2021
 * @param player Jugador a usar
 * @param id Id a establecer
 * @return STATUS
 */
STATUS player_del_object(Player *player, Id id);

/**
 * @brief Devuelve la Id del jugador
 *
 * @file player.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param player Jugador a usar
 * @return Id
 */
Id player_get_id(Player *player);

/**
 * @brief Devuelve el nombre del jugador
 *
 * @file player.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param player Jugador a usar
 * @return const char *
 */
const char *player_get_name(Player *player);

/**
 * @brief Devuelve la localización de un jugador
 *
 * @file player.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param player Jugador a usar
 * @return Id
 */
Id player_get_location(Player *player);

/**
 * @brief Devuelve la Id del objeto de un jugador
 *
 * @file player.c
 * @author Álvaro Derecho && Sergio Dominguez
 * @version 2.0
 * @date 15/02/2021
 * @param player Jugador a usar
 * @return Id
 */
Inventory* player_get_objects(Player *player);

/**
 * @brief Devuelve True si el inventario del jugador contiene un objeto, en otro caso o caso de error devuelve False
 *
 * @file player.c
 * @author Sergio Domínguez
 * @version 1.0
 * @date 17/04/2021
 * @param Player Jugador a usar
 * @param Id a buscar
 * @return Bool
 */
BOOL player_containsObject (Player *player, Id id);

/**
 * @brief Imprime los datos de un jugador
 *
 * @file player.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/02/2021
 * @param player Jugador a usar
 * @return STATUS
 */
STATUS player_print(Player *player);

/**
 * @brief Crea un inventario de un jugador
 *
 * @file player.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 04/05/2021
 * @param player Jugador a usar
 * @param max Tamaño de inventario
 * @return STATUS
 */
STATUS player_create_inventory(Player *player, int max);
#endif