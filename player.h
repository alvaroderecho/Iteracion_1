/**
 * @brief Define un jugador
 *
 * @file player.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

//funciones

/**
 * @brief Crea un jugador
 *
 * @file player.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
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
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
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
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
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
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
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
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param player Jugador usado
 * @param id Id a establecer
 * @return STATUS
 */
STATUS player_set_location(Player *player, Id id);

/**
 * @brief Establece la Id de un objeto
 *
 * @file player.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param player Jugador a usar
 * @param id Id a establecer
 * @return STATUS
 */
STATUS player_set_object(Player *player, Id id);

/**
 * @brief Devuelve la Id del jugador
 *
 * @file player.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
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
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
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
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
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
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param player Jugador a usar
 * @return Id
 */
Id player_get_object(Player *player);

/**
 * @brief Imprime los datos de un jugador
 *
 * @file player.c
 * @author Álvaro Derecho, Sergio Domínquez, Joseba Arranz
 * @version 1.0
 * @date 15/02/2021
 * @param player Jugador a usar
 * @return STATUS
 */
STATUS player_print(Player *player);

#endif