/**
 * @brief Diseña la interfaz para cada comando
 *
 * @file game_reader.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @return STATUS
 */

#ifndef __GAME_READER__
#define __GAME_READER__

#include "game.h"

/**
 * @brief Carga los espacios
 *
 * @file game_reader.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @param filename Nombre del archivo
 * @return STATUS
 */
STATUS game_reader_load_spaces(Game *game, char *filename);

/**
 * @brief Crea un juego a partir de un archivo
 *
 * @file game_reader.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @param game Juego usado
 * @param filename Nombre del archivo
 * @return STATUS
 */
STATUS game_reader_create_from_file(Game *game, char *filename);

/**
 * @brief Carga los objetos
 *
 * @file game_reader.c
 * @author Álvaro Derecho
 * @version 1.0
 * @date 15/03/2021
 * @param game Juego usado
 * @param filename Nombre del archivo
 * @return STATUS
 */
STATUS game_reader_load_objects(Game *game, char *filename);
/**
 * @brief Carga un jugador
 *
 * @file game_reader.c
 * @author Joseba Arranz
 * @version 1.0
 * @date 12/04/2021
 * @param game Juego usado
 * @param filename Nombre del archivo
 * @return STATUS
 */
STATUS game_reader_load_player(Game *game, char *filename);
#endif
