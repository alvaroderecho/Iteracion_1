/**
 * @brief It defines the game interface
 * for each command
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "die.h"

#define OBJECTS 120

typedef struct _Game
{
  Player *player;                 //Puntero al jugador del juego
  Object *objects[OBJECTS];                 //Puntero al objeto
  Space *spaces[MAX_SPACES + 1];  //Espacios de un juego
  T_Command last_cmd;             //Último comando escrito por pantalla
  Die *die;                       //Dado usado en el juego
} Game;

/**
 * @brief Añade un espacio
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @param space Espacio a añadir
 * @return STATUS
 */
STATUS game_add_space(Game *game, Space *space);

/**
 * @brief Crea un espacio
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @return STATUS
 */
STATUS game_create(Game *game);

/**
 * @brief Actualiza el juego
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @param cmd Comando Introducido
 * @return STATUS
 */
STATUS game_update(Game *game, T_Command cmd);

/**
 * @brief Destruye un juego
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @return STATUS
 */
STATUS game_destroy(Game *game);

/**
 * @brief Indica el final del juego
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @return STATUS
 */
BOOL game_is_over(Game *game);

/**
 * @brief Imprime los datos del juego
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @return void
 */
void game_print_data(Game *game);

/**
 * @brief Devuelve un espacio del juego
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @param id Id del espacio deseado
 * @return Space*
 */
Space *game_get_space(Game *game, Id id);

/**
 * @brief Devuelve el jugador del juego
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @return Player*
 */
Player *game_get_player(Game *game);

/**
 * @brief Devuelve el dado del juego
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 18/03/2021
 * @param game Juego usado
 * @return Player*
 */
Die *game_get_die(Game *game);

/**
 * @brief Devuelve el objeto del juego
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @param id Id del objeto
 * @return Object*
 */
Object *game_get_object(Game *game, Id id);

/**
 * @brief Devuelve la localización del jugador
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @return Id
 */
Id game_player_get_location(Game *game);

/**
 * @brief Devuelve la localización del objeto
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @param Id del objeto
 * @return Id
 */
Id game_get_object_location(Game *game, Id id);
/**
 * @brief Devuelve el último comando
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @return T_Command
 */
T_Command game_get_last_command(Game *game);

/**
 * @brief Establece la localización de un jugador
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @param id Localización del jugador
 * @return STATUS
 */
STATUS game_player_set_location(Game *game, Id id);

/**
 * @brief Establece la localización de un objeto
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @param id Localización del objeto
 * @return STATUS
 */
STATUS game_set_object_location(Game *game, Id id, Id id2);

/**
 * @brief Devuelve la id de un espacio
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @param int Posición del espacio
 * @return Id
 */
Id game_get_space_id_at(Game *game, int position);

/**
 * @brief Añade un Objeto
 *
 * @file game.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 20/03/2021
 * @param game Juego usado
 * @param objet Objeto a añadir
 * @return STATUS
 */
STATUS game_add_object(Game *game, Object* object);

/**
 * @brief Devuelve el número de objetos de un juego
 *
 * @file game.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 20/03/2021
 * @param game Juego usado
 * @return int
 */
int game_num_o(Game *game);


#endif
